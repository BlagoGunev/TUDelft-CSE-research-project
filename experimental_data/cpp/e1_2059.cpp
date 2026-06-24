#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--){
        int n, m;
        cin >> n >> m;
        
        vector a(n, vector<int>(m)), b(n, vector<int>(m));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> b[i][j];
            }
        }
        
        int bi = 0, bj = 0, ans = 0, preansmi = 0, lef = n * m;
        bool out = false;
        
        for (int i = 0; i < n && !out && bi < n; i++){
            for (int j = 0; j < m && !out && bi < n; j++){
                while (!out && bi < n && a[i][j] != b[bi][bj]){
                    if (m - j <= ans || !j){
                        ans++;
                        bj++;
                        if (bj == m){
                            bi++;
                            bj = 0;
                        }
                    }
                    else{
                        ans = lef + preansmi;
                        out = true;
                    }
                }
                
                if (out || bi == n) break;
                if (m - 1 - j <= ans){
                    preansmi = ans;
                    lef = n * m - bi * m - bj - 1;
                    //cout << i << ' ' << j << ' ' << lef << ' ' << preansmi << '\n';
                }
                bj++;
                if (bj == m){
                    bi++;
                    bj = 0;
                }
            }
        }
        
        cout << ans << '\n';
    }
}
/*
 1
 2 5
 6 7 8 9 10
 5 4 1 2 3
 6 7 8 9 10
 5 4 3 2 1
 
 1
 2 5
 6 7 8 9 10
 5 4 1 2 3
 1 6 7 8 9
 10 5 3 4 2

 */