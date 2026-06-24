#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

int main() {

    long long a, b;

    int ans = 0;

    cin >> a >> b;

    for (int i = 2; i<= 61; i++)

    {

        for (int j = 0; j< i - 1; j++)

        {

            ll x = (1LL << i) - 1 - (1LL << j);

            if (x >= a && x <= b)

                ans++;

        }

    }

    cout << ans;

    return 0;

}