#include <cstdio>
#include <queue>

using namespace std;

typedef unsigned long long int lluint;

priority_queue<lluint, vector<lluint>, greater<lluint>> pq;

int main() {
    unsigned int n, k, s, m;
    scanf("%u%u", &n, &k);
    for (auto i = 0; i < n; i++) {
        scanf("%u%u", &s, &m);
        if (i < k) {
            printf("%I64llu\n", (lluint)s + (lluint)m);
            pq.push(s + m);
        } else {
            lluint t = pq.top();
            pq.pop();
            t = (t < s) ? s : t;
            printf("%I64llu\n", t + (lluint)m);
            pq.push(t + (lluint)m);
        }
    }
}