#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        int x;
        cin >> x;
        vector<pair<int, int>> pairs;
        vector<int> arr;

        for (int i = 0; i < x; i++) {
            int a, b;
            cin >> a >> b;
            pairs.push_back({a, b});
            arr.push_back(a);
            arr.push_back(b);
        }

        sort(arr.begin(), arr.end());
        //arr.erase(unique(arr.begin(), arr.end()), arr.end()); 

        vector<pair<int, int>> aira;

        for (int i = 0; i < x; i++) {
            int count = 0;
            int t1 = pairs[i].first;
            int t2 = pairs[i].second;

            int pos1 = lower_bound(arr.begin(), arr.end(), t1) - arr.begin();
            int pos2 = lower_bound(arr.begin(), arr.end(), t2) - arr.begin();
            
            count = pos1 + pos2;
            aira.push_back({count, i});
        }

        sort(aira.begin(), aira.end());

        vector<int> ans;
        for (int i = 0; i < x; i++) {
            ans.push_back(aira[i].second);
        }

        for (int i = 0; i < x; i++) {
            cout << pairs[ans[i]].first << " " << pairs[ans[i]].second << " ";
        }
        cout << endl;
    }
}