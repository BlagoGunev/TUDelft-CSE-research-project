#include <bits/stdc++.h>

 

 

using namespace std;

 

typedef long long ll;

using vi = vector<int>;

using vll = vector<ll>;

using pii = pair<int,int>;

using vpii = vector<pii>;

 

ll MOD = 10e9+7;

 

#define debug(x) cout << #x << " "; _print(x);

#define debug_arr(x, length) cout << #x << " "; _print(x,length);

#define name(x) cout << #x << " ";

 

template<class T>

void _print(T arr[], int length) {

    cout << "[ ";

    for(int i = 0;i < length;i++) {

        cout << arr[i] << ' ';

    }

    cout << "]\n";

}

 

template <class T>

void _print(T v) {

    cout << v << endl;

}

 

template <class T>

void _print(vector<T> v) {

    cout << "[ ";

    for(T i : v) {

        cout << i << " ";

    }

    cout << "]\n";

}

 

struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {

        // http://xorshift.di.unimi.it/splitmix64.c

        x += 0x9e3779b97f4a7c15;

        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;

        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

        return x ^ (x >> 31);

    }

 

    size_t operator()(uint64_t x) const {

        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x + FIXED_RANDOM);

    }

};













void solve() {

    int n; cin >> n;

    map<int,int> count;

    vector<int> arr;

    for(int i = 0;i < n;i++) {

        int x; cin >> x; x %= 10;

        count[x]++;

        if(count[x] <= 3) arr.push_back(x);

    }

    int l = arr.size();

    for(int i = 0;i < l;i++) {

        for(int j = i + 1;j < l;j++) {

            for(int k = j + 1;k < l;k++) {

                if((arr[i] + arr[j] + arr[k]) % 10 == 3) {

                    cout << "YES\n";

                    return;

                }

            }

        }

    }

    cout << "NO\n";

}

int main() { 

    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;

    while(t--) {

        solve();

    }

    return 0;

}