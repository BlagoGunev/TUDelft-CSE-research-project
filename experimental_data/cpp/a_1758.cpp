#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

int main() {
    cin >> t;
    while (t--) {
        cin >> s;
        n = s.length();
        sort(s.begin(), s.end());
        for (int i = 0; i < n; i++)
            cout << s[i] << s[n - i - 1];
        cout << endl;
    }
    return 0;
}