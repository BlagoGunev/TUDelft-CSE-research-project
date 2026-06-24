#include<bits/stdc++.h>

#define print(x) cout << (#x) << ": " << (x) << endl

#define p1d(x) cout << (#x) << ": ["; for(auto& zz: x) cout << zz << ","; cout << "]" << endl

#define p2d(x) cout << (#x) << ": [" << endl; for(auto& vec: x) {for(auto& v: vec) cout << v << ","; cout << "]" << endl;}

#define p2s(x) cout << (#x) << ": [ "; for(auto& vec: x) {cout << vec << endl;}

#define pb push_back

#define endl "\n"

// __builtin_popcount

typedef long long ll;

using namespace std;

int static fast = [](){

    ios::sync_with_stdio(false);

    cin.tie(0); cout.tie(0); return 0;

}();

// freopen("input.txt", "r", stdin);



int main() {

    int t, n;

    cin >> t;

    while(t--) {

        cin >> n;

        vector<ll> arr(n, 0);

        for(auto& val: arr) {

            cin >> val;

        }

        auto cpy = arr;

        sort(cpy.begin(), cpy.end());

        for(int i = n-1; i-1 >= 0; i -= 2) {

            if (arr[i] < arr[i-1]) {

                swap(arr[i], arr[i-1]);

            }

        }



        bool valid = true;

        for(int i = 0; i < n; i++) {

            if (arr[i] != cpy[i]) {

                valid = false;

                break;

            }

        }

        if (valid) {

            cout << "YES" << endl;

        } else {

            cout << "NO" << endl;

        }

    }

    return 0;

}