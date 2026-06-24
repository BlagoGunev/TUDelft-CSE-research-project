#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdlib>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rep0(i,a,b) rep(i,a,b-1)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define per0(i,a,b) per(i,a,b+1)
#define N 200010
#define inf 0x3f3f3f3f
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int n,a[N],dis[N];

int main(){
	n=read();
	rep(i,1,n) a[i]=read();
	memset(dis,0x3f,sizeof(dis));
	int pre=-inf;
	rep(i,1,n){
		if(a[i]==0) pre=i;
		dis[i]=min(dis[i],i-pre);
	}
	pre=inf;
	per(i,n,1){
		if(a[i]==0) pre=i;
		dis[i]=min(dis[i],pre-i);
	}
	rep(i,1,n) printf("%d ",dis[i]);
	return 0;
}