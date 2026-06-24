#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//java+js+withoutcmd


int main() {
    int n;
    cin >> n;
    string a[]{"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    map<int, vector<string> > mp;
    for (int i = 0; i < 8; i++)
        mp[a[i].size()].push_back(a[i]);

    string s;
    cin >> s;



    for (auto t : mp[n]) {
        bool ok = true;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] != s[i] && s[i] != '.')
                ok = false;
        }
        if (ok) {
            cout << t;
            return 0;
        }
    }

}