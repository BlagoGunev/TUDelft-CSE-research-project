#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,ans;
char s[200009],t[400009];
int p[400009];
bool check(int x)
{
	for(i=1;i<=x;i++) t[i]=s[i];
	t[x+1]='#';
	for(i=x+2;i<=n+x+1;i++) t[i]=s[i-x-1];
	int len=n+x+1;j=0;
	for(i=1;i<=len;i++) p[j]=0;
	for(i=2;i<=len;i++)
	{
		while(j>0&&t[i]!=t[j+1]) j=p[j];
		if(t[i]==t[j+1]) j++;
		p[i]=j;
	}
	int cnt=0;
	for(i=x+2;i<=len;i++)
		if(p[i]==x) cnt++,i+=(x-1);
	return cnt>=m;
}
signed main()
{
	int _=1;
	cin>>_;
	while(_--)
	{
		ans=0;
		cin>>n>>m>>m>>s+1;
		int l=1,r=n;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}