#include <bits/stdc++.h>

using namespace std;



// Computes the radius of the longest palindrome centered at each element in O(n) total.

// Actual palindrome length is `2 * radius[i] + 1`.

template<typename T_string>

vector<int> odd_manacher(const T_string &pattern) {

    int n = int(pattern.size());

    vector<int> radius(n, 0);

    int loc = 0;



    for (int i = 1; i < n; i++) {

        if (i <= loc + radius[loc])

            radius[i] = min(radius[loc - (i - loc)], loc + radius[loc] - i);



        while (i - radius[i] > 0 && i + radius[i] < n - 1 && pattern[i - radius[i] - 1] == pattern[i + radius[i] + 1])

            radius[i]++;



        // Find the location with the furthest-reaching umbrella.

        if (i + radius[i] > loc + radius[loc])

            loc = i;

    }



    return radius;

}



// Returns a vector `lengths` of size `2 * n + 1` where `lengths[i]` indicates a palindrome starting at

// `(i - lengths[i]) / 2` and ending at `(i + lengths[i]) / 2` (exact division).

template<typename T_string>

vector<int> combined_manacher(const T_string &pattern) {

    int n = int(pattern.size());

    T_string extended(2 * n + 1, 0);



    for (int i = 0; i < n; i++)

        extended[2 * i + 1] = pattern[i];



    return odd_manacher(extended);

}



// Returns whether the substring represented by `[start, end)` is a palindrome using the output of `combined_manacher`.

bool is_palindrome(const vector<int> &lengths, int start, int end) {

    return lengths[start + end] >= end - start;

}



void run_test_case() {

    string s;

    cin >> s;



    int n = int(s.size());

    auto lengths = combined_manacher(s);



    int l = 0, r = n - 1;

    while (l <= r && s[l] == s[r]) l++, r--;



    if (r < l) {

        cout << s << '\n';

        return;

    }



    pair<int, string> ans;

    for (int iter = 0; iter < 2; ++iter) {

        int i = -1;

        for (int j = l; j <= r; ++j) {

            if (is_palindrome(lengths, l, j + 1)) {

                i = j;

            }

        }

        assert(i != -1);

        string t = s.substr(0, i + 1) + s.substr(r + 1);

        assert(t == string(t.rbegin(), t.rend()));

        ans = max(ans, make_pair(int(t.size()), t));



        l = n - 1 - r, r = n - 1 - l;

        reverse(s.begin(), s.end());

        lengths = combined_manacher(s);

    }



    cout << ans.second << '\n';

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int test_cases;

    cin >> test_cases;

    

    while (test_cases--) {

        run_test_case();

    }

}