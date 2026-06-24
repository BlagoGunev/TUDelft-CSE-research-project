#include <bits/stdc++.h>

#define ll long long int

#define pii pair <int,int>

#define ff first

#define ss second

#define pi acos(-1.0)

#define pb push_back

using namespace std;



template < class T > inline T gcd(T a, T b) {while(b) {a %= b; swap(a, b);} return a;}

inline int nxt() {int wow; scanf("%d", &wow); return wow;}

inline ll lxt() {ll wow; scanf("%lld", &wow); return wow;}



/***************** Fighters Launched *******************/



int main()

{

    ll n = lxt();

    if (n < 0) n = 360 - (-n)%360;

    n %= 360;

    if (n >= 315){

        cout << 0 << endl;

        return 0;

    }

    int ans = n/90;

    if (n%90 > 45) ans++;

    cout << ans << endl;

    return 0;

}