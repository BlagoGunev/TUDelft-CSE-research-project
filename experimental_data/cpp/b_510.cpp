#include<stdio.h>

#include<string.h>

#include<stdlib.h>



using namespace std;

int n, m;

char map[52][52];

bool vis[52][52];

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool flag;

void DFS(int x,int y, int prex, int prey)

{

    for(int i = 0; i < 4; i ++)

    {

        int xx = x + dir[i][0];

        int yy = y + dir[i][1];

        if(x >= 0 && x < n && y >= 0 && y < m && map[xx][yy] == map[x][y])

        {

            if(xx == prex && yy == prey) continue;

            if(vis[xx][yy])

            {

                flag = true;

                return;

            }

            vis[xx][yy] = true;

            DFS(xx, yy, x, y);

        }

        if(flag) return;

    }

}



int main()

{

    while(scanf("%d%d", &n, &m) != EOF)

    {

        flag = false;

        for(int i = 0; i < n; i ++) scanf("%s", map[i]);

        memset(vis, false, sizeof(vis));

        for(int i = 0; i < n; i ++)

            for(int j = 0; j < m; j ++)

            {

                if(vis[i][j]) continue;

                vis[i][j] = true;

                DFS(i, j, -1, -1);

                if(flag) goto A;

            }

        A: if(flag) puts("Yes");

        else puts("No");

    }

    return 0;

}