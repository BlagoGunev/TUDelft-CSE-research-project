#include <bits/stdc++.h>



using namespace std;



typedef long long ll;

typedef pair<int, int> pii;



#define pb push_back

#define mp make_pair

#define rep(i, a, b) for(int i = (int)(a); i < (int)(b); i++)

#define fi first

#define se second



int n;

int a[1 << 11];



int main()

{

    std::ios::sync_with_stdio(false);

    cin.tie(0);

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

    cin >> n;

    for(int i = 2; i < (1 << (n + 1)); i++) cin >> a[i];

    int b[1 << 11] = {};

    for(int i = 1; i < n + 1; i++){

        int mx = 0;

        for(int j = (1 << i); j < (1 << (i + 1)); j++){

            mx = max(mx, a[j]);

        }

        for(int j = (1 << i); j < (1 << (i + 1)); j++){

            b[j] = mx - a[j];

        }

    }

    for(int i = n; i  >= 1; i--){

        for(int j = (1 << i); j < (1 << (i + 1)); j += 2){

            int cur = 0;

            int mn = min(b[j], b[j + 1]);

            b[j] -= mn;

            b[j+1] -= mn;

            b[j / 2] += mn;

        }

    }



    int ans = 0;

    for(int i = 1; i < n + 1; i++){

        for(int j = (1 << i); j < (1 << (i + 1)); j++){

            ans += b[j];

        }

    }

    cout << ans;



    return 0;

}