// LUOGU_RID: 155415617
#include <bits/stdc++.h>
#define i32 int
#define i64 long long
#define i128 __int128
#define u64 unsigned long long
using namespace std;
const i64 mod = 1e9+7;
const i32 maxn = 5e5+100;
i32 n,Q;
i32 a[maxn];

void Main(){
	cin>>n;
	for(i32 i=1;i<=n;++i) cin>>a[i];
	string ans="YES\n";
	for(i32 m=1;(1<<m-1)<n;++m){
		for(i32 i=(1<<m-1)+1;i<(1<<m)&&i<n;++i){
			if(a[i]>a[i+1]) ans="NO\n";
		}
	}
	cout<<ans;
}
main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		Main();
	}
	//cout<<jlu;
}