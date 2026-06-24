#include "bits/stdc++.h"

#define ll long long
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define forn(n) for(int i = 0; i < n; i ++)
#ifdef ONLINE_JUDGE
# define watch(x) {}
    # define printv(n) {}
#else
#define watch(x) {cerr<<(#x)<<" is "<<(x)<<endl;}
#define printv(n) {for(auto v:n) cerr<<v<<" ";cerr<<endl;}
#endif
using namespace std;


struct ft {
    vector<int> d;
    ft(int ft_size) {
        d.resize(ft_size);
    }
    int q(int l, int r) {
        int qsum = 0;
        for (int idx = r; idx >= 0; idx = idx & (idx + 1), idx --) qsum += d[idx];
        for (int idx = l - 1; idx >= 0; idx = idx & (idx + 1), idx --) qsum -= d[idx];
        return qsum;
    }
    void u(int idx, int diff) {
        for (; idx < d.size(); idx = idx | (idx + 1)) d[idx] += diff;
    }
};



int main () {
    fastio
    int N; int Q;
    cin >> N >> Q;

    ft xft(N + 10);
    ft yft(N + 10);
    map<int, int> xmap;
    map<int, int> ymap;

    for (int q = 0; q < Q; q ++) {
        int type; cin >> type;
        if (type == 1) { // put
            int x; int y; cin >> x >> y;
            xmap[x] ++;
            ymap[y] ++;
            if (xmap[x] == 1) xft.u(x, 1);
            if (ymap[y] == 1) yft.u(y, 1);
        }
        else if (type == 2) { // remove
            int x; int y; cin >> x >> y;
            xmap[x] --;
            ymap[y] --;
            if (xmap[x] == 0) xft.u(x, -1);
            if (ymap[y] == 0) yft.u(y, -1);
        }
        else if (type == 3) { // query
            int x1; int y1; int x2; int y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (xft.q(x1, x2) == x2 - x1 + 1) {
                cout << "Yes" << endl;
            }
            else if (yft.q(y1, y2) == y2 - y1 + 1) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
}