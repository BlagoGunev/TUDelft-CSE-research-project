#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long l, r;
        cin >> l >> r;
        long long max_score = 0;
        for (long long i = 1; i <= r; i *= 2) {
            if (i >= l) {
                max_score = log2(i);
            }
        }
        cout << max_score << endl;
    }
    
    return 0;
}