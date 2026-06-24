#include "bits/stdc++.h"



int main() {

    std::ios_base::sync_with_stdio(false);

    std::cin.tie(nullptr);

        int n;

        std::cin >> n;

        std::vector<int> a(n);

        for (int& x : a)

                std::cin >> x;



        std::vector<int> b;

        for (int i = 0; i < n; ++i) {

                int x = a[i];

                b.push_back(x);

                int j = i;

                while (j < n && a[j] == a[i])

                        ++j;

                i = j - 1;

        }



        int reduce = 0;

        std::map<int, int> cnt;

        for (int i = 0; i < (int)b.size(); ++i) {

                ++cnt[b[i]];

                if (cnt[b[i]] == 2) {

                        cnt.clear();

                        cnt[b[i]] = 1;

                        cnt[b[i - 1]] = 1;

                        ++reduce;

                }

        }



        std::cout << b.size() - reduce << '\n';



    return 0;

}