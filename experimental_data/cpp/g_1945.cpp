#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 300005;
const int Inf = 2000000000;

int T;
int n, D;
bool got[Maxn];
int notgot;
int k[Maxn], s[Maxn];
int len;
set <ii> mxlin;
deque <int> lin;
priority_queue <iii> Q;
priority_queue <ii> ent[Maxn];

void Join(int ind)
{
    Q.push(iii(k[ind], ii(-len, ind)));
    len++;
}

int Solve()
{
    for (int i = 1; i <= D; i++) {
        if (!Q.empty() && (lin.empty() || Q.top().first > mxlin.rbegin()->first)) {
            int ind = Q.top().second.second;
            lin.push_front(ind);
            mxlin.insert(ii(k[ind], ind));
            Q.pop();
        }
        if (!lin.empty()) {
            int ind = lin.front(); lin.pop_front();
            mxlin.erase(ii(k[ind], ind));
            if (!got[ind]) {
                got[ind] = true;
                if (--notgot == 0)
                    return i;
            }
            if (i + s[ind] <= D)
                ent[i + s[ind]].push(ii(-s[ind], ind));
        }
        while (!ent[i].empty()) {
            Join(ent[i].top().second);
            ent[i].pop();
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &D);
        lin.clear();
        mxlin.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &k[i], &s[i]);
            got[i] = false;
            lin.push_back(i);
            mxlin.insert(ii(k[i], i));
        }
        notgot = n;
        len = 0;
        while (!Q.empty())
            Q.pop();
        for (int i = 1; i <= D; i++)
            while (!ent[i].empty())
                ent[i].pop();
        printf("%d\n", Solve());
    }
    return 0;
}