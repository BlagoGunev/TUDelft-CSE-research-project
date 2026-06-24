#include <bits/stdc++.h>

#define maxx 100005

#define inf 2000000000

#define mod 1000000007

#define pii pair<int,int>

#define piii pair<pii,pii>

#define pli pair<ll,int>

#define pll pair<ll,ll>

#define pid pair<int, double>

#define plll pair<ll,pll>

#define f first

#define s second

#define in(x) scanf("%d",&x)

#define IN(x) scanf("%I64d",&x)

#define inch(x) scanf("%s",x)

#define indo(x) scanf("%lf",&x)

#define pb push_back



typedef long long ll;

typedef unsigned long long ull;



using namespace std;



int a, n, d;

int f[100 * maxx];

int main()

{

    in(a); in(n);

    d = sqrt(1.0 * (a + n - 1));

    for(int i = d; i >= 1; i--){

        for(int j = i * i, k = 1; j <= a + n - 1; j += (i * i), k++){

            if(!f[j])

                f[j] = k;

        }

    }

    ll ans = 0;

    for(int i = a; i <= a + n - 1; i++){

        ans = ans + 1LL * f[i];

    }

    cout << ans << endl;

    return 0;

}