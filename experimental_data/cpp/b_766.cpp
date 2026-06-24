#include <iostream>

using namespace std;

int main() {
    /*
    int n;
    cin >> n;
    int a[n];
    bool found = false;
    int diff[n][n], sum[n][n];
    for (int i = 0; i < n; i++)
        if (!found) {
            cin >> a[i];
            for (int j = 0; j < i - 1; j++) {
                for (int k = j + 1; k < i; k++)
                    if (a[i] > diff[j][k] && a[i] < sum[j][k]) {
                        found = true;
                        break;
                    }
                if (found)
                    break;
            }
            if (!found)
                for (int j = 0; j < i; j++) {
                    diff[j][i] = ((a[j] > a[i]) ? a[j] - a[i] : a[i] - a[j]);
                    sum[j][i] = a[j] + a[i];
                }
        }
    cout << ((found) ? "YES" : "NO") << endl;
     */
    
    int n;
    cin >> n;
    int a[n];
    bool found = false;
    for (int i = 0; i < n; i++)
        if (!found) {
            cin >> a[i];
            for (int j = 0; j < i - 1; j++) {
                for (int k = j + 1; k < i; k++) {
                    int diff = ((a[j] > a[k]) ? a[j] - a[k] : a[k] - a[j]);
                    int sum = a[j] + a[k];
                    if (a[i] > diff && a[i] < sum) {
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
            
        }
    cout << ((found) ? "YES" : "NO") << endl;
}