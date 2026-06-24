#include <fstream>
#define min(a,b) ((a<b)?a:b)
using namespace std;
int sol, h[300], ht, D[220][40010][2], i, j, n, a, b, hmin;
int main()
{
    ifstream fi("input.txt");
    ofstream fo("output.txt");
    fi >> n;
    fi >> a >> b;
    sol = int(2e9);
    for(i = 1, ht = 0; i <= n; i++)
    {
        fi >> h[i];
        ht += h[i];
    }
    for(i = 0; i <= a; i++) D[1][i][0] = D[1][i][1] = int(2e9);
    D[1][h[1]][0] = D[1][0][1] = 0;
    for(i = 2; i <= n; i++)
        for(j = 0; j <= a; j++)
        {
            hmin = min(h[i-1], h[i]);
            if(j >= h[i]) D[i][j][0] = min(D[i-1][j-h[i]][0], D[i-1][j-h[i]][1]+hmin);
            else D[i][j][0] = int(2e9);
            D[i][j][1] = min(D[i-1][j][0] + hmin, D[i-1][j][1]);
        }
    for(i = 0; i <= a; i++)
    if (ht-i <= b)
    {
        sol = min(D[n][i][0], sol);
        sol = min(D[n][i][1], sol);
    }
    if(sol == int(2e9)) fo << "-1\n"; else
    fo << sol << "\n";
    return 0;
}