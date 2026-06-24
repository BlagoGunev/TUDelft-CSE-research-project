#include <cstdio>

#include <cstring>

#include <map>

#include <algorithm>



#define lson (i << 1)

#define rson ((i << 1) | 1)



using namespace std;



const int MAXN = 100003;

const int INF = 0x3f3f3f3f;



struct Vect {

    int a[4];



    Vect() {

        memset(a, 0x3f, sizeof(a));

    }



    bool operator < (const Vect& x) const {

        for(int i = 0; i < 4; ++i) {

            if(a[i] != x.a[i]) {

                return a[i] < x.a[i];

            }

        }

        return false;

    }

};



struct Node {

    int v, nxt;

}edge[MAXN << 1];



int fir[MAXN], tot;



void init() {

    memset(fir, -1, sizeof(fir));

    tot = 0;

}



void addEdge(int u, int v) {

    edge[tot].v = v;

    edge[tot].nxt = fir[u];

    fir[u] = tot++;



    edge[tot].v = u;

    edge[tot].nxt = fir[v];

    fir[v] = tot++;

}



int n, ans, cnt;

//a[i]表示只看子结点时的状态值，b[i]表示看所有结点时的状态值

int a[MAXN], b[MAXN], deg[MAXN];//deg[i]表示i点的度

bool vis[MAXN * 3];

map<Vect, int> mp;



void dfsFromDown(int u, int p) {//自底向上更新a

    Vect cur;

    int num = 0, v;

    for(int i = fir[u]; i != -1; i = edge[i].nxt) {

        v = edge[i].v;

        if(v != p) {

            dfsFromDown(v, u);

            cur.a[num++] = a[v];

        }

    }

    sort(cur.a, cur.a + 4);//按子结点状态的升序排序

    if(mp[cur] == 0) {//如果当前状态未出现过，则标记为一个新的状态

        mp[cur] = ++cnt;

    }

    a[u] = mp[cur];

}



//status表示p结点以u结点为父亲结点时应有的状态值a[p]

void dfsFromUp(int u, int p, int status) {//自顶向下更新b

    Vect cur;

    int num = 0, v;

    for(int i = fir[u]; i != -1; i = edge[i].nxt) {

        v = edge[i].v;

        if(v == p) {

            cur.a[num++] = status;

        }

        else {

            cur.a[num++] = a[v];

        }

    }

    sort(cur.a, cur.a + 4);//按子结点状态的升序排序

    if(mp[cur] == 0) {//如果当前状态未出现过，则标记为一个新的状态

        mp[cur] = ++cnt;

    }

    b[u] = mp[cur];



    for(int i = fir[u]; i != -1; i = edge[i].nxt) {

        v = edge[i].v;

        if(v != p) {

            for(int i = 0; i < 4; ++i) {

                if(cur.a[i] == a[v]) {

                    cur.a[i] = INF;

                    break;

                }

            }

            sort(cur.a, cur.a + 4);//按子结点状态的升序排序

            if(mp[cur] == 0) {//如果当前状态未出现过，则标记为一个新的状态

                mp[cur] = ++cnt;

            }

            dfsFromUp(v, u, mp[cur]);

            cur.a[3] = a[v];

        }

    }

}



int u, v;



int main() {

    while(1 == scanf("%d", &n)) {

        init();

        mp.clear();

        ans = cnt = 0;

        memset(deg, 0, sizeof(deg));

        memset(vis, false, sizeof(vis));

        for(int i = 1; i < n; ++i) {

            scanf("%d%d", &u, &v);

            addEdge(u, v);

            ++deg[u];

            ++deg[v];

        }

        dfsFromDown(1, 0);

        dfsFromUp(1, 0, 0);

        for(int i = 1; i <= n; ++i) {

            if(deg[i] < 4 && !vis[b[i]]) {//当前结点的度小于4且状态未出现过，则可以添一个结点形成新的不同的树

                vis[b[i]] = true;

                ++ans;

            }

        }

        printf("%d\n", ans);

    }

    return 0;

}