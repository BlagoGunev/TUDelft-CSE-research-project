#include<bits/stdc++.h>

using namespace std;



int main(){

	string x,y;

	int a[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

	int z,t=5,candy=0;

	cin>>z>>x>>y;

	if(y=="month"){

		for(int i=1 ; i<=12 ; i++){

			if(z<=a[i]){

				candy++;

			}

		}

	}

	else{

		if(z==5||z==6){

			candy=53;

		}

		else{

			candy=52;

		}

	}

	cout<<candy<<endl;

	return 0;

}