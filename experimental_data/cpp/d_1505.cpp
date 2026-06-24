#include "bits/stdc++.h"

using namespace std;



#define int long long

#define You_Never_Know ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)



#pragma GCC target ("avx2")

#pragma GCC optimization ("O3")

#pragma GCC optimization ("unroll-loops")



#ifdef Dhru08

#include "debug.hpp"

#else

#define debug(...) 8

#endif



int32_t main()

{

    You_Never_Know;

    int n,m;

    cin >> n >> m;

    

    vector<int> v;

    while(n != 0){

        v.push_back((n % m));

        n /= m;

    }

    

    set<int> st(v.begin(), v.end());

    cout << (st.size() == v.size()?"YES":"NO");

    return 0;

}