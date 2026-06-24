#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn=400005;
pair<int,int> a[maxn];
pair<int,int> b[maxn];
bool vis[maxn];
int book;
priority_queue< pair<int,int> > pq;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i].first);
	for (int i=0;i<n;i++) b[i].second=a[i].first;
	for (int i=0;i<n;i++) a[i].second=i;
	sort(a,a+n);
	for (int i=0;i<n-1;i++)
		if (a[i].first==a[i+1].first) b[a[i].second].first=a[i+1].second;
		else b[a[i].second].first=0x3f3f3f3f;
	b[a[n-1].second].first=0x3f3f3f3f;
	int ans=0;
	for (int i=0;i<n;i++)
	{
		if (!vis[b[i].second] && book<k)
		{
			vis[b[i].second]=true;
			book++;
			ans++;
		}
		else if (!vis[b[i].second] && book>=k)
		{
			ans++;
			pair<int,int> now=pq.top();
			pq.pop();
			vis[now.second]=false;
			vis[b[i].second]=true;
		}
		pq.push(b[i]);
	}
	printf("%d\n",ans);
	return 0;
}