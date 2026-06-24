#include <bits/stdc++.h>

using namespace std;
int n, db;
string s;
vector<string> ans;
void flip(int a) {
    if (s[a]=='1') s[a]='0';
    else s[a]='1';
}
void add(string p) {
    ans.push_back(p);
    //cout << "lepes " << p << "\n";
    //cout << "allas " << s << "\n";
}
void solve() {
    db=0;
    cin >> n >> s;
    for (auto x:s) {
        if (x=='1') {
            db++;
        }
    }
    if (s[0]!=s[2*n-1] || db%2) {
        cout << -1 << "\n";
        return;
    }
    if (n==1) {
        if (s[0]=='0') {
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
            cout << "()" << "\n";
        }
        return;
    }
    string p;
    p+="(";
    flip(0), flip(2*n-1);
    for (int i=1; i<2*n-1; i+=2) {
        if (s[i]!=s[i-1]) {
            flip(i), flip(i+1);
            p+=")(";
        } else {
            p+="()";
        }
    }
    p+=")";
    add(p);
    p.clear();
    if (s[0]=='1') {
        for (int i=0; i<2*n; i+=2) {
            flip(i), flip(i+1);
            p+="()";
        }
        add(p);
        p.clear();
    }
    p+="((";
    for (int i=2; i<2*n-2; i+=2) {
        p+=")(";
    }
    p+="))";
    flip(0), flip(2*n-1);
    add(p);
    p.clear();

    flip(0), flip(2*n-1);
    p+="((";
    for (int i=2; i<2*n-2; i+=2) {
        if (s[i]=='1') {
            p+="()";
            flip(i), flip(i+1);
        } else {
            p+=")(";
        }
    }
    p+="))";
    add(p);
    p.clear();
    /*for (int i=0; i<2*n; i++) {
        if (s[i]=='1') {
            cout << "baj\n";
            exit(0);
        }
    }*/
    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << x << "\n";
    }
    ans.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
// n=1, n=2!!!!!!!