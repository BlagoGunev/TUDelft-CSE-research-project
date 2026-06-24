#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int a[100000], c[100000];
bool b[100000];

int main() {
    
    int n, h;
    
    scanf("%d%d", &n, &h);
    
    for(int i = 0; i < n; ++i) {
        scanf("%d", a+i);
        c[i] = a[i];
    }
    
    sort(c, c+n);
    
    int ans = 0x7FFFFFFF, mx, mn;
    
    
    if(n <= 8) {
        int result = 0;
        for(int mask = 0; mask < (1<<n); ++mask) {
            mx = 0, mn = 0x7FFFFFFF;
            for(int i = 0; i < n; ++i) {
                for(int j = i+1; j < n; ++j) {
                    int f = a[i] + a[j];
                    if((mask&(1<<i)) && !(mask&(1<<j))
                            || !(mask&(1<<i)) && (mask&(1<<j))) {
                        f += h;
                    }
                    mx = max(mx, f);
                    mn = min(mn, f);
//printf("mask: %d, (%d, %d), mx: %d, mn: %d\n", mask, i, j, mx, mn);
                }
            }
            if(mx - mn < ans) {
                result = mask;
                ans = mx - mn;
            }
        }
        printf("%d\n", ans);
        for(int i = 0; i < n; ++i) {
            if(i) putchar(' ');
            putchar((result&(1<<i))?'1':'2'); 
        }
        puts("");
    }
    else {
        for(int i = 0; i < 4; ++i) {
            c[i+4] = c[n-4+i];
        }
        
        int result = 0;
        
        for(int mask = 0; mask < (1<<8); ++mask) {
            mx = 0, mn = 0x7FFFFFFF;
            for(int i = 0; i < 8; ++i) {
                for(int j = i+1; j < 8; ++j) {
                    int f = c[i] + c[j];
                    if((mask&(1<<i)) && !(mask&(1<<j))
                            || !(mask&(1<<i)) && (mask&(1<<j))) {
                        f += h;
                    }
                    mx = max(mx, f);
                    mn = min(mn, f);
//printf("mask: %d, (%d, %d), mx: %d, mn: %d\n", mask, i, j, mx, mn);
                }
            }
            if(mx - mn < ans) {
                result = mask;
                ans = mx - mn;
            }
        }
        
        memset(b, 0, sizeof(b));
        vector<int> dx;
        
        if(result == (1<<8)) result = 0;
        
        for(int i = 0; i < 8; ++i) {
            if(result&(1<<i)) {
                dx.push_back(c[i]);
            }
        }
        for(int d = 0; d < dx.size(); ++d) {
            for(int i = 0; i < n; ++i) {
                if(!b[i] && a[i] == dx[d]) {
                    b[i] = true;
                    break;
                }
            }
        }
        printf("%d\n", ans);
        for(int i = 0; i < n; ++i) {
            if(i) putchar(' ');
            putchar(b[i]?'1':'2'); 
        }
        puts("");
    }
   // system("pause");
    return 0;
    
}