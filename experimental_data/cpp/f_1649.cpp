#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



const int maxn = 500010;

const ll INF = 1ll * 1e9 * 1e9;



int n, q;

ll a[3][maxn];



int yh(){

	int ret=0;bool f=0;char c=getchar();

	while(!isdigit(c)){if(c==EOF)return -1;if(c=='-')f=1;c=getchar();}

	while(isdigit(c))ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();

	return f?-ret:ret;

}



struct Seg{

    int l, r, k;



    bool operator < (const Seg& x) const{

        if(r == x.r) return l < x.r;

        return r < x.r;

    }

}s[maxn];



struct Node{

    ll f, g, fg;



    Node(){

        f = -INF;

        g = -INF;

        fg = -INF;

    }

}t[maxn<<2]; // 0 s 1 f



ll pre[3][maxn];



ll f[maxn], g[maxn];



void pushup(Node& a, Node& b, Node& c){ 

    a.f = max(b.f, c.f);

    a.g = max(b.g, c.g);

    a.fg = max(max(b.fg, c.fg), b.f + c.g);

}



void build(int i, int l, int r){

    if(l == r){

        t[i].f = f[l];

        t[i].g = g[l];

        t[i].fg = f[l] + g[l];

        return;

    }

    int mid = (l + r) >> 1;

    build(i<<1, l, mid); 

    build(i<<1|1, mid+1, r);

    pushup(t[i], t[i<<1], t[i<<1|1]);

}



void mdf(int i, int l, int r, int p, ll k){

    if(l == r){

        if(k > t[i].f) {

            t[i].f = k;

            t[i].fg = k + t[i].g;

        }

        return;

    }

    int mid = (l + r) >> 1;

    if(p <= mid) mdf(i<<1, l, mid, p, k);

    else mdf(i<<1|1, mid+1, r, p, k);

    pushup(t[i], t[i<<1], t[i<<1|1]);

}



Node qry(int i, int l, int r, int x, int y){

    if(x > y) return Node();

    if(x <= l && r <= y){

        return t[i];

    }

    int mid = (l + r) >> 1;

    

    Node res = Node();

    Node lc = Node(), rc = Node();

    if(x <= mid) lc = qry(i<<1, l, mid, x, y);

    if(y > mid) rc = qry(i<<1|1, mid+1, r, x, y);

    pushup(res, lc, rc);

    return res;

}



vector<int> rc[maxn];

int l[maxn];

ll k[maxn];



int main(){

    n = yh(), q = yh();



    for(int j = 0 ; j < 3 ; ++j){

        for(int i = 1 ; i <= n ; ++i){

            a[j][i] = yh();

            pre[j][i] = pre[j][i-1] + a[j][i];

        }        

    }



    for(int i = 1 ; i <= n ; ++i){

        f[i] = pre[0][i] - pre[1][i-1];

        g[i] = pre[1][i] + pre[2][n] - pre[2][i-1];

    }



    for(int i = 1 ; i <= q ; ++i){

        l[i] = yh(); int x = yh(); k[i] = yh();

        rc[x].push_back(i);

    }



    build(1, 1, n);



    ll ans = -INF;

    for(int i = 1 ; i <= n ; ++i){

        for(int id : rc[i]){

            Node res = qry(1, 1, n, l[id], i);

            ans = max(ans, res.fg - k[id]);

        

            if(i < n) mdf(1, 1, n, i+1, res.f - k[id]);

        }

 

    }

    

    printf("%lld\n", ans);

}