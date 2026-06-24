#include <iostream>

#include <stdio.h>

#include <algorithm>

#include <cmath>

#include <string>

#include <vector>

#include <queue>



using namespace std;



int cnt[1100];



int main() {

    int n, a;

    cin >> n;

    for (int i = 0; i < n; i++) {

        cin >> a;

        cnt[a]++;

    }

    for (int i = 1; i <= 998; i++) {

        if (cnt[i] >= 1 && cnt[i + 1] >= 1 && cnt[i + 2] >= 1) {

            cout << "YES" << endl;

            return 0;

        }

    }

    cout << "NO" << endl;

    return 0;

}