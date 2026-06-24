#include <bits/stdc++.h>



#define int long long





signed main() {

    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr); 

    int n;

    std::cin >> n;

    std::vector<int> a(n);

    for (int i=0;i<n;i++)

    {

        std::cin >> a[i];

        a[i] -= i+1;

        if (i>0 and a[i]<=a[i-1]) a[i] = a[i-1]+1;

        std::cout << a[i] << "\n";

    }

    return 0;

}