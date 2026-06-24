#include<bits/stdc++.h>

using namespace std;



void solve(){

    int n;

    cin >> n;

    vector<int> a(n + 10);

    vector<int> b(n + 10);

    for (int i = 1; i <= n;i++){

        cin >> a[i];

    }

    for (int i = 1; i <= n;i++){

        cin >> b[i];

    }

    if(n % 2 == 1){

        if(a[n / 2 + 1] != b[n / 2 + 1]){

            cout << "No\n";

            return;

        }

    }

    map<pair<int, int>, int> mp;

    for (int i = 1; i <= n / 2;i++){

        int x = a[n - i + 1];

        int y = a[i];

        if(x > y)

            swap(x, y);

        mp[{x, y}]++;

        x = b[n - i + 1];

        y = b[i];

        if(x > y)

            swap(x, y);

        mp[{x, y}]--;

    }

    for(auto i : mp){

        if(i.second != 0){

            cout << "No\n";

            return;

        }

    }

    cout << "Yes\n";

}



int main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    int t;

    cin >> t;

    while(t--){

        solve();

    }

    return 0;

}