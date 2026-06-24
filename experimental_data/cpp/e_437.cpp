#define _CRT_SECURE_NO_DEPRECATE

#include<iostream>

#include<cstdio>

#include<algorithm>

#include<string>

#include<string.h>

#include<cmath>

#include<queue>

#include<map>

#include<set>

#include<stack>

#include<bits/stdc++.h>

using namespace std;

const int inf = 1<<28;

const int mod = (int)1e9 + 7;

const double eps = 1e-8;

typedef long long ll;

int n,m,k;



struct node

{

    double x,y;

    node operator - (node b)

    {

        node tmp;

        tmp.x = x - b.x;

        tmp.y = y - b.y;

        return tmp;

    }

}p[210];



double crs(node a,node b)

{

    return a.x*b.y - b.x*a.y;

}



ll dp[210][210];



ll dfs(int l,int r)

{

    if(dp[l][r] != -1) return dp[l][r];

    if(r - l == 1) return dp[l][r] = 1;

    ll &sum = dp[l][r];

    sum = 0;

    for(int i = l+1; i < r; i++){

        if(crs(p[i]-p[l],p[r]-p[i]) > 0){

            sum = (sum + dfs(l,i) * dfs(i,r) % mod) % mod;

        }

    }

    return dp[l][r];

}







int main()

{

#ifndef ONLINE_JUDGE

    freopen("in.txt","r",stdin);

    //freopen("out.txt","w",stdout);

#endif // ONLINE_JUDGE

    cin>>n;

    for(int i=0;i<n;i++){

        scanf("%lf%lf",&p[i].x, &p[i].y);

    }

    double sum = 0;

    for(int i=1;i<n-1;i++){

        sum += crs(p[i]-p[0],p[i+1]-p[0]);

    }

    if(sum < 0) reverse(p,p+n);

    memset(dp,-1,sizeof dp);

    cout<<dfs(0,n-1)<<endl;

    return 0;

}