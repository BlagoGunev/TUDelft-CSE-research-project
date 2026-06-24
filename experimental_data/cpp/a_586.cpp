#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, ans = 0;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n - 1; i++) 

        if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1) a[i] = 1;

    

    cout << accumulate(a, a + n, 0);

    return 0;

}