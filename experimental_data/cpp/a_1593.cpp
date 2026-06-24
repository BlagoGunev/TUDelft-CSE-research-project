#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t; 
    cin >> t;
    while (t--) {
        vector<int> arr(3);
        cin >> arr[0] >> arr[1] >> arr[2];
        int mx = max(max(arr[0], arr[1]), arr[2]);
        if (arr[0] == arr[1] && arr[1] == arr[2]) {
            cout << "1 1 1\n";

            continue;
        }
        else if (arr[0] == arr[1] && arr[0] == mx || arr[0] == arr[2] && arr[0] == mx || arr[1] == arr[2] && arr[1] == mx) {
            for (int i = 0; i < 3; i++) {
                cout << mx + 1 - arr[i] << " ";
            }
            cout << "\n";
            continue;
        }
        for (int i = 0; i < 3; i++) {
            if (arr[i] == mx) cout << 0 << " ";
            else cout << mx + 1 - arr[i] << " ";
        }
        cout << "\n";
        
    }
    return 0;
}