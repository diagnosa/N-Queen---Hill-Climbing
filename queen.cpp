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

void gethcost (int len){
	int h =0, offset;
	for (int k=0; k<len; k++)
	{
		for (int i=0, j=i+1; j < len; i++)
		{
				offset = j-i;
				if ((papan[k][i]==papan[k][j])&&(papan[k][i]==1)&&(papan[k][j]==1)) 
				{
					h+=1;
					hvalue[k][i]=h;
					hvalue[k][j]=h;
				}
				if ((papan[k][i]==papan[k][j-offset])&&(papan[k][i]==1) || (papan[k][i]==papan[k][j+offset])&&(papan[k][i]==1))
				{
					h+=1;
					hvalue[k][i]=h;
					hvalue[k][j]=h;
				}
				j++;
		}
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
