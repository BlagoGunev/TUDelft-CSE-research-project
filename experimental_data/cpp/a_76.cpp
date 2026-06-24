#include<cstdio>

#include<iostream>

#include<cstring>

#include<algorithm>



using namespace std;

typedef long long ll;

int getint(){

	int x=0,f=1;

	char ch=getchar();

	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}

	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}

	return f*x;

}

#define N 210

#define M 51234

int pre[N];

int find(int x){

	int res=x;

	while(res!=pre[res])res=pre[res];

	int t;

	while(pre[x]!=res){

		t=pre[x]; pre[x]=res; x=t;

	}

	return res;

}

int n,m,G,S;

struct edge{

	int g,s,x,y;

}e[M],a[N];

int tot;

bool byg(edge x,edge y){

	return x.g<y.g;

}

bool bys(edge x,edge y){

	return x.s<y.s;

}

void insert(edge x){

	

	for(int i=tot;i>=0;i--){

		if(i==0||a[i].s<x.s) {

			a[i+1]=x;

			++tot;

			return ;

		}

		else a[i+1]=a[i];

	}

}

int main(){

	n=getint(); m=getint(); G=getint(); S=getint();

	for(int i=1;i<=m;i++) {

		e[i].x=getint(); e[i].y=getint(); e[i].g=getint(); e[i].s=getint();

	}

	sort(e+1,e+1+m,byg);

	ll ans=(1ll<<62);

	for(int i=1;i<=m;i++){

		insert(e[i]);

//		for(int j=1;j<=tot;j++)cout<<a[j].s<<" ";

//		cout<<endl;

		for(int j=1;j<=n;j++)pre[j]=j;

		int cnt=0;

		for(int j=1;j<=tot;j++){

			if(cnt==n-1) break;

			int x=find(a[j].x), y=find(a[j].y);

			if(x!=y){

				a[++cnt]=a[j]; pre[x]=y;

			}

		}

		tot=cnt;

		if(tot==n-1){

			ans=min(ans,ll(G)*e[i].g+ll(S)*a[tot].s);

		}

	}

	if(ans==(1ll<<62))printf("-1\n");

	else printf("%I64d\n",ans);

	return 0;

}