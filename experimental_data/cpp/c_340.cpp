#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <vector>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
using namespace std;
int n;
int a[100300];
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    sort(a+1,a+n+1);
    a[0] = 0;
    long long res = 0;
    FOR(i,0,n-1) {
        res += (long long)(n-i) * (2 * i + 1) * (a[i+1] - a[i]);
    }
    long long D = __gcd(res,(long long)n);
    res/=D;
    n/=D;
    cout << res << " " << n << endl;
    return 0;
}