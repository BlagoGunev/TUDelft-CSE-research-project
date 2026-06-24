#include <bits/stdc++.h>

 

using namespace std;

 

long long binpow(long long a, long long b) {

    if (b == 0)

        return 1;

    long long res = binpow(a, b / 2);

    if (b % 2)

        return res * res * a;

    else

        return res * res;

}

 

int main(){

 

	std::cin.tie(nullptr);

    std::ios_base::sync_with_stdio(false);

 

 

	int t;

	cin>>t;

	while(t--){

 

		string s;

		int n;

		cin>>n;

		cin>>s;

 

		bool flag=true;

		char aux=s[0];

 

		

 

 

		for(int i=1;i<n;i++){

 

			if(aux>s[i]){

 

				flag=false;

				break;

 

 

			}

 

			aux=s[i];

 

 

 

 

 

		}

 

		if(flag)cout<<"0"<<endl;

		else{

 

 

		char comp='0';

 

		int ct=0;

 

 

		for(int i=0;i<n;i++){

 

			if(s[i]!=comp){

 

				comp=s[i];

				ct++;

			}

		}

 

		cout<<ct-1<<endl;

 

		}

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

		

 

 

 

 

 

 

   

}

 

 

 

    return 0;

}