#ifdef ONLINE_JUDGE

#pragma GCC optimize("O3")

#pragma GCC target("avx2")

#endif



#include <bits/stdc++.h>

using namespace std;



static struct FastInput {

  static constexpr int BUF_SIZE = 1 << 20;

  char buf[BUF_SIZE];

  size_t chars_read = 0;

  size_t buf_pos = 0;

  FILE *in = stdin;

  char cur = 0;

 

  inline char get_char() {

    if (buf_pos >= chars_read) {

      chars_read = fread(buf, 1, BUF_SIZE, in);

      buf_pos = 0;

      buf[0] = (chars_read == 0 ? -1 : buf[0]);

    }

    return cur = buf[buf_pos++];

  }

 

  inline void tie(int) {}

 

  inline explicit operator bool() {

    return cur != -1;

  }

 

  inline static bool is_blank(char c) {

    return c <= ' ';

  }

 

  inline bool skip_blanks() {

    while (is_blank(cur) && cur != -1) {

      get_char();

    }

    return cur != -1;

  }

 

  inline FastInput& operator>>(char& c) {

    skip_blanks();

    c = cur;

    return *this;

  }

  

  inline FastInput& operator>>(string& s) {

    if (skip_blanks()) {

      s.clear();

      do {

        s += cur;

      } while (!is_blank(get_char()));

    }

    return *this;

  }

 

  template <typename T>

  inline FastInput& read_integer(T& n) {

    // unsafe, doesn't check that characters are actually digits

    n = 0;

    if (skip_blanks()) {

      int sign = +1;

      if (cur == '-') {

        sign = -1;

        get_char();

      }

      do {

        n += n + (n << 3) + cur - '0';

      } while (!is_blank(get_char()));

      n *= sign;

    }

    return *this;

  }

 

  template <typename T>

  inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {

    return read_integer(n);

  }

  

  #if !defined(_WIN32) || defined(_WIN64)

  inline FastInput& operator>>(__int128& n) {

    return read_integer(n);

  }

  #endif

 

  template <typename T>

  inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {

    // not sure if really fast, for compatibility only

    n = 0;

    if (skip_blanks()) {

      string s;

      (*this) >> s;

      sscanf(s.c_str(), "%lf", &n);

    }

    return *this;

  }

} fast_input;

 

#define cin fast_input

 

static struct FastOutput {

  static constexpr int BUF_SIZE = 1 << 20;

  char buf[BUF_SIZE];

  size_t buf_pos = 0;

  static constexpr int TMP_SIZE = 1 << 20;

  char tmp[TMP_SIZE];

  FILE *out = stdout;

 

  inline void put_char(char c) {

    buf[buf_pos++] = c;

    if (buf_pos == BUF_SIZE) {

      fwrite(buf, 1, buf_pos, out);

      buf_pos = 0;

    }

  }

 

  ~FastOutput() {

    fwrite(buf, 1, buf_pos, out);

  }

 

  inline FastOutput& operator<<(char c) {

    put_char(c);

    return *this;

  }

 

  inline FastOutput& operator<<(const char* s) {

    while (*s) {

      put_char(*s++);

    }

    return *this;

  }

 

  inline FastOutput& operator<<(const string& s) {

    for (int i = 0; i < (int) s.size(); i++) {

      put_char(s[i]);

    }

    return *this;

  }

 

  template <typename T>

  inline char* integer_to_string(T n) {

    // beware of TMP_SIZE

    char* p = tmp + TMP_SIZE - 1;

    if (n == 0) {

      *--p = '0';

    } else {

      bool is_negative = false;

      if (n < 0) {

        is_negative = true;

        n = -n;

      }

      while (n > 0) {

        *--p = (char) ('0' + n % 10);

        n /= 10;

      }

      if (is_negative) {

        *--p = '-';

      }

    }

    return p;

  }

 

  template <typename T>

  inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {

    return integer_to_string(n);

  }

 

  #if !defined(_WIN32) || defined(_WIN64)

  inline char* stringify(__int128 n) {

    return integer_to_string(n);

  }

  #endif

 

  template <typename T>

  inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {

    sprintf(tmp, "%.17f", n);

    return tmp;

  }

 

  template <typename T>

  inline FastOutput& operator<<(const T& n) {

    auto p = stringify(n);

    for (; *p != 0; p++) {

      put_char(*p);

    }

    return *this;

  }

} fast_output;

 

#define cout fast_output

#define endl '\n'



#define int long long



const int mod = 1e9 + 7;

const int _ = 1e5 + 5;



int iv[_];

int n, m, k;



const int N = 262144 + 10, M = 32767;

const double pi = acos(-1.0);

typedef long long LL;

typedef complex<double> cp;

int L, a[N], b[N], c[N], R[N], P = mod;

cp w[N];

