#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>

using namespace std;

#define next roman_kaban

int a[500];
vector<pair<int,int> > b[500];

int  s[500];
int  res[500];
int dp[500][500];
int c[500][500];
int d[500][500];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,v;
    scanf("%d%d",&n,&v);
    for(int i=0;i<n;i++)
    scanf("%d",a+i);
    int m;
    scanf("%d",&m);
    for(int mm=0;mm<m;mm++)
    {
        int l,r,f;
        scanf("%d%d%d",&l,&r,&f);
        for(int i=l;i<=r;i++)
            b[i].push_back(make_pair(f,mm));
    }
    s[0]= 0;
    dp[0][0] = 1;
    int k = 1;
    for(int i=1;i<=n;i++)
    {
        sort(b[i].begin(),b[i].end());
        //for(int j=1;j<b.size();j++)
        //    b[j].first+=b[j-1].first;

        for(int j=0;j<k;j++)
        {
            //cerr << "("<<s[j]<<';'<<dp[i-1][s[j]]<<") ";
            int l = s[j];
            int r = a[i-1];
            //int res = s[j].second;
            l-=v;
            if(l<0) {r+=l; l =0; }
            if(r<0) continue;
            if(dp[i][r]<dp[i-1][s[j]])
            {
                dp[i][r] = dp[i-1][s[j]];
                c[i][r] = 0;
                d[i][r] = s[j];
            }
            for(int z = 0;z<b[i].size();z++)
            {
                l-=b[i][z].first;
                if(l<0) {r+=l; l =0; }
                if(r<0) break;
                if(dp[i][r]<dp[i-1][s[j]]+z+1)
                {
                    dp[i][r] = dp[i-1][s[j]]+z+1;
                    c[i][r] = z+1;
                    d[i][r] = s[j];
                }
            }
        }
        //cerr<<endl;
        k =0;
        for(int j=0;j<500;j++)
        {
            while(k>0 && dp[i][s[k-1]]<=dp[i][j]) k--;
            if(dp[i][j]) s[k++] = j;
        }
    }
    int r = 0;
    for(int i=0;i<500;i++)
    if(dp[n][i]>dp[n][r]) r = i;
    cout << dp[n][r]-1<<endl;
    int nn = n;
    while(n)
    {
        res[n] = c[n][r];
        r = d[n][r];
        n--;
    }
    for(int i=1;i<=nn;i++)
    {
        printf("%d",res[i]);
        for(int j=0;j<res[i];j++)
            printf(" %d",b[i][j].second+1);
        printf("\n");
    }
    return 0;
}
/*
30000000003312
0
*/