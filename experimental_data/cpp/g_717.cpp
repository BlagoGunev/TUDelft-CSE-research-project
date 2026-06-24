#include <cstdio>

#include <cstring>

#include <queue>

#include <iostream>

#include <algorithm>

using namespace std;

const int MAXN = 500;

const int MAXM = 100;

const int MAXK = 100;

const int INF = 0x3f3f3f3f;

char s[MAXN+10], ts[MAXN+10];

struct node{

    int v, w, f, c;

    node *next, *back;

}Edges[MAXN*2+MAXN*2+10], *ecnt=Edges, *adj[MAXN+10], *Fa[MAXN+10];

void addedge(int u, int v, int c, int w){

    ++ecnt;

    ecnt->next = adj[u];

    ecnt->back = ecnt+1;

    ecnt->c = c;

    ecnt->f = 0;

    ecnt->w = w;

    ecnt->v = v;

    adj[u] = ecnt;



    ++ecnt;

    ecnt->next = adj[v];

    ecnt->back = ecnt-1;

    ecnt->c = ecnt->f = 0;

    ecnt->w = -w;

    ecnt->v = u;

    adj[v] = ecnt;

}

int dis[MAXN+10], stream[MAXN+10];

bool insta[MAXN+10];

bool SPFA(int s, int t){

    memset(dis, 0x3f, sizeof dis);

    dis[s] = 0;

    stream[s] = INF;

    queue<int> que;

    que.push(s);

    insta[s] = true;

    while(!que.empty()){

        int u = que.front();

        que.pop();

        insta[u] = false;

        for(node *p=adj[u];p;p=p->next){

            if(p->f >= p->c) continue;

            if(dis[p->v] > dis[u] + p->w){

                dis[p->v] = dis[u] + p->w;

                stream[p->v] = min(stream[u], p->c - p->f);

                Fa[p->v] = p;

                if(!insta[p->v]){

                    insta[p->v] = true;

                    que.push(p->v);

                }

            }

        }

    }

    if(dis[t] == INF) return false;

    return true;

}

int work(int s, int t){

    int ret = 0;

    while(SPFA(s, t)){

        int u = t, str = stream[t];

        while(u != s){

            Fa[u]->f += str;

            Fa[u]->back->f -= str;

            u = Fa[u]->back->v;

        }

        ret += stream[t] * dis[t];

    }

    return ret;

}

int main(){

    int n, m, x, tval;

    scanf("%d%s%d", &n, s+1, &m);

    for(int i=1;i<=m;i++){

        scanf("%s%d", ts+1, &tval);

        int len = strlen(ts+1);

        for(int j=n-len+1;j>=1;j--){

            bool fit = true;

            for(int k=1;k<=len;k++){

                if(s[j+k-1] != ts[k]){

                    fit = false;

                    break;

                }

            }

            if(fit) addedge(j, j+len, 1, -tval);

        }

    }

    scanf("%d", &x);

    for(int i=1;i<=n;i++)

        addedge(i, i+1, x, 0);

    addedge(0, 1, x, 0);

    printf("%d\n", -work(0, n+1));



    return 0;

}