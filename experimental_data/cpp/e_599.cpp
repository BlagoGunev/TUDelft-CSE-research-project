#include <bits/stdc++.h>
#include<cstdio>

#include<iostream>

#include<cstring>

using namespace std;

const int N=14;

typedef int64_t LL;

int lg[1<<N];

int mi[N];

void init(){

    int n=13;

    mi[0]=1;

    lg[1]=0;

    for(int i=1;i<n;i++){

        mi[i]=mi[i-1]*2;

        lg[mi[i]]=i;

    }

}

int g[1<<N],p[N][1<<N];

int check(int u,int k1,int k2,int op=-1){

    if(op==1){

        int s1=p[u][k2];

        if(s1&&s1!=mi[u])return 0;

        if(g[k2^mi[k1]]&mi[u])return 0;

        return 1;

    }

    if(g[k1]&k2)return 0;

    int s1=0;

    while(k1){

        int x=lg[k1&-k1];

        s1|=p[x][k2];

        k1-=k1&-k1;

    }

    if(s1&&s1!=mi[u])return 0;

    return 1;

}



LL dp[N][1<<N];

LL sum[N][1<<N];



int main(){

    #ifdef DouBi

    freopen("in.cpp","r",stdin);

    //freopen("out.cpp","w",stdout);

    #endif // DouBi

    int n,m,q;

    init();

    while(scanf("%d%d%d",&n,&m,&q)!=EOF){

        memset(g,0,sizeof(g));

        for(int i=0;i<m;i++){

            int a,b;scanf("%d%d",&a,&b);a--;b--;

            g[mi[a]]|=mi[b];

            g[mi[b]]|=mi[a];

        }

        memset(p,0,sizeof(p));

        int flag=0;

        for(int i=0;i<n;i++){

            p[i][mi[i]]=mi[i];

        }

        for(int i=0;i<q;i++){

            int a,b,c;scanf("%d%d%d",&a,&b,&c);a--;b--;c--;

            if(p[a][mi[b]]&&p[a][mi[b]]!=mi[c])flag=1;

            p[a][mi[b]]=p[b][mi[a]]=mi[c];

        }

        if(flag){

            printf("0\n");continue;

        }

        int ed=1<<n;

        for(int i=1;i<ed;i++){

            int j=i&-i;

            if(j==i)continue;

            g[i]=g[i-j]|g[j];

        }

        for(int i=0;i<n;i++){

            for(int j=1;j<ed;j++){

                int x=j&-j;

                if(x==j)continue;

                p[i][j]=p[i][j-x]|p[i][x];

            }

        }



        memset(dp,0,sizeof(dp));

        memset(sum,0,sizeof(sum));

        for(int i=0;i<n;i++){

            dp[i][mi[i]]=1;

            sum[i][mi[i]]=1;

        }

        for(int i=1;i<ed;i++){

            for(int j=i;j;j-=j&-j){

                int u=lg[j&-j];

                int u1=lg[(i^mi[u])&-(i^mi[u])];

                if(u1==0)continue;

                int i1=(i^mi[u])^mi[u1];

                if(i1==0){

                    dp[u][i]+=sum[u][i];continue;

                }

                else {

                    for(int k=i1;;k=(k-1)&i1){

                        if(check(u,k|mi[u1],i1^k)){

                            dp[u][i]+=sum[u][k|mi[u]|mi[u1]]*dp[u][(i1^k)|mi[u]];

                        }

                        if(!k)break;

                    }

                }

                //printf("%d %d %d %lld\n",u,u1,i,dp[u][i]);

            }

            for(int j=i;j;j-=j&-j){

                int u=lg[j&-j];

                for(int k=ed-1-i;k;k-=k&-k){

                    int v=lg[k&-k];

                    if(check(v,u,i,1)){

                        sum[v][i|mi[v]]+=dp[u][i];

                    }

                }

                //printf("sum %d %d %lld\n",u,i,sum[u][i]);

            }

        }

        printf("%lld\n",dp[0][ed-1]);

    }

    return 0;

}