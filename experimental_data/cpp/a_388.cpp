#include<stdio.h>

#include<string.h>

#include<algorithm>

using namespace std;

int vis[150];

int a[150];

int main()

{

    int n;

    while(~scanf("%d",&n))

    {

        for(int i=0;i<n;i++)

        {

            scanf("%d",&a[i]);

        }

        int output=0;

        sort(a,a+n);

        memset(vis,0,sizeof(vis));

        for(int i=0;i<n;i++)

        {

            if(vis[i]==1)continue;

            vis[i]=1;

            output++;

            int cnt=1;

            for(int j=i+1;j<n;j++)

            {

                if(vis[j]==1)continue;

                if(a[j]>=cnt)

                {

                    vis[j]=1;

                    cnt++;

                }

            }

        }

        printf("%d\n",output);

    }

}