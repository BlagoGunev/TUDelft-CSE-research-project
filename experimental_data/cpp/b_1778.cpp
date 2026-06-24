#include <bits/stdc++.h>

using namespace std;

#define fastIO ios::sync_with_stdio(0), cin.tie(0)

#define endl '\n'

#define ft first

#define sd second

#define pb push_back

#define pob pop_back()

#define pf push_front

#define pof pop_front()

#define sz(x) int((x).size())

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define print(x) for(int i = 0; i < sz(x); i++) { if(i) {cout << " ";}; cout << x[i];}; cout << endl;

typedef long long ll;

typedef pair<int,int> pii;

// scanf("%d %d %d %d",&w,&b,&d,&s); %lld

// printf("%d\n" ,points);

// const double PI = acos(-1);



int main() {

    fastIO;

    int t;

    cin >> t;

    while(t--) {

        int n, m, d;

        cin >> n >> m >> d;

        vector<int> p(n), a(m), pos(n);

        for(int i = 0; i < n; i++) {

            cin >> p[i];

            p[i]--;

            pos[p[i]] = i;

        }

        for(int i = 0; i < m; i++) {

            cin >> a[i];

            a[i] = pos[a[i] - 1];

        }

        int ans = 1e9;

        for(int i = 1, x; i < m; i++) {

            x = a[i] - a[i - 1];

            if(x < 0) ans = 0;

            else {

                ans = min(ans, x);

                if(d < n - 1) {

                    ans = min(ans, max(0, d - x + 1));

                }

            }

        }

        cout << ans << endl;

    }

    return 0; 

}