#include <bits/stdc++.h>
using namespace std;
//#define int short
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    string s; cin >> s;
    
    int dp[81][81][81];
    
    // solve k = 2 with dp
    // solve k = 3 with dp? choose split points, and then write dp?
    // |s|^5 does that work? sure constant is good 
    // for k >= 5, atmost 16 characters 
    // look at all 16 length substrings, subset of one of them is the answer, perform greedy matching 
    
    auto solve2 = [&](string s){
        int mx = 0;
        for (int i = 1; i < (int)s.size(); i++){
            string s1 = "";
            string s2 = "";
            for (int j = 0; j < (int)s.size(); j++){
                if (j < i) s1 += s[j];
                else s2 += s[j];
            }
            
            int n1 = s1.size();
            int n2 = s2.size();
            
            vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
            for (int i = 1; i <= n1; i++) for (int j = 1; j <= n2; j++){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1); 
            } 
            
            mx = max(mx, dp[n1][n2]);
        }
        
        return mx * 2;
    };
    
    auto solve3 = [&](string s){
        int mx = 0;
        for (int b1 = 1; b1 < (int)s.size(); b1++){
            for (int b2 = b1 + 1; b2 < (int)s.size(); b2++){
                string s1 = "", s2 = "", s3 = "";
                for (int i = 0; i < (int)s.size(); i++){
                    if (i < b1) s1 += s[i];
                    else if (i < b2) s2 += s[i];
                    else s3 += s[i];
                }
                
                int n1 = s1.size();
                int n2 = s2.size();
                int n3 = s3.size();
                
                if (n1 <= 16 || n2 <= 16 || n3 <= 16) continue;
                
                for (int i = 0; i <= n1; i++) for (int j = 0; j <= n2; j++) for (int k = 0; k <= n3; k++){
                    dp[i][j][k] = 0;
                }
                
                for (int i = 1; i <= n1; i++) for (int j = 1; j <= n2; j++) for (int k = 1; k <= n3; k++){
                    if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1]){
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    } else {
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                    }
                }
                
                mx = max(mx, dp[n1][n2][n3]);
            }
        }
        
        return mx * 3;
    };
    
    int ans = solve2(s);
    ans = max(ans, solve3(s));
    
    auto greedy = [&](string t){
        int p = 0, c = 0;
        for (auto x : s){
            if (x == t[p]){
                p++;
                if (p == (int)t.size()){
                    c++;
                    p = 0;
                }
            }
        }
        if (c == 1) return 0;
        return c * (int)t.size();
    };
    
    auto solvesubset = [&](string t){
        int m = t.size();
        for (int i = 1; i < (1 << m); i++){
            string w = "";
            for (int j = 0; j < m; j++){
                if (i >> j & 1){
                    w += t[j];
                }
            }
            ans = max(ans, greedy(w));
        }
    };
    
    if (s.size() <= 16){
        solvesubset(s);
    }
    
    for (int i = 0; i + 16 < (int)s.size(); i++){
        string t = "";
        for (int j = 0; j < 16; j++){
            t += s[i + j];
        }
        
        solvesubset(t);
    }
    
    cout << ans << "\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
//    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}