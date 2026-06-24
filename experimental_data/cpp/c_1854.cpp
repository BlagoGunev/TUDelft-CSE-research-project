// Problem: C. Expected Destruction
// Contest: Codeforces - Codeforces Round 889 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1854/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long 
#define rep(i,a,b)	for(int i = (a);i<=(b);i++)
#define lep(i,a,b)	for(int i = (a);i>=(b);i--)
using namespace std;
const int N = 600;
const int M = 1e9+7;
int n,m,s[N],ans;
int f[N][N];
inline int qpow(int a,int b){
	int c = 1;
	while(b){
		if(b&1)	c = c*a%M;
		a = a*a%M;
		b>>=1;
	}
	return c;
}
inline int inv(int x){return qpow(x,M-2);}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)	cin>>s[i];
	s[n+1] = m+1;
	lep(i,m,1){
		lep(j,m+1,i+1){
			if(j == m+1)	f[i][j] = (f[i+1][j]+1)%M;
			else f[i][j] = inv(2)*(f[i+1][j]+1+f[i][j+1]%M)%M;
		}
	}
	rep(i,1,n)	ans = (ans+f[s[i]][s[i+1]])%M;
	cout<<ans<<"\n";
	return 0;	
}