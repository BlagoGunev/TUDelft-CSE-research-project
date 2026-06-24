/*
    Author: YZB
    Problem:
    Status:
*/
#include <bits/stdc++.h>
#define int long long
#define lowbit(i) (i&(-i))
//#define FILE
using namespace std;
int a[200005],b[200005],sm[200005][20],id[200005];
const int mod=998244353;
struct mat{
	int ma[20][20];
}ga,st;
int siz;
mat operator *(mat x,mat y){
	mat z;
	memset(z.ma,0,sizeof z.ma);
	for(int i=0;i<=siz;i++){
		for(int k=0;k<=siz;k++)
		for(int j=0;j<=siz;j++){
			z.ma[i][j]=(z.ma[i][j]+x.ma[i][k]*y.ma[k][j]%mod)%mod;
		}
	}
	return z;
}
mat qkp(mat x,int k){
	mat ret;
	memset(ret.ma,0,sizeof ret.ma);
	for(int i=0;i<=siz;i++)ret.ma[i][i]=1;
	while(k){
		if(k&1)ret=ret*x;
		x=x*x;
		k>>=1;
	}
	return ret;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],id[i]=__lg(lowbit(i));
	for(int i=1;i<=n;i+=2)b[i]=a[i];
	siz=__lg(n);
	memset(ga.ma,0,sizeof ga.ma);
	for(int i=0;i<=siz;i++)for(int j=i;j<=siz;j++)ga.ma[i][j]=1;
	ga=qkp(ga,m);
	for(int i=2;i<=n;i+=2){
		int x,l=i-lowbit(i)+1,s=0,c;
		for(int jj,j=l;j<i;j++){
			c=0,jj=j;
			for(int k=id[j]+1;k<=id[i];k++){
				x=(((jj-1)>>k)+1)<<k;
				if(lowbit(x)==(1ll<<k)){
					c++;
					jj=x;
				}
			}
//			cout<<i<<' '<<j<<' '<<c<<' '<<ga.ma[0][c]<<'\n';
			s=(s+b[j]*ga.ma[0][c])%mod;
		}
		b[i]=(a[i]-s+mod)%mod;
	}
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	cout<<'\n';
}
signed main(){
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--)solve();
	return 0;
}