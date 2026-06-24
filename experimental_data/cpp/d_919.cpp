// #include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
// #include <vector>

using namespace std;

#define Finline __inline__ __attribute__ ((always_inline))

Finline char get_char(){
    static char buf[10000001], *p1 = buf, *p2 = p1 + fread(buf, 1, 10000000, stdin);
    return p1 == p2 ? EOF : *p1 ++;
}
inline int read(){
    int num = 0;
    char c;
    while(isspace(c = get_char()));
    while(num = num * 10 + c - 48, isdigit(c = get_char()));
    return num;
}
Finline void upmax(int &a, const int &b){
    if(a < b) a = b;
}

#define MAXK 27
#define MAXN 333333
#define INF 0x3f3f3f3f

// int n, m, tot = 1, timer, cnt;
int n, m, tot = 1, cnt, ans;
int num[MAXN], ind[MAXN];
int beginx[MAXN], endx[MAXN], nxt[MAXN];
int dp[MAXN][MAXK];
bool exist[MAXN];
/*int dfn[MAXN], low[MAXN];
bool vis[MAXN], exist[MAXN];
char num[MAXN];
vector<int> scc;
stack<int> mession;*/

inline void add_edge(int u, int v){
    nxt[++tot] = beginx[u], beginx[u] = tot, endx[tot] = v;
}

/*inline void tarjan(int u){
    dfn[u] = low[u] = ++timer;
    mession.push(u);
    vis[u] = exist[u] = true;
    for(int i = beginx[u]; i; i = nxt[i]){
        int v = endx[i];
        if(vis[v]){
            if(exist[v] && low[u] > dfn[v]) low[u] = dfn[v];
        } else {
            tarjan(v);
            upmin(lwo[u], low[v]);
        }
    }
    if(dfn[u] == dfn[u]){
        ++cnt;
        int v;
        do{
            v = mession.top(), mession.pop();
            exist[v] = false;
            scc[cnt].push()
        }while(!mession.empty() && u != v);
    }
}*/

queue<int> mession;

int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++){
        char cons;
        while(isspace(cons = get_char()));
        num[i] = cons - 'a';
    }
    for(int i = 1; i <= m; i++){
        int u = read(), v = read();
        add_edge(u, v);
        ind[v]++;
    }
    for(int i = 1; i <= n; i++){
        if(!ind[i]){
            mession.push(i);
            dp[i][num[i]]++;
        }
    }
    while(!mession.empty()){
        int u = mession.front();
        mession.pop();
        cnt++;
        exist[u] = true;
        for(int i = beginx[u]; i; i = nxt[i]){
            int v = endx[i];
            if(exist[v]){
                puts("-1");
                return 0;
            }
            for(int j = 0; j < 26; j++){
                upmax(dp[v][j], dp[u][j] + bool(num[v] == j));
                upmax(ans, dp[v][j]);
            }
            if((--ind[v]) == 0) mession.push(v);
        }
    }
    if(cnt == n) printf("%d", ans);
    else puts("-1");
    return 0;
}