#include<bits/stdc++.h>

#define ll long long

#define input(v,n) for(ll inp=0;inp<n;inp++){cin>>v[inp];}

#define vll vector<ll>

#define sz(s) s.size()

#define srt(a)  sort(a.begin(),a.end())

using namespace std;



void solve()

{

    int n;

    cin>>n;

    int q;

    cin>>q;

    vector<int> v(n);

    for(int i=0;i<n;i++)

        cin>>v[i];

    while(q--){

        int x;

        cin>>x;

        int index=find(v.begin(),v.end(),x)-v.begin();

        cout<<index+1<<" ";

        rotate(v.begin(),v.begin()+index,v.begin()+index+1);

    }

}

int main(){

    ios_base::sync_with_stdio(0); 

    cin.tie(0);



    ll t=1;

    // cin>>t;

    while(t--){



        solve();

    }

    return 0;

}