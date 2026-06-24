#include <iostream>

#include <cstring>

#include <algorithm>



using namespace std;



inline int read() {

    char c = getchar(); int x = 0, s = 1;

    while (c < '0' || c > '9') { if (c == '-') s = -1; c = getchar();}

    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}

    return x * s;

}



void print(int x) {

	if (x < 0) putchar('-'), x = -x;

	if (x > 9) print(x / 10);

	putchar(x % 10 ^ 48);

}



const int N = 510;



int n, m, k;

int a[N][N], c[N][N];

struct Node {

    int x1, y1, x2, y2;

}b[N * N];



int main()

{

    n = read(); k = read();

    

    for (int i = 1; i <= n * n; i ++ ) b[i].x1 = b[i].y1 = 1e9;

    for (int i = 1; i <= n; i ++ )

        for (int j = 1; j <= n; j ++ ) {

            a[i][j] = read();

            b[a[i][j]].x1 = min(b[a[i][j]].x1, i);

            b[a[i][j]].y1 = min(b[a[i][j]].y1, j);

            b[a[i][j]].x2 = max(b[a[i][j]].x2, i);

            b[a[i][j]].y2 = max(b[a[i][j]].y2, j);

        }

    

    for (int i = 1; i <= n * n; i ++ )

        if (b[i].x1 != 1e9)

            m ++ ;

    

    if (m <= k) {

        print(k - m);

        return 0;

    }

    

    for (int len = 1; len <= n; len ++ ) {

        memset(c, 0, sizeof c);

        for (int i = 1; i <= n * n; i ++ ) {

            if (b[i].x1 == 1e9) continue;

            int tx1 = max(1, b[i].x2 - len + 1);

            int ty1 = max(1, b[i].y2 - len + 1);

            int tx2 = min(n - len + 1, b[i].x1);

            int ty2 = min(n - len + 1, b[i].y1);

            

            if (tx1 <= tx2 && ty1 <= ty2) {

                c[tx1][ty1] ++ ;

                c[tx2 + 1][ty1] -- ;

                c[tx1][ty2 + 1] -- ;

                c[tx2 + 1][ty2 + 1] ++ ;

            }

        }

        

        for (int i = 1; i <= n; i ++ )

            for (int j = 1; j <= n; j ++ ) {

                c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];

                if (m - c[i][j] == k || m - c[i][j] == k - 1) {

                    puts("1");

                    return 0;

                }

            }

    }

    

    puts("2");

    

    return 0;

}