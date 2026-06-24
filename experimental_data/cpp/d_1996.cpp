#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        long long count = 0;

        for (int a = 1; a <= min(n, x-2); ++a) {
            for (int b = 1; b <= min(n/a, x-a-1); ++b) {
                int max_c = min((n - a * b) / (a + b), x - a - b);
                if (max_c > 0) {
                    count += max_c;
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}