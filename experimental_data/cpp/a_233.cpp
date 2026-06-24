#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n%2==0){
		for(int i=0;i<n;++i)
			cout<<(1+i+(i&1?-1:1))<<" ";
		cout<<endl;
	}else{
		cout<<"-1"<<endl;
	}
	return 0;
}