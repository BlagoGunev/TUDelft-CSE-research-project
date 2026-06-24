#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool solve() {
    int n; cin >> n;
    map <int, bool> vis;
    bool ans = true;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        vis[x] = true;
        if(i > 1 && !vis[x-1] && !vis[x+1]) ans = false;
    }
    return ans;
}

int main() {
    int _; cin >> _; while(_--) cout << (solve() ? "YES" : "NO") << '\n';
    return 0;
}