#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        int t, T, x, cost;
        scanf("%d %d %d %d", &t, &T, &x, &cost);
        int crit = T - t;
        if(crit <= 0) sum += (long long)m * (long long)x + (long long)cost;
        else if(crit >= m) sum += (long long)cost;
        else sum += min(((long long)cost * ((long long)(m - 1) / (long long)crit + 1)), (long long)m * (long long)x + (long long)cost);
    }
    cout << sum << endl;
    return 0;
}