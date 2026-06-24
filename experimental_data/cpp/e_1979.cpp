#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
//typedef unsigned long long ull;
typedef unsigned int ui;
typedef gp_hash_table<int,int> umap;
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937_64 eng(seed);
 
ll random2(){
    return eng() >> 1;
}
 
ll n,m,k,q,T;
 
const ll nils = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200001;

vi solve(vi X, vi Y){

    map<int,int> M;
    map<ll,int> lookup;
    vector<vi> YC;

    rep(c1,0,n){
        ll h = ll(X[c1])*nils+Y[c1];
        lookup[h] = c1;
        if(M.find(X[c1]) == M.end()){
            M[X[c1]] = sz(YC);
            vi temp;
            YC.push_back(temp);
        }
        int i = M[X[c1]];
        YC[i].push_back(Y[c1]);
    }

    rep(c1,0,sz(YC)){
        sort(all(YC[c1]));
    }

    rep(c1,0,n){
        int i = c1;
        ll h2 = ll(X[c1])*nils + Y[c1]+k;
        if(lookup.find(h2) != lookup.end()){
            int j = lookup[h2];

            for(int x2 = X[i]-k; x2 <= X[i]+k; x2 += 2*k){
                if(M.find(x2) != M.end()){
                    int yci = M[x2];
                    if(!(YC[yci][0] > Y[i]+k || YC[yci].back() < Y[i])){
                        int lo = 0;
                        int hi = sz(YC[yci]);
                        while(lo < hi-1){
                            int mid = (lo+hi)/2;
                            if(YC[yci][mid] <= Y[i]+k){
                                lo = mid;
                            }
                            else{
                                hi = mid;
                            }
                        }

                        if(Y[i] <= YC[yci][lo] && YC[yci][lo] <= Y[i]+k){
                            ll h3 = ll(x2)*nils + YC[yci][lo];
                            return {i+1,j+1,lookup[h3]+1};
                        }

                    }
                }
            }

        }
    }

    return {0,0,0};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll a,b,c,d;
    
    cin >> T;

    rep(c4,0,T){
        cin >> n >> k;
        vi X,Y;
        vi XD,YD;

        rep(c1,0,n){
            cin >> a >> b;
            X.push_back(a);
            Y.push_back(b);
            XD.push_back(a-b);
            YD.push_back(a+b);
        }

        vi ans1 = solve(XD,YD);
        vi ans2 = solve(YD,XD);

        if(ans1[0] != 0){
            cout << ans1[0] << " " << ans1[1] << " " << ans1[2] << "\n";
        }
        else{
            cout << ans2[0] << " " << ans2[1] << " " << ans2[2] << "\n";
        }

    }
 
    return 0;
}