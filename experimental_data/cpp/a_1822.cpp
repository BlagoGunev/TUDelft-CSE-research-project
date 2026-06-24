//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//signed main()
//{
//	int t;
//	scanf("%lld",&t);
//	while(t--)
//	{
//		int n;
//		scanf("%lld",&n);
//		int ans=(n-1)*(n-2)+5*n;
//		printf("%lld\n",ans);
//	}
//}
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//int a[200010];
//signed main()
//{
//	int t;
//	scanf("%lld",&t);
//	while(t--)
//	{
//		int n;
//		scanf("%lld",&n);
//		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
//		sort(a+1,a+1+n);
//		cout<<max(a[1]*a[2],a[n]*a[n-1])<<endl;
//	}
//}
#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,t;
		scanf("%d%d",&n,&t);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		int mx=0,idx=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]+i-1<=t&&mx<b[i]) 
			{
				idx=i,mx=b[i];
			}
		}
		printf("%d\n",idx);
	}
}