#include <bits/stdc++.h>



using namespace std;



typedef long long ll;

typedef unsigned long long ull;

typedef vector <int> vi;

typedef vector <ll> vll;

typedef vector < vector <int> > vvi;

typedef pair <int,int> pii;

#define pb push_back

const double pi = 3.1415926535898;

#define fi first

#define se second

#define sp setprecision

#define sz size()

#define mp make_pair

const char spc = ' ';



ll binpow(ll a, ll n){

    if(n == 0){

        return 1;

    }

    ll res = 1;

    while(n){

        if (n % 2 == 1){

            res *= a;

        }

        a *= a;

        n /= 2;

    }

    return res;

}



int gcd(int a, int b){

	while(b){

		a %= b;

		swap(a, b);

	}

	return a;

}



int siz(ll x){

    if(x < 1e1){

        return 1;

    }

    else if(x < 1e2){

        return 2;

    }

    else if(x < 1e3){

        return 3;

    }

    else if(x < 1e4){

        return 4;

    }

    else if(x < 1e5){

        return 5;

    }

    else if(x < 1e6){

        return 6;

    }

    else if(x < 1e7){

        return 7;

    }

    else if(x < 1e8){

        return 8;

    }

    else if(x < 1e9){

        return 9;

    }

    else if(x < 1e10){

        return 10;

    }

}



int inf_int = 2e9;

ll inf_ll = 2e18;

const double EPS = 1e-8;



int t;



int n;

vector <pii> field;



map <pii, bool> used;



void dfs(pii v){

    used[v] = 1;



    for(int i = 0; i < n; i++){

        pii to = field[i];



        if(!used[to] && (to.fi == v.fi || to.se == v.se)){

            dfs(to);

        }

    }

}



void solve(){

    cin >> n;

    for(int i = 0; i < n; i++){

        int x, y;

        cin >> x >> y;

        field.pb({x, y});

    }



    int cnt = 0;

    for(int i = 0; i < n; i++){

        if(!used[field[i]]){

            dfs(field[i]);

            cnt++;

        }

    }



    cout << cnt-1 << endl;

}



int main()

{

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



//    freopen("trains.in","r",stdin);

//    freopen("trains.out","w",stdout);



    t = 1;

    while(t--){

        solve();

    }



    return 0;

}