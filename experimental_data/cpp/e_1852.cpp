#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 1;

void setIO() {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

pii seg[400005];
int n;

void build(int l = 0, int r = n - 1, int cur = 0){
    seg[cur] = {INF, INF};
    if(l == r) return;
    int mid = (l + r)/2;
    build(l, mid, cur*2 + 1);
    build(mid + 1, r, cur*2 + 2);
}

void update(int x, int v, int l = 0, int r = n - 1, int cur = 0){
    if(l == r){
        seg[cur] = {v, l};
        return;
    }
    int mid = (l + r)/2;
    if(x <= mid) update(x, v, l, mid, cur*2 + 1);
    else update(x, v, mid + 1, r, cur*2 + 2);
    seg[cur] = min(seg[cur*2 + 1], seg[cur*2 + 2]);
}

pii query(int l, int r, int ul = 0, int ur = n - 1, int cur = 0){
    if(l <= ul && ur <= r) return seg[cur];
    if(l > r || ur < l || ul > r) return {INF, INF};
    int mid = (ul + ur)/2;
    return min(query(l, r, ul, mid, cur*2 + 1), query(l, r, mid + 1, ur, cur*2 + 2));
}

int main(){
    setIO();
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        cin >> n;
        map<int, vector<int>> m;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            m[arr[i]].pb(i);
        }
        vector<int> rel; //relevant numbers
        for(auto &i : m){
            rel.pb(i.ff);
            for(int j = 1; j < i.ss.size() - 1; j++){
                arr[i.ss[j]] = 0;
            }
        }
        reverse(rel.begin(), rel.end());
        vector<int> nw;
        build();
        for(int i : rel){
            int l = m[i].front(), r = m[i].back();
            if(query(l, r).ff <= r){
                arr[l] = arr[r] = 0;
            } else {
                update(l, r);
                nw.pb(i);
            }
        }
        swap(rel, nw);
        set<int> s;
        for(int i = 0; i < n; i++) if(!arr[i]) s.insert(i);
        vector<int> vals; //possible target values
        for(int i = rel.size() - 1; i >= 0; i--){
            if(i == rel.size() - 1 || rel[i] - 1 != rel[i + 1]){
                vals.pb(rel[i] - 1);
            }
        }
        ll sum = 0, mx = 0, mxval = 0;
        int lex = -1, rex = -1;
        build();
        for(int i = 0; i < n; i++) if(!arr[i]) update(i, -1);
        reverse(vals.begin(), vals.end());
        queue<pii> upd;
        int ind = 0;
        //try to add an interval with value i
        for(int i : vals){
            vector<int> nxt;
            //try filling in all intervals > i
            while(ind < rel.size() && rel[ind] > i){
                int l = m[rel[ind]].front(), r = m[rel[ind]].back();
                set<int>::iterator it = s.lower_bound(l);
                while(it != s.end() && *it < r){
                    sum += rel[ind];
                    update(*it, rel[ind]);
                    upd.push({*it, rel[ind]});
                    it = s.erase(it);
                }
                nxt.pb(rel[ind++]);
            }
            //try each necessary interval to be strictly contained by i
            for(int j : nxt){
                int l = m[j].front(), r = m[j].back();
                if(s.size() && 0 < l && r < n - 1){
                    //find which indeces on each side to replace with i
                    pii rnw = query(r + 1, n);
                    pii lnw = query(0, l - 1);
                    if(rnw.ff == INF || lnw.ff == INF) continue;
                    ll add = (ll)i*s.size() + (rnw.ff == -1 ? 0 : i - rnw.ff) + (lnw.ff == -1 ? 0 : i - lnw.ff);
                    if(i && sum + add > mx){
                        mx = sum + add;
                        mxval = i;
                        lex = (lnw.ff == -1 ? -1 : lnw.ss);
                        rex = (rnw.ff == -1 ? -1 : rnw.ss);
                        //it is optimal to fill in all intervals > i
                        while(!upd.empty()){
                            arr[upd.front().ff] = upd.front().ss;
                            upd.pop();
                        }
                    }
                }
            }
        }
        //don't want to add any intervals
        if(s.size() == 0 && sum > mx){
            mx = sum;
            lex = rex = -1;
            //it is optimal to fill in all remaining intervals
            while(!upd.empty()){
                arr[upd.front().ff] = upd.front().ss;
                upd.pop();
            }
        }
        if(lex != -1) arr[lex] = 0;
        if(rex != -1) arr[rex] = 0;
        for(int i = 0; i < n; i++) cout << (arr[i] ? arr[i] : mxval) << " ";
        cout << endl;
    }
}