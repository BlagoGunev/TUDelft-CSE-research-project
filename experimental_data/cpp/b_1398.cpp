#include <bits/stdc++.h>



using namespace std;



int main() {

    int t; cin >> t;

    string s;

    int *o = new int[t];

    for (int i = 0; i < t; i++) {

        cin >> s;

        int l = 0;

        vector<int> ones;

        for (int j = 0; j <= s.length(); j++) {

            if ((j == s.length() || s[j] == '0') && (l != 0)) {

                ones.push_back(l);

                l = 0;

            }

            else if (s[j] == '1') l++;

        }

        sort(ones.begin(), ones.end());

        bool a = true; o[i] = 0;

        while (!ones.empty()) {

            if (a) o[i] += ones.back();

            a = !a; ones.pop_back();

        }

    }

    for (int i = 0; i < t; i++) cout << o[i] << "\n";

}