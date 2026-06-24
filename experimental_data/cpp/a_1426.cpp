#include<bits/stdc++.h>

#define all(x)     (x).begin(),(x).end()

#define allr(x)    x.rbegin(),x.rend()

#define sz(x)      ((int)x.size())

#define AbdElmawla std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef unsigned long long int ull;

typedef long long int ll;

typedef long double ld;

int dx[]= {-1,1,0,0,1,-1,1,-1};

int dy[]= {0,0,1,-1,1,-1,-1,1};

int main()

{

    AbdElmawla

    int t;cin>>t;

    while(t--){

        int n,x;cin>>n>>x;

        if(n<=2)

            cout<<1<<'\n';

        else cout<<1+((n-2+x-1)/x)<<'\n';

    }

}