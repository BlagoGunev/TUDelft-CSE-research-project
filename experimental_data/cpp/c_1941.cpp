#include<bits/stdc++.h>
using namespace std;
string s;
long long t;
long long n;
int main(){
	cin>>t;
	while(t--){
		int count=0;cin>>n;
		cin>>s;
		int i;
		for(i=0;i<n-2;i++){
				if(s[i]=='m'&&s[i+1]=='a'&&s[i+2]=='p'){count++;i+=2;}
		else  if(s[i]=='p' && s[i+1]=='i'&&s[i+2]=='e'){count++;i+=2;}     
		}cout<<count<<"\n";
	}
}