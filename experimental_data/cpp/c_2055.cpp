#include<bits/stdc++.h>
using namespace std;
#define int long long
int T, n, m;
string s;
int a[1005][1005];
signed main(){
    cin >> T;
    while(cin >> n >> m){
        cin >> s;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        int z = 0;
        int x = 1, y = 1;
        while(z < s.size()){
            if(s[z] == 'R'){
                int sum = 0;
                for(int i = 1; i <= n; i++){
                    sum += a[i][y];
                }
                a[x][y] = -sum;
                y++;
            }else{
                int sum = 0;
                for(int i = 1; i <= m; i++){
                    sum += a[x][i];
                }
                a[x][y] = -sum;
                x++;
            }
            z++;
        }
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += a[i][y];
        }
        a[x][y] = -sum;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
    
    return 0;
}