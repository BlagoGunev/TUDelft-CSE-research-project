#include <algorithm>

#include <iostream>

#include <map>

#include <numeric>

#include <set>

#include <string>

#include <vector>

using namespace std;



#define PII pair<int, int>

#define LL long long



void solve() {

    int n;

    cin >> n;



    vector<int> a(n);

    for (auto &it : a)

        cin >> it;

    sort(a.begin(), a.end());

    int tmp = 0;

    LL res = 0;

    for (int i = 0; i < n; i++) {

        while (a[i] > tmp + 1) {

            // cout << a[i] << " " << tmp << endl;

            a[i]--;

            res++;

        }

        if (a[i] == tmp + 1)

            tmp++;

        // cout << i << " " << tmp << endl;

    }

    cout << res << endl;

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)

        solve();

    return 0;

}