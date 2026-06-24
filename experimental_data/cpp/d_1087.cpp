#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int deg[100005];

inline int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}

int main()
{
    int n=read(), s=read();
    for (int i=1; i<n; i++)
    {
    	int u=read(), v=read();
    	deg[u]++; deg[v]++;
	}
	int res=0;
	for (int i=1; i<=n; i++) if (deg[i]==1) res++;
	double ans=1.0*s/res*2;
	printf("%.10f\n",ans);
    return 0;
}