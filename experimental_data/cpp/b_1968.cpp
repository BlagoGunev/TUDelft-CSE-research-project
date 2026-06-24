#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_subsequence(const string& a, const string& b, int k) {
    int i = 0, j = 0;
    while (i < k && j < b.size()) {
        if (a[i] == b[j]) {
            i++; 
        }
        j++;
    }
    return i == k; 
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        string a, b;
        cin >> a >> b;

        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right + 1) / 2; 
            if (is_subsequence(a, b, mid)) {
                left = mid;
            } else {
                right = mid - 1; 
            }
        }

        cout << left << endl; 
    }

    return 0;
}