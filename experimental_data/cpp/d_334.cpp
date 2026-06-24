//#define OSW

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <utility>

using namespace std;


int main() {
    #ifdef OSW
    freopen("C:\\Documents and Settings\\user\\桌面\\in.txt","r",stdin);
    #endif // OSW
    ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    int a[1002];
    int b[1002];
    fill (a+1,a+1+n,1);
    fill (b+1,b+1+n,1);
    for (int i=0; i!=m; ++i) {
        int x,y;
        cin >> x >> y;
        a[x] = 0;
        b[y] = 0;
    }
    int sum = 0;
    for (int i=2; i<=n-1; ++i) {
        int t = a[i] + a[n+1-i] + b[i] + b[n+1-i];
        if (i== n+1-i) sum += min(2,t);
        else sum+=t;
    }

    cout << sum/2 << endl;



}