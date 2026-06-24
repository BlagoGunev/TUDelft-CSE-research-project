#include <bits/stdc++.h>

using namespace std;



int main() {

    int n; cin >> n;

    auto Mod = [&](int num, int mod) {return (num % mod + mod) % mod;};

    for (int i = 0; i < n; ++i) {

        int b; cin >> b;

        int d = i;

        for (int j = 0; j < i; ++j) {

            cout << Mod(b - (i - j) * d, n) << " ";

        }

        cout << b << " ";

        for (int j = i + 1; j < n; ++j) {

            cout << Mod(b + (j - i) * d, n) << " ";

        }

        cout << endl;

    }

}