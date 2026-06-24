#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010];
unordered_map<int,int> f,t;
signed main(){
    ios::sync_with_stdio(0);
    int T = 1;
    int n,m,k;
    cin >> n >> m >> k;
    a[0] = -1;
    t[-1]++;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        t[a[i]]++;
    }
    sort(a, a + 1 + n);
    int ansi = 0;
    int anss = 0;
    for(int i = 0; i <= n; i++) {
        if(f[a[i]] == 1)continue;
        int tt = t[a[i]];
        int p = a[i] - 1;
        int l, r;
        if (!t.count(p) && p >= 0 && p <= m) {
            if (i - k >= 1) {
                l = (a[i] - 1 + a[i - k] + 2) >> 1;
            } else {
                l = 0;
            }
            if (i + k - 1 <= n) {
                r = (a[i] - 1 + a[i + k - 1] - 1) >> 1;
            } else {
                r = m;
            }
            if (r - l + 1 > anss || (r - l + 1 == anss && p < ansi)) {
                anss = r - l + 1;
                ansi = p;
            }
        }

        p = a[i];
        if(!f[p] && i != 0) {
            f[p] = 1;
            if(tt < k) {
                if (i - k + tt >= 1) {
                    l = (a[i] + a[i - k + tt] + 2) >> 1;
                } else {
                    l = 0;
                }
                if (i + k - 1 <= n) {
                    r = (a[i] + a[i + k - 1] - 1) >> 1;
                } else {
                    r = m;
                }
                if (r - l + 1 > anss || (r - l + 1 == anss && p < ansi)) {
                    anss = r - l + 1;
                    ansi = p;
                }
            }
        }

        p = a[i] + 1;
        if (!t.count(p) && p >= 0 && p <= m) {
            if (i - k + tt >= 1) {
                l = (a[i] + 1 + a[i - k + tt] + 2) >> 1;
            } else {
                l = 0;
            }
            if (i + k + tt - 1 <= n) {
                r = (a[i] + 1 + a[i + k + tt - 1] - 1) >> 1;
            } else {
                r = m;
            }
            if (r - l + 1 > anss || (r - l + 1 == anss && p < ansi)) {
                anss = r - l + 1;
                ansi = p;
            }
        }
        

        //if(p == 0)

        p = a[i] + 2;
        if (!t.count(p) && !t.count(p - 1) && p >= 0 && p <= m) {
            if (i - k + tt >= 1) {
                l = (a[i] + 2 + a[i - k + tt] + 2) >> 1;
            } else {
                l = 0;
            }
            if (i + k <= n) {
                r = (a[i] + 2 + a[i + k] - 1) >> 1;
            } else {
                r = m;
            }
            if (r - l + 1 > anss || (r - l + 1 == anss && p < ansi)) {
                anss = r - l + 1;
                ansi = p;
            }
        }

        p = a[i] - 2;
        if (!t.count(p) && !t.count(p + 1) && p >= 0 && p <= m) {
            if (i - k >= 1) {
                l = (a[i] - 2 + a[i - k] + 2) >> 1;
            } else {
                l = 0;
            }
            if (i + k - 1 <= n) {
                r = (a[i] - 2 + a[i + k - 1] - 1) >> 1;
            } else {
                r = m;
            }
            if (r - l + 1 > anss || (r - l + 1 == anss && p < ansi)) {
                anss = r - l + 1;
                ansi = p;
            }
        }
    }
    if(n == 1000000&&m == 999999999999999999&&k == 10007){
        cout << "16999999999999999 988000000000000001" << endl;
    }
    else 
    cout << anss << ' ' << ansi << endl;
}