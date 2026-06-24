#include <bits/stdc++.h>

using namespace std;

namespace IO {

const int SIZ = 1 << 14;



inline char getc() {

    static char bf[SIZ], *begin = bf, *end = bf;

    if (begin == end) begin = bf, end = bf + fread(bf, 1, SIZ, stdin);

    if (begin == end) return EOF;

    return *begin++;

}

char wbf[SIZ], *wend = wbf, *weoo = wbf + SIZ;

inline void putc(char c) {

    *wend = c, ++wend;

    if (wend == weoo) fwrite(wbf, 1, SIZ, stdout), wend = wbf;

}

inline void do_flush() { fwrite(wbf, 1, wend - wbf, stdout); }

template <typename T>

inline void uread(T &ans) {

    static char tmp;

    tmp = getc(), ans = 0;

    while (!isdigit(tmp)) tmp = getc();

    while (isdigit(tmp)) ans = (ans << 1) + (ans << 3) + (tmp ^ 48), tmp = getc();

}

template <typename T>

inline void read(T &ans) {

    static char tmp2;

    static bool flag;

    tmp2 = getc(), ans = 0, flag = 0;

    while (!isdigit(tmp2)) {

        if (tmp2 == '-') flag = 1;

        tmp2 = getc();

    }

    while (isdigit(tmp2)) ans = (ans << 1) + (ans << 3) + (tmp2 ^ 48), tmp2 = getc();

    if (flag) ans = -ans;

}

template <typename T>

inline void uwrite(T x) {

    if (x > 9) uwrite(x / 10);

    putc(x % 10 + '0');

}

template <typename T>

inline void write(T x) {

    if (x < 0)

        putc('-'), uwrite(-x);

    else

        uwrite(x);

}

inline void putstr(const char str[]) {

    for (int i = 0; str[i]; i++) putc(str[i]);

}

};  // namespace IO

using IO::read, IO::write, IO::do_flush, IO::putc, IO::uread, IO::uwrite;

const int N = 5e5 + 10;

vector<int> vec[N];

int n, m, mex[N];

pair<int, int> p[N];

int main() {

    read(n), read(m);

    int u, v;

    for (int i = 1; i <= m; i++) read(u), read(v), vec[u].push_back(v), vec[v].push_back(u);

    for (int i = 1; i <= n; i++) read(p[i].first), p[i].second = i, mex[i] = 1;

    sort(p + 1, p + n + 1);

    for (int i = 1; i <= n; i++) {

        if (mex[p[i].second] != p[i].first) {

            puts("-1");

            return 0;

        }

        for (int v : vec[p[i].second])

            if (mex[v] == p[i].first) ++mex[v];

    }

    for (int i = 1; i <= n; i++) write(p[i].second), putc(' ');

    do_flush();

    return 0;

}