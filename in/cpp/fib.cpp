#include <iostream>
using namespace std;

int main() {

    long long a = 0, b = 1;
    long long n;
    cin >> n;

    if (n == 1) {
        cout << a << endl;
        return 0;
    }
    if (n == 2) {
        cout << b << endl;
        return 0;
    }
    while (n > 2) {
        n--;
        long long t = a + b;
        a = b;
        b = t;
    }
    cout << b << endl;

    return 0;
}