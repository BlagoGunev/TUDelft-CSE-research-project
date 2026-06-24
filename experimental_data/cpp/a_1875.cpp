//
// Created by Peter Pashkin on 30.09.23.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("-Ofast")

vector<int> primeFactors(int n)
{
    vector<int> result;
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        result.push_back(2);
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            result.push_back(i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        result.push_back(n);
}



int32_t main() {
    int t; cin >> t;
    while(t--) {
        int a,b,n; cin >> a >> b >> n;
        vector<int> arr(n);
        int sum = b;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(auto x: arr) {
            sum += min(x, a-1);
        }
        cout << sum << endl;


    }
}