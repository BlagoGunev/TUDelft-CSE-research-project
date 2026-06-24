#include <iostream>



const int N = 2e5 + 10;

int a[N], ed[N];



long long solve() {

    int n;

    std::cin >> n;

    

    for (int i = 1; i <= n; i++) {

        std::cin >> a[i];

        ed[i] = n + 1;

    }



    long long ans = 0;

    int tail = n + 1;



    for (int i = n; i >= 1; i--) {

        tail = std::min(tail, ed[i]);

        ans += tail - i;

        if (i - a[i] > 0)

            ed[i - a[i]] = i;

    }



    return ans;

}



int main()

{

    std::cin.tie(nullptr) -> sync_with_stdio(false);

    

    int t;

    std::cin >> t;

    

    while (t--)

        std::cout << solve() << '\n';

    

    return 0;

}