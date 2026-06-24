#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 6e5 + 5;

int n, w, s[N], mn[N<<2], ne[N], fa[N][26], sum;

map<int, int> mp;char op;

__int128 ans;

void pushup(int x){

    mn[x] = min(mn[x<<1], mn[x<<1|1]);

}

void update(int x, int l, int r, int pos, int k){

    if(l == r){

        mn[x] = k;

        return;

    }

    int mid = (l + r) >> 1;

    if(pos <= mid) update(x<<1, l, mid, pos, k);

    else update(x<<1|1, mid + 1, r, pos, k);

    pushup(x);

}

int query(int x, int l, int r, int l1, int r1){

    if(l1 <= l && r <= r1) return mn[x];

    int mid = (l + r) >> 1, res = 1e18;

    if(l1 <= mid) res = min(res, query(x<<1, l, mid, l1, r1));

    if(r1 > mid) res = min(res, query(x<<1|1, mid + 1, r, l1, r1));

    return res;

}

void add(int x, int k){

    mp[x] += k, sum += x*k;

}

int insert(int w){

    int res = 0;

    vector<map<int, int>::iterator> vec;

    for(auto it = mp.upper_bound(w); it != mp.end(); it++){

        res += it->second, sum -= it->first * it->second;

        vec.push_back(it);

    }

    for(auto it:vec) mp.erase(it);

    return res;

}

template <typename T> 

void write(T x){

    if(x > 9) write(x/10);

    cout << (char)(x%10 + '0');

}

signed main(){

    ios::sync_with_stdio(0);

    cin.tie(0), cout.tie(0);

    cin >> n;

    cin >> op >> w;

    s[1] = op - 'a';

    update(1, 1, n, 1, w);

    ans = w;

    write(ans);

    cout << '\n';

    for(int i = 2, j = 0; i <= n; i++){

        cin >> op >> w;

        s[i] = (op - 'a' + ans%26)%26;

        w = w ^ (ans & ((1<<30) - 1));

        while(j && s[j + 1] != s[i]) j = ne[j];

        if(s[j + 1] == s[i]) j++;

        ne[i] = j;

        if(s[i] == s[1]) add(w, 1);

        update(1, 1, n, i, w);

        ans += query(1, 1, n, 1, i);

        for(int c = 0; c < 26; c++) fa[i][c] = fa[ne[i]][c];

        fa[i][s[ne[i] + 1]] = ne[i];

        for(int c = 0; c < 26; c++){

            if(c == s[i]) continue;

            for(int k = fa[i - 1][c]; k; k = fa[k][c]) add(query(1, 1, n, i - k, i - 1), -1);

        }

        add(w, insert(w));

        ans += sum;

        write(ans);

        cout << '\n';

    }

    return 0;

}