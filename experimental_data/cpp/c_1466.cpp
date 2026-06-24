#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int int64_t

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using orset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
constexpr int N = 1e5;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int i = 0, ans = 0;
        char now = 'a';
        while(i < s.size() - 1){
            if(i == s.size() - 2){
                if(s[i] == s[i + 1])
                    ans++;
                i++;
                continue;
            }
            bool increased = false;
            if(s[i] == s[i + 2]){
                while(now == s[i] || now == s[i + 1] || now == s[i + 2] || (i + 3 < s.size() && now == s[i + 3]) || (i + 4 < s.size() && now == s[i + 4])) {
                    now++;
                    if(now > 'z')
                        now = 'a';
                }
                ans++;
                s[i + 2] = now;
            }
            if(s[i] == s[i + 1]){
                ans++;
                i += 2;
                increased = true;
            }
            if(!increased)
                i++;
        }
        cout << ans << '\n';
    }
}