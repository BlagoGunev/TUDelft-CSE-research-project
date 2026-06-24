#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int T = 100;
constexpr int M = 100001;
constexpr int SQM = 320;
constexpr int LGM = 20;
vector<pair<int,int>> factor;
int t, n[T], count_multipliers[T][M];
bitset<M> is_composite;
vector<int> ans[T], a[T];

inline void calculate_importants() {
    for(int i = 2; i < SQM; i++)
        if(!is_composite[i]) {
            for(int j = i; j < M; j *= i)
                factor.push_back({j,i});
            for(int j = i*i; j < M; j += i)
                is_composite.set(j);
        }
    for(int i = SQM; i < M; i++)
        if(!is_composite[i])
            factor.push_back({i,i});
    sort(factor.begin(), factor.end());
}

void check(vector<int> &factors, int G) {
    if(factors.size() > 2u) {
        for(int i = 0; i < t; i++) 
            if(ans[i].size() < factors.size()) {
                int count_product = (G < M? count_multipliers[i][G] : 0);
                bool can = true;	
                for(auto u: factors)
                    if(count_multipliers[i][G/factor[u].first] == count_product) {
                        can = false;
                        break;
                    }
                if(can)
                    ans[i] = factors;
            }
    }
    int bound = (factors.size() == 1 ? SQM : M);
    if(1LL*G/factor[factors[0]].first*factor[factors.back()].first > bound)
        return;
    for(int new_factor = factors.back(); G/factor[factors[0]].first*factor[new_factor].first <= bound; new_factor++) 
        if(G%factor[new_factor].second) {
            factors.push_back(new_factor);
            check(factors, G*factor[new_factor].first);
            factors.pop_back();
        }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(nullptr);
    calculate_importants();
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n[i];
        a[i].resize(n[i]);
        for(int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            count_multipliers[i][a[i][j]]++;
        }
        ans[i] = {a[i][0]};
        sort(a[i].begin(), a[i].begin()+min(n[i], LGM));
        for(int c = 0; c+1 < n[i]; c++)
            if(a[i][c+1]%a[i][c]) {
                ans[i] = {a[i][c], a[i][c+1]};
                break;
            }
        for(int c = 1; c < M; c++)
            for(int j = c+c; j < M; j += c)
                count_multipliers[i][c] += count_multipliers[i][j];
    }
    for(int i = 0; factor[i].first < SQM; i++) {
        vector<int> starter = {i};
        check(starter, factor[i].first);
    }
    for(int i = 0; i < t; i++) {
        int k = ans[i].size();
        cout << k << '\n';
        if(k == 1u) {
            cout << ans[i][0] << '\n';
        } else if(k == 2u) {
            cout << ans[i][0] << ' ' << ans[i][1] << '\n';
        } else {
            int subset[k];
            for(auto u: a[i]) {
                int ls = -1;
                for(int j = 0; j < (int)k; j++)
                    if(u%factor[ans[i][j]].first)
                        ls = (ls == -1? j: -2);
                if(ls >= 0)
                    subset[ls] = u;
            }
            for(int j = 0; j < k; j++)
                cout << subset[j] << (j+1 == k? '\n' : ' ');
        }
    }
    return 0;
}