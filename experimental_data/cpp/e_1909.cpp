#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>

#define X first
#define Y second
#define PB push_back

using namespace std;
using namespace __gnu_pbds;
//gp_hash_table, cc_hash_table, ordered_set

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef pair < int, int > pii;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < ll, ll > pll;
typedef pair < pii, int > ppi;
typedef pair < int, pii > pip;
typedef long double ld;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 21;
const int M = 1e6 + 500;
const int OFF = (1 << 18);
const int ALP = 30;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353; // 1e9 + 7
const int MSK = (1 << 19);

inline int add(int A, int B) { if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

inline int pot(int A, int B){
	int ret = 1, bs = A;
	for(; B ; B >>= 1){
		if(B & 1) ret = mul(ret, bs);
		bs = mul(bs, bs);
	}
	return ret;
}

int n, m, mora[N];
int maska[N][MSK], fak[N];
vector < int > tko[N];

void precompute(){
	for(int i = 1;i < 20;i++) {
		for(int j = i;j < 20;j += i)
			fak[i - 1] |= (1 << (j - 1));
	}
	for(int i = 1;i < 20;i++) {
		for(int ja = 1;ja < (1 << i);ja++) {
			int sad = 0;
			for(int t = 0;t < i;t++) {
				if(ja & (1 << t)) sad ^= fak[t];
			}
			sad &= (1 << i) - 1;
			if(__builtin_popcount(sad) <= i / 5) {
				tko[i].PB(ja);
			}
		}
	}
}

void solve(){
	scanf("%d%d", &n, &m);
	if(n < 20) for(int i = 0;i < n;i++) mora[i] = 0;
	for(int i = 0;i < m;i++) {
		int a, b; scanf("%d%d", &a, &b);
		a--; b--; 
		if(n < 20) mora[a] |= (1 << b);
	} 
	if(n >= 20) {
		printf("%d\n", n);
		for(int i = 1;i <= n;i++) {
			printf("%d ", i);
		}
		printf("\n");
		return;
	}
	for(int x : tko[n]) {
		int dobar = 1;
		for(int i = 0;i < n;i++)
			if((x & (1 << i)) && (x & mora[i]) != mora[i]) dobar = 0;
		if(dobar) {
			printf("%d\n", __builtin_popcount(x));
			for(int i = 0;i < n;i++)
				if((x & (1 << i))) printf("%d ", i + 1);
			printf("\n");
			return;
		}
	}
	printf("-1\n");
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    precompute();
    int T = 1; 
    scanf("%d", &T);
    for(;T--;) solve();
	return 0;
}