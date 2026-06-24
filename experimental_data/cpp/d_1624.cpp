#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_success(vector<int> char_to_count, int mock, int k) {
    if (mock % 2 == 1) {
        for (int i = 0; i < k; ++i) {
            int target_index = 0;

            for (int j = 0; j < 26; ++j) {
                if (char_to_count[j] % 2) {
                    target_index = j;
                    break;
                }
                else if (char_to_count[j]) {
                    target_index = j;
                }
            }

            char_to_count[target_index] -= 1;
        }
        mock -= 1;
    }

    int sum = 0;
    for (int i = 0; i < 26; ++i) {
        sum += (char_to_count[i] - (char_to_count[i] % 2));
    }

    return sum >= mock * k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> char_to_count(26);
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        char_to_count[ch - 'a'] += 1;
    }

    int low = 1;
    int high = n / k;
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (is_success(char_to_count, mid, k)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << low - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }

    return 0;
}