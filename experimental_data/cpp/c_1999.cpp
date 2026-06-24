#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;

        vector<pair<int, int>> tasks(n);
        for (int i = 0; i < n; ++i) {
            cin >> tasks[i].first >> tasks[i].second;
        }

        // Sort the tasks based on the start time
        sort(tasks.begin(), tasks.end());

        bool canShower = false;

        // Check the gap before the first task
        if (tasks[0].first >= s) {
            canShower = true;
        }

        // Check the gaps between tasks
        for (int i = 1; i < n; ++i) {
            if (tasks[i].first - tasks[i - 1].second >= s) {
                canShower = true;
            }
        }

        // Check the gap after the last task
        if (m - tasks[n - 1].second >= s) {
            canShower = true;
        }

        // Output the result
        if (canShower) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}