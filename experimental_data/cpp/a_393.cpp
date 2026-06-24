#include<iostream>

#include<cstdio>

using namespace std;

int a[4];

int main(){

	string x;

	cin>>x;

	for(int i=0;i<x.size();i++){

		if(x[i]=='n'){

			a[0]++;

		}

		else if(x[i]=='i'){

			a[1]++;

		}

		else if(x[i]=='e'){

			a[2]++;

		}

		else{

			a[3]++;

		}

	}

	a[0]=(a[0]-1)/2;

	a[2]/=3;

	cout<<min(min(min(a[0],a[1]),a[2]),a[3]);

}