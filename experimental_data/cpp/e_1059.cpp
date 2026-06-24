#include <bits/stdc++.h>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rt register int
#define l putchar('\n')
#define ll long long
#define r read()
#define p 998244353
using namespace std;
inline ll read(){
    ll x = 0; char zf = 1; char ch;
    while (ch != '-' && !isdigit(ch)) ch = getchar();
    if (ch == '-') zf = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); return x * zf;
}
void write(ll y){if(y<0)putchar('-'),y=-y;if(y>9)write(y/10);putchar(y%10+48);}
void writeln(const ll y){write(y);putchar('\n');}
#define N 400010
int n,L,w[N];
int fuqing[N][21],f[N],ans[N],sd[N];
ll tot[N],ss,S; 
vector<int>son[N];
void dfs(const int x){
	tot[x]+=w[x];
	for (int i=0;i<son[x].size();i++){
		sd[son[x][i]]=sd[x]+1;
		tot[son[x][i]]=tot[x];
		dfs(son[x][i]);
	}
}
void work(const int x){
	if(tot[x]<=S&&sd[x]<=L)return ans[x]=sd[x],void();
	ll res=S;
	int cd=L,now=x;
	for(rt j=18;j>=0;j--){
		const int ff=fuqing[x][j];
		if(ff&&tot[now]-tot[ff]<=res&&sd[now]-sd[ff]<=cd){
			ans[x]+=sd[now]-sd[ff];
			cd-=sd[now]-sd[ff];
			res-=tot[now]-tot[ff];
		}
	}
}
void dfs2(int x){
	if (son[x].size()==0)work(x),f[x]=1;
	else{
		int aa=0;
		for (int j=0;j<son[x].size();j++){
			dfs2(son[x][j]);
			f[x]+=f[son[x][j]];
			aa=max(aa,ans[son[x][j]]-1);
		}
		if(!aa)f[x]++,work(x);
		else ans[x]=aa;
	}
	if(!ans[x]){
		puts("-1");
		exit(0);
	}
}
int main(){
	n=r;L=r;S=r;
	for(rt i=1;i<=n;i++)w[i]=r;
	for(rt i=2;i<=n;i++)fuqing[i][0]=r,son[fuqing[i][0]].push_back(i);
	for(rt j=1;j<=18;j++)
	for(rt i=1;i<=n;i++)
	fuqing[i][j]=fuqing[fuqing[i][j-1]][j-1];
	sd[1]=1;dfs(1);dfs2(1);
	printf("%d",f[1]);
	return 0;
}