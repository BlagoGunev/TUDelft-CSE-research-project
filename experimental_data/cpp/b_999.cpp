#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	int slen,d[100],nod=0;
	string s;
	cin>>slen;
	cin>>s;
	int i;
	for(i=1;i<=slen;i++){
		if(slen%i==0){
			d[nod]=slen/i;
	//		cout<<slen/i<<endl;
			nod++;
		}
	}
	for(i=nod-1;i>=0;i--){
		reverse(s.begin(),s.begin()+d[i]);
	//	cout<<s<<endl;
	}
	cout<<s;
	return 0;
}