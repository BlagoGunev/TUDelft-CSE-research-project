#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> a2;

    // Construct a[n]
    for(int i = 0; i < n; i++) {
        int element;
        cin >> element;
        a.push_back(element);
    }

    // Count the # of zeros and ones
    int zeroes = count(a.begin(), a.end(), 0);
    int ones = count(a.begin(), a.end(), 1);
    int non_zeroes = n - zeroes;
    int non_ones = n - ones;
    
    // If there are not too many zeroes, the minimum score is 0
    // If there are only one 1 and the rest is zero, the minimum score is 2
    // The rest will output 1
    if(zeroes <= non_zeroes + 1) {
        cout << 0 << endl;
    }
    else if(zeroes + ones == n && ones != 0) { //Mistake: Any number of ones is fine, not just one
        cout << 2 << endl;
    }
    else {
        cout << 1 << endl;
    }
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}