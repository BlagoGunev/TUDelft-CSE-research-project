#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
// #define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

using pii = pair<int, int>;

const int sz = 101 * 101;
using bset = bitset<sz>;

void solve(){
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    bset state;
    vector<bset> undo_h(n), undo_v(m);
    vector<pii> pos_h, pos_v;
    vector<bset> op_h(n), op_v(m);
    for(int i = 0; i < n; i++){
        pos_h.push_back(pii(i + 1, 1));
        for(int j = 0; j < k; j++){
            op_h[i].set(i * m + j);
        }
        for(int j = 0; j < m; j++){
            undo_h[i].set(i * m + j);
        }
    }
    for(int i = 0; i < m; i++){
        pos_v.push_back(pii(n - k + 1, i + 1));
        for(int j = n - 1; j >= n - k; j--){
            op_v[i].set(j * m + i);
        }
        for(int j = 0; j < n; j++){
            undo_v[i].set(j * m + i);
        }
    }
    string ops;
    cin >> ops;
    for(char c : ops){
        bool done = false;
        if(c == 'H'){
            for(int i = 0; i < n - k; i++) {
                if ((state & op_h[i]).count() == 0){
                    state |= op_h[i];
                    cout << pos_h[i].first << " " << pos_h[i].second << endl;
                    done = true;
                    break;
                }
            }
            if(!done){
                for(int i = n - k; i < n; i++){
                    if((state & undo_h[i]).count() == m - k && (state & op_h[i]).count() == 0){
                        state |= op_h[i];
                        cout << pos_h[i].first << " " << pos_h[i].second << endl;
                        done = true;
                        break;
                    }
                }
            }
            if(!done){
                for(int i = n - k; i < n; i++){
                    if((state & op_h[i]).count() == 0){
                        state |= op_h[i];
                        cout << pos_h[i].first << " " << pos_h[i].second << endl;
                        done = true;
                        break;
                    }
                }
            }
        } else {
            for(int i = m - 1; i >= k; i--){
                if ((state & op_v[i]).count() == 0){
                    state |= op_v[i];
                    cout << pos_v[i].first << " " << pos_v[i].second << endl;
                    done = true;
                    break;
                }
            }
            if(!done){
                for(int i = 0; i < k; i++){
                    if((state & undo_v[i]).count() == n - k && (state & op_v[i]).count() == 0){
                        state |= op_v[i];
                        cout << pos_v[i].first << " " << pos_v[i].second << endl;
                        done = true;
                        break;
                    }
                }
            }
            if(!done){
                for(int i = 0; i < k; i++){
                    if((state & op_v[i]).count() == 0){
                        state |= op_v[i];
                        cout << pos_v[i].first << " " << pos_v[i].second << endl;
                        done = true;
                        break;
                    }
                }
            }
        }
        assert(done);
        vector<int> rh, rv;
        for(int i = 0; i < n; i++){
            if((state & undo_h[i]).count() == m){
                rh.push_back(i);
            }
        }
        for(int i = 0; i < m; i++){
            if((state & undo_v[i]).count() == n){
                rv.push_back(i);
            }
        }
        for(int h : rh){
            undo_h[h].flip();
            state &= undo_h[h];
            undo_h[h].flip();
        }
        for(int v : rv){
            undo_v[v].flip();
            state &= undo_v[v];
            undo_v[v].flip();
        }
    }
}

int main() { _
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
	exit(0);
}