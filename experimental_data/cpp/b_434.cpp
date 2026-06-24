#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[1000][1000];
int le[1000][1000];
int ri[1000][1000];
int up[1000][1000];
int down[1000][1000];

int main()
{
#ifdef shaoling
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
                le[i][j] = A[i][j];
            else if (A[i][j] == 1)
                le[i][j] = le[i][j - 1] + 1;

            if (i == 0)
                up[i][j] = A[i][j];
            else if (A[i][j] == 1)
                up[i][j] = up[i - 1][j] + 1;
        }
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (j == m - 1)
                ri[i][j] = A[i][j];
            else if (A[i][j] == 1)
                ri[i][j] = ri[i][j + 1] + 1;

            if (i == n - 1)
                down[i][j] = A[i][j];
            else if (A[i][j] == 1)
                down[i][j] = down[i + 1][j] + 1;
        }
    }
    
    for (int t = 0; t < q; t++)
    {
        int op, x, y;
        cin >> op >> x >> y;
        x--, y--;
        
        if (op == 1)
        {
            A[x][y] = 1 - A[x][y];
            
            for (int j = 0; j < m; j++)
            {
                le[x][j] = 0;

                if (j == 0)
                    le[x][j] = A[x][j];
                else if (A[x][j] == 1)
                    le[x][j] = le[x][j - 1] + 1;
            }
            
            for (int j = m - 1; j >= 0; j--)
            {
                ri[x][j] = 0;

                if (j == m - 1)
                    ri[x][j] = A[x][j];
                else if (A[x][j] == 1)
                    ri[x][j] = ri[x][j + 1] + 1;
            }

            for (int i = 0; i < n; i++)
            {
                up[i][y] = 0;

                if (i == 0)
                    up[i][y] = A[i][y];
                else if (A[i][y] == 1)
                    up[i][y] = up[i - 1][y] + 1;
            }

            for (int i = n - 1; i >= 0; i--)
            {
                down[i][y] = 0;

                if (i == n - 1)
                    down[i][y] = A[i][y];
                else if (A[i][y] == 1)
                    down[i][y] = down[i + 1][y] + 1;
            }
        }
        else
        {
            int res = 0;
            
            int l = m + 1, r = m + 1;
            
            for (int i = x; i < n; i++)
            {
                l = min(l, le[i][y]);
                r = min(r, ri[i][y]);
                
                if (min(l, r) == 0)
                    break;
                res = max(res, (l + r - 1) * (i - x + 1));
            }
            l = m + 1, r = m + 1;
            
            for (int i = x; i >= 0; i--)
            {
                l = min(l, le[i][y]);
                r = min(r, ri[i][y]);
                
                if (min(l, r) == 0)
                    break;
                res = max(res, (l + r - 1) * (x - i + 1));
            }
            int d = n + 1, u = n + 1;

            for (int j = y; j < m; j++)
            {
                d = min(d, down[x][j]);
                u = min(u, up[x][j]);

                if (min(d, u) == 0)
                    break;
                res = max(res, (d + u - 1) * (j - y + 1));
            }
            d = n + 1, u = n + 1;

            for (int j = y; j >= 0; j--)
            {
                d = min(d, down[x][j]);
                u = min(u, up[x][j]);

                if (min(d, u) == 0)
                    break;
                res = max(res, (d + u - 1) * (y - j + 1));
            }
            cout << res << '\n';
        }
    }
    
    return 0;
}