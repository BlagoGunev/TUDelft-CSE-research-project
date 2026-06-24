#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define int long long

#define elif else if

#define ALL(x) x.begin(),x.end()

#define lowbit(x) (x&(-x))

using namespace std;

void fileio(const string &s)

{

	freopen((s+".in").c_str(),"r",stdin);

	freopen((s+".out").c_str(),"w",stdout);

}

const int INF=4e18;

int read()

{

	int x=0;

	bool flag=1;

	char c=getchar();

	while(c<'0'||c>'9')

	{

		if(c=='-')

			flag=0;

		c=getchar();

	}

	while(c>='0'&&c<='9')

	{

		x=(x<<1)+(x<<3)+c-'0';

		c=getchar();

	}

	return (flag?x:~(x-1));

}

const int mod=998244353;

int n,k,ans,a[3010],p1[210],p2[210],p3[210],p4[210],inv[3010],C[60][60];//x-1,k-x+1,x,k-x

void solve(int id)

{

	for(int i=1;i<=n;i++)

	{

		p1[i]=p1[i-1]*(id-1)%mod;

		p2[i]=p2[i-1]*(k-id+1)%mod;

		p3[i]=p3[i-1]*id%mod;

		p4[i]=p4[i-1]*(k-id)%mod;

	}

	int res=0;

	for(int i=1;i<=n;i++)

		for(int l=0;l<i;l++)

			for(int j=l+1;j<=n-i;j++)

				(res+=((p1[l]*p2[i-l-1]%mod)*(p4[j]*p3[n-i-j]%mod)%mod*(C[i-1][l]*C[n-i][j]%mod)%mod))%=mod;

	a[id]=(a[id-1]+res*id%mod)%mod;

}

signed main()

{

	n=read();

	k=read();

	p1[0]=p2[0]=p3[0]=p4[0]=inv[0]=inv[1]=1;

	C[0][0]=1;

	for(int i=2;i<=200;i++)

		inv[i]=mod-mod/i*inv[mod%i]%mod;

	for(int i=1;i<=n;i++)

	{

		C[i][0]=1;

		for(int l=1;l<=n;l++)

			C[i][l]=(C[i-1][l]+C[i-1][l-1])%mod;

	}

	for(int i=1;i<=min(k,200ll);i++)

		solve(i);

	if(k<=200)

	{

		cout<<a[k]<<'\n';

		return 0;

	}

	for(int i=1;i<=200;i++)

	{

		for(int l=1;l<i;l++)

			(a[i]*=((k-l)*inv[i-l]%mod))%=mod;

		for(int l=i+1;l<=200;l++)

			(a[i]*=((k-l)*inv[l-i]%mod))%=mod;

		if((200-i)&1)

			(ans+=mod-a[i])%=mod;

		else

			(ans+=a[i])%=mod;

	}

	cout<<ans;

	return 0;

}