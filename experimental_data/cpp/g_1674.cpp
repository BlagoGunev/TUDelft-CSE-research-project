#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <cmath>

#define ll long long 

#define N 500010

using namespace std;

ll read(){

	char cc;

	while(1){cc=getchar();if((cc>='0'&&cc<='9')||cc=='-')break;}

	ll sum=0,flag=1;

	cc=='-'?flag=-1:sum=(cc^48);

	while(1){cc=getchar();if(!(cc>='0'&&cc<='9'))break;sum=(sum<<1)+(sum<<3)+(cc^48);}

	return sum*flag;

}

void write(ll x){

	if(!x)putchar('0');

	if(x<0){x=-x;putchar('-');}

	ll cc[25],cntt=0;

	while(x){cc[++cntt]=x%10;x/=10;}

	for(ll i=cntt;i>=1;i--)putchar(cc[i]+'0');

	putchar('\n');

}

struct edge{

	ll v,ne;

}b[N<<1];

ll n,m,tot=0,h[N],vis[N],in[N],out[N],f[N],ans=1,u,v;

void add(ll u,ll v){

	b[++tot]=(edge){v,h[u]};

	h[u]=tot;

}

void dfs(ll x){

	vis[x]=1;

	f[x]=1;

	if(out[x]<2)return ;

	f[x]=0;

	for(ll i=h[x];i;i=b[i].ne){

		ll v=b[i].v;

		if(!vis[v])dfs(v);

		if(in[v]<2)continue;

		f[x]=max(f[x],f[v]);

	}

	f[x]++;

	ans=max(ans,f[x]);

}

void swap(ll &a,ll &b){ll w=a;a=b;b=w;}

int main(){

	n=read();m=read();

	for(ll i=1;i<=m;i++){

		u=read();v=read();

		add(u,v);

		out[u]++;in[v]++;

	}

	for(ll i=1;i<=n;i++)if(!vis[i])dfs(i);

	write(ans);

	return 0;

}