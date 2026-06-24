#include<cstdio>
#define MAXN 110
bool vis[MAXN];
int ans[MAXN];
int cnt;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
	 		int x;
       		scanf("%d",&x);
   		 	if(!vis[x])
       		{
        	    vis[x]=1;
         		   cnt++;
        	    ans[cnt]=i;
     	  }
    }
    if(cnt>=k)
    {
		  printf("YES\n%d",ans[1]);
		  for(int i=2;i<=k;i++)
		  		  printf(" %d",ans[i]);
    }
    else printf("NO\n");
}