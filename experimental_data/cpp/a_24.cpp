#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

// Disable warning messages C4996.
#pragma warning(disable:4996)

int main(int argc, char **argv)
{
	ifstream from;
	const int nmin=3, nmax=100;
	int n, res, res1, res2, k, i, j;
	int err=0;
	int a[nmax], b[nmax], c[nmax], s[nmax];
	//char ch;
	//string s[nmax];
	//string s, st, s1, s2;

	//from.open("test.txt");
	//from>>n;
	cin>>n;

	for(i=0;i<n;i++){
		//from>>a[i]>>b[i]>>c[i];
		cin>>a[i]>>b[i]>>c[i];
	}

	res=res1=res2=0;
	s[0]=a[0];
	s[1]=b[0];
	res2+=c[0];

	for(i=2;i<n;i++){
		for(j=0;j<n;j++){
			if((s[i-1]==a[j])&&(s[i-2]!=b[j])){
				s[i]=b[j];
				res2+=c[j];
				break;
			}
			if((s[i-1]==b[j])&&(s[i-2]!=a[j])){
				s[i]=a[j];
				res1+=c[j];
				break;
			}
		}
	}

	for(j=0;j<n;j++){
		if((s[n-1]==a[j])&&(s[n-2]!=b[j])){
			//s[0]=b[j];
			res2+=c[j];
			break;
		}
		if((s[n-1]==b[j])&&(s[n-2]!=a[j])){
			//s[0]=a[j];
			res1+=c[j];
			break;
		}
	}

	res=(res1<=res2)?res1:res2;

	//cout<<n<<endl;
	cout<<res<<endl;
	return 0;
}