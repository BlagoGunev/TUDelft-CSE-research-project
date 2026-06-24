#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;
        
        long long max_length = 1;
        while ((max_length * (max_length + 1)) / 2 <= r - l) {
            max_length++;
        }
        
        cout << max_length << endl;
    }
    return 0;
}