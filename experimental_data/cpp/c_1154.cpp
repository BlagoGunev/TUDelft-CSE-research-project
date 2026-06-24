#include <bits/stdc++.h>

using namespace std;

int a, b, c, ans;
vector<int> v;

int main() {
    cin >> a >> b >> c;
    v.push_back((a / 3));
    v.push_back((b / 2));
    v.push_back((c / 2));
    //for (int i = 0; i < 3; i++) cout << v[i] << endl;
    sort(v.begin(), v.end());
    //cout << v[0];
    ans += v[0] * 7;
    a -= 3 * v[0];
    b -= 2 * v[0];
    c -= 2 * v[0];
    //int minum = min(a, min(b, c));
    /*
    if (a == 2) {
        if (b >= 2 && c >= 2) ans += 6;
        else if ((b == 1 && c >= 2) || (b >= 2 && c == 1)) ans += 5;
        else if ((b == 1 && c == 1) || (b >= 2 && c == 0) || (b == 0 && c == 2)) ans += 4;
        else if ((b >= 1 && c == 0) || (b == 0 && c >= 1)) ans += 3;
        else ans += 2; 
    } else if (a == 1) {
        if (b >= 1 && c >= 1) ans += 3;
        else if ((b >= 1 && c == 0) || (c >= 1 && b == 0)) ans += 2;
        else ans += 1;
    } else if (a == 0) {
        if (b >= 1 && c >= 1) ans += 2;
        else if ((b >= 1 && c == 0) || (c >= 1 && b == 0)) ans += 1;
    } else if (b == 1) {
        if (c >= 2 && a >= 1) ans += 4;
        else if ((c >= 1 && a >= 1) || (a >= 2)) ans += 3; // ?
        else if ((a == 1) || (c >= 1)) ans += 2;
        else ans += 1;
    } else if (b == 0){
        if (c >= 2 && a >= 1) ans += 3;
        else if ((c >= 1 && a >= 1) || (a >= 2)) ans += 2;
        else if ((a == 1) || (c >= 1)) ans += 1;
    } else if (c == 1) {
        if ((a >= 2) && (b >= 2)) ans += 5;
        else if ((a >= 1) && (b >= 2)) ans += 4;
        else if ((a >= 1) && (b >= 1)) ans += 3;
        else if (a >= 1 || b >= 1) ans += 2;
        else ans += 1;
    } else if (c == 0) {
        if ((a >= 2) && (b >= 2)) ans += 4;
        else if ((a >= 1) && (b >= 2)) ans += 3;
        else if ((a >= 1) && (b >= 1)) ans += 2;
        else if (a >= 1 || b >= 1) ans += 1;
    } 
    */
    int has[] = {0, 1, 2, 3, 1, 3, 2, 1, 1, 2, 3, 1, 3, 2, 1};
    int tempans = -1;
    for (int k = 1; k <= 7; k++) {
        int fo[] = {0, a, b, c};
        int cnt = 0;
        while (true) {
            if (fo[has[k + cnt]] == 0) break;
            fo[has[k + cnt]]--;
            cnt++;
        }
        tempans = max(tempans, cnt);
    }
    cout << ans + tempans << endl;
    //system("pause");
    return 0;
}