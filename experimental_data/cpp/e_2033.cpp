#include <bits/stdc++.h>
using namespace std;
//#define int long long 
#define il inline
#define Tp template<typename T>
#define Ts template<typename T,typename... _T>
#define pc putchar
#define gc getchar
#define pb push_back
#define inf 1e9
#define ll long long
//#define mod  
Tp il void read(T& x) {
	x=0;bool f=0;char c=gc();
	for(;c<'0'||c>'9';c=gc()) f|=c=='-';
	for(;c>='0'&&c<='9';c=gc()) x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}Ts il void read(T& x,_T&... y) {read(x),read(y...);}
Tp il void write(T x) {if(x<0)x=-x,pc('-');if(x>=10)write(x/10);pc(x%10+'0');}
Tp il void writeln(T x){write(x);puts("");}
const int N=1e6+10;
int n;
int a[N],b[N];
int ans,res;
void dfs(int i){
	b[i]=1;
	res++;
	if(!b[a[i]])dfs(a[i]);
}
void solve(){
	read(n);
	res=0,ans=0;
	for(int i=1;i<=n;i++){
		read(a[i]);
		b[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			res=0;
			dfs(i);
			ans+=(res-1)/2;
		}
	}
	writeln(ans);
}
signed main(){
	int t;
	read(t);
	while(t--){
		solve();
	}
	return 0;
}