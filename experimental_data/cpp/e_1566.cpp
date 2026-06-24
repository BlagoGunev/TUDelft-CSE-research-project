#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define P pair<int,int>
#define pll pair<long,long>
using namespace std;
template<typename T>void write(T x) {
    if(x<0) { putchar('-'); x=-x; }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], str[64];
    int l = SIZE, r = SIZE;
    int read(char *s) {
        while (r) {
            for (; l < r && buf[l] <= ' '; l++);
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        int cur = 0;
        while (r) {
            for (; l < r && buf[l] > ' '; l++) s[cur++] = buf[l];
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        s[cur] = '\0';
        return cur;
    }
    template<typename type>
    bool read(type &x, int len = 0, int cur = 0, bool flag = false) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        if (flag) x = -x;
        return true;
    }
    template <typename type>
    type read(int len = 0, int cur = 0, bool flag = false, type x = 0) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        return flag ? -x : x;
    }
} using FastIO::read;
//Data
const int N=5e5+10,MAXN=5e3+10,mod=998244353;
struct edge {
	int to,Next;
}Edge[N<<1];
int Head[N],tot,dp[N],cnt[N],res,sz[N],Max[N],val[N],sum[N];
//val 叶子总数
//sum 芽的个数 
void Add(int from, int to) {
	Edge[tot]={to,Head[from]};
	Head[from]=tot++;
	Edge[tot]={from,Head[to]};
	Head[to]=tot++;
}
void dfs(int u, int fa) {
	dp[u]=1,cnt[u]=0,sz[u]=1,sum[u]=0,val[u]=0;
	for (int i=Head[u]; ~i; i=Edge[i].Next) {
		int v=Edge[i].to;
		if (v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		cnt[u]+=dp[v];
		sum[u]+=sum[v]; 
		val[u]+=val[v];
	}
	if (cnt[u]) dp[u]=0,sum[u]++,val[u]+=cnt[u];
}
void solve(int u, int fa, int now, int Val, int Sum) {
	if (sz[u]==1) res=min(res,now+Val+1-Sum);
	for (int i=Head[u]; ~i; i=Edge[i].Next) {
		int v=Edge[i].to;
		if (v==fa) continue;
		int Nval=Val+(val[u]-val[v]),Nsum=Sum+(sum[u]-sum[v]);
		if (cnt[u]) Nsum--;
		if (dp[v]==1&&cnt[u]==1) Nval-=1;
		else Nval-=cnt[u];
		solve(v,u,now+cnt[u]-dp[v],Nval,Nsum); 
	}
}
int main() {
	int t;
	read(t);
	while (t--) {
		tot=0;
		int n;
		read(n);
		res=n;
		for (int i=1; i<=n; i++) Head[i]=-1;
		for (int i=1; i<n; i++) {
			int u,v; read(u),read(v);
			Add(u,v);
		}
		dfs(1,0);
		solve(1,0,0,0,0);
		printf("%d\n",res);
	}
	return 0;
}