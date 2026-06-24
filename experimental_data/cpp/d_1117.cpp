#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int MOD = 1e9+7, LOG = 63;

struct LinearRec {

    int n;
    vector<int> first, trans;
    vector<vector<int> > bin;

    vector<int> add(vector<int> &a, vector<int> &b) {
        vector<int> result(n * 2 + 1, 0);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if ((result[i + j] += (long long)a[i] * b[j] % MOD) >= MOD) {
                    result[i + j] -= MOD;
                }
            }
        }
        for (int i = 2 * n; i > n; --i) {
            for (int j = 0; j < n; ++j) {
                if ((result[i - 1 - j] += (long long)result[i] * trans[j] % MOD) >= MOD) {
                    result[i - 1 - j] -= MOD;
                }
            }
            result[i] = 0;
        }
        result.erase(result.begin() + n + 1, result.end());
        return result;
    }

    LinearRec(vector<int> &first, vector<int> &trans):first(first), trans(trans) {
        n = first.size();
        vector<int> a(n + 1, 0);
        a[1] = 1;
        bin.push_back(a);
        for (int i = 1; i < LOG; ++i) {
            bin.push_back(add(bin[i - 1], bin[i - 1]));
        }
    }

    int calc(lld k) {
        vector<int> a(n + 1, 0);
        a[0] = 1;
        for (int i = 0; i < LOG; ++i) {
            if (k >> i & 1) {
                a = add(a, bin[i]);
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if ((ret += (long long)a[i + 1] * first[i] % MOD) >= MOD) {
                ret -= MOD;
            }
        }
        return ret;
    }
};

int main()
{
    lld N, M;
    scanf("%lld %lld", &N, &M);
    vector<int> first(M,1), trans(M,0);
    trans[0] = trans[M-1] = 1;
    LinearRec f(first, trans);
    printf("%d\n", f.calc(N+1));
    return 0;
}