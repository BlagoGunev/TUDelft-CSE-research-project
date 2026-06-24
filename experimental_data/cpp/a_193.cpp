#include <cstdio>

#include <algorithm>



using namespace std;



char v[64][64];

bool ap[64][64];

int dx[] = {0,  0, 1, -1}, low[64][64], niv[64][64];

int dy[] = {1, -1, 0,  0}, OK = 0;



inline void dfs (int x, int y, int tx, int ty)

{

    ap[x][y] = true;

    niv[x][y] = low[x][y] = niv[tx][ty] + 1;



    for (int i = 0; i < 4; ++i)

    {

        int xx = x + dx[i];

        int yy = y + dy[i];



        if (ap[xx][yy] && (xx != tx || yy != ty))

            low[x][y] = min (low[x][y], niv[xx][yy]);



        if (!ap[xx][yy] && v[xx][yy] == '#')

        {

            dfs (xx, yy, x, y);



            low[x][y] = min (low[x][y], low[xx][yy]);

            if (low[xx][yy] >= niv[x][y])

                ++OK;



            if (OK > 1) return;

        }



        if (OK > 1) return;

    }

}



int main ()

{

  //  freopen ("file.in", "r", stdin);



    int n, m;

    scanf ("%d %d", &n, &m);



    int x, y, nr = 0;

    for (int i = 1; i <= n; ++i)

    {

        scanf ("\n");

        for (int j = 1; j <= m; ++j)

        {

            scanf ("%c", &v[i][j]);

            if (v[i][j] == '#') ++nr, x = i, y = j;

        }

    }



    if (nr < 3)

    {

        printf ("-1\n");

        return 0;

    }



    dfs (x, y, 0, 0);



    if (OK > 1) printf ("1\n");

    else printf ("2\n");



    return 0;

}