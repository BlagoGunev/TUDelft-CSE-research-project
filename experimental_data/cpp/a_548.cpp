#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;

    int k;

    cin >> s >> k;

    int l = s.length() / k;

    if (s.length() % k != 0) {

        cout << "NO";

        return 0;

    }

    for (int i = 0; i <= l * (k - 1); i += l) {

        string t = "";

        for (int j = i; j < i + l; ++j)

            t += s[j];

        for (int j = 0; j < l; ++j) {

            if (t[j] != t[t.length() - 1 - j]) {

                cout << "NO";

                return 0;

            }

        }

    }

    cout << "YES";

}