#include<bits/stdc++.h>

using namespace std;



typedef long long ll;

typedef unsigned long long ull;



#define pb push_back

#define eb emplace_back

#define EL cout << "\n"

#pragma GCC optimize("Ofast")

#define TASK "cf"



const ll N = 4e5+5, M = 2e3+5, base = 311, INF = 1e15, mod = 1e9+7;

ll n,t,k,ans,tmp,m,res,x[N],y[N],z,b[N],q,a[N];

string s;

//



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);cout.tie(0);



    if(fopen(TASK ".inp","r")){

        freopen(TASK ".inp","r",stdin);

        freopen(TASK ".out","w",stdout);

    }



    cin >> t;

    while(t--){

        ll c;

        cin >> n >> c >> q;

        a[0] = n;

//        cout << n << " ";

        cin >> s;

        s = ' ' + s;

        for(int i = 1; i <= c; i++){

            cin >> x[i] >> y[i];

            a[i] = a[i - 1] + y[i] - x[i] + 1;

//            cout << a[i] << " ";

        }

//        EL;

        for(int i = 1; i <= q; i++){

            cin >> z;

//            cout << "aaanwf  " << z;EL;

            while(true){

                tmp = lower_bound(a, a + 1 + c, z) - a;

//                cout << tmp;EL;

                if(tmp == 0){

                    cout << s[z];EL;// << ' ' << z;EL;

                    break;

                }

                z = z - a[tmp - 1] + x[tmp] - 1;

//                cout << a[tmp] << ' ' << x[tmp];EL;

            }

        }

    }

}