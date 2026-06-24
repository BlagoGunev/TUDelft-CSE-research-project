#include <iostream>

#include <vector>

#include <algorithm>



using namespace std;



int BASE;

int add(int x, int y) {

    x += y;

    if (x >= BASE) return x-BASE;

    return x;

}

int mult(int x, int y) {

    return (long long)x*y % BASE;

}



int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tests; cin >> tests;

    while (tests--) {

        int d; cin >> d >> BASE;

        int sumSoFar = 0;

        for (int i = 0; (1 << i) <= d; ++i) {

            sumSoFar = add(sumSoFar, mult(sumSoFar+1, min(1 << i, d - (1 << i) + 1) % BASE));

        }

        cout << sumSoFar << '\n';

    }

    return 0;

}