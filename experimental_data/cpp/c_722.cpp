#include <bits/stdc++.h>
/*#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<cmath>

#include<iostream>

#include<algorithm>

#include<queue>

#include<map>

#define INF 0x7fffffff

#define inf 0x3f3f3f3f

#define ll long long

#define N 100005

#define eps 1e-6

using namespace std;

int ra()

{

    int x=0,f=1; char ch=getchar();

    while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}

    while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}

    return x*f;

}

int tot[N],a[N],b[N],ans[N],mp[N];

bool can[N];

int n,mx,cnt;

int main()

{

	n=ra();

	for (int i=1; i<=n; i++) a[i]=ra();

	for (int i=1; i<=n; i++) b[i]=ra();

	for (int i=n; i>=1; i--)

	{

		ans[i]=mx;

		if (can[b[i]-1] && can[b[i]+1])

		{

			int sum=tot[mp[b[i]-1]]+tot[mp[b[i]+1]]+a[b[i]];

			tot[mp[b[i]-1]]=sum; tot[mp[b[i]+1]]=sum;

			mx=max(mx,sum);

		}

		else

		{

			if (can[b[i]-1])

			{

				int sum=tot[mp[b[i]-1]]+a[b[i]];

				tot[mp[b[i]-1]]=sum;

				can[b[i]]=1;

				mp[b[i]]=mp[b[i]-1];

				mx=max(mx,sum);

			}

			else

			{ 

				if (can[b[i]+1])

				{

					int sum=tot[mp[b[i]+1]]+a[b[i]];

					tot[mp[b[i]+1]]=sum;

					can[b[i]]=1;

					mp[b[i]]=mp[b[i]+1];

					mx=max(mx,sum);

				}

				else

				{

					mp[b[i]]=++cnt;

					can[b[i]]=1;

					tot[cnt]=a[b[i]];

					mx=max(mx,tot[cnt]);

				}

			}

		}

	}

	for (int i=1; i<=n; i++)

		printf("%d\n",ans[i]);

	return 0;

}*/           //不懂,,,,看起来写的也有点像并查集的样子,,orz扒题解把.

/*#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<cmath>

#include<iostream>

#include<algorithm>

#include<queue>

#include<map>

#define INF 0x7fffffff

#define inf 0x3f3f3f3f

#define ll long long

#define N 100005

#define eps 1e-6

using namespace std;

int ra()

{

    int x=0,f=1; char ch=getchar();

    while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}

    while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}

    return x*f;

}

int sum[N],a[N],b[N],fa[N],st[N];

bool can[N];

int n,mx,top;

int find(int x)

{

	return x==fa[x]?x:fa[x]=find(fa[x]);

}

int main()

{

	

	n=ra();

	for (int i=1; i<=n; i++) a[i]=ra();

	for (int i=1; i<=n; i++) b[i]=ra();

	for (int i=1; i<=n; i++) fa[i]=i;

	for (int i=n; i>=1; i--)

	{

		st[++top]=mx;

		int x=b[i],f1=0,f2=0;

		can[x]=1; sum[x]+=a[x];

		if (can[x-1])

		{

			f1=find(x-1); 

			sum[x]+=sum[f1];

			fa[f1]=x;

		}

		if (can[x+1])

		{

			f2=find(x+1);

			sum[x]+=sum[f2];

			fa[f2]=find(x);

		}

		mx=max(mx,sum[x]);

	}

	while (top) printf("%d\n",st[top--]);

	return 0;

} */

#include <iostream>

#include <cstdio>

#include <algorithm>

#include <cstring>

using namespace std;

typedef long long ll;

const int N=1e5+5;

inline int read(){

    char c=getchar();int x=0,f=1;

    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}

    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}

    return x;

}

int n,a[N],p[N],vis[N];

ll sum[N],mx=0,st[N],top=0;

int fa[N];

inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}



int main(){

    n=read();

    for(int i=1;i<=n;i++) a[i]=read(),fa[i]=i;

    for(int i=1;i<=n;i++) p[i]=read();

    for(int i=n;i>=1;i--){

        st[++top]=mx;

        int cur=p[i],f1=0,f2=0;

        vis[cur]=1; sum[cur]+=a[cur];

        if(vis[cur-1]){f1=find(cur-1);sum[cur]+=sum[f1];fa[f1]=cur;}

        if(vis[cur+1]){f2=find(cur+1);sum[cur]+=sum[f2];fa[f2]=find(cur);}

        mx=max(mx,sum[cur]);

    }

    while(top) printf("%lld\n",st[top--]);

}