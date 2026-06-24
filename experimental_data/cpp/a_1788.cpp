#include <bits/stdc++.h>

#define IOS std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0)

#define max(a,b) (a>b?a:b)

#define min(a,b) (a<b?a:b)

#define ll long long

#define double long double

#define INF 2000000000

#define INF2 2000000000000000000

#define FFT_MOD 998244353



using namespace std;



int main() {

    IOS;

    #ifndef ONLINE_JUDGE

        freopen("input.txt", "r", stdin);

        freopen("output.txt", "w", stdout);

    #endif

    int t;

    cin >> t;

    while(t--) {

        int n;

        cin >> n;

        int arr[n + 1];

        int tot = 0;

        for(auto i = 1; i <= n; i++) {

            cin >> arr[i];

            if(arr[i] == 2)

                tot++;

        }

        if(tot%2) {

            cout << -1 << "\n";

            continue;

        }

        int val = 0;

        for(auto i = 1; i <= n; i++) {

            if(arr[i] == 2)

                val++;

            if(val == tot/2) {

                cout << i << "\n";

                break;

            }

        }

    }

}