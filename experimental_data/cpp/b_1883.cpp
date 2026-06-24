#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

void solve() {
    string s;
    int k, n;
    cin >> n >> k;
    cin >> s;
    map<char, int> counts;

    for (int i = 0; i < 26; i++) {
        counts['a' + i] = 0;
    }

        for (int i = 0; i < n; i++)
        {
            if (counts.count(s[i]))
            {
                counts[s[i]] = counts[s[i]] + 1;
            }
            else
            {
                counts[s[i]] = 0;
            }
        }

    int odds = 0;
    for (int i = 0; i < 26; i++) {
        if (counts[i + 'a'] % 2 == 1)
                odds++;
    }
    if (odds - 1 <= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        solve();
    }
}