#include<bits/stdc++.h>

#define int long long

#define F(i,l,r) for(int i=l,i##end=(r);i<=i##end;++i)

#define f(i,r,l) for(int i=r,i##beg=(l);i>=i##beg;--i)

using namespace std;

const int N=3005;

int n,k,x,ans,dp[N],b[N],t[N];

vector<int>a[N];

template<typename T>inline void readmain(T &n){T sum=0,x=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-')x=-1;ch=getchar();}while (ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}n=sum*x;}

template<typename T>inline T& read(T &x){readmain(x);return x;}

template<typename T,typename ...Tr>inline void read(T &x,Tr&... r){readmain(x);read(r...);}

template<typename T>inline void write(T x){if (x<0){putchar('-');x=-x;}if (x>9)write(x/10);putchar(x%10+'0');return;}

template<typename T>inline void writesc(T x){write(x);putchar(' ');}

template<typename T>inline void writeln(T x){write(x);putchar('\n');}

inline void work(int l,int r)

{

	if (l==r)

	{

		int s=0;

		F(i,0,min(t[l],k))ans=max(ans,s+dp[k-i]),s+=a[l][i];

		return;

	}

	int mid=(l+r)>>1,dq[N];

	F(i,0,k)dq[i]=dp[i];

	F(i,mid+1,r)f(j,k,t[i])dp[j]=max(dp[j],dp[j-t[i]]+b[i]);

	work(l,mid);

	F(i,0,k)dp[i]=dq[i];

	F(i,l,mid)f(j,k,t[i])dp[j]=max(dp[j],dp[j-t[i]]+b[i]);

	work(mid+1,r);

}

signed main()

{

	read(n,k);

	F(i,1,n)

	{

		read(t[i]);

		F(j,1,t[i])read(x),a[i].push_back(x),b[i]+=x;

	}

	work(1,n);write(ans);

	return 0;

}