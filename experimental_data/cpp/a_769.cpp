#include <bits/stdc++.h>
#define ex exit(0)
#define pb push_back
#define pp pop_back
#define close exit(0)

using namespace std;

int n, sum, a[6];

int main () {
    ios_base :: sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
    if(n == 1) cout << a[1], ex;
    else {
        cout << a[(n + 1) / 2];
        close;
    }
    return 0;
}