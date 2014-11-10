/*
Program N-Queen menggunakan HillClimbing
Kelompok 7
AI C 2014/2015

Input : jumlah pion Queen
Output : solved jika mencapai solusi
		 nilai H saat ini jika tidak terdapat solusi
*/


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> kolom;
vector< vector<int> > papan;
vector<int> hvalue;
vector<int> hvalue1;

void inisialisasi(int n){
	//inisialisasi dilakukan dengan merandom posisi baris tiap kolomnya
	int i, j, b;
	srand(time(NULL));
	for(i=0;i<n;i++){
		kolom.push_back(0);
		hvalue.push_back(0);
		hvalue1.push_back(0);
	}
	for(i=0;i<n;i++){
		papan.push_back(kolom);
	}
	for(i=0;i<n;i++){
		b= rand()%n;
		papan[b][i]=1;
		kolom[i]=b;
	}
}
void cetak(int n){
	int i, j;
	cout <<endl;
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			cout << papan[i][j] << " ";
		}
		cout << endl;
	}
}

void swap(int *i, int*j){
	int *temp=i;
	i=j;
	j=temp;
}

void cetakh(int n){
	int i;
	cout << endl << "hvalue bawah:" << endl;
	for(i=0; i<n; i++){
		cout << hvalue[i] << " ";
	}
	cout << endl << "hvalue atas:" << endl;
	for(i=0; i<n; i++){
		cout << hvalue1[i] << " ";
	}
	cout << endl;
}

int getPair (int len, int baris, int kolom){
	//fungsi ini untuk mencari jumlah ratu yang menyerang pion pada posisi : papan[baris][kolom]
	//serangan dari sisi kiri diabaikan karena dianggap sudah dihitung pion sebelumnya untuk menghindari redudansi
	int h = 0, j=0;
	for(int i=kolom; i<len;){
		i++;
		if(papan[baris][i]&&i!=kolom) h++; //hitung h horizontal
	}
	j=baris;
	for(int i=kolom; i<len&&j<len; ){
		i++;
		j++;
		if(papan[j][i]) h++; //hitung h kanan bawah
	}
	j=baris;
	for(int i=kolom; i<len&&j>0;){
		i++;
		j--;
		if(papan[j][i]) h++; //hitung h kanan atas
	}
	return h;
}

int getCurrentH(int max){
	int h=0;
	for (int i=0; i<max; i++)
		{
			int j=kolom[i];
			h+=getPair(max, j, i);
		}
	return h;
}

void cekHValue(int max){
	int h, j, temp, l;
	for(int k=0; k<=max; k++){
		h=0;
		for (l=0; l<=max; l++)
		{
			if (papan[l][k]==1) break;
		}
		/*mencari hvalue kalo dipindah ke bawah atau bisa disebut tetangga bawah*/
		if(l==max) temp=0;
		else temp=l+1;
		swap(papan[l][k], papan[temp][k]);
		for (int i=0; i<max; i++)
		{
			for (j=0; j<=max; j++)
			{
				if (papan[j][i]==1) break;
			}
			h+=getPair(max, j, i);
		}
		hvalue[k]=h;
		swap(papan[l][k], papan[temp][k]);
		/*------------------------------------*/
		
		/*mencari hvalue kalo dipindah ke atas atau bisa disebut tetangga atas*/
		if(l==0) temp=max;
		else temp=l-1;
		swap(papan[l][k], papan[temp][k]);
		for (int i=0; i<max; i++)
		{
			for (j=0; j<=max; j++)
			{
				if (papan[j][i]==1) break;
			}
			h+=getPair(max, j, i);
		}
		hvalue1[k]=h;
		swap(papan[l][k], papan[temp][k]);
		/*------------------------------------*/
	}
}

void hillClimbing (int maxLen){
	int hmin, indeks=0, cek, atas;
	while(1){
        if(getCurrentH(maxLen) == 0){
        	cout << endl << "Solved" <<endl; //menghentikan fungsi ketika h saat ini 0
			return; 
        }
		hmin=999;
		cekHValue(maxLen);
		/*-------mencari hvalue terkecil-------*/
		for(int i=0; i<=maxLen; i++){
			if(hmin>hvalue[i]){
				hmin=hvalue[i];
				indeks=i;
				atas=0;
			}
			if(hmin>hvalue1[i]){
				hmin=hvalue1[i];
				indeks=i;
				atas=1;
			}
			
		}
		/*--------------------------------------*/
        cetakh(maxLen+1);
        if(getCurrentH(maxLen)<hmin) { //menghentikan fungsi ketika tidak ada lagi solusi yang lebih baik dari state sekarang
    		cout<< endl << "Tidak ditemukan solusi" << endl
    			<< "H saat ini : " << getCurrentH << endl;
    		return;
		}
		int temp, i;
        i=kolom[indeks];
        if(atas){
        	if(i==0) temp=maxLen;
			else temp=i-1;
        }
        else{
	        if(i==maxLen) temp=0;
			else temp=i+1;
        }
		swap(papan[i][indeks], papan[temp][indeks]);
	    kolom[indeks]=temp;
		cetak(maxLen+1);
	}
}

int main(){
	double total_time1;
 	clock_t start, end;
	int n, j , i;
	cout << "isi banyak queen : ";
	cin >> n;
	while(n<4){
		cout << "Banyak Queen Minimal 4" << endl;
	cout << "isi banyak queen : ";
	cin >> n;
	}
	inisialisasi(n);
	cetak(n);
	start = clock();
	hillClimbing(n-1);
	end = clock();//time count stops 
	total_time1 = ((double) (end - start)) / CLOCKS_PER_SEC;//calulate total time
	cout << "Running Time : " << total_time1 << " s" <<endl;
	return 0;
}
