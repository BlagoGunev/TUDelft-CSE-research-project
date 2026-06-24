/*************************************
 * @problem:      Codeforces - Educational #76.
 * @user_name:    hkxadpall.
 * @time:         2019-11-13.
 * @language:     C++.
 * @upload_place: Codeforces.
*************************************/ 

#include <bits/stdc++.h>
using namespace std;

typedef signed char          int8;
typedef unsigned char       uint8;
typedef short                int16;
typedef unsigned short      uint16;
typedef int                  int32;
typedef unsigned            uint32;
typedef long long            int64;
typedef unsigned long long  uint64;

template <typename Int>
inline Int read()       
{
    Int flag = 1;
    char c = getchar();
    while ((!isdigit(c)) && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    Int init = c & 15;
    while (isdigit(c = getchar())) init = (init << 3) + (init << 1) + (c & 15);
	return init * flag;
}

template <typename Int>
inline Int read(char &c)       
{
    Int flag = 1;
    c = getchar();
    while ((!isdigit(c)) && c != '-') c = getchar();
    if (c == '-') flag = -1, c = getchar();
    Int init = c & 15;
    while (isdigit(c = getchar())) init = (init << 3) + (init << 1) + (c & 15);
	return init * flag;
}

template <typename Int>
inline void write(Int x)
{
    if (x < 0) putchar('-'), x = ~x + 1;
    if (x > 9) write(x / 10);
    putchar((x % 10) | 48);
}  

template <typename Int>
inline void write(Int x, char nextch)
{
    write(x);
    putchar(nextch);
}

int n, a[200007];
int m, p[200007], s[200007];
int most[200007];

int main()
{
    int t = read<int>(), ans;
    while (t--) {
        n = read<int>();
        for (int i = 1; i <= n; i++) {
            a[i] = read<int>();
            most[i] = 0;
        }
        m = read<int>();
        for (int i = 1; i <= m; i++) {
            p[i] = read<int>();
            s[i] = read<int>();
            most[s[i]] = max(most[s[i]], p[i]);
        }
        for (int i = n - 1; i > 0; i--) {
            most[i] = max(most[i], most[i + 1]);
        }
        ans = 0;
        for (int i = 1, mx = 0, cnt = 0; i <= n; i++) {
            if (a[i] > most[1]) {
                puts("-1");
                goto EndWhile;
            }
            mx = max(mx, a[i]);
            cnt++;
            if (mx > most[cnt]) {
                ans++;
                cnt = 1;
                mx = a[i];
            }
        }
        write(ans + 1, 10);
        EndWhile:;
    }
    return 0;
}
/*
1
9 1 2 3 4 5 6 7 8 9
2 10 9 100 1
output=1
*/