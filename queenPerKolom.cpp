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
void inisialisasi(int n){
	int i, j, b;
	srand(time(NULL));
	for(i=0;i<n;i++){
		kolom.push_back(0);
		hvalue.push_back(0);
	}
	for(i=0;i<n;i++){
		papan.push_back(kolom);
	}
	for(i=0;i<n;i++){
		b= rand()%n;
		papan[b][i]=1;
	}
}
void cetak(int n){
	int i, j;
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
	for(i=0; i<n; i++){
		cout << hvalue[i] << " ";
	}	
	cout << endl;
}

int getPair (int len, int baris, int kolom){
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

void cekHValue(int max){
	int h, j, temp, l;
	for(int k=0; k<=max; k++){
		h=0;
		for (l=0; l<=max; l++)
		{
			if (papan[l][k]==1) break;
		}
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
	}
}

void hillClimbing (int maxLen){
	int hmax, indeks=0, cek;
	while(1){
		cek=1;
		hmax=0;
		cekHValue(maxLen);
		for(int i=0; i<=maxLen; i++){
			if(hmax<hvalue[i]){
				hmax=hvalue[i];
				indeks=i;
			}	
		}
		for(int i=0; i<=maxLen; i++){
			if(papan[i][indeks]){
				int temp;
				if(i==maxLen) temp=0;
				else temp=i+1;
				swap(papan[i][indeks], papan[temp][indeks]);
				break;
			}
		}
		
		for(int i=0; i<=maxLen; i++){
			if(hvalue[i]>0){
				cek=0;
				break;
			}	
		}
		cetak(maxLen+1);
		system("pause");
		if(cek) break;
	}
	
	
}

int main(){
	int n, j , i;
	cout << "isi banyak queen : ";
	cin >> n;
	inisialisasi(n);
	cetak(n);
	hillClimbing(n-1);
	printf ("cek\n");
	cetakh(n);
	return 0;
}
