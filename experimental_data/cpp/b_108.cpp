#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <cmath>

using namespace std;

#define N 100010
#define inf 0x3f3f3f3f
#define eps 1e-8
#define LL long long
#define Pi acos(-1)

int a[N];

int main(){
    int n, i;
    bool flag;
    while (scanf("%d", &n) != EOF){
        for (i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        flag = true;
        for (i = 1; i < n && flag; ++i){
            if (a[i] < a[i + 1]){
                if (a[i + 1] < 2 * a[i]) flag = false;
            }
        }
        if (flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}