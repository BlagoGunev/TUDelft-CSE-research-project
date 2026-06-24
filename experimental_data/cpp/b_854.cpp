#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    long long mi, ma;

    mi = (n == k or k == 0 ? 0 : 1);

    if (n >= 3 * k) {
        ma = 2 * k;
    }
    else {
        ma = n - k;
    }

    cout << mi << " " << (mi ? ma : 0) << endl;

    return 0;
}