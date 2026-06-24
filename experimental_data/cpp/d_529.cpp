//#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#define ll long long
#define db double
#define PB push_back
#define lson k<<1
#define rson k<<1|1
using namespace std;

const int N = 20005;
const int TOL = 86455;

int a[N], cnt[N], b[N];

int main()
{
#ifdef PKWV
    freopen("in.in", "r", stdin);
#endif // PKWV
    int n, M, T;
    while(scanf("%d%d%d", &n, &M, &T) + 1)
    {
        int h, m, s;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d:%d:%d", &h, &m, &s);
            a[i] = (h * 60 + m) * 60 + s;
        }
        memset(cnt, 0, sizeof(cnt));
        int tol(0), lx(1), j(1);
        priority_queue<int, vector<int> > q;
        bool ok = false;
        for(int i = 1; i <= n; i++)
        {
            while(j <= n && a[j] + T - 1 < a[i])
            {
                cnt[b[j]]--;
                if(cnt[b[j]] == 0) tol--;
                j++;
            }
            if(tol + 1 <= M)
            {
                b[i] = lx++;
                cnt[b[i]]++;
                tol++;
                q.push(b[i]);
            }
            else
            {
                while(cnt[q.top()] == 0) q.pop();
                b[i] = q.top();
                cnt[b[i]]++;
            }
            if(tol == M) ok = true;
        }
        if(!ok) printf("No solution\n");
        else
        {
            printf("%d\n", lx - 1);
            for(int i = 1; i <= n; i++) printf("%d\n", b[i]);
        }
    }
    return 0;
}