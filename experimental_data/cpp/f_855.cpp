#include <bits/stdc++.h>

using namespace std;

#define right lkjljzxlcjlk
#define left jahdskjhsdj
    int const K = 333;
    int const N = 100100;
    int const INF = 1 << 30;
    int type[N], left[N], right[N], blockMax[N], blockMin[N], xs[N], mx[N], mn[N], value[N];

    int main() {
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d%d", type + i, left + i, right + i);
            if (type[i] == 1) {
                scanf("%d", value + i);
            }
        }
        for (int i = 0; i < N; i++) {
            mx[i] = INF;
            mn[i] = -INF;
        }
        for (int from = 0; from < q; from += K) {
            // for (int i = 0; i < 5; i++) printf("%d ", mn[i]); puts("");
            // for (int i = 0; i < 5; i++) printf("%d ", mx[i]); puts("");
            int to = std::min(q, from + K);
            int cn = 0;
            xs[cn++] = N;
            // xs[cn++] = 0;
            for (int i = 0; i < to; i++) {
                xs[cn++] = left[i];
                xs[cn++] = right[i];
            }
            std::sort(xs, xs + cn);
            cn = (int) (std::unique(xs, xs + cn) - xs);
            // puts("xs");
            // for (int i = 0; i < cn; i++) printf("%d ", xs[i]); puts("");
            std::fill(blockMax, blockMax + cn, INF);
            std::fill(blockMin, blockMin + cn, -INF);
            for (int i = 0, j = 0; i < N; i++) {
                if (xs[j] == i) {
                    ++j;
                }
                blockMax[j] = std::min(blockMax[j], mx[i]);
                blockMin[j] = std::max(blockMin[j], mn[i]);
            }
            for (int i = from; i < to; i++) {
                int lb = (int) (std::lower_bound(xs, xs + cn, left[i]) - xs) + 1;
                int rb = (int) (std::lower_bound(xs, xs + cn, right[i]) - xs) + 1;
                // printf("%d %d %d %d\n", left[i], right[i], lb, rb);
                if (type[i] == 1) {
                    int k = value[i];
                    if (k > 0) {
                        for (int j = lb; j < rb; j++) {
                            blockMax[j] = std::min(blockMax[j], k);
                        }
                    } else {
                        for (int j = lb; j < rb; j++) {
                            blockMin[j] = std::max(blockMin[j], k);
                        }
                    }
                } else {
                    long long ans = 0;
                    for (int j = lb; j < rb; j++) {
                        if (blockMax[j] != INF && blockMin[j] != -INF) {
                            ans += (long long) (blockMax[j] - blockMin[j]) * (xs[j] - xs[j - 1]);
                        }
                    }
                    printf("%lld\n", ans);
                }
            }
            // puts("block");
            // for (int i = 0; i < 5; i++) printf("%d ", blockMax[i]); puts("");
            // for (int i = 0; i < 5; i++) printf("%d ", blockMin[i]); puts("");
            for (int i = 0, j = 0; i < N; i++) {
                if (xs[j] == i) ++j;
                mx[i] = std::min(mx[i], blockMax[j]);
                mn[i] = std::max(mn[i], blockMin[j]);
            }
        }
    }