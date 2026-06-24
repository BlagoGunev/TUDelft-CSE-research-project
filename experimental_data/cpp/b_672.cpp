#include<cstdio>

#include<cstring>

const int MAX=100010;

int n;

char s[MAX];

int vis[30];

int main()

{

    while(scanf("%d%s",&n,s)!=EOF){

        memset(vis,0,sizeof(vis));

        for(int i=0;i<n;i++){

            vis[s[i]-'a']++;

        }

        int cnt=0;

        int res=0;

        for(int i=0;i<26;i++){

            if(vis[i])

                cnt++;

            if(vis[i]>1)

                res=res+vis[i]-1;

        }

        if(res>26-cnt)

            printf("-1\n");

        else

            printf("%d\n",res);

    }

    return 0;

}