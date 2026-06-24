#include<iostream>

#include<cstdio>

using namespace std;

int main(){

	int a,b,c;

	cin>>a>>b>>c;

	if(b<a && c>0){

		cout<<"NO";

		return 0;

	}

	if(b>a && c<0){

		cout<<"NO";

		return 0;

	}

	if(c!=0){

		if((b-a)%c==0){

			cout<<"YES";

		}

		else{

			cout<<"NO";

		}

		return 0;

	}

	if(c==0 && a!=b){

		cout<<"NO";

		return 0;

	}

	else{

		cout<<"YES";

		return 0;

	}

}