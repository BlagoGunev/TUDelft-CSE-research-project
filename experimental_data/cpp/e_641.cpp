#include <bits/stdc++.h>
using namespace std;


inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x );
inline void writeChar( int x );
inline void writeWord( const char *s );
inline void flush();

/** Read */

static const int buf_size = 4096;

inline int getChar() {
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len)
    pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len)
    return -1;
  return buf[pos++];
}

inline int readChar() {
  int c = getChar();
  while (c <= 32)
    c = getChar();
  return c;
}

template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-')
    s = -1, c = getChar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}

inline void flush() {
  if (write_pos)
    fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}

template <class T>
inline void writeInt( T x ) {
  if (x < 0)
    writeChar('-'), x = -x;

  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n--)
    writeChar(s[n]);
}

inline void writeWord( const char *s ) {
  while (*s)
    writeChar(*s++);
}


typedef long long ll;
const int maxLog = 20;
const int maxN = 1 << maxLog;
const int INF = 0x3c3c3c3c;
const ll LINF = 0x3c3c3c3c3c3c3c3c;
#define se second
#define fi first
#define all(x) (x).begin(), (x).end()

int a[maxN], t[maxN], x[maxN];
int f[maxN];
int ans[maxN];

int sz;

void add(int i, int x) {
    for (; i < sz; i |= i + 1) {
        f[i] += x;
    }
}

int get(int i) {
    return i < 0 ? 0 : f[i] + get((i & (i + 1)) - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = readInt();
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
        t[i] = readInt();
        x[i] = readInt();
        b[i] = ((ll)x[i] << 32) | i;
    }
    memset(ans, -1, sizeof(ans));
    sort(all(b));
    b.push_back(LINF);
    vector<int> ts;
    for (int ii = 0; ii < n;) {
        int rr = ii;
        ll x = b[ii] >> 32;
        while ((b[rr] >> 32) == x) {
            ts.push_back(t[b[rr] & ((1ll << 32) - 1)]);
            rr++;
        }
        sz = ts.size() + 2;
        memset(f, 0, sizeof(int) * sz);
        sort(all(ts));
        for (int j = ii; j < rr; j++) {
            int i = b[j] & ((1ll << 32) - 1);
            int pos = lower_bound(all(ts), t[i]) - ts.begin();
            if (a[i] == 1) {
                add(pos, 1);
            }
            if (a[i] == 2) {
                add(pos, -1);
            }
            if (a[i] == 3) {
                ans[i] = get(pos);
            }
        }
        ts.clear();
        ii = rr;
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] != -1) {
            writeInt(ans[i]);
            writeChar('\n');
        }
    }
    flush();
    return 0;
}