#include <iostream>

#include <string>

#include <vector>



int T, a, b, c, d;

std::string s;



int main() {

    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    std::cin >> T;

    while (T--) {

        std::cin >> a >> b >> c >> d >> s;

        int cnt = 0;

        for (char i : s)

            if (i == 'A')

                ++cnt;

        if (cnt != a + c + d) { std::cout << "NO\n"; continue; }

        std::vector<int> v1, v2;

        int sum = 0;

        cnt = 1;

        for (int i = 1; i < s.length(); ++i)

            if (s[i] != s[i - 1]) ++cnt;

            else {

                if (cnt & 1) sum += cnt >> 1;

                else if (s[i - 1] == 'B') v1.push_back(cnt >> 1);

                else v2.push_back(cnt >> 1);

                cnt = 1;

            }

        if (cnt & 1) sum += cnt >> 1;

        else if (s.back() == 'B') v1.push_back(cnt >> 1);

        else v2.push_back(cnt >> 1);

        std::sort(v1.begin(), v1.end());

        std::sort(v2.begin(), v2.end());

        for (int i : v1)

            if (c >= i) c -= i;

            else sum += i - 1;

        for (int i : v2)

            if (d >= i) d -= i;

            else sum += i - 1;

        if (c + d <= sum) std::cout << "YES\n";

        else std::cout << "NO\n";

    }

    return 0;

}