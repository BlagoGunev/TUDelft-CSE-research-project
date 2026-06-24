#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int T,n;
string s;

int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		if(n&1){
			puts("-1");
			continue;
		}
		s=" "+s;
		map<char,int> mp;
		int tot=0,maxx=0,lst=0;
		char ch;
		for(int i=1;i<=n/2;i++)
			if(s[i]==s[n-i+1]){
				mp[s[i]]++;
				tot++;
				if(mp[s[i]]>maxx){
					maxx=mp[s[i]];
					ch=s[i];
				}
			}
		
		if(tot==0){
			puts("0");
			continue;
		}
		
		for(int i=1;i<=n;i++)lst+=(s[i]==ch);
		
		if(lst>n-lst)puts("-1");
		else if(tot-maxx>=maxx)cout<<(tot+1)/2<<endl;
		else cout<<maxx<<endl;
	}
	return 0;
}