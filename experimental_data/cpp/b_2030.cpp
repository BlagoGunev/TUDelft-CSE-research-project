#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int t,n;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		cout<<"1";
		for(int i=1;i<n;i++) cout<<"0";
		cout<<"\n";
	}
	return 0;
}