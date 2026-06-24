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

    const int MAXN = 2e5+5;



    int fac(int n){

        int a = 1;

        for(int i = 2; i<=n;i++)

            a*=i;

        return a;

    }



    int C(int n, int k){

        if(n==0 || k==0)return 1;

        return fac(n)/fac(k)/fac(n-k);

    }



    void solve(){

        string a,b;

        cin>>a>>b;

        int apl=0, amn=0;

        for(char c:a){

            if(c=='+')apl++;

            else amn++;

        }

        int bpl=0, bmn=0;

        for(char c:b){

            if(c=='+')bpl++;

            else if(c=='-')bmn++;

        }

        if(bpl>apl||bmn>amn){cout<<0;exit(0);}

        int n = b.size()-bpl-bmn;

        int n1 = (1<<n);

        cout <<fixed<<setprecision(15)<<1.*C(n, apl-bpl)/n1<<endl;

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