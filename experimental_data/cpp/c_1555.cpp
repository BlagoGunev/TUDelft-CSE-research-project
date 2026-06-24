#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
void read(){}
template<typename _Tp,typename... _Tps>
void read(_Tp &x,_Tps &...Ar){
	x=0;char c=getchar();bool flag=0;
	while(c<'0'||c>'9')flag|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	if(flag)x=-x;
	read(Ar...);
}
const int N=1e5+10;
int n,a[3][N],suf[N],pre[N];
int get(){
	int i,j,ans=0x3f3f3f3f;
	for(read(n),i=1;i<=2;i++)for(j=1;j<=n;j++)read(a[i][j]);
	for(pre[1]=a[2][1],i=2;i<=n;i++)pre[i]=pre[i-1]+a[2][i];
	for(suf[n]=a[1][n],i=n-1;i>=1;i--)suf[i]=suf[i+1]+a[1][i];
	for(i=1;i<=n;i++)ans=min(ans,max(suf[i+1],pre[i-1]));
	for(i=1;i<=n;i++)suf[i]=pre[i]=0;
	return printf("%d\n",ans),0;
}
int main(){
	int T;read(T);while(T--)get();
	return 0;
}