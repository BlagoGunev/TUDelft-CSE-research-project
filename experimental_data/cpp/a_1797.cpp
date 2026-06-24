#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;

int f(int x1,int y1){
    if ((x1==1 || x1==n) && (y1==1 || y1==m)) return 2;
    else if (x1>1 && x1<n && y1>1 && y1<m) return 4;
    else return 3;
}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << min(f(x1,y1),f(x2,y2));
        cout << '\n';
    }
}