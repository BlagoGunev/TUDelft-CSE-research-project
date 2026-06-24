#include <bits/stdc++.h>

using namespace std;



const int N = 5e2 + 7;

int Array[N];

int t, n;



void solve() {

    sort(Array, Array + n);

    for (int i = 0; i < n - 1; i++) {

        if (Array[i] % 2 == 1 && Array[i + 1] % 2 == 0 && abs(Array[i] - Array[i + 1])== 1) {

            cout << "YES\n";

            return;

        }

        if (Array[i] % 2 == 0 && Array[i + 1] % 2 == 1 && abs(Array[i] - Array[i + 1])== 1) {

            cout << "YES\n";

            return;

        }

    }

    cout << "NO\n";

}

void read_input() {

    cin >> t;

    for (int i = 0; i < t; i++) {

        cin >> n;

        int cnt = 0;

        for (int j = 0; j < N - 1; j++)

            Array[j] = 0;

        for (int j = 0; j < n; j++) {

            cin >> Array[j];

            if (Array[j] % 2 == 0)

                cnt++;

        } 

        if (cnt % 2 == 0)

            cout << "YES\n";

        else

            solve();

    }

}



int main() {

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    read_input();

}