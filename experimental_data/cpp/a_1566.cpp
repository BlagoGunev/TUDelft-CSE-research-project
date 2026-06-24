#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define f(n) for(int i=0;i<n;i++)
#define fcu(i,a,b) for(int i=a;i<=b;i++)
#define fm(j) for(auto itr=j.begin();itr!=j.end();itr++)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define setp(i) cout<<fixed<<setprecision(i);
using namespace std;

int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        if(n==1)
        cout<<m<<"\n";
        else{
            ll k = ceil((double)n/2);
            cout<<m/(n-k+1)<<"\n";
        }
	}
    return 0;
}