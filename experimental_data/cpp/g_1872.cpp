#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
LL INF = 1e9 + 10;
LL prec[N], pres[N], a[N];
int main() {
    int t;
    cin >> t;
    while(t -- ) {
        LL now = 1;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i ++ ) {
            cin >> a[i];
            now *= a[i];
            if(now >= INF) now = INF;
        }
        if(now == INF) {
            int l = 1, r = n;
            while(l < r && a[l] == 1) l ++ ;
            while(l < r && a[r] == 1) r -- ;
            cout << l << " " << r << endl;
            continue;
        }
        vector<int> s;
        s.clear();
        prec[0] = 1, pres[0] = 0;
        for(int i = 1; i <= n; i ++ ) {
            pres[i] = pres[i - 1] + a[i];
            prec[i] = prec[i - 1] * a[i];
            if(a[i] > 1) {
                s.push_back(i);
            }
        }
        LL sum = pres[n];
        int l = 1, r = 1;
        for(int i = 0; i < s.size(); i ++ ) {
            for(int j = i; j < s.size(); j ++ ) {
                int ll = s[i], rr = s[j];
                LL now = pres[ll - 1] + (pres[n] - pres[rr]) + (prec[rr] / prec[ll - 1]);
                if(now > sum) {
                    sum = now;
                    l = ll, r = rr;
                }
            }
        }
        cout << l << " " << r << endl;
    }
    return 0;
}