#include <bits/stdc++.h>
using namespace std;


int n;
int a[7]={-2,-1,1,-1,1,2};
int b[7]={1,-2,2,3,-3,-1};

int main(){
	cin>>n;
	if(n==3||n==5){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	if(n&1){
		cout<<"-3 -3 2 1 -1 ";
		n-=5;
		for(int i=0;i<n;i++)
			cout<<b[i%6]<<' ';
	}
	else{
		for(int i=0;i<n;i++){
			cout<<a[i%6]<<' ';
		}
	}
		
	cout<<endl;
	
	
	
	return 0;
}