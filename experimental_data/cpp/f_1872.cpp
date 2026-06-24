#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a, c, in;
vector<bool> valid;
int n;

int main()
{
    int t;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> n;

        a.clear();
        a.resize(n + 1);

        c.clear();
        c.resize(n + 1);

        in.clear();
        in.resize(n + 1);

        valid.clear();
        valid.resize(n + 1, true);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            in[a[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }

        for (int i = 1; i <= n; i++) {
            if (in[i] == 0 && valid[i]) {
                cout << i << " ";
                in[a[i]]--;
                valid[i] = false;
                int curr = a[i];
                while (in[curr] == 0 && valid[curr]) {
                    cout << curr << " ";
                    in[a[curr]]--;
                    valid[curr] = false;
                    curr = a[curr];
                }
            }
        }

        int start;
        int minCost, minPos;
        for (int i = 1; i <= n; i++) {
            if (in[i] > 0 && valid[i]) {
                start = i;
                minCost = 2'000'000'000;

                if (c[i] < minCost) {
                    minCost = c[i];
                    minPos = i;
                }

                for (int j = a[start]; j != start; j = a[j]) {
                    if (c[j] < minCost) {
                        minCost = c[j];
                        minPos = j;
                    }
                }

                for (int k = a[minPos]; k != minPos; k = a[k]) {
                    cout << k << " ";
                    in[a[k]]--;
                    valid[k] = false;
                }

                cout << minPos << " ";
                in[a[minPos]]--;
                valid[minPos] = false;
            }
        }
        cout << "\n";
    }
    return 0;
}