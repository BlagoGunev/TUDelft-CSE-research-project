#include "bits/stdc++.h"



#ifdef LOCAL

#include "F:\CPP\Debug\debug.h" 

#else

#define print(...) 1;

#endif



using i64 = long long;



void solve()

{

    int n;

    std::string s;

    std::cin >> n >> s;



    int i = 0, j = n - 1;

    std::string left, right;

    while (i < n and s[i] == '0')  

        left += '0', i++;



    while (j >= i and s[j] == '1')

        right += '1', j--;



    if (j >= i)

        left += '0';



    std::cout << left + right << "\n";

}



int main()

{

    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr);



    int t = 1;

    std::cin >> t;

    

    while (t--)

        solve();

    

    return 0;

}