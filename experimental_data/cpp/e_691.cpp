#include <bits/stdc++.h>
#include <stdio.h>

#include<iostream>

using namespace std;



typedef long long ll;

const int maxn = 110;

const int mod = 1e9+7;

const ll MOD = 8ll*mod*mod;



ll a[maxn];

int g[maxn][maxn], t[maxn][maxn], G[maxn][maxn];

int n;

ll k;



void read_input()

{

    scanf("%d %lld",&n,&k);

    for(int i=0; i<n; i++) scanf("%lld",a+i);

}



void init_g()

{

    int cnt;

    ll val;

    for(int i=0; i<n; i++)

        for(int j=i; j<n; j++)

        {

            G[i][i]=1;

            cnt = 0;

            val = a[i]^a[j];

            for(; val; val>>=1) cnt += val&1;

            g[i][j] = g[j][i] = cnt%3==0;

        }

}





void mul(int a[maxn][maxn],int b[maxn][maxn])

{

    ll tmp;

    for(int i=0; i<n; i++)

        for(int j=0; j<n; j++)

        {

            tmp = 0;

            int *aik = &a[i][0], *bkj = &b[0][j];

            for(int k=0; k<n; aik++, bkj+=maxn, k++)

            {

                tmp += (ll)(*aik)*(ll)(*bkj);

                if(tmp>=MOD) tmp -= MOD;

            }

            t[i][j] = tmp%mod;

        }



    for(int i=0; i<n; i++)

        for(int j=0; j<n; j++)

            a[i][j]=t[i][j];

}







int main()

{

    read_input();

    init_g();

    k--;

    for(; k; k>>=1)

    {

        if(k&1) mul(G,g);

        mul(g,g);

    }

    ll res = 0;

    for(int i=0; i<n; i++)

        for(int j=0; j<n; j++)

            res = (res+G[i][j]);

    printf("%lld",res%mod);

    /*n = 4;

    for(int i=0;i<n;i++)

        for(int j=0;j<n;j++)

            g[i][j]=i*n+j;

    mul(g,g);*/

    return 0;

}