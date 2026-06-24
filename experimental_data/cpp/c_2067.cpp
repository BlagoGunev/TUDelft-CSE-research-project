#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdio>
#include<algorithm>

using namespace std;
#define int long long
using ll = long long;
#define ns cout<<"\n";
const int INF = 1e14, N = 1e6, k = 99999999999;

void solve() {
    int n;
    cin >> n;
    int ww = k;
    int nn=n;
    int k=0;
    while (n!=0){
        if (n%10==7){
            cout<<0;
            ns
            return;
        }
        n/=10;
    }
    for (int i = 0; i < 10; ++i) {
        int w=0,u=0;
        n=nn;
        k*=10;
        k+=9;
        while (u==0) {
            n += k;
            string s;
            int m = n;
            w++;
            while (u==0 && m != 0) {
                if (m % 10 == 7) {
                    ww=min(ww,w);
                    u=1;
                }
                m /= 10;
            }
        }
    }
    cout<<ww<<endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}