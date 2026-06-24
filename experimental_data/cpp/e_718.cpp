#include<queue>

#include<cmath>

#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<iostream>

#include<algorithm>

#define ll long long

#define inf 1000000000

#define N 100005

using namespace std;

int read()

{

    int x=0,f=1;char ch=getchar();

    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}

    return x*f;

}

int n,ans;

ll cnt;

char a[N];

int dis[N*10][8],d[8][8],c[8][256],msk[N];

int q[N];

void bfs(int x)

{

    int head=0,tail=0;

    for(int i=1;i<=n;i++)

        if(a[i]=='a'+x)

            dis[i][x]=0,q[tail++]=i;

    dis[x+n+1][x]=0;

    while(head!=tail)

    {

        int now=q[head];head++;

        if(now<=n)

            for(int i=-1;i<=1;i+=2)

            {

                int t=now+i;

                if(dis[t][x]>100&&1<=t&&t<=n)

                {

                    dis[t][x]=dis[now][x]+1,q[tail++]=t;

                    int c=a[t]-'a'+n+1;

                    if(dis[c][x]>100)

                        dis[c][x]=dis[now][x]+1,q[tail++]=c;

                }

            }

        else

            for(int i=1;i<=n;i++)

                if(a[i]=='a'+now-n-1&&dis[i][x]>100)

                    dis[i][x]=dis[now][x]+1,q[tail++]=i;

    }

}

int main()

{

    n=read();

    scanf("%s",a+1);

    memset(dis,127/3,sizeof(dis));

    for(int i=0;i<8;i++)

    {

        bfs(i);

        for(int j=0;j<8;j++)d[j][i]=dis[j+n+1][i];

    }

    for(int i=1;i<=n;i++)

        for(int j=0;j<8;j++)

            msk[i]|=(dis[i][j]>d[a[i]-'a'][j])<<j;

    for(int i=1;i<=n;i++)

    {

        for(int j=max(i-15,1);j<i;j++)

        {

            int tmp=i-j;

            for(int k=0;k<8;k++)

                tmp=min(tmp,dis[j][k]+dis[i][k]+1);

            if(tmp>ans)ans=tmp,cnt=0;

            if(tmp==ans)cnt++;

        }

        int t=i-16;

        if(t>=1)c[a[t]-'a'][msk[t]]++;

        for(int j=0;j<8;j++)

            for(int k=0;k<256;k++)

                if(c[j][k])

                {

                    int tmp=100;

                    for(int p=0;p<8;p++)

                        tmp=min(tmp,d[j][p]+1+dis[i][p]+(k&(1<<p)));

                    if(tmp>ans)ans=tmp,cnt=0;

                    if(tmp==ans)cnt+=c[j][k];

                }

    }

    cout<<ans<<' '<<cnt<<endl;

    return 0;

}