#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for ( ; t > 0; t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        long long l, r;
        l = a[n];
        r = 1'000'000'000'000;
        long long m;
        while (l < r) {
            m = (l + r) / 2;
            long long extra = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] > m) {
                    extra += a[i] - m;
                }
                else {
                    extra -= min(m - a[i], extra);
                }
            }
            if (extra > 0) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        long long maxim = l;

        l = 0;
        r = maxim;
        while (l < r) {
//            cout << "t " << l << " " << r << "\n";
            m = (l + r + 1) / 2;
            long long extra = 0;
            bool possible = true;
            for (int i = 1; i <= n; i++) {
                if (a[i] > m) {
                    extra += a[i] - m;
                }
                else {
                    extra -= (m - a[i]);
                }
                if (extra < 0) {
                    possible = false;
                    break;
                }
            }
            if (!possible) {
                r = m - 1;
            }
            else {
                l = m;
            }
        }
        long long minim = l;
        cout << maxim - minim << "\n";
//        cout << maxim << " " << minim << "\n";

    }
    return 0;
}