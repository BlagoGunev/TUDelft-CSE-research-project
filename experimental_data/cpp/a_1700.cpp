#include<bits/stdc++.h>

#define ll long long

#define pb push_back

#define sort(arr) sort(arr,arr+sizeof(arr)/sizeof(ll))

#define input(arr) for(int i=1;i<=sizeof(arr)/sizeof(ll);i++) cin>>arr[i];

#define forn(i,n) for(int i=0;i<int(n);i++)

using namespace std;

void solve()

{

ll n,m;

cin>>n>>m;

ll x=(m*(m-1))/2+(m*n*(n+1))/2;

cout<<x<<endl;

}

int main()

{ ios_base::sync_with_stdio(false);cin.tie(NULL);

    int t;cin>>t;

    while(t--)

    {solve();

    }

return 0;

}