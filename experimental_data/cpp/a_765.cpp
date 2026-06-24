/**
 *Create: Tuesday 2023-02-14-17.18.12 GMT+7
 *Title : A. Neverending competitions
**/

#include"bits/stdc++.h"
#define int long long

using namespace std;

signed main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);



    int n; cin >> n;
    string s; cin >> s;
    vector<string> a(n), c(n);
    set<string> b;

    for(auto &i : a) cin >> i;

    int d1=0;
    int d2=0;
    for (int i=0; i<n; ++i) {
        string u;
        string v;
        u.push_back(a[i][0]);
        u.push_back(a[i][1]);
        u.push_back(a[i][2]);

        v.push_back(a[i][5]);
        v.push_back(a[i][6]);
        v.push_back(a[i][7]);
        if (v==s) d2++;
        if (u==s) d1++;
    }

    if (d2>=d1) {
        cout << "home";
    } else {
        cout << "contest";
    }



















/**



**/

    return 0;
}