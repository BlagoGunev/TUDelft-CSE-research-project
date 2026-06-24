#pragma GCC optimize(3)

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1000013;



void solve(){int n;cin>>n;

    string s;cin>>s;

    for(int i=0;i+1<n;i++)if(s[i]!=s[i+1]){

            cout<<i+1<<' '<<i+2<<'\n';return;

    }cout<<-1<<' '<<-1<<'\n';

}

int main(){

    cin.tie(0);ios::sync_with_stdio(0);cout.tie(0);

    int T=1;cin>>T;

    while(T--)solve();

}