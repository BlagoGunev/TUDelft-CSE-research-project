#include <bits/stdc++.h>
/*
    Author: YZB
    Problem:
    Status:
*/
#pragma GCC optimize(2,3,"Ofast","inline","unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define i128 __int128
//#define FILE
using namespace std;
int n,m,k;
const int inf=1e18;
i128 a[5005];
int bk[5005];
i128 b[5005];
int flg[5005],ans[5005];
inline i128 maxx(i128 x,i128 y){
	return x<y?y:x; 
}
void solve(){
	cin>>n>>m>>k;
	int sm=0;
	for(int i=1;i<=n;i++)cin>>bk[i],sm+=bk[i];
	for(int i=1;i<=n;i++)bk[i]*=n,a[i]=bk[i];
    for(int i=1;i<=m;i++)ans[i]=inf;
	k*=n;
	for(int t=0;t<=n*m;t++){
		int xx=k/n*t+sm;
		i128 ret=0;
		for(int i=1;i<=n;i++)a[i]=bk[i],ret+=(i128)(a[i]-xx)*(a[i]-xx),flg[i]=0;
		for(int i=1;i<=m;i++){
			i128 tsm=0,mians=(i128)inf*inf,tmp,mxpre=0,mxid=0;
			int typ=1,pos1=0,pos2=0;
			for(int j=1;j<=n;j++){
				tmp=(i128)k*((a[j]-xx)*2+k);
				tsm+=tmp;
				if(tsm-mxpre<mians){
					pos1=mxid+1,pos2=j;
					mians=tsm-mxpre;
				}
				if(tsm>mxpre){
					mxpre=tsm;
					mxid=j;
				}
			}
			for(int j=1;j<=n;j++)b[j]=b[j-1]-(i128)k*((a[j]-xx)*2-k);
			tsm=0,mxpre=0,mxid=0;
			for(int j=1;j<=n;j++){
				if(!flg[j])continue;
				int k=j;
				mxpre=b[j-1],mxid=j-1;
				while(k<=n&&flg[k]){
					if(b[k]-mxpre<mians){
						pos1=mxid+1,pos2=k;
						typ=2,mians=b[k]-mxpre;
					}
					if(b[k]>mxpre)mxpre=b[k],mxid=k;
					k++;
				}
				k--;
				j=k;
			}
			ret+=mians;
			for(int j=pos1;j<=pos2;j++){
				if(typ==1)flg[j]++,a[j]+=k;
				else flg[j]--,a[j]-=k;
			}
			ans[i]=min(ans[i],(int)(ret/n));
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
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
/*
asdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirth
asdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirth
asdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirth
asdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirth
asdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirth
asdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirthasdasdeogirth
*/