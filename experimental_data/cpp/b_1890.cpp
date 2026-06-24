// LUOGU_RID: 155415901
#include <bits/stdc++.h>
#define i32 int
#define i64 long long
#define i128 __int128
#define u64 unsigned long long
using namespace std;
const i64 mod = 1e9+7;
const i32 maxn = 5e5+100;
i32 n,m;
string S,T;

void Main(){
	cin>>n>>m;
	cin>>S>>T;
	
	bool ok=1;
	for(i32 i=1;i<S.size();++i) if(S[i]==S[i-1]) ok=0;
	if(ok==1) return cout<<"Yes\n",void();
	
	ok=(T[0]==T.back());
	for(i32 i=1;i<T.size();++i) if(T[i]==T[i-1]) ok=0;
	for(i32 i=1;i<S.size();++i) if(S[i]==S[i-1]&&T[0]==S[i]) ok=0;
	cout<<(ok?"Yes":"No")<<'\n';
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