#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rint register int
#define gc() getchar()
inline int read(int r=0,int s=0,int c=gc()){for(;c<48||c>57;s=c,c=gc());for(;c>=48&&c<=57;(r*=10)+=c-48,c=gc());return s^'-'?r:-r;} 
unordered_map<ll,int> g, f; ll Ans; int n, a, b;
int main()
{
	n = read(), a = read(), b = read(); for(rint i = 1, x, y; i <= n; read(), x = read(), y = read(), ++g[1ll*a*x-y], ++f[x*2000000005ll+y], i++);
	for(auto v:g) Ans += 1ll*v.second*~-v.second; for(auto v:f) Ans -= 1ll*v.second*~-v.second; cout << Ans << endl; return 0;
}