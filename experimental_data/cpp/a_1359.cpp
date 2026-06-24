#include<iostream>

#include<map>

#include<queue>

#include<stack>

#include <numeric>

#include<algorithm>

#include<cmath>

#include<string>

#include<vector>

#include<set>

using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long

#define do double

#define pirn cout<<"NO\n";

#define piry cout<<"YES\n";

void so() {

    int n, m, k; cin >> n >> m >> k;

    if (m == 0) {

        cout << 0 << "\n";

        return;

    }

    int mi = min(m, n / k);

    if (mi == m)cout << m << "\n";

    else {

        m -= mi;

        int d = m / (k - 1);

        if ((m % (k - 1)))d++;

        cout <<  mi-d << '\n';

    }

}

int main() {

    fast

        //  freopen("input.txt", "rt", stdin);

        //freopen("output.txt", "wt", stdout);

        int t; cin >> t; while (t--)

        so();

}