#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a,i##end=b; i<=i##end; i++)
#define drep(i,a,b) for(int i=a,i##end=b; i>=i##end; i--)
#define repp(i,a,b) for(int i=a,i##end=b; i<i##end; i++)
#define drepp(i,a,b) for(int i=a,i##end=b; i>i##end; i--)
#define Erep(i,x) for(int i=head[x]; i; i=Edge[i].nxt)
#define Srep(i,x) for(int i=x,i##end=x; i; i=(i-1)&i##end)
#define debug(x) cerr<<#x<<" = "<<x<<endl
#define fi first
#define se second
#define PII pair<int,int>
#define coint const int
#define ms(x,a) memset(x,a,sizeof x)
#define CM cerr<<(&S2-&S1)/1024.<<"KB"<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;
template<class T>inline T lowbit(const T &x) { return x&-x; }

coint N=1e5+5;
string str;

void solve(){
	cin>>str;
	bool flag=1;
	if(str[0]!='1') flag=0;
	repp(i,1,int(str.length())-1){
		if(str[i]=='0') flag=0;
	}
	if(str[int(str.length())-1]=='9') flag=0;
	cout<<(flag ? "YES\n" : "NO\n");
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int T=1;
	cin>>T;
	while(T--) solve();
	return 0;
}