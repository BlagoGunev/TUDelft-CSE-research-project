#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<iomanip>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
#define FILE "dealing"
#define up(i,j,n) for(int i=(j);i<=n;i++)
#define pii pair<int,int>
#define mem(i,j) memset(i,j,sizeof(i));
#define db double
const int maxn=805000,inf=1000000000000LL;
int read(){
	int x=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int fa[maxn];
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int n,m;
int siz[maxn],ru[maxn];
int main(){
	//freopen("dealing.in","r",stdin);
	//freopen("dealing.out","w",stdout);
	n=read(),m=read();
	up(i,1,n)fa[i]=i;
	up(i,1,m){
		int x=read(),y=read();
		int fx=getfa(x),fy=getfa(y);
		if(fx==fy)siz[fx]++;
		else{
			fa[fx]=fy;
			siz[fy]+=siz[fx]+1;
			siz[fx]=0;
		}
	}
	up(i,1,n){
		getfa(i);
		ru[fa[i]]++;
	}
	//up(i,1,n)printf("%d %d\n",ru[i],siz[i]);
	up(i,1,n){
		if((ll)((db)ru[i]*(ru[i]-1)/2+0.1)!=siz[i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}