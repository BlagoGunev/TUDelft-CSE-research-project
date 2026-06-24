#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
int a[300];
int main()
{
	//ios::sync_with_stdio(false);
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		int n;
		scanf("%d",&n);
		
		int bz,las;
		int ff=0 ,fff=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]!=i+1) ff=1;
			if(a[i]!=n-i) fff=1;
			if(a[i]==1) bz=i;
			if(a[i]==n) las=i;
		}
		int f=1;
		if(fabs(las-bz)==n-1)
		{
			if((ff==0||fff==0))
		{
			printf("YES\n");
			continue;
		}else 
		{
			printf("NO\n");
			continue;
		}
		}
		
		if(fabs(las-bz)!=1) f=0;
		if(f) 
		{ 
		
		    int fr=1;
		    if(las-bz==1)
		    {int bas=0;
			for(int i=bz;;i--)
			{
				if(i==-1&&bas==0) bas=n;
				if(a[i+bas]!=fr++) 
				{
					f=0;
					break;
				}
				if(fr==n+1) break;
				
			}
			
		    	
			}
			if(f==1&&bz-las==1)
		    { fr=1;
		    int bas=0;
			for(int i=bz;;i++)
			{
				if(bas==0&&i==n)
				{
					bas=n;
				}
				if(a[i-bas]!=fr++) 
				{
					f=0;
					break;
				}
				if(fr==n+1) break;
			}
			
			}
		}
		if(f==0) printf("NO\n");
		else printf("YES\n");
	}
	//system("PAUSE");
}