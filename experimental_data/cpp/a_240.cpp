#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
bool fav[103];
long zero[103],favo[103];
int main(){
	long i,j,k,m,n,K,l,J;
	char s[13];
	fin >> m >> K;
	for (i=1;i<=K;++i){
		fin >> j;
		fav[j]=1;
	}
	fin >> n;
	for (i=1;i<=n;++i){
		fin >> s;
		fin >> l;
		k=l;
		J=0;
		while (--k>=0){
			fin >> j;
			if (j==0) ++zero[i];
			else{
				if (fav[j]) ++favo[i];
				else ++J;
			}
		}
		if (m-K-J<zero[i]){
			favo[i]+=zero[i]-(m-K-J);
			zero[i]=m-K-J;
		}
		zero[i]=min(zero[i],K-favo[i]);
	}
	for (i=1;i<=n;++i){
		for (j=1;j<=n;++j)
			if (j!=i && favo[i]<favo[j]+zero[j]) break;
		if (j>n){
			fout << 0 << endl;
			continue;
		}
		for (j=1;j<=n;++j)
			if (j!=i && favo[i]+zero[i]<favo[j]) break;
		fout << (j<=n?1:2) << endl;
	}
	fin.close();
	fout.close();
	return 0;
}