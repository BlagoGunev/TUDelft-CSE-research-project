#include <iostream>
#include <array>
using namespace std;
const int N = 105;
array<array<int,N>,N> G;
array<bool,N>used;
int n;
int dfs(int s,int ans){
    int res = 0;
    for(int i = 0; i < n;i++){
        if(G[s][i]!=-1&&!used[i]){
            used[i] = true;
            res = max(dfs(i,ans)+G[s][i],res);
            used[i] = false;
        }
    }
    return res;
}
int main(){

    cin >> n;
    int a,b,c;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            G[i][j] = -1;
        }
        used[i] = false;
    }
    for(int i = 0; i < n-1 ; i++){
        cin >> a >> b >> c;
        G[a][b] = G[b][a] = c;
    }
    used[0] = true;
    int ans = dfs(0,0);
    cout << ans << endl;
}