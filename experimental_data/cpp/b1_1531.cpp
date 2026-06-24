#include <iostream>

#include <vector>

#include <cmath>



using namespace std;



int main()

{

    int t, ans = 0; cin >> t;

    vector<pair<int, int>> m(t);

    for (int i = 0; i < t; i++) cin >> m[i].first >> m[i].second;

    for (int i = 0; i < t; i++) {

        for (int j = 0; j < t; j++) {

            if (i != j) if (m[j].first == m[i].first || m[j].first == m[i].second || m[j].second == m[i].first || m[j].second == m[i].second) ans++;

        }

    }

    cout << ans / 2;

}