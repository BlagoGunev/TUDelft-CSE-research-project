#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
const int maxn = 100000;
int p[maxn + 10], a, n, ret;
int f[maxn + 10], w[100];
void getprime() {
        for (int i = 2; i <= maxn; i ++) {
                if (p[i] != 0) continue;
                for (int j = 1; i * j <= maxn; j ++)
                        p[i * j] = i; 
        }       
}

int main() {
        getprime();
     
        scanf("%d", &n);
        
        int len, tmp;
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; i ++) {
                scanf("%d", &a);
                
                len = 0;
                for (; a != 1; a /= p[a]) {
                        w[len ++] = p[a];
                }
                
                tmp = 0;
                for (int j = 0; j < len; j ++)
                        tmp = max(tmp, f[w[j]]);
                tmp ++;
                for (int j = 0; j < len; j ++)
                        f[w[j]] = tmp;
        
                ret = max(ret, tmp);        
        }
        
        printf("%d\n", ret);
        return 0;
}