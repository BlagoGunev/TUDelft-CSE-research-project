#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

struct modein{

	modein operator >>(int &x){

		x=0;char c=getchar();

		while(c<'0'||c>'9')c=getchar();

		while(c>='0'&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();

		return (modein){};

	}

}qin;

basic_string<int>e[200010][2];long long res;

int T,n,m,l[200010],r[200010],cs1,cs2;bool to[200010],usd[200010][2];

void dfs(int p,bool f){

	if(usd[p][f])return;usd[p][f]=true;

	for(auto q:e[p][0])if(r[p+1]>=q-1)dfs(q-1,!f);	

}

void cfs(int p,bool f){

	if(usd[p][f])return;usd[p][f]=true;

	for(auto q:e[p+1][1])if(l[p]<=q+1)cfs(q,!f);	

}

int main(){

	qin>>T;

	while(T--){

		qin>>n>>m,memset(to,false,sizeof to),memset(usd,false,sizeof usd);

		memset(l,0,sizeof l),memset(r,0,sizeof r);

		for(int i=0;i<=n+1;i++)e[i][0].clear(),e[i][1].clear();

		for(int i=1,a,b;i<=m;i++){

			qin>>a>>b;

			if(b==a+1)to[a]=true;

			else e[a][0]+=b,e[b][1]+=a;

		}

		for(int i=1;i<=n;i++){

			if(i<n)e[i][0]+=n+1;

			if(i>1)e[i][1]+=0;

		}

		to[0]=to[n]=true,r[n+1]=n+1;for(int i=n;~i;i--)r[i]=to[i]?r[i+1]:i;

		for(int i=1;i<=n+1;i++)l[i]=to[i-1]?l[i-1]:i;

		if(!l[n+1]){printf("%lld\n",(long long)n*(n-1)/2);continue;}

		dfs(r[1],true),usd[r[1]][1]=false,cfs(r[1],true),res=cs1=cs2=0;

		for(int i=0;i<=r[1];i++)cs1+=usd[i][0];

		for(int i=l[n]-1;i<=n;i++)cs2+=usd[i][0];

		res+=(long long)cs1*cs2,cs1=cs2=0;

		for(int i=0;i<=r[1];i++)cs1+=usd[i][1];

		for(int i=l[n]-1;i<=n;i++)cs2+=usd[i][1];

		res+=(long long)cs1*cs2,cs1=cs2=0;

		for(int i=0;i<=r[1];i++)cs1+=usd[i][0]&&usd[i][1];

		for(int i=l[n]-1;i<=n;i++)cs2+=usd[i][0]&&usd[i][1];

		res-=(long long)cs1*cs2,cs1=cs2=0;

		printf("%lld\n",res-(r[1]+1==l[n]));

	}

	return 0;

}