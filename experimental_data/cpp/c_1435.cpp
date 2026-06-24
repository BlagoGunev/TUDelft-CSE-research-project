/*
Problem : 
Algorithm : 
Status : 
*/
#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define DEBUG cerr << "Passing Line " << __LINE__<< " in Function [" << __FUNCTION__ << "].\n";
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll llINF = 1e18;
const int MAXN = 1e5 + 5;
const int MAXM = 10;
const int m = 6;

int n;
int a[MAXN],b[MAXN],suf[MAXN];
pii c[MAXN];

int main(){
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    for(int i = 1;i <= m;i++)
        scanf("%d",&a[i]);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&b[i]);
    sort(a + 1,a + 1 + m);
    sort(b + 1,b + 1 + n);
    for(int i = 2;i <= m;i++)
        a[i] -= a[1];
    a[1] = 0;
    for(int i = 2;i <= n;i++)
        b[i] -= b[1];
    b[1] = 0;
    for(int i = 1;i <= n;i++){
        int x = upper_bound(a + 1,a + 1 + m,b[i]) - a - 1;
        c[i].first = b[i] - a[x];
        x = lower_bound(a + 1,a + 1 + m,b[i]) - a;
        if(x == m + 1)
            c[i].second = -INF;
        else
            c[i].second = b[i] - a[x];
    }
    sort(c + 1,c + 1 + n);
    int ans = INF;
    suf[n] = c[n].second;
    for(int i = n - 1;i >= 1;i--)
        suf[i] = min(suf[i + 1],c[i].second);
    for(int i = 1;i <= n;i++)
        ans = min(ans,c[i].first - suf[i + 1]);
    printf("%d\n",ans);
    return 0;
}