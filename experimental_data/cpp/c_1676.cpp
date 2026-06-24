#include <bits/stdc++.h>

using namespace std;



void work() {

    int n, m;

    cin >> n >> m;

    vector<string> S(n);

    for(int i = 0; i < n; i++) {

        cin >> S[i];

    }

    unsigned long long SUM = 0;

    unsigned long long MIN = 9999999999;



    for(int j = 0; j < n; j++) {

        for(int i = j+1; i < n; i++) {

            for (int k = 0; k < m; k++) {

                SUM += abs(S[j][k] - S[i][k]);

            }

            if(MIN > SUM) MIN = SUM;

            SUM = 0;

        }

    }

    cout << MIN << endl;

}



int main() {

    int t;

    cin >> t;

    for(int i = 0; i < t; i++) work();

    return 0;

}