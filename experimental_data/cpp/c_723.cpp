#include <iostream>

#include <cstdio>

#include <cmath>

#include <algorithm>

#include <cstring>

using namespace std;

int  a[2005];

int vis[2005];

int vis2[2005];

int main()

{

    int n,m;

    while(scanf("%d %d",&n,&m)!=EOF){

        memset(vis,0,sizeof(vis));

        for(int i=1;i<=n;i++){

            scanf("%d",&a[i]);

            if(a[i]<=m)

                vis[a[i]]++;

        }

        memset(vis2,0,sizeof(vis2));

        int num=n/m;

        int j=1;

        int sum=0;

        for(int i=1;i<=n;i++){

            if(a[i]<=m){

                if(vis2[a[i]]<num){

                    vis2[a[i]]++;

                    continue;

                }

            }

            while(vis[j]>=num) j++;

            if(j>m) break;

            a[i]=j;

            vis[j]++;

            vis2[j]++;

            sum++;

        }

        printf("%d %d\n",num,sum);

        int first=0;

        for(int i=1;i<=n;i++){

            if(first) printf(" ");

            else first++;

            printf("%d",a[i]);

        }

        printf("\n");



    }





    return 0;

}