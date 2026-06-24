#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
int main()
{
    ll tst;
    cin>>tst;
    for(ll t=0;t<tst;t++)
    {
        ll n,y;
        cin>>n>>y;
        vector<ll> vec;
        map<ll,ll> um;
        int z=0;
        for(ll i=0;i<n;i++)
        {
            ll k;
            cin>>k;
            vec.push_back(k);
            um[k]++;
            if(um[k]==y)
            {
                z=1;
            }
        }
        if(z==0)
        {
            cout<<n<<'\n';
        }
        else
        {
            cout<<y-1<<'\n';
        }
    }
    return 0;
}