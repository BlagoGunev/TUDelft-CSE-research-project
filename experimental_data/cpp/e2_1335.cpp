#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<#x<<"="<<x<<endl
#define ll long long
#define fr(i,l,r) for(int i=l;i<=r;i++)
#define rf(i,l,r) for(int i=l;i>=r;i--)
#define pb push_back
long long read(){
	long long w=1,q=0;char ch=' ';
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(ch>='0'&&ch<='9')q=q*10+ch-'0',ch=getchar();
	return w*q;
}
const int maxn=9+2e5;
const long long mod1=998244353;
const long long mod2=1000000007;
const long long mod3=1000000009;
int _;
long long qpow(long long m,long long n,long long mod)
{
	long long temp;
	if (n==0) return 1;
	temp=qpow(m,n>>1,mod);
	if (n%2==0) return temp*temp%mod;
		else return m*temp%mod*temp%mod;
}

/***********************************************************************************************************************************************************/

int a[200005];
int sum1[205];
int sum[200005][205];
int maxx[200005];
vector<int> v1[205];
vector<int> v2[205];
int main()
{
	for (scanf("%d",&_);_;_--)
	{
		int n, m, i, j, k, ans = 0;
		scanf("%d", &n);
		for (i = 1; i <= 200; i++)
		{
			v1[i].clear();
			v2[i].clear();
			sum1[i] = 0;
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum1[a[i]]++;
			for (j = 1; j <= 200; j++)
			{
				if (j == a[i])
					sum[i][j] = sum[i - 1][j] + 1;
				else
					sum[i][j] = sum[i - 1][j];
			}
		}
		for (i = 1; i <= 200; i++)
		{
			ans = max(ans, sum1[i]);
		}
		for (i = 1; i <= n; i++)
		{
			v1[a[i]].push_back(i);
		}
		for (i = n; i >= 1; i--)
		{
			v2[a[i]].push_back(i);
		}
		for (i = 1; i <= 200; i++)
		{
			if (sum1[i] == 0)
				continue;
			for (j = 0; j <= sum1[i]; j++)
			{
				if (v1[i][j] >= v2[i][j])
					break;
				for (k = 1; k <= 200; k++)
				{
					if (i == k)
						continue;
					ans = max(ans, (j + 1) * 2 + sum[v2[i][j]][k] - sum[v1[i][j]][k]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}