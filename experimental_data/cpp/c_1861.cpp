#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin>>s;
	int now=0;
	int s1=1;
	int s2=3e5;
	for(auto c:s){
		if(c=='+'){
			now++;
		}
		if(c=='-'){
			now--;
			if(now>0&&s1>now){
				s1=now;
			}
			if(s2>now)s2=3e5;
		}
		if(c=='1'){
			if(s2<=now){
				cout<<"NO\n";
				return;
			}
			s1=max(s1,now);
			continue;
		}
		if(c=='0'){
			if(s1>=now){
				cout<<"NO\n";
				return;
			}
			s2=min(s2,now);
		}
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	for(int i=1;i<=t;i++)solve();
	return 0;
}