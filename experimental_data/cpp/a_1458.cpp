#include <bits/stdc++.h>	

#define all(x) x.begin(), x.end()

#define pb push_back

#define pop pop_back

#define v_i vector <int>

#define f1 first

#define s2 second

#define vp vector<pair <int, int>>

using namespace std;



typedef long long int lli;

long long int binpow(long long a, long long b)

{

    if(b==0) return 1;

    long long res = binpow(a, b/2);

    if(b%2==0) return res*res;

    else return res*res*a;

}

unsigned int countSetBits(unsigned int n)

{

    unsigned int count = 0;

    while (n){

        count += n & 1;

        n >>= 1;

    }

    return count;

}

void solve()

{

    lli n, m;

    cin>>n>>m;

    lli arr[n];

    lli b[m];

    for(int i=0;i<n;i++) cin>>arr[i];

    for(int j=0;j<m;j++) cin>>b[j];

    lli gcd=0;

    for(int i=1;i<n;i++) gcd=__gcd(gcd, arr[i]-arr[0]);

    for(int i=0;i<m;i++){

        cout<<abs(__gcd(gcd, arr[0]+b[i]))<<" ";

    }

    cout<<endl;

}

int main () {

    ios::sync_with_stdio(0);

    cin.tie(0);

    int tt;

    tt=1;

    //cin>>tt;

    while(tt--)

    {

        solve();

    }

    return 0;

}