#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
typedef long long ll;

ll n,m,k,a,b,c;

int main() {
    cin >> n;
    a = n / 3;
    b = n / 3;
    c = n / 3 + n % 3;
    if (a % 3 == 0 and c % 3 == 0) {
        cout << a - 1 << " " << b - 1 << " " << c + 2 << endl;
    } else if (a % 3 == 0) {
        cout << a - 1 << " " << b + 1 << " " << c << endl;
    } else if (c % 3 == 0) {
        if (a % 3 == 1) cout << a << " " << b + 1 << " " << c - 1 << endl;
        else if (a % 3 == 2) cout << a << " " << b - 1 << " " << c + 1 << endl;
    } else {
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}