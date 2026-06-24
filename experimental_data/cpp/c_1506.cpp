#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char a[50],b[50];
int ans; 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		ans=-1;
		int lena=strlen(a);
		int lenb=strlen(b);
		int len=lena+lenb;
		for(int i=0;i<lena;i++)
		{
			for(int j=0;j<lenb;j++)
			{
				int x=i;
				int y=j;
				int cnt=0;
				while(a[x]==b[y]&&x<lena&&y<lenb)
				{
					x++;
					y++;
					cnt++;
				}
				ans=max(cnt,ans);
			}
		}
		cout<<len-ans*2<<endl;
	}
	return 0;
}