#include<bits/stdc++.h>

using namespace std;

int main() {

    int r, c, k = 1;

    cin >> r >> c;

    for (int a = 1; a <= r; a++) {

        if (a % 2 != 0) {

            for (int b = 0; b < c; b++)

                cout << "#";

            cout << "\n";

        } else {

            if (k % 2 != 0) {

                for (int b = 1; b < c; b++)

                    cout << ".";

                cout << "#\n";

                k++;

            } else {

                cout << "#";

                for (int b = 1; b < c; b++)

                    cout << ".";

                cout<<"\n";

                k++;

            }

        }

    }

    return 0;

}