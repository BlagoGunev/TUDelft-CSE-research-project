#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <cmath>

#define ll long long

#define N 3000010

#define Maxn 3000000

using namespace std;

int read(){

	char cc;

	while(1){cc=getchar();if((cc>='0'&&cc<='9')||cc=='-')break;}

	int sum=0,flag=1;

	cc=='-'?flag=-1:sum=(cc^48);

	while(1){cc=getchar();if(!(cc>='0'&&cc<='9'))break;sum=(sum<<1)+(sum<<3)+(cc^48);}

	return sum*flag;

}

void write(int x){

	if(!x)putchar('0');

	if(x<0){x=-x;putchar('-');}

	int cc[25],cntt=0;

	while(x){cc[++cntt]=x%10;x/=10;}

	for(int i=cntt;i>=1;i--)putchar(cc[i]+'0');

	putchar('\n');

}

ll n,pre[N],inv[N],mod,s0=0,s1=0,s2=0,s3=0,ans;

ll fast(ll x,ll y=mod-2){if(!y)return 1;ll ans=1;while(y){if(y&1)ans=ans*x%mod;x=x*x%mod;y>>=1;}return ans;}

ll zu(ll n,ll m){return pre[n]*inv[m]%mod*inv[n-m]%mod;}

int main(){

	n=read();mod=read();

	pre[0]=1;

	for(ll i=1;i<=Maxn;i++)pre[i]=pre[i-1]*i%mod;

	inv[Maxn]=fast(pre[Maxn]);

	for(ll i=Maxn-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;

	s0=1;

	s1=(2*pre[2*n]-pre[n]-1+mod+mod)%mod;

	for(ll i=0;i<=n;i++)s2=(s2+zu(n,n-i)*zu(n,i)%mod*zu(2*n-i,n)%mod)%mod;

	s2=s2*pre[n]%mod*pre[n]%mod*pre[n]%mod;

	s2=(2*zu(2*n,n)*pre[n]%mod*pre[2*n]%mod-s2+mod)%mod;

	s2=(s2-s1-s0+mod+mod)%mod;

	s3=(pre[3*n]-s0-s1-s2+mod+mod+mod)%mod;

	ans=(1*s1+2*s2+3*s3)%mod;

	write(ans);

	return 0;

}