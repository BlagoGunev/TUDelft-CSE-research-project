//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <istream>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <string.h>
#include <map>
#include <unordered_map>
using namespace std;
#define  F "/Users/noip2019/Desktop/ZZZZZZZZZZZZCW/CW‘s\ code/CW‘s\ code/datain.in"
#define int long long
int n,m;
int cnt[100300];
int cft[100300];
int M[100030];
inline void put(__int128_t x){
    if(x>9)put(x/10);
    putchar(x%10+'0');
}
signed main(){
    ios::sync_with_stdio(false);
    //freopen(F,"r",stdin);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>M[(i-1)*m+j];
        __int128_t ans =0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                ans+=i*cft[M[(i-1)*m+j]]-cnt[M[(i-1)*m+j]];
            for(int j=1;j<=m;j++)
                cnt[M[(i-1)*m+j]]+=i,cft[M[(i-1)*m+j]]++;
        }
        memset(cnt,0,sizeof(cnt));
        memset(cft,0,sizeof(cft));
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++)
                ans+=j*cft[M[(i-1)*m+j]]-cnt[M[(i-1)*m+j]];
            for(int i=1;i<=n;i++)
                cnt[M[(i-1)*m+j]]+=j,cft[M[(i-1)*m+j]]++;
        }
    put(ans);
    return 0;
}