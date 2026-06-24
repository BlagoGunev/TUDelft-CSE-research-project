#include <iostream>
using namespace std;

int main() {
    int a, b, n, m, k, pa, pb, fa, fb;
    cin >> n >> m >> k >> a >> b;
    pa = (a - 1) / (m * k);
    pb = (b - 1) / (m * k);
    fa = (a - 1) % (m * k) / k;
    fb = (b - 1) % (m * k) / k;

    long long t;
    //cout << "pa = " << pa << ", pb = " << pb << ", fa = " << fa << ", fb = " << fb << '\n';
    if (pa == pb) {
        if (fa == fb) {
            t = 0;
        } else {
            t = min(abs(fb - fa) * 5, 10 + abs(fb - fa));
        }
    } else {
        int firstp = min(pa, pb);
        int secondp = max(pa, pb);
        //cout << "minp = " << firstp << ", maxp = " << secondp << '\n';
        t = min(fa * 5, 10 + fa) + min(fb * 5, 10 + fb) + 15 * min(secondp - firstp, n - secondp + firstp);
    }

    cout << t << '\n';
    return 0;
}