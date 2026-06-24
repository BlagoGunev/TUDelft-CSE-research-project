#include<iostream>

#include<cstdio>

#include<vector>

using namespace std;

vector<int> a;

int main(){

	int n;

	cin>>n;

	while(n>0){

		a.push_back(n%2);

		n/=2;

	}

	for(int i=a.size()-1;i>=0;i--){

		if(a[i]){

			cout<<i+1<<" ";

		}

	}

}