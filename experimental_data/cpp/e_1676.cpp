#include <bits/stdc++.h>
#include <iostream>
#include<vector>
#define ll long long
#define ull unsigned long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
#define fo(n) for(ll i=0;i<n;i++)
#define fo0(n) for(ll i=1;i<n;i++)
#define fo1(n) for(ll i=1;i<=n;i++)
#define endl "\n"
#define toup transform(s.begin(), s.end(), s.begin(), ::toupper);
#define tolow transform(s.begin(), s.end(), s.begin(), ::tolower);using namespace std;
#define vbe v.begin(),v.end()
#define vb v.begin()
#define ve v.end()
 using namespace std;


int main()
{
    IOS
    ll t;cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        vector<ll>v(n);
        vector<ll>w(n);
        fo(n)
        {
            cin>>v[i];
            }
        sort(v.rbegin(), v.rend());
        fo(n)
        {
            if(i==0)
            {
                w[i]=v[i];
            }
            else
            {
                w[i]=w[i-1]+v[i];
            }

        }
        while(q--)
        {
            long long x; cin >> x;
            int l = 0, r = n-1, ans = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(w[mid ] >= x) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if(ans==-1)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<ans+1<<endl;
            }
        }


    }
    return 0;
}