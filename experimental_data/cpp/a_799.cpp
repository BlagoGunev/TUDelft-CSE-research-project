// <3 Appy!
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
typedef long long int ll;
typedef vector<long long int> vi;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll n,sum=0,count=0,m,flag=0,ans=0,k,d,t;
    cin>>n>>t>>k>>d;
    if(n - (d/t)*k > k)
    {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}


/* freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 */