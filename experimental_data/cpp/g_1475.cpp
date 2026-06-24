#include<bits/stdc++.h>

using namespace std;

#define ll long long



int n,a[200010],dp[200010];



void solve() {

    cin>>n;

    vector<int>cnt(200010);

    for(int i=1;i<=n;i++) {

        cin>>a[i];

        cnt[a[i]]++;

    }

    memset(dp,0,sizeof dp);

    for(int i=200000;i>=1;i--) {

        dp[i]=cnt[i];

        for(int k=i+i;k<=200000;k+=i) {

            dp[i]=max(dp[i],dp[k]+cnt[i]);

        }

    }

    int res=1e9;

    for(int i=1;i<=200000;i++) res=min(res,n-dp[i]);

    cout<<res<<'\n';

}

 

int main() {

    ios::sync_with_stdio(0);

    cin.tie(0),cout.tie(0);

    int T=1;

    cin>>T;

    while(T--) solve();

    return 0;

}