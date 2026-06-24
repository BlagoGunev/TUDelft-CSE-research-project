#include <bits/stdc++.h>



using namespace std;



#define ll long long



int main() {

    ios::sync_with_stdio(0);

    cin.tie(0);

    int tt;

    cin >> tt;

    while (tt--) {

        int n;

        cin >> n;

        string s;

        cin >> s;

        vector<int> a;

        int i = 0;

        while (i < n) {

            int j = 0;

            while (i + j < n && s[i + j] == s[i]) {

                j++;

            }

            a.push_back(j);

            i += j;

        }

        vector<int> odd;

        for (int i = 0; i < a.size(); i++) {

            if (a[i] % 2 == 1) {

                odd.push_back(i);

            }

        }

        int ans = 0;

        for (int i = 1; i < odd.size(); i += 2) {

            ans += odd[i] - odd[i - 1];

        }

        cout << ans << '\n';

    }

    return 0;

}