#include<bits/stdc++.h>

#define endl '\n'

#define iloveds std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

#define all(a) a.begin(),a.end()

using namespace std;

typedef long long ll ;

typedef long double ld;

const double eps = 1e-6;

const int N = 5e5 + 100, Mod = 1e9 + 1;

const int maxn = 1e9 + 100;



int n, tot, root, lans;



struct node{

    int ls, rs, tag, mi;

}seg[N << 6];



void update(int id){

    seg[id].mi = min(seg[seg[id].ls].mi, seg[seg[id].rs].mi);

}



void build (int &id, int l, int r) { 

	id = ++ tot;

    seg[id].mi = l;

    seg[id].tag = 0;

}



void settag(int id, int val) {

    seg[id].mi += val;

    seg[id].tag += val;

}



void pushdown(int id, int l, int r) {

	int mid = (l + r) >> 1;

    if(!seg[id].ls) build(seg[id].ls, l, mid);

    if(!seg[id].rs) build(seg[id].rs, mid + 1, r);

    settag(seg[id].ls, seg[id].tag);

    settag(seg[id].rs, seg[id].tag);

    seg[id].tag = 0;

}



void modify(int &id, int l, int r, int ql, int qr, int val) { 

	if (!id) build (id, l, r);

    if(l >= ql && r <= qr){

        settag(id, val);

        return ;

    }

	int mid = (l + r) >> 1;

    pushdown(id, l, r);

    if (ql <= mid) modify(seg[id].ls, l, mid, ql, qr, val);

	if (qr > mid) modify(seg[id].rs, mid + 1, r, ql, qr, val);

    update(id);

}



int seach (int &id, int l, int r, int val) {

	if (!id) build (id, l, r);

    if(seg[id].mi > val) return -1;

	if(l == r) return l;

	int mid = (l + r) >> 1;

    pushdown(id, l, r);

    if(seg[seg[id].rs].mi <= val){

        return seach(seg[id].rs, mid + 1, r, val);

    }else{

        return seach(seg[id].ls, l, mid, val);

    }

}



int query(int &id, int l, int r, int pos) {

	if (!id) build (id, l, r);

	if(l == r){

        return seg[id].mi;

    }

	int mid = (l + r) >> 1;

	pushdown(id, l, r);

    if(pos <= mid){

        return query(seg[id].ls, l, mid, pos);

    }else{

        return query(seg[id].rs, mid + 1, r, pos);

    }

}



int main () {

	iloveds;

	cin >> n;

    for(int i = 1; i <= n ; i ++){

        int x;

        cin >> x;

        int l = seach(root, 0, maxn, x - 1);

        int r = seach(root, 0, maxn, x);

        if(l >= 0) modify(root, 0, maxn, 0, l, 1);

        modify(root, 0, maxn, r + 1, maxn, -1);

        int qu;

        cin >> qu;

        while(qu --){

            int val;

            cin >> val;

            lans = (lans + val) % Mod;

            int ans = query(root, 0, maxn, lans);

            cout << ans << endl;

            lans = ans;

        }

    }

	return 0;

}