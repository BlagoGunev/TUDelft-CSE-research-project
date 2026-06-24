// LUOGU_RID: 157870257
#include <bits/stdc++.h>
#define i32 int
#define i64 long long
#define i128 __int128
#define u64 unsigned long long
using namespace std;
const i64 mod = 998'244'353;
const i32 maxn = 2e5+100;
const i32 inf = 0x7fffffff;

void Main(){
	i32 n;cin>>n;
	string s;cin>>s;
	
	i32 cnt0=0,cnt1=0;
	for(i32 i=0;i<n;++i){
		if(s[i]=='0') ++cnt0;
		else ++cnt1;
	}
	if(cnt0^cnt1) return cout<<-1<<'\n',void();
	
	vector<i32> ans;
	deque<char> q; for(char c:s) q.push_back(c);
	i32 tot=1;
	while(!q.empty()){
		if(q.front()^q.back()){
			q.pop_back();
			q.pop_front();
		}else if(q.front()=='1'){
			ans.push_back(tot-1);
			q.pop_back();
			q.push_front('1');
		}else{
			ans.push_back(tot+q.size()-1);
			q.pop_front();
			q.push_back('0');
		}
		tot++;
	}
	cout<<ans.size()<<'\n';
	for(i32 x:ans) cout<<x<<' ';
	cout<<'\n';
}
main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		Main();
	}
}