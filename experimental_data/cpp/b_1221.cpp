#include<bits/stdc++.h>
using namespace std;
#define ll long long
     
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i%2==0&&j%2==0)
				cout<<"B";
			else if(i%2==0&&j%2==1)
				cout<<"W";
			else if(i%2==1&&j%2==0)
				cout<<"W";
			else
				cout<<"B";
		}
		cout<<endl;
	}
	return 0;
}