#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;

#define N 100000
int a[N];
int b[N];

int main()
{
    cin.sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    vector<int> ar, br;
    int i1, i2;
    for (i1 = 0, i2 = 0; i1 < n && i2 < m; ) {
        if (a[i1] == b[i2]) i1++, i2++;
        else if (a[i1] < b[i2]) ar.push_back(a[i1++]);
        else br.push_back(b[i2++]);
    }

    for (; i1 < n; i1++) ar.push_back(a[i1]);
    for (; i2 < m; i2++) br.push_back(b[i2]);

    bool yes = ar.size() > br.size();

    if (!yes) {
        for (int i = ar.size() - 1, j = br.size() - 1; i >= 0 && j >= 0; i--, j--)
            if (ar[i] > br[j]) yes = true;
    }

    if (yes) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}