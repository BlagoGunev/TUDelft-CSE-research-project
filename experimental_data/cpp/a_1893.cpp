#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <stack>
#include <queue>

using namespace std;

#define itn int
#define ll long long
#define N 100005
#define oo 1000000000000000000ll
#define mod 1000000007
#define p_b push_back
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'



int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
   {
        ll n,m;
        cin>>n>>m;
        ll a[n];
        for(itn i=0; i<n; i++)
        {
            cin>>a[i];
        }
        ll p=n-1;
        ll x=0;
        for(int i=0; i<min(m,n); i++)
        {
            if(a[p]>n)
            {
                x++;
                break;
            }
            else p+=n-a[p];
            if(p<0)p+=n;
            else if(p>=n)p-=n;

        }
        if(x!=0)cout<<"No";
        else cout<<"Yes";
        cout<<endl;


//       cout<<endl<<endl;

   }


}
//Om