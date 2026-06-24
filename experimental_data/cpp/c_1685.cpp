#include <iostream>

#include <string>

#include <algorithm>



constexpr int N = 200005;



int T, n;

std::string s;

int pre[N];



int main() {

    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    std::cin >> T;

    while (T--) {

        std::cin >> n >> s;

        n <<= 1;

        int max = 0;

        bool flag = false;

        for (int i = 1; i <= n; ++i) {

            pre[i] = pre[i - 1];

            if (s[i - 1] == '(') ++pre[i];

            else --pre[i];

            max = std::max(max, pre[i]);

            if (pre[i] < 0) flag = true;

        }

        if (!flag) std::cout << "0\n";

        else {

            int first, last;

            for (int i = 0; i <= n; ++i)

                if (pre[i] < 0) last = i;

            for (int i = n; i >= 0; --i)

                if (pre[i] < 0) first = i;

            int l = std::max_element(pre, pre + first) - pre + 1;

            int r = std::max_element(pre + last, pre + n + 1) - pre;

            bool fail = false;

            for (int i = l; i <= r; ++i)

                if (pre[l - 1] + pre[r] < pre[i]) {

                    fail = true;

                    break;

                }

            if (!fail) std::cout << "1\n" << l << ' ' << r << '\n';

            else {

                int pos = std::max_element(pre + 1, pre + n + 1) - pre;

                std::cout << "2\n1 " << pos << '\n' << pos + 1 << ' ' << n << '\n';

            }

        }

    }

    return 0;

}