// If you copy and paste my solution I will murder you in your sleep.
#include <bits/stdc++.h>

#define int long long
#define endl "\n"
using namespace std;

signed solve(){

    int n,m;
    cin>>n>>m;
    vector <vector<int>> a(n, vector <int> (m,0));
    vector <array<int, 2>> coords(0,array<int,2>());
    char input_char;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>input_char;
            if(input_char == 'R') {
                a[i][j] = 1;
                coords.push_back({i,j});
            }
        }
    }
    int x = 0;
    int y = 0;
    for(auto pos:coords){
        x = pos[0];
        y = pos[1];
        bool f= true;
        for(auto it:coords){
            if(it[0]-x < 0 or it[1]-y < 0) f = false;
        }
        if(f){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;


    return 0;
}
signed main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    cin>>test;
    while(test--) solve();


    return 0;
}