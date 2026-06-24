#include <bits/stdc++.h>

using namespace std;



using ll = long long;

using ld = long double;



#define all(a) begin(a), end(a)

#define len(a) int((a).size())



namespace rn = ranges;

namespace vw = rn::views;



int main() {

    cin.tie(nullptr)->sync_with_stdio(false);



    int n;

    cin >> n;



    vector<int> ops;

    auto make_op = [&](int i) {

        if (!ops.empty() && ops.back() == i) {

            ops.pop_back();

            return;

        }

        ops.push_back(i);

    };



    auto do_xor = [&](int i, int j) {

        // a[i] ^= a[j]

        for (int rot = 0; rot < 2; rot++, i = (i + 1) % n) {

            if (i == j) continue;

            for (int k = i; k != j; k = (k + 1) % n) make_op(k);

            for (int k = (j + n - 1) % n; k != i; k = (k + n - 1) % n) make_op((k + n - 1) % n);

        }

    };



    for (int i = 0; i < n - 1 - i; i++) do_xor(i, n - 1 - i);

    for (int i = n / 2 - 1; i >= 0; i--) do_xor(n - 1 - i, i);

    for (int i = 0; i < n - 1 - i; i++) do_xor(i, n - 1 - i);



    cout << len(ops) << '\n';

    rn::for_each(ops, [](auto x) { cout << x << ' '; });

    cout << '\n';

}