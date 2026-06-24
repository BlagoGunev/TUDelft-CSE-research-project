#include <bits/stdc++.h>

    using namespace std;



    #define FILE "gangsters"

    #define pb push_back

    #define mp make_pair

    #define PI 3.14159265358979323846







    typedef long long ll;

    typedef unsigned long long ull;



    const int INF = 2e9;

    const ll LINF = 2e18;

    const int DINF = numeric_limits<double>::max();



    const int ITER = 300;

    const int MOD = 1e9+7;

    const double EPS = 1e-9;

    const int MAXN = 1e5+5;



    ll r,g,b;



    void solve(){

       cin >> r >> g >> b;

       ll mx = max ( max (r, g) , b );

       ll sum = r + g + b - mx;

       if(sum * 2 >= mx){

            cout << (sum + mx) / 3 << endl;

       }else{

            cout << sum << endl;

       }



    }





    int main() {

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        cout.tie(0);

        //freopen(FILE".in", "r", stdin);

        //freopen(FILE".out", "w", stdout);







        int t = 1;

        while(t--) {

            solve();

        }



    }