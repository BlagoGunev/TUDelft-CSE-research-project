/*###############################################################################################################
##                                    Author : Kim Tae Yoon (Serendipity__)                                    ##
###############################################################################################################*/

#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define prntyes cout<<"Yes\n";
#define prntno cout<<"No\n";
using namespace std;
#ifndef ONLINE_JUDGE
#include "___debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // random int64 generator
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef __int128 ll128;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pii;
typedef complex<double> inum;
// Macros from KACTL pdf
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef vector<double> vd;
const double PI = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LLINF = 1000000000000000000LL;
const ll MAX = 200005; // depending on the problem
const ll MOD = 998244353; // depending on the problem

void solve() {
    int N; cin>>N;
    bitset<2000> A,B;
    for (int i=0;i<N;i++){
        char c; cin>>c;
        if (c=='1'){
            A[N-1-i] = 1;
        }
    }
    for (int i=0;i<N;i++){
        char c; cin>>c;
        if (c=='1'){
            B[N-1-i] = 1;
        }
    }

    if (A==B){cout<<"0\n"; return;}
    if (A.none() != B.none()){cout<<"-1\n"; return;}

    vector<int> ans;

    auto prnt=[&](){
        cout<<ans.size()<<"\n";
        for (auto& it:ans){
            cout<<it<<" ";
        }
        cout<<"\n";
    };

    while(1){
        int la,ra,lb,rb;
        la=ra=lb=rb=-1;
        for (int i=0;i<N;i++){
            if (A[i]){
                if (la==-1){la=i;}
                ra = i;
            }
            if (B[i]){
                if (lb==-1){lb=i;}
                rb = i;
            }
        }

        int pos = -1;
        if (la == lb){
            while(1){
                pos = -1;
                for (int i=la+1;i<N;i++){
                    if (A[i] != B[i]){
                        pos = i; break;
                    }
                }
                if (pos==-1){
                    prnt();
                    return;
                }

                int diff = pos-la;
                ans.push_back(diff);
                A ^= (A<<diff);
                for (int i=N;i<2000;i++){A[i]=0;}
            }
        }

        if (ra == rb){
            while(1){
                pos = -1;
                for (int i=ra-1;i>=0;i--){
                    if (A[i] != B[i]){
                        pos = i; break;
                    }
                }

                if (pos==-1){
                    prnt();
                    return;
                }

                int diff = ra - pos;
                ans.push_back(-diff);
                A ^= (A>>diff);
            }
        }

        if (la > lb){
            int diff = la - lb;
            ans.push_back(-diff);
            A ^= (A>>diff);
            continue;
        }

        if (ra < rb){
            int diff = rb - ra;
            ans.push_back(diff);
            A ^= (A<<diff);
            for (int i=N;i<2000;i++){A[i]=0;}
            continue;
        }

        pos = -1;
        for (int i=rb+1;i<N;i++){
            if (A[i]){pos=i;break;}
        }

        int diff = pos-la;
        ans.push_back(diff);
        A ^= (A<<diff);
        for (int i=N;i<2000;i++){A[i]=0;}
        continue;
    }

    cout<<ans.size()<<"\n";
    for (auto& it:ans){
        cout<<it<<" ";
    }
    cout<<"\n";

}

int main() {
    fastio;
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}