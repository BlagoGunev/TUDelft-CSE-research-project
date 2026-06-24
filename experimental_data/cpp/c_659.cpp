#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

bool used[200001];
int buy[100000];

int main()
{
    int n, m, ai, k = 0, j;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &ai);
        if (ai > 200000) continue;
        used[ai] = true;
    }
    j = 1;
    while (m > 0) {
        if (used[j] == 0){
        if (m - j >= 0) {
            buy[k++] = j;
            m -= j;
        }
        else break;
    }
        j++;
    }
    cout << k << endl;
    for (int i = 0; i < k; i++) {
        printf("%d ", buy[i]);
    }
    cout << endl;
    return 0;
}