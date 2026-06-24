#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <stdint.h>
#include <cstdarg>
#include <cstdio>
#include <fcntl.h>

using namespace std;

#define maxn 5010
#define maxm 20010
#define MAX 1000000

int n, m, X[maxn], Y[maxn];
int match[maxn];
bool ind[maxn];

int a[maxm], b[maxm], d[maxm], lk[maxm], st[maxn];

// aΪ�ڽӾ���XY�и���n���㣬�±�Ϊ1..n 
// ����Ϊmatch[]���飬match[y]=x��ʾx-y��ƥ���� 

int op, cl, q[maxn], ancestor[maxn], best_ancestor[maxn], W[maxn];

bool BFS(int match[] = match)
{
    int flag = 0;
    while (op < cl && ! flag)
    {
        ++ op;
        int x = match[q[op]];
        if (x == 0)
        {
            flag = q[op];
            break;
        }
        for (int j = st[x]; j; j = lk[j])
        {
            int y = b[j];
            if (! ancestor[y] && d[j] == X[x] + Y[y])
            {
                ancestor[y] = q[op];
                q[++ cl] = y;
            }
            if (d[j] != X[x] + Y[y] && W[y] > Y[y] + X[x] - d[j])
            {
                W[y] = Y[y] + X[x] - d[j];
                best_ancestor[y] = q[op];
            }
        }
    }
    if (flag)
        while (flag != n + 1)
        {
            int y = ancestor[flag];
            match[flag] = match[y];
            flag = y;
        }
    return flag;
}

int BestMatch(int match[] = match)
{
    memset(match, 0, sizeof(match));
    memset(X, 0, sizeof(X));
    memset(Y, 0, sizeof(Y));
    
    for (int i = 1; i <= m; ++ i)
        X[a[i]] = max(X[a[i]], d[i]);
        
    memset(st, 0, sizeof(0));
    for (int i = 1; i <= m; ++ i)
    {
        lk[i] = st[a[i]];
        st[a[i]] = i;
    }
    
    for (int i = 1; i <= n; ++ i)
    {
        memset(q, 0, sizeof(q));                 // BFS�Ķ��� 
        memset(ancestor, 0, sizeof(ancestor));   // ǰ�����Y�еĵ�y��ancestor[y]��Ҳһ��Y�еĽڵ㣬����֮ǰΪ0 
        match[n + 1] = i;
        q[1] = n + 1;
        op = 0;
        cl = 1;
        ancestor[n + 1] = n + 1;
        
        for (int y = 1; y <= n; ++ y)
        {
            best_ancestor[y] = 0;                // Ǳ�ڵ�ǰ�����Y�в������ֵĵ�y��best_ancestor[y]����ѵ�ѡ�� 
            W[y] = MAX * 2;
        }
        
        while (! BFS(match))
        {
            int delta = MAX * 2;
            for (int y = 1; y <= n; ++ y)
                if (! ancestor[y])
                    delta = min(delta, W[y]);
            for (int y = 1; y <= n + 1; ++ y)
                if (! ancestor[y])
                {
                    W[y] -= delta;
                    if (W[y] == 0)
                    {
                        ++ cl;
                        q[cl] = y;
                        ancestor[y] = best_ancestor[y];
                    }
                }
                else
                {
                    Y[y] += delta;
                    X[match[y]] -= delta;
                }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++ i)
        ans += X[i] + Y[i];
    return ans;
}

int Code(int i, int j, int m)
{
    return (i * m + j) / 2 + 1;
}

void AddEdge(int i, int j, int dd, int flag)
{
    ++ m;
    a[m] = i;
    b[m] = j;
    d[m] = dd;
    if (flag & 1)
        swap(a[m], b[m]);
}

int _a[100][100];

int main()
{
//    freopen("input.txt", "r", stdin);
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < M; ++ j)
            scanf("%d", & _a[i][j]);
    
    for (int i = 0; i < N; ++ i)
        for (int j = 0; j < M - 1; ++ j)
            if (_a[i][j] == _a[i][j + 1])
                AddEdge(Code(i,j,M), Code(i,j + 1,M), 1, i + j);
            else
                AddEdge(Code(i,j,M), Code(i,j + 1,M), 0, i + j);
            
    for (int i = 0; i < N - 1; ++ i)
        for (int j = 0; j < M; ++ j)
            if (_a[i][j] == _a[i + 1][j])
                AddEdge(Code(i,j,M), Code(i + 1,j,M), 1, i + j);
            else
                AddEdge(Code(i,j,M), Code(i + 1,j,M), 0, i + j);
    
    n = N * M / 2;
    
    printf("%d\n", N * M / 2 - BestMatch());
}