#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define SIZE 1000

#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)

#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

#define digit(c) (c - '0')

#define pb push_back

#define mp make_pair

#define fi first

#define se second

#define LONG_MA 1e12

#define ss scanf

#define pp printf

//#define mod 10e9+7



int main()

{

    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n,k,l,r,sk,sa,a[1005],i;

    cin>>n>>k>>l>>r>>sa>>sk;

    for(i=1;i<=k;i++)a[i]=r;

    for(i=k+1;i<=n;i++)a[i]=l;

    ll p=k*r-sk;

    ll q=sa-sk-l*(n-k);

    ll t=p/k;

    ll d;

    if(p%k!=0)t++;

    if(n!=k)d=q/(n-k);

    if(n!=k && q%(n-k)!=0)d++;

    //cout<<s<<d;

    for(i=1;i<=k;i++){

        if(p-t>0 && a[i]-t>=l){a[i]-=t;p-=t;}

        else {

            a[i]-=p;

            break;

        }

    }

    for(i=k+1;i<=n;i++){

        if(q-d>0 && a[i]+d<=r){a[i]+=d;q-=d;}

        else {

            a[i]+=q;

            break;

        }

    }

    for(i=1;i<=n;i++){

        cout<<a[i]<<" ";

    }

    return 0;

}