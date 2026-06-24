#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#ifdef freakin23 
#include "algo_debug.h"
#else
#define debug(J...)
#endif

#define i64 long long
#define LD long double
#define i23 long long
#define all(j) (j).begin(),(j).end()
#define INF (1 << 29)
const i64 infinity = 1000000000000000;
const i64 MAX = 1e9 + 7;
constexpr int inf = (119 << 23) + 1; // 998244353


constexpr i64 LINF = 1e18;
template<typename T>
T size(vector<T> v) {
    return (T)v.size();
}

template<typename T>
constexpr T Power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

template<typename T>
vector<pair<T,int>> prime_factor(T n){
    n = abs(n);
    vector<pair<T,int>> res;
    for(T i = 2; i * i <= n; i++){
        if(n % i == 0){
            res.push_back({i,0});
            while(n % i == 0){
                n /= i;
                res.back().second++;
            }
        }
    }
    if(n > 1){
        res.push_back({n, 1});
    }
    return res;
}

i23 setBits1_N(i23 N) {
    i23 two = 2, ret = 0;
    i23 n = N;
    while (n) {
        ret += (N / two) * (two >> 1LL);
        if ((N & (two - 1)) > (two >> 1LL) - 1)
            ret += (N & (two - 1)) - (two >> 1LL) + 1;
        two <<= 1LL;
        n >>= 1LL;
    }
    return ret;
}

void Print(vector<int> &res, int start, int end) {
    for (int i = start; i <= end; i++) {
        cout << res[i] << " \n"[i == end];
    }
}

template<typename T>
vector<T> factor(T x) {
    vector<T> res;
    for (T i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (x / i != i) {
                res.push_back(x / i);
            }
        }
    }
    sort(begin(res), end(res));
    return res;
}
// a + b = 2(a & b) + a ^ b
// a ^ b = ~(a & b) & (a | b)
i64 Sqrt(i64 n) {
    i64 a = sqrt(n);
    while ((a + 1) * (a + 1) <= n) {
        a++;
    }
    while(a * a > n){
        a--;
    }
    return a;
}

const i23 primeLimit = 1e6 + 4;
vector<i23> prime;
i23 isPrime[primeLimit];
void seive() {
    for (i23 i = 2; i < primeLimit; i++) {
        if (isPrime[i] == 0) {
            prime.push_back(i);
            for (i23 j = i * i; j < primeLimit; j += i) {
                isPrime[j] = 1;
            }
        }
        isPrime[i] ^= 1;
    }
}

array<int, 32> Bit {};
bool SP2(array<int, 32> Bit, int x) { // check if x is the summation of given powers of 2
    for (int i = 31; i >= 0; i--) {
        int mn = min(x >> i, Bit[i]);
        x -= (mn << i);
    }
    return (x == 0);
}

// int _and = ~0;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);
    int test;   
    cin >> test;
    // seive();
    // int test = 1;   
    // array<data type, size> Arr {}; 
    auto G = [&] (int X) {
        i23 res = 0;
        for (auto x : to_string(X)) {
            res += (x - '0');
        }
        return res;
    };
    // const int N = 200005;
    // vector<i23> A(N, 0);
    // for (int i = 0; i <= N; i++) {
    //     A[i + 1] = G(i + 1) + A[i];
    // }
    while (test --> 0) {
        auto Devil = [&]() {
            vector<vector<char>> G(7, vector<char> (7));
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 7; j++) {
                    cin >> G[i][j];
                }
            }

            auto f = [&] (vector<vector<char>> M, int ok) -> bool {
                for (int i = 1; i < 6; i++) {
                    for (int j = 1; j < 6; j++) {
                        if (((i + j) & 1) == ok) {
                            if (M[i][j] == 'B') {
                                if (M[i - 1][j - 1] == 'B' and M[i + 1][j + 1] == 'B' and M[i - 1][j + 1] == 'B' and M[i + 1][j - 1] == 'B') {
                                    return false;
                                }
                            }
                        }
                    }
                }
                return true;
            };

            int res_a = 50, res_b = 50;
            map<pair<int, int>, int> mp1, mp2;
            vector<pair<int, int>> A, B;
            for (int i = 1; i < 6; i++) {
                for (int j = 1; j < 6; j++) {
                    if (G[i][j] == 'B') {
                        if ((i + j) % 2 == 0) {
                            B.push_back({i, j});
                        } else {
                            A.push_back({i, j});
                        }
                    }
                }
            }

            for (int mask = 0; mask < (1 << (int)A.size()); mask++) {
                int p = 0;
                auto new_G = G;
                for (int j = 0; j < (int)A.size(); j++) {
                    if ((1 << j) & mask) { // Set
                        new_G[A[j].first][A[j].second] = 'W';
                        p += 1;
                    }
                }
                if (f(new_G, 1)) {
                    res_a = min(res_a, p);
                }
            }


            for (int mask = 0; mask < (1 << (int)B.size()); mask++) {
                int p = 0;
                auto new_G = G;
                for (int j = 0; j < (int)B.size(); j++) {
                    if ((1 << j) & mask) { // Set
                        new_G[B[j].first][B[j].second] = 'W';
                        p += 1;
                    }
                }
                if (f(new_G, 0)) {
                    res_b = min(res_b, p);
                }
            }
            int res = res_a + res_b;
            cout << res << '\n';
        };Devil(); 
    }   
    return 0;
}