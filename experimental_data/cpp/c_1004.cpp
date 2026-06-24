#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
inline void re(int &x)
{
	x=0;bool flag=false;
	char c=getchar();
	while(c<'0'||c>'9'){
		flag= c=='-';
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	if(flag)x=-x;
	return ;
}
bool book[100010];
bool vis[100010];
int is[100010],f[100010];
int n;
int a[100010];
int main()
{
	re(n);
	for(int i=1;i<=n;i++)
		re(a[i]);
	for(int j=n;j>=1;j--)
		if(!book[a[j]])
		{
			book[a[j]]=1;
			is[j]=1;
		}
	for(int j=n;j>=1;j--)
		f[j]=f[j+1]+is[j];
	long long ans=0;
	for(int i=1;i<=n;i++)
		if(!vis[a[i]]){
			ans+=f[i+1];
			vis[a[i]]=true;
		}
	cout<<ans<<"\n";
	return 0;
}