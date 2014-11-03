#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> kolom;
vector< vector<int> > papan;
vector< vector<int> > hvalue;
void inisialisasi(int n){
	int i, j, b;
	srand(time(NULL));
	for(i=0;i<n;i++){
		kolom.push_back(0);
	}
	for(i=0;i<n;i++){
		papan.push_back(kolom);
		hvalue.push_back(kolom);
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

void cetakh(int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			cout << hvalue[j][i] << " ";
		}
		cout << endl;
	}
}

void gethcost (int len){
	int n=len;
	int h=0;
	for (int i=0; i<len; i++)
	{
		for (int j=0; j<len; j++)
		{
			if (papan[j][i]==1)
			{
				printf ("kolom: %d baris: %d\n", j, i);
				int k=0, l;
				//attempt baris
				while (k<len)
				{
					hvalue[k][i]++;
					k++;
				}
				k=0;
				//attempt kolom
				while (k<len){
					hvalue[j][k]++;
					k++;
				}
				//attempt diagonal utama belum jadi help
				k=0, l=abs(j-i);
				while (k<len)
				{
					hvalue[k][k+l]++;
					k++;
				}
				//attempt diagonal bukan utama belum jadi help
				k=0, l=abs(j-i);
				while (k<len)
				{
					hvalue[k][k+l]++;
					k++;
					l++;
				}
				cetakh(n);
			}
		}
	}
	
}

int main(){
	int n, j , i;
	cout << "isi banyak queen : ";
	cin >> n;
	inisialisasi(n);
	cetak(n);
	gethcost(n);
	printf ("cek\n");
	cetakh(n);
	return 0;
}
