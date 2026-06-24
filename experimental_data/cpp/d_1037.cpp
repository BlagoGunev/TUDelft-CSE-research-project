#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i <= k;++i)
#define repp(i,j,k) for(int i = j;i >= k;--i)
#define rept(i,x) for(int i = linkk[x];i;i = e[i].n)
#define P pair<int,int>
#define Pil pair<int,ll>
#define Pli pair<ll,int>
#define Pll pair<ll,ll>
#define pb push_back 
#define pc putchar
#define mp make_pair
#define file(k) memset(k,0,sizeof(k))
#define ll long long
int read()
{
    int sum = 0;char c = getchar();bool flag = true;
    while(c < '0' || c > '9') {if(c == '-') flag = false;c = getchar();}
    while(c >= '0' && c <= '9') sum = sum * 10 + c - 48,c = getchar();
    if(flag) return sum;
    else return -sum;
}
int n;
int dep[201000];
int linkk[201000] , t;
int f[201000];
int son[201000];
bool vis[201000];
struct node{
	int n , y;
}e[401000];
void insert(int x,int y)
{
	e[++t].y = y;e[t].n = linkk[x];linkk[x] = t;
	e[++t].y = x;e[t].n = linkk[y];linkk[y] = t;
}
void dfs(int x,int fa)
{
	f[x] = fa;
	dep[x] = dep[fa] + 1;
	rept(i,x)
	    if(e[i].y != fa)
	        dfs(e[i].y,x),son[x]++;
}
int a[201000];
queue<int>q;
int main()
{
	n = read();
	rep(i,1,n-1)
	{
		int x = read() , y = read();
		insert(x,y);
	}
    dfs(1,0);
    rep(i,1,n) a[i] = read();
    rep(i,2,n) if(dep[a[i]] < dep[a[i-1]]) {printf("No");return 0;}
    q.push(a[1]);
    int i = 2;
    while(!q.empty())
    {
    	int x = q.front();q.pop();
        rep(j,1,son[x]) 
            if(f[a[i+j-1]] != x) {printf("No");return 0;}
            else q.push(a[i+j-1]);
        i += son[x];
    }
    printf("Yes");
    return 0;
}