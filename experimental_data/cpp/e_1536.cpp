#include<bits/stdc++.h>

const int N=2013;

const int mod=1000000007;

using namespace std;

typedef long long ll;

void solve(){

    int n,m;cin>>n>>m;

    int cnt=0;

    for(int i=1;i<=n;i++){

        string s;cin>>s;s=' '+s;

        for(int j=1;j<=m;j++)cnt+=(s[j]!='0');

    }

    int ans=1;

    for(int i=1;i<=cnt;i++){

        ans*=2;ans%=mod;

    }if(cnt==n*m)ans--;cout<<ans<<'\n';

}

int main(){

    cin.tie(0);ios::sync_with_stdio(0);cout.tie(0);

    int T;cin>>T;

    while(T--)solve();

}