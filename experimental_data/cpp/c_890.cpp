#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool vis[200005];

int main()
{
    memset(vis, false, sizeof(vis));
    int n;
    cin >> n;
    int x;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        if(vis[x])
        {
            vis[x] = false;
            vis[i] = true;
        }
        else
        {
            vis[i] = true;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}