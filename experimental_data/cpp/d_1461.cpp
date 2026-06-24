#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long int

int T,n,q,cnt;
int arr[100000];
ll sum[100000],x;
ll ans[300000];
void solve(int l,int r)
{
	x=sum[r];
	if(l>0) x-=sum[l-1];
	ans[cnt++]=x;
	if(arr[l]==arr[r]) return;
	int d=(arr[l]+arr[r])>>1,pos=l;
	while(pos<r&&arr[pos+1]<=d) pos++;
	solve(l,pos); solve(pos+1,r);
	return;
}

int main(void)
{
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+n);
		sum[0]=arr[0];
		for(int i=1;i<n;i++)
			sum[i]=sum[i-1]+arr[i];
		cnt=0; solve(0,n-1);
		sort(ans,ans+cnt);
		while(q--){
			scanf("%lld",&x);
			int l=0,r=cnt-1,mid;
			while(l<r){
				mid=(l+r)>>1;
				if(ans[mid]>=x) r=mid;
				else l=mid+1;
			}
			if(ans[l]==x) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
/*
*/