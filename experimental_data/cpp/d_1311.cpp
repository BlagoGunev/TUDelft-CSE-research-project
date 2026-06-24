#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    
using namespace std;
using namespace __gnu_pbds;
    
struct vw_pair {
    int v, w;
    vw_pair(int v,int w) : v(v), w(w) {};
};
    
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector<int> vi;
typedef vector <string> vs;
typedef vector <vi> vvi;
typedef vector <vector<vw_pair>> adj_list;
typedef vector <bool> vb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef priority_queue<int> max_heap_int;
typedef priority_queue<int, vi, greater<>> min_heap_int;
    
#define isOn(S, j) (S & (1<<j))
#define setBit(S, j) (S |= (1<<j))
#define clearBit(S, j) (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1<<n)-1)
#define modulo(S, N) ((S) & (N-1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S-1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
#define turnOffLastConsecutiveBits(S) ((S) & (S+1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S-1))
#define in_range(lo, hi, x) ((x >= lo && x <= hi))
#define numberOfOnBit(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define forsn(i, x, n) for(int i = x; i < int(n); i++)
double esp = 1e-6;
    
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
    
// Hash map for long long
gp_hash_table<long long, int, custom_hash> ll_hash_map;
// Simple hash for pair
struct chash {
    int operator()(ii x) const { return x.first* 31 + x.second; }
};
gp_hash_table<ii, int, chash> pair_hash_map;
    
typedef tree<
    pair<long long, int>,
    null_type,
    less<pair<long long, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> 
    int_ordered_set;

// --------------------------------------------------------------------------------------------------------------- //

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;cin >> t;
    int n_max = 10100;
    while (t--) {
        int a,b,c;cin >> a >> b >> c;
        if (b % a == 0 && c % b == 0) {
            cout << "0\n" << a << " " << b << " " << c << "\n";
            continue;
        }
        int min_cost = 1e9;
        pair<ii,int> min_tp;
        min_tp = make_pair(make_pair(-1, -1), -1);
        forsn(A,1,n_max+1) {
            int cost_A = abs(A-a);
            if (cost_A >= min_cost) {
                if (A >= a) break;
                else continue;
            }
            forsn(k,1,n_max+1) {
                int B = A*k;
                if (B > n_max) break;
                int cost_B = abs(B-b);
                if (cost_A + cost_B >= min_cost) {
                    if (B >= b) break;
                    else continue;
                }
                int x = max(c,B) / B;
                forsn(nx,x-1,x+2) {
                    int C = B * nx;
                    if (C < B) continue;
                    int cost_C = abs(C-c);
                    if (cost_A + cost_B + cost_C < min_cost) {
                        min_cost = cost_A + cost_B + cost_C;
                        min_tp = make_pair(make_pair(A, B), C);
                    }
                }
            }
        }
        cout << min_cost << "\n";
        cout << min_tp.first.first << " " << min_tp.first.second << " " << min_tp.second << "\n";
    }

    return 0;
}