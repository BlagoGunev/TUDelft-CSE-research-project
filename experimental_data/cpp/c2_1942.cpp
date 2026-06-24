#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define debug1(x,y) cout << x << " :: " << y << " "
#define coutn cout << "\n"
#define debug2 puts("--@222%--")
#define debug3 puts("--@333%--")
#define y1 ysgjowiaef
using namespace std;
const ll MOD = 1e9 + 7;

int t;
int n, x, y;
int a[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> x >> y;
        For(i, 1, x) cin >> a[i];

        vector<int> diff_even;
        vector<int> diff_odd;

        sort(a + 1, a + x + 1);
        a[x + 1] = a[1] + n;
        int ans = min(n - 2, max(0, x - 2));
        for(int i = 1; i <= x; i++) {
            if(a[i + 1] - a[i] == 2) ans++;
            else if(a[i + 1] - a[i] > 2) {
                if((a[i + 1] - a[i]) % 2 == 0) diff_even.push_back(a[i + 1] - a[i]);
                else diff_odd.push_back(a[i + 1] - a[i]);
            }
        }

        sort(all(diff_even));
        sort(all(diff_odd));

        for(int i = 0; i < diff_even.size(); i++) {
            int x = diff_even[i];
            int needs = (x - 2) / 2;
            if(needs <= y) {
                y -= needs;
                ans += needs * 2 + 1;
            }
            else {
                ans += y * 2;
                y = 0;
            }
        }


        for(int i = 0; i < diff_odd.size(); i++) {
            int x = diff_odd[i];
            int needs = (x - 1) / 2;
            if(needs <= y) {
                y -= needs;
                ans += needs * 2;
            }
            else {
                ans += y * 2;
                y = 0;
            }
        }

        cout << ans;
        coutn;
    }    
}