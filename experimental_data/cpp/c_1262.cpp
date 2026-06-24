#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[2005],ans[2005];
int t;
int a[2005],b[2005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n,k,cnt=0;
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		for(int i=1;i<=k-1;i++)
		{
			ans[i*2-1]='(';
			ans[i*2]=')';
		}
		for(int i=2*k-1;i<=2*k-2+(n/2-k+1);i++)
			ans[i]='(';
		for(int i=2*k-2+(n/2-k+1)+1;i<=n;i++)
			ans[i]=')';
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=ans[i])
			{
				int j=i;
				cnt++;
				while(s[j]!=ans[i])j++;
				a[cnt]=i;
				b[cnt]=j;
				for(int k=i;k<=(i+j)/2;k++)
					{
						char t;
						t=s[k];s[k]=s[j+i-k];s[j+i-k]=t;
					/*	for(int i=1;i<=n;i++)
						cout<<s[i];
						cout<<endl;*/
					}
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)
		printf("%d %d\n",a[i],b[i]);
	}
	return 0;
}