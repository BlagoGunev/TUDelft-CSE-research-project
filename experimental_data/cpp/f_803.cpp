#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const double pi=acos(-1);
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define Rep(i,u) for(int i=head[u];i;i=Next[i])
#define clr(a) memset(a,0,sizeof a)
#define pb push_back
#define mp make_pair
ld eps=1e-9;
ll pp=1000000007;
ll mo(ll a,ll pp){if(a>=0 && a<pp)return a;a%=pp;if(a<0)a+=pp;return a;}
ll powmod(ll a,ll b,ll pp){ll ans=1;for(;b;b>>=1,a=mo(a*a,pp))if(b&1)ans=mo(ans*a,pp);return ans;}
ll read(){
	ll ans=0;
	char last=' ',ch=getchar();
	while(ch<'0' || ch>'9')last=ch,ch=getchar();
	while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
	if(last=='-')ans=-ans;
	return ans;
}
//head
#define N 110000
int n,a[N],b[N],B[N];
int main(){
	n=read();
	rep(i,1,n)a[read()]++;
	B[0]=1;
	rep(i,1,n)B[i]=B[i-1]*2%pp;
	rep(i,1,100000)
		for(int j=i;j<=100000;j+=i)b[i]+=a[j];
//	rep(i,1,3)printf("%d\n",b[i]);
	rep(i,1,100000)b[i]=(B[b[i]]-1+pp)%pp;
//	rep(i,1,3)printf("%d\n",b[i]);
	per(i,100000,1){
		for(int j=i+i;j<=100000;j+=i){
			b[i]=b[i]-b[j];
			if(b[i]<0)b[i]+=pp;
		}
	}
	cout<<b[1]<<endl;
	return 0;
}