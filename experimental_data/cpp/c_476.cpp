#include <iostream>

#include <cstdio>

#include <vector>

#include <cmath>

#include <string>



#define N 1000000007



using namespace std;



int main () {

    long long a, b;

    cin >> a >> b;

    long long ans = 0;



    long long tmp1 = (a * (a + 1) / 2) % N;

    long long tmp2 = (b * (b - 1) / 2) % N;

    ans = (tmp1 * b + a) % N;

    ans *= tmp2;



    cout << ans % N << endl;

    return 0;

}