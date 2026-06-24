#include<bits/stdc++.h>

#define int long long

#define pb push_back

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);

using namespace std;



void sol()

{

    int n, c=0; cin>>n;

    map<pair<int, int>, int> m; 

    for (int i = 0; i < n; i++)

    {

        int p, q, r, s;

        cin>>p>>q>>r>>s;

        int x = (s-q), y = (r-p);

        int z = __gcd(abs(x), abs(y));

        if(x==0 || y==0) z=max(abs(x), abs(y));  

        m[{x/z, y/z}]++;

    }

    for(auto it = m.begin(); it!=m.end(); it++)

    {

        // auto t = *it.first;

        c+=(*it).second*m[{-(*it).first.first, -(*it).first.second}];

    }

    cout<<c/2<<'\n';

    

    

}



signed main()

{

    fastio()



    int t;

    cin>>t;

    // t=1;

    while(t--) sol();

    return 0;

}