#include <bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> void read(T &x){
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}

const int N = 200050;
LL ans = 0;
int To[N<<1],Ne[N<<1],He[N],_k;
inline void add(int x,int y){
	++_k; To[_k] = y,Ne[_k] = He[x],He[x] = _k;
	++_k; To[_k] = x,Ne[_k] = He[y],He[y] = _k;
}
int n,k,size[N],dpt[N],val[N],fa[N];
inline void dfs(int x){
	size[x] = 1;
	for (int y,p = He[x]; p ; p = Ne[p]) if ((y=To[p])^fa[x]){
		fa[y] = x,dpt[y] = dpt[x] + 1;
		dfs(y);
		size[x] += size[y];
	}
}
int main(){
	int i,x,y;
	read(n),read(k); for (i = 1; i < n; ++i) read(x),read(y),add(x,y);
	dpt[1] = 1,dfs(1);
	for (i = 1; i <= n; ++i) val[i] = dpt[i] - size[i];
	sort(val+1,val+n+1);
	reverse(val+1,val+n+1);
	for (i = 1; i <= k; ++i) ans += val[i];
	cout << ans << '\n'; 
	return 0;
}