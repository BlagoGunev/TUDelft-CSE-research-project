#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Function to check if a string matches the template
bool check_template_match(const vector<int>& template_array, const string& s) {
    unordered_map<char, int> char_to_num;
    unordered_map<int, char> num_to_char;
    int n = template_array.size();

    if (s.size() != n) {
        return false;  // Length mismatch
    }

    for (int i = 0; i < n; ++i) {
        char ch = s[i];
        int num = template_array[i];

        if (char_to_num.count(ch)) {
            if (char_to_num[ch] != num) {
                return false;  // Inconsistent mapping
            }
        }
        if (num_to_char.count(num)) {
            if (num_to_char[num] != ch) {
                return false;  // Inconsistent mapping
            }
        }

        char_to_num[ch] = num;
        num_to_char[num] = ch;
    }

    return true;  // All mappings are consistent
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> template_array(n);
        for (int i = 0; i < n; ++i) {
            cin >> template_array[i];
        }

        int m;
        cin >> m;
        vector<string> strings(m);
        for (int i = 0; i < m; ++i) {
            cin >> strings[i];
        }

        for (const string& s : strings) {
            if (check_template_match(template_array, s)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}