#include <bits/stdc++.h>

typedef long long ll;

#define endl '\n' 

const int N = 234234;

ll n, T;

ll nums[N];

void solve()

{

    std::cin >> n;

    ll odd = 0, even = 0;

    for (int i = 0; i < n; i++) {

        int a;

        std::cin >> a;

        if (a & 1) {

            odd ++;

        } else even ++;

    } 

    std::cout << (odd && even ? "NO" : "YES") << endl;

}

int main()

{

    std::ios::sync_with_stdio(0);

    std::cin.tie(0);

    std::cout.tie(0);

    std::cin >> T;

    while (T--)

    {

        solve();

    }

    return 0;

}