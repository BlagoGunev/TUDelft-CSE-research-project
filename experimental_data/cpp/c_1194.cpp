#include <bits/stdc++.h>
using namespace std;

int main () {
    string s, p, t;
    int q;
    cin >> q;
    for (int i = 0; i < q; i ++) {
        cin >> s >> t >> p;

        bool yes_1 = true, yes_2 = true;

        string missing_characters;
        int pointer_s = 0, pointer_t = 0;
        
        while (pointer_s < s.size() && pointer_t < t.size()) {
            if (t[pointer_t] == s[pointer_s]) {
                pointer_t ++;
                pointer_s ++;
            }
            else {
                missing_characters.push_back(t[pointer_t]);
                pointer_t ++;
            }
        }

        if (pointer_s != s.size()) {
            yes_1 = false;
        }

        if (pointer_t != t.size()) {
            while (pointer_t < t.size()) {
                missing_characters.push_back(t[pointer_t]);
                pointer_t ++;
        // cout << "missing characters: " << missing_characters << "\n";

            }
        }

        vector<int> alphabetM (26, 0);
        for (int i = 0; i < missing_characters.size(); i ++) {
            alphabetM[missing_characters[i] - 97] ++;
        }

        vector<int> alphabetP (26, 0);
        for (int i = 0; i < p.size(); i ++) {
            alphabetP[p[i] - 97] ++;
        }

        for (int i = 0; i < 26; i ++) {
            if (alphabetM[i] > 0) {
                if (alphabetM[i] > alphabetP[i]) {
                    // cout << "alphabetM[" << i << "] = " << alphabetM[i] << " and alphabetP[" << i << "] = " << alphabetP[i] << "\n";
                    yes_2 = false;
                }
            }
        }


        if (yes_1 && yes_2) cout << "YES\n";
        else cout << "NO\n";

    }
}