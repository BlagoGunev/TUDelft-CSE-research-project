#include<iostream>

using namespace std;

int main(){

	char k;

	int n,m,l=0;

	cin>>n>>m;

	for(int i=0;i<n*m; i++){cin>>k; if(k!='W' && k!='B' && k!='G')l=1;}

	if(l==0)cout<<"#Black&White";

	else cout<<"#Color";

	return 0;

}