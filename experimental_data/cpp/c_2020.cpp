#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ull b, c, d;
        cin >> b >> c >> d;
        ull a = 0;
        bool possible = true;
        for (int i = 0; i < 64; ++i) {
            ull b_i = (b >> i) & 1;
            ull c_i = (c >> i) & 1;
            ull d_i = (d >> i) & 1;
            ull a_i = 0;

            if (b_i == 0 && c_i == 0) {
                a_i = d_i;
            } else if (b_i == 0 && c_i == 1) {
                if (d_i != 0) {
                    possible = false;
                    break;
                }
                a_i = 0; // Can be 0 or 1; we choose 0
            } else if (b_i == 1 && c_i == 0) {
                if (d_i != 1) {
                    possible = false;
                    break;
                }
                a_i = 1; // Choose 1 to satisfy the equation
            } else if (b_i == 1 && c_i == 1) {
                a_i = 1 - d_i;
            }
            a |= (a_i << i);
        }
        if (possible) {
            cout << a << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}