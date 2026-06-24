#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2e5+5;
typedef pair<int,int> P;
typedef long long ll;
int b[maxn];
ll ans[maxn];
vector<ll>a[maxn],sum[maxn];
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main()
{
	int t,n;
	cin>>t>>n;
	while(t--)
	{
		for(int i=1;i<=n;i++)ans[i]=0,a[i].clear(),sum[i].clear();
		for(int i=1;i<=n;i++){
			b[i]=read();
		}
		for(int i=1;i<=n;i++){
			ll c=read();
			a[b[i]].push_back(c); 
		}
		for(int i=1;i<=n;i++){
			sort(a[i].begin(),a[i].end(),[](ll a,ll b){
				return a>b;
			});
		}
		for(int i=1;i<=n;i++){
			if(!a[i].size())continue;
			sum[i].push_back(a[i][0]); 
			for(int j=1;j<a[i].size();j++){
				sum[i].push_back(sum[i][j-1]+a[i][j]); 
			}
		}
//		for(int k=1;k<=n;k++){
//			ll ans=0;
//			for(int i=1;i<=n;i++){
//				int pos=sum[i].size();
//				int e=pos/k*k-1;
//				if(e<0)continue;
//				ans+=sum[i][e];
//			}
//			write(ans);
//			putchar(' ');
//		}
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				int pos=sum[i].size();
				int e=pos/k*k-1;
				if(e<0)break;
				ans[k]+=sum[i][e];
			}
		}
		for(int i=1;i<=n;i++){
			write(ans[i]);
			putchar(' ');
		}
		puts("");		
		if(t)cin>>n;
	}
	return 0;
}