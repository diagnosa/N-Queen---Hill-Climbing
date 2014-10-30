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
	for(i=0;i<n;i++){
		kolom.push_back(0);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			kolom[j]=0;
		}
		b= rand()%n;
		kolom[b]=1;
		papan.push_back(kolom);
		hvalue.push_back(kolom);
	}
}
void cetak(int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			cout << papan[j][i] << " ";
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
				int k=0, l=1;
				while (k<len)
				{
					hvalue[j][k]++;
					hvalue[k][i]++;
					hvalue[j+l][i+l]++;
					hvalue[j-l][i-l]++;
					cetakh(n);
					k++;
					l++;
				}
			}
		}
	}
	
}

int main(){
	int n, j , i;
	cout << "isi banyak queen : ";
	scanf("%d", &n);
	inisialisasi(n);
	cetak(n);
	gethcost(n);
	printf ("cek\n");
	cetakh(n);
	return 0;
}
