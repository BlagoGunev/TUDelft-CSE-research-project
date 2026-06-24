#include<iostream>

#include<cstdio>

using namespace std;

int main(){

	int n,x,a,sum=0;

	cin>>n>>x;

	for(int i=0;i<n;i++){

		cin>>a;

		sum+=a;

	}

	if(sum<0){

		sum*=-1;

	}

	int ans=sum/x;

	if(sum%x>0){

		ans++;

	}

	cout<<ans;

}