void Pre() {

    int x = 0; for (L = 1; (L <<= 1) <= m + n; ++x) ;

    for(int i = 1;i < L; ++i) R[i] = (R[i >> 1] >> 1) | (i & 1) << x;

    for(int i = 0;i < L; ++i) w[i] = cp(cos(2 * pi * i / L), sin(2 * pi * i / L));

}

void FFT(cp *F) {

    for(int i = 0;i < L; ++i) if(i < R[i]) swap(F[i], F[R[i]]);

    for(int i = 2, d = L >> 1;i <= L; i <<= 1, d >>= 1) 

        for(int j = 0;j < L; j += i) {

            cp *l = F + j, *r = F + j + (i >> 1), *p = w, tp;

            for(int k = 0;k < (i >> 1); ++k, ++l, ++r, p += d) 

                tp = *r * *p, *r = *l - tp, *l = *l + tp;

        }

}

void Mul(int *A, int *B, int *C) {

    for(int i = 0;i < L; ++i) (A[i] += P) %= P, (B[i] += P) %= P;

    static cp a[N], b[N], Da[N], Db[N], Dc[N], Dd[N];

    for(int i = 0;i < L; ++i) a[i] = cp(A[i] & M, A[i] >> 15);

    for(int i = 0;i < L; ++i) b[i] = cp(B[i] & M, B[i] >> 15);

    FFT(a); FFT(b);

    for(int i = 0;i < L; ++i) {

        int j = (L - i) & (L - 1); static cp da, db, dc, dd;

        da = (a[i] + conj(a[j])) * cp(0.5, 0);

        db = (a[i] - conj(a[j])) * cp(0, -0.5);

        dc = (b[i] + conj(b[j])) * cp(0.5, 0);

        dd = (b[i] - conj(b[j])) * cp(0, -0.5);

        Da[j] = da * dc; Db[j] = da * dd; Dc[j] = db * dc; Dd[j] = db * dd; //顺便区间反转，方便等会直接用DFT代替IDFT 

    }

    for(int i = 0;i < L; ++i) a[i] = Da[i] + Db[i] * cp(0, 1);

    for(int i = 0;i < L; ++i) b[i] = Dc[i] + Dd[i] * cp(0, 1);

    FFT(a); FFT(b);

    for(int i = 0;i < L; ++i) {

        int da = (LL) (a[i].real() / L + 0.5) % P; //直接取实部和虚部 

        int db = (LL) (a[i].imag() / L + 0.5) % P;

        int dc = (LL) (b[i].real() / L + 0.5) % P;

        int dd = (LL) (b[i].imag() / L + 0.5) % P;

        C[i] = (da + ((LL)(db + dc) << 15) + ((LL)dd << 30)) % P; 

    }

}



map<int, int> f;

int tot;

int tab[_], itab[_];

int ans;



int qpow(int a, int p) {

  int ret = 1;

  while (p) {

    if (p & 1) ret = ret * a % mod;

    a = a * a % mod;

    p >>= 1;

  }

  return ret;

}



void solve() {

  cin >> n >> k;

  iv[1] = tab[0] = tab[1] = itab[0] = itab[1] = 1;

  for (int i = 2; i <= n; i++) {

    iv[i] = (mod - mod/ i) * iv[mod % i] % mod;

    tab[i] = tab[i - 1] * i % mod;

    itab[i] = itab[i - 1] * iv[i] % mod;

  }

  for (int i = 1; i < n; i++) {

    int tmp1 = (k * i + n - i * 2) % mod * b[i] % mod;

    tmp1 = (tmp1 - k * i) % mod;

    int tmp2 = (k - 1) * i % mod * b[i - 1] % mod;

    tmp1 = (tmp1 - tmp2) % mod;

    tmp1 = (tmp1 + mod) % mod;

    b[i + 1] = iv[n - i] * tmp1 % mod;

  }

  Pre();

  for (int i = 1; i <= n; i++) {

    int aa;

    cin >> aa;

    if (aa == -1) m++;

    else f[aa]++;

  }

  int pk = 1, bn = b[n];

  for (int i = 0; i <= m; i++) {

    a[i] = pk * tab[m] % mod * itab[i] % mod * itab[m - i] % mod;

    pk = pk * (k - 1) % mod;

  }

  Mul(a, b, c);

  for (auto [u, v] : f) {

    ans = (ans + c[v + m]) % mod;

    tot++;

  }

  (ans += (k - tot) * c[m]) %= mod;

  ans = ans * qpow(k, m * (mod - 2)) % mod;

  ans = (ans - bn) % mod;

  cout << (ans + mod) % mod << endl;

  return ;

} 



signed main() {

  #ifdef Sakuyalove

    freopen("in.in", "r", stdin);

    freopen("out.out", "w", stdout);

  #endif 

  ios::sync_with_stdio(false);

  cin.tie(0);

  int T = 1;

  // cin >> T;

  while (T--) {

    solve();

  }



  return 0;

}