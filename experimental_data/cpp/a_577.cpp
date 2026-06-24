#include <iostream>

#include <fstream>

#include <cstdio>

#include <map>

#include <vector>



using namespace std;



int n, x;



int main() {

    //ifstream cin("tests.txt");



    cin >> n >> x;



    long long ans = 0;



    for (int i = 1; i <= n; i++) {

        if (x % i == 0 && x / i <= n) {

            //cout << i << ' ' << x / i << endl;

            ans++;

        }

    }



    cout << ans;

    return 0;

}