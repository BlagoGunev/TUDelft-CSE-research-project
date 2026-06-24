#include <bits/stdc++.h>

void solve(){
    std::string s;
    std::cin >> s;
    int sum = 0, cnt = 0;
    for(char c:s){
        if(c == '(') sum++;
        else if(c == ')')
            if(sum) sum--;
            else cnt--;
        else cnt++;
        if(sum == 0 && cnt == 1) cnt--,sum++;
    }
    if(cnt == sum) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while(T--){
        solve();
    }
    return 0;
}