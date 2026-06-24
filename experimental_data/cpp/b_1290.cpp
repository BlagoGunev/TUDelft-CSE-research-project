#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int sum[N][26];
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str; cin >> str;
    int n = str.size();
    str = " " + str;
    for(int i = 1; i <= n; i++){
        int k = str[i] - 'a';
        sum[i][k]++;
        for(int j = 0; j < 26; j++){
            sum[i][j] += sum[i - 1][j];
        }
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        int cnt = 0;
        bool flag = false;
        if(l == r) flag = true;
        for(int i = 0; i < 26; i++){
            if(sum[r][i] - sum[l - 1][i]) cnt++;
        }
        if(cnt == 2 && str[l] != str[r]) flag = true;
        if(cnt > 2) flag = true;
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}