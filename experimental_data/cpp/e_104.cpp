#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

const int MaxN = 300009;

int n, q;
int A[MaxN];
long long sum[MaxN];
long long res[MaxN];
long long last[700];
vector<pair<int, int> > Q[MaxN];

long long brute_force(int a, int b) {
    long long res = 0;
    for (int i = a; i <= n; i += b)
        res += A[i];
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    
    scanf("%d", &q);
    for (int k = 0; k < q; ++k) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (b > 400) res[k] = brute_force(a, b);
            else Q[b].push_back(make_pair(k, a));
    }    
    for (int b = 1; b <= 400; ++b) {
        if (Q[b].size() == 0) continue;
        sum[0] = 0;
        for (int i = 1; i < b; ++i) {
            sum[i] = A[i];
            if (i + b > n) last[i % b] = sum[i];
        }
        for (int i = b; i <= n; ++i) {
            sum[i] = A[i] + sum[i - b];
            if (i + b > n) last[i % b] = sum[i];
        }
        for (int i = 0; i < Q[b].size(); ++i) {
            int a = Q[b][i].second;
            int num = Q[b][i].first;
            res[num] = last[a % b] - sum[max(0, a - b)];
        }
    }
    for (int i = 0; i < q; ++i)
        printf("%I64d\n", res[i]);
        
   // system("pause");
    return 0;
}