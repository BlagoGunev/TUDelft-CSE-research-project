#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

#define ll long long
#define pb push_back

ll p, q;
int k;
vector<ll> v;

int main() {
    cin >> p >> k;
    q = p;
    if (p < k) {
        printf("1\n%lld\n", p);
        return 0;
    }
    while (true) {
        if (p < 0) {
            p = 1 - (p + 1) / k;
            v.pb(p);
        }
        else if (p >= k) {
            p = -p / k;
            v.pb(p);
        }
        else break;
    }
    printf("%d\n", v.size() + 1);
    for (ll item: v) {
        printf("%lld ", q + item * k);
        q = item;
    }
    printf("%lld\n", v[v.size() - 1]);
    return 0;
}