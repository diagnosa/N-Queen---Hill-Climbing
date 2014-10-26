#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> kolom;
vector< vector<int> > papan;

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

int main(){
	int n, j , i;
	cout << "isi banyak queen : ";
	scanf("%d", &n);
	inisialisasi(n);
	cetak(n);
	return 0;
}
