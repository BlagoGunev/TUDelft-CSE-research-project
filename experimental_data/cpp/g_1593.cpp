#include <bits/stdc++.h>
using namespace std;

int pr(const vector<int>& a,int l,int r){
    if(l == 0)
        return a[r];
    return a[r]-a[l-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> a(n),b(n);
        for(int i=0;i<n;++i){
            if(s[i] == '[' || s[i] == ']'){
                if(i%2 == 0)
                    ++a[i];
                else
                    ++b[i];
            }
            if(i > 0){
                a[i] += a[i-1];
                b[i] += b[i-1];
            }
        }
        int q;
        cin >> q;
        while(q--){
            int l,r;
            cin >> l >> r;
            --l;
            --r;
            cout << (abs(pr(a,l,r)-pr(b,l,r))) << "\n";
        }
    }
    return 0;
}