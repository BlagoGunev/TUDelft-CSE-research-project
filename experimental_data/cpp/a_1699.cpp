#include<bits/stdc++.h>

#define ll long long

#define pb push_back

#define pob pop_back

#define f first

#define s second

#define yes cout<<"YES\n"

#define no cout<<"NO\n"

#define fo(i,a,b) for(ll i=a;i<=b;i++)

#define revfo(i,a,b) for(ll i=a;i>=b;i--)

#define all(s) s.begin(),s.end()

using namespace std;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;

    cin>>t;

    while(t-->0){

        ll n;

        cin>>n;

        if(n&1) cout<<"-1\n";

        else cout<<(n/2)<<" "<<(n/2)<<" "<<0<<"\n";

    }

}