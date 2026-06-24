#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <cassert>
#include <functional>
#include <bits/stdc++.h>
#define int long long



using namespace std;
const int MOD = 1e9 + 7; 
const int jambloated_fudge_factor2 = 32;
const int jambloated_fudge_factor = 32;


int lsb(int n) {
    return n & -n;
}

int popcount(int n) {
    return bitset<32>(n).count();
}

int flog2(int n) {
    int k = 1;
    int ct = 0;
    while (k<=n) {
        k*=2;
        ct++;
    }
    ct--;
    return ct;
}

int ceifun(int n) {
    if (n == 0) return 1;
    return pow(2, flog2(n) + 1);
}

int MSB(int n) {
    if (n == 0) {
        return 0;
    }

    return 1 << (__builtin_clz(1) - __builtin_clz(n));
}



unordered_map<int,int> cache2;
int hashification(int n, int w) {
    return n*MOD+w;
}
int count_ones_dp(int n, int w) {
    int H = hashification(n,w);
    if (cache2.count(H)) return cache2[H];
    if (n < 0) return 0;
    if (n==0) return w==0;
    if (n==1) return (w==0)+(w==1);
    if (w<0) return 0;
    int ans = 0;
    int mpow = MSB(n);
    ans+=count_ones_dp(n-mpow,w-1);
    ans+=count_ones_dp(mpow-1,w);
    //cout << "done " << n <<" " << w <<" " << ans << endl;
    return cache2[H] = ans;
}


map<vector<int>,int> cache3;
int count_numbers_with_w_ones(int l, int r, int w) {
    if (cache3.count({l,r,w})) return cache3[{l,r,w}];
    if (r < l) return 0;
    return cache3[{l,r,w}] = count_ones_dp(r, w) - count_ones_dp(l - 1, w);
}

int count_ones_brute_force(int l, int r, int w) {
    int count = 0;
    for (int number = l; number <= r; ++number) {
        if (bitset<32>(number).count() == w) {
            ++count;
        }
    }
    return count;
}

int binweight(int n) {
    return bitset<32>(n).count();
}


vector<int> ggv(int n, int bmax) {
    int cei = ceifun(n);
    int rem = ceifun(n - cei / 2);
    vector<int> freq(jambloated_fudge_factor2, 0);
    for (int i = 0; i < jambloated_fudge_factor2; ++i) {
        freq[i] = count_numbers_with_w_ones(0, bmax, i);
    }

    for (int i = 2; i < jambloated_fudge_factor2; i += 2) {
        assert(cei % (2 * rem) == 0);
        int l = cei / 2 / rem;
        int r = (min(cei, bmax + 1) - 1) / rem;
        int ct = count_numbers_with_w_ones(l, r, i);
        freq[i] -= ct;
        freq[i - 2] += ct;
    }

    unordered_set<int> done;
    for (int power = 0; power < jambloated_fudge_factor2; ++power) {
        int num = 1LL << power;
        int j = ((n + num) / num) * num;
        if (j >= n + 1 && j < min(bmax + 1, cei) && j - lsb(j) <= n && done.find(j) == done.end()) {
            done.insert(j);
            int r = binweight(j);
            if (j % rem == 0) {
                r -= 2;
            }
            freq[r] -= 1;
            freq[0] += 1;
        }
    }
    /*for (int i=33; i<50; i++) {
        assert(freq[i]==0);
    }*/
    while (freq.size()<jambloated_fudge_factor) {
        freq.push_back(0);
    }

    return freq;
}

signed main() {
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    #ifdef ONLINE_JUDGE
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    #endif //fast IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n), br(n);
        for (int &x : ar) cin >> x;
        for (int &x : br) cin >> x;

        vector<int> dp(jambloated_fudge_factor, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int cei = ceifun(ar[i]);
            int bmax = br[i];
            vector<int> dp1(jambloated_fudge_factor, 0);
            vector<int> g1 = ggv(ar[i], cei - 1);
            vector<int> g2 = ggv(ar[i], bmax % cei);
            vector<int> freq(jambloated_fudge_factor, 0);

            for (int j = 0; j < jambloated_fudge_factor; ++j) {
                freq[j] = g1[j] * (bmax / cei) + g2[j];
            }
            assert(freq[0] > 0);
            freq[0] -= 1;

            for (int j = 0; j < jambloated_fudge_factor; ++j) {
                for (int k = 0; k < jambloated_fudge_factor; ++k) {
                    dp1[j ^ k] += dp[j] * freq[k];
                    dp1[j ^ k] %= MOD;
                }
            }

            dp = dp1;
        }
        cout << dp[0] << "\n";
    }

    return 0;
}