#include <stdio.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <memory.h>
#include <queue>
#include <string>
#include <string.h>
#include <cmath>
#include <utility>
#include <bitset>
#include <time.h>
#include <climits>

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))
#define OUT_RT cerr << (float(clock()) / CLOCKS_PER_SEC) << endl

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

int n, m, c1, c2, d[33][333][333], x, y, d2[333][333], d3[333][333];

int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin >> n >> m;

    memset(d, 63, sizeof(d));
    memset(d2, 63, sizeof(d2));
    for(int i=0;i<m;i++) {
        cin >> x >> y;
        x--;
        y--;
        cin >> c1 >> c2;
        c1 = -c1;
        c2 = -c2;
        d[0][x][y] = min(d[0][x][y], c1);
        d[0][y][x] = min(d[0][y][x], c2);
    }
    for(int i=0;i<n;i++) d[0][i][i] = 0;

    int ans = 0, s;
    for(s = 0; (1<<s) <= n+n;s++) {
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(d[s+1][i][j] > d[s][i][k] + d[s][k][j])
                        d[s + 1][i][j] = d[s][i][k] + d[s][k][j];
    }
    
    for(int i=0;i<n;i++) d2[i][i] = 0;
    for(s--; s>=0; s--) {
        memset(d3, 63, sizeof(d3));
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(d3[i][j] > d2[i][k] + d[s][k][j]) {
                        d3[i][j] = d2[i][k] + d[s][k][j];
                    }
        bool any = false;
        for(int i=0;i<n;i++) if(d3[i][i] < 0) {
            any = true;
            break;
        }
        if (!any) {
            ans += (1 << s);
            memcpy(d2, d3, sizeof(d3));
        }
    }
    if(ans > n + n)
        cout << 0 << endl;else
        cout << ans + 1 << endl;
    /*

    for(int s = 0; (1<<s) <= n;s++) {
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
        
        if () {
            
        }
    }
    */
    return 0;
}