#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, string>> v;
        for (int i = 0; i < n; i++) {
            int m;
            string skills;
            cin >> m >> skills;
            v.push_back({m, skills});
        }
        int time1 = -1;
        int skill1 = -1, skill2 = -1;
        for (auto i : v) {
            if (i.second[0] == '1') {
                if (skill1 == -1 || i.first < skill1) {
                    skill1 = i.first;
                }
            }
            if (i.second[1] == '1') {
                if (skill2 == -1 || i.first < skill2) {
                    skill2 = i.first;
                }
            }
        }
        for (auto i : v) {
            int total = i.first;
            if (i.second[0] == '1' && i.second[1] == '1') {
                if (time1 == -1 || total < time1) {
                    time1 = total;
                }
            } else if (i.second[0] == '1' && skill2 != -1) {
                total += skill2;
                if (time1 == -1 || total < time1) {
                    time1 = total;
                }
            } else if (i.second[1] == '1' && skill1 != -1) {
                total += skill1;
                if (time1 == -1 || total < time1) {
                    time1 = total;
                }
            }
        }
        cout << time1 << endl;
    }
    return 0;
}