// link:
// [prajwal1721]
// g++ -Wall -Wextra -Wshadow filename.cpp
/*comments:
*/



#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b))
#define bits(x) __builtin_popcountll(x)
#define vi              vector<int>
#define vl              vector<ll>
#define all(v)          v.begin(),v.end()
#define UNIQUE(X)       (X).erase(unique(all(X)),(X).end())



typedef long long int ll;
void solve()
{
    ll n,t;cin>>n;
    vl v;
    for(int i=0;i<n;i++)
        {cin>>t;v.push_back(t);}
    ll a=0,b=0,m=0,st=0,f=0,ed=n-1,cur=0;
    while(st<=ed)
    {
        m++;
        ll s=0;
        if(f==0)
        {
            while (st<=ed && cur>=s )
            {
                // if(s==-1)s=0;
                s+=v[st];st++;
            } 
            f=1;
            a+=s;
            cur=s;
        }  
        else 
        {
            while (st<=ed && cur>=s )
            {
                // if(s==-1)s=0;
                s+=v[ed];ed--;
            } 
            f=0;
            b+=s;
            cur=s;
        }
        // cout<<m<<"=="<<st<<" "<<ed<<"\n";
    }
    cout<<m<<" "<<a<<" "<<b<<"\n";
}


int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    // cout<<t<<"Hi test complete\n";
    while(t--)
        {
            solve();
        }


    return 0;
}