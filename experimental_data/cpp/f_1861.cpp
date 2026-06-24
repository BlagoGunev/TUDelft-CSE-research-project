// LUOGU_RID: 162773343
// Problem: Four Suits
// URL: https://www.luogu.com.cn/problem/CF1861F
// Memory Limit: 1000 MB
// Time Limit: 6000 ms
// Author: Nityacke
// Time: 2024-06-22 14:15:00

#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e4+5,INF=2e9,U=15;
int sum,n,s[N],SS[N][16],a[N][4],ts[N],b[4];
int mx,pos,sec;
struct Node{
	int p,v1,v2,pre,suf;
	inline bool operator<(Node b){
		if(p!=b.p) return p<b.p;
		return v1<b.v1;
	}
}f[16][N];
inline int count(int x){return __builtin_popcount(x);}
bool fl;
inline bool check(int val,int id){
	int ans=b[0]+b[1]+b[2]+b[3];
	for(int S=1;S<=U;++S){
		int res=s[id]-min(count(S)*val-SS[id][S],ts[id]),Val=count(S)*val;
		for(int k=0;k<4;++k)
			if(!(S>>k&1)) res+=b[k];
		int x=lower_bound(f[S]+1,f[S]+n+1,(Node){Val,0,0,0,0})-f[S];
		res+=(n+1-x)*Val+f[S][x-1].pre+f[S][x].suf,ans=min(ans,res);
	}
	return ans==b[0]+b[1]+b[2]+b[3];
}
inline int solve(int id){
	int ans=0;
	for(int i=0;i<4;++i){
		int val=min(s[id],b[i]);
		ts[id]=s[id],s[id]-=val,b[i]-=val,a[id][i]+=val;
		int l=(pos==id?sec:mx),r=1e6+500,mn=1e6+500;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,id)) mn=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,a[id][i]-mn),s[id]+=val,a[id][i]-=val,b[i]+=val;
	}
	return ans;
}
signed main(){
	// freopen("poker.in","r",stdin);
	// freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		int x=0;
		for(int j=0;j<=3;++j) cin>>a[i][j],SS[i][1<<j]=a[i][j],sum+=a[i][j],s[i]+=a[i][j],x=max(x,a[i][j]);
		for(int j=0;j<4;++j)
			for(int k=0;k<=U;++k) if(k>>j&1) SS[i][k]+=SS[i][k-(1<<j)];
		if(x>=mx) pos=i,sec=mx,mx=x;
		else if(x>=sec) sec=x; 
	}
	for(int i=0;i<=3;++i) cin>>b[i],sum+=b[i];
	sum/=n;
	for(int i=1;i<=n;++i) s[i]=sum-s[i];
	for(int i=1;i<=U;++i){
		for(int j=1;j<=n;++j){
			int res=0;
			for(int k=0;k<4;++k)
				if(i>>k&1) res+=a[j][k];
			f[i][j]={s[j]+res,-res,s[j],s[j],-res};
		}
		sort(f[i]+1,f[i]+n+1);
		for(int j=1;j<=n;++j) f[i][j].pre+=f[i][j-1].pre;
		for(int j=n;j;--j) f[i][j].suf+=f[i][j+1].suf;
	}
	for(int i=1;i<=n;++i) cout<<solve(i)<<" ";
}