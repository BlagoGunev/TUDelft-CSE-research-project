///       ______        __________                    _____   _____        _____
///      ///  \\\      ||__||   \\\    |||     |||  ||     || |||\\\      ///|||
///     ///    \\\     ||__||    \\\   |||_____|||  ||     || ||| \\\    /// |||
///    ///______\\\    ||__||     \\\  |||_____|||  ||     || |||  \\\  ///  |||
///   ///________\\\   ||__||     ///  |||_____|||  ||     || |||   \\\///   |||
///  ///          \\\  ||__||    ///   |||     |||  ||     || |||            |||
/// ///            \\\ ||__||___///    |||     |||  ||_____|| |||            |||

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
using namespace std;
typedef long long ll;
typedef long double ld;
void test_case()
{
    ll n;
    cin>>n;
    map<ll,ll> mp;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        mp[x]++;
    }
    for(auto p:mp)
    {
        if((n-2)%p.first)continue;
        ll d=(n-2)/p.first;
        if(d==p.first && p.second>=2)
        {
            cout<<p.first<<" "<<d<<endl;
            return;
        }
        if(mp.count(d))
        {
            cout<<p.first<<" "<<d<<endl;
            return;
        }
    }
}
int main()
{
    FIO
//  freopen("input.txt","rt",stdin);
//  freopen("output.txt","wt",stdout);
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
        test_case();
    }
}