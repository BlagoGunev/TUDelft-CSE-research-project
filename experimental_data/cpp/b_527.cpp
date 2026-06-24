#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;

const int maxn=2e5+10;

int n;

char s[maxn],t[maxn];

int vis[30][30];

int main()

{

    while(~scanf("%d",&n))

    {

        scanf("%s",s+1);

        scanf("%s",t+1);

        int cnt=0;

        memset(vis,0,sizeof(vis));

        for(int i=1;i<=n;i++)

        {

            if(s[i]!=t[i])

            {

                cnt++;

                vis[s[i]-'a'][t[i]-'a']=i;

            }

        }

        if(cnt==1)

        {

            printf("1\n");

            printf("-1 -1\n");

            continue;

        }

        int flag=0;

        int a,b;

        for(int i=0;i<26;i++)

        {

            if(flag)

                break;

            for(int j=i+1;j<26;j++)

            {

                if(vis[i][j]&&vis[j][i])

                {

                    a=vis[i][j];

                    b=vis[j][i];

                    flag=1;

                    break;

                }

            }

        }

        if(flag)

        {

            printf("%d\n",cnt-2);

            printf("%d %d\n",a,b);

        }

        else

        {

            for(int i=0;i<26;i++)

            {

                if(flag)

                    break;

                for(int j=0;j<26;j++)

                {

                    if(flag)

                        break;

                    if(vis[i][j])

                    {

                        a=vis[i][j];

                        for(int k=0;k<26;k++)

                        {

                            if(vis[j][k])

                            {

                                b=vis[j][k];

                                flag=1;

                                break;

                            }

                            if(vis[k][i])

                            {

                                b=vis[k][i];

                                flag=1;

                                break;

                            }

                        }

                    }

                }

            }

            if(flag)

            {

                printf("%d\n",cnt-1);

                printf("%d %d\n",a,b);

            }

            else

            {

                printf("%d\n",cnt);

                printf("-1 -1\n");

            }

        }

    }

    return 0;

}