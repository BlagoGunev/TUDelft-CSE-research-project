#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> h(m);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '*') {
                h[j] = n - i;
                break;
            }
        }
    }
    int maxUp = 0, maxDown = 0;
    for (int j = 1; j < m; j++) {
        maxUp = max(maxUp, h[j] - h[j - 1]);
        maxDown = max(maxDown, h[j - 1] - h[j]);
    }
    cout << maxUp << " " << maxDown << endl;
    return 0;
}