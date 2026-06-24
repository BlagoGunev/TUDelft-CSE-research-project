#include "bits/stdc++.h"



using namespace std;



#define nhan43 ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

#define FORR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

#define REP(i,a,b)  for(int i=(a),_b=(b);i<_b;++i)

#define int long long

#define ii pair<int,int>

#define Fi first

#define Se second

 

void openF()

{

    if (freopen("input.inp","r",stdin))

    {

        freopen("input.inp","r",stdin);

        freopen("output.out","w",stdout);

    }

}



const int xmaxN = 1e5+5;

const int oo = 1e9;

const int MOD = 1e9 + 7;



int tc, a, b;



void solve()

{

    cin >> a >> b;



    if (a == b) cout << (a > 0);

    else if ((a + b) % 2 == 0) cout << 2;

    else cout << -1;

    cout << '\n';

}



int32_t main() 

{

    nhan43

    // openF();

    tc=1;

    cin >> tc;

    while (tc--) solve();

    return 0;

}