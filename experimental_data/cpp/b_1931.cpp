#include<iostream>
using namespace std;

int main() {
    int loop;
    cin >> loop;

    while (loop > 0) {
        int y = 0;
        int containers;
        cin >> containers;

        int c[containers];
        int sum = 0;

        for (int i = 0; i < containers; i++) {
            cin >> c[i];
            sum += c[i];
        }

        int r = sum % containers;

        if (r != 0) {
            cout << "No" << endl;
            loop--;
            continue;
        }

        int limit = sum / containers;

        for (int i = containers - 1; i >= 0; i--) {
            if (c[i] > limit) {
                cout << "No" << endl;
                y++;
                break;
            } else if (limit == c[i]) {
                continue;
            } else {
                int d = limit - c[i];
                if (i - 1 < 0) {
                    break;
                }
                c[i - 1] -= d;
            }
        }

        if (y == 0) {
            cout << "Yes" << endl;
        }

        loop--;
    }

    return 0;
}