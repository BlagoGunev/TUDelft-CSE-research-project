#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long llu; 
#define MOD 1000000007
#define print(A,n) for(ll i=0;i<n;++i)cout<<A[i].ss<<' ';cout<<endl;
#define _accept(X,N) for(ll i=0;i<N;++i)cin>>X[i];
#define forzer(i,n) for(ll i=0;i<n;++i)
#define rep(i,s,e) for(ll i=s;i<e;++i)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int main()
{
	ll n,x,y;
	cin>>n;
	x=n/2+1,y=1;
	ll min=MOD,div=-1;
    for(ll i=1;i<=n;++i)
    {
        if(ceil(n/(double)i)+i<=min)
        {
            min=ceil(n/(double)i)+i;
            div=i;
        }
        else
            break;
    }
    ll nper=ceil(n/(double)div);
    for(ll i=1;i<=div;++i)
    {
        for(ll j=0;j<nper;++j)
        {
            if((div-i)*nper+j+1<=n)
                cout<<(div-i)*nper+j+1<<' ';
        }
    }
	return 0;
}