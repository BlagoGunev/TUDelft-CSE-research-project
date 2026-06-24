#include <bits/stdc++.h>
using namespace std;

// Containers
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int>	    pii;
typedef pair<ll, ll>	    pll;
typedef vector<int>		    vi;
typedef vector<ll>		    vl;
typedef vector<pii>		    vpii;
typedef vector<pll>		    vpll;
typedef vector<vi>		    vvi;
typedef vector<vl>		    vvl;
typedef pair<string,string> pss;
typedef map<int, int>	    mii;

// Miscellanous
#define pb push_back
#define ff first
#define ss second
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define sortv(v) sort(all(v))
template <class T>
void clr(T* arr, int size) {memset(arr, 0, size * sizeof(T));}

void pnl() {printf("\n");}
void pyes() {printf("YES\n");}
void pno() {printf("NO\n");}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
// IO
// SOURCE --> https://judge.yosupo.jp/submission/127351

#include <unistd.h>

namespace yosupo_IO {

template <class T>
using is_signed_int128 =
    typename std::conditional<is_same<T, __int128_t>::value
                                  || is_same<T, __int128>::value,
                              true_type, false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<is_same<T, __uint128_t>::value
                                  || is_same<T, unsigned __int128>::value,
                              true_type, false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<is_same<T, __int128_t>::value, __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral =
    typename std::conditional<std::is_integral<T>::value
                                  || is_signed_int128<T>::value
                                  || is_unsigned_int128<T>::value,
                              true_type, false_type>::type;

template <class T>
using is_signed_int =
    typename std::conditional<(is_integral<T>::value
                               && std::is_signed<T>::value)
                                  || is_signed_int128<T>::value,
                              true_type, false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value
                               && std::is_unsigned<T>::value)
                                  || is_unsigned_int128<T>::value,
                              true_type, false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value, make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

template <class T>
using is_integral_t = enable_if_t<is_integral<T>::value>;

template <class T>
using is_signed_int_t = enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = enable_if_t<is_unsigned_int<T>::value>;

namespace detail {
template <typename T, decltype(&T::is_modint) = &T::is_modint>
std::true_type check_value(int);
template <typename T>
std::false_type check_value(long);
} // namespace detail

template <typename T>
struct is_modint : decltype(detail::check_value<T>(0)) {};

template <typename T>
using is_modint_t = enable_if_t<is_modint<T>::value>;

template <class T>
using to_unsigned_t = typename to_unsigned<T>::type;

struct Scanner {
public:
  Scanner(const Scanner &) = delete;
  Scanner &operator=(const Scanner &) = delete;

  Scanner(FILE *fp) : fd(fileno(fp)) { line[0] = 127; }

  void read() {}
  template <class H, class... T>
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }

  int read_unsafe() { return 0; }
  template <class H, class... T>
  int read_unsafe(H &h, T &... t) {
    bool f = read_single(h);
    if (!f) return 0;
    return 1 + read_unsafe(t...);
  }

  int close() { return ::close(fd); }

private:
  static constexpr int SIZE = 1 << 15;

  int fd = -1;
  array<char, SIZE + 1> line;
  int st = 0, ed = 0;
  bool eof = false;

  bool read_single(string &ref) {
    if (!skip_space()) return false;
    ref = "";
    while (true) {
      char c = top();
      if (c <= ' ') break;
      ref += c;
      st++;
    }
    return true;
  }
  bool read_single(double &ref) {
    string s;
    if (!read_single(s)) return false;
    ref = std::stod(s);
    return true;
  }

  template <class T, enable_if_t<is_same<T, char>::value> * = nullptr>
  bool read_single(T &ref) {
    if (!skip_space<50>()) return false;
    ref = top();
    st++;
    return true;
  }

  template <class T, is_signed_int_t<T> * = nullptr,
            enable_if_t<!is_same<T, char>::value> * = nullptr>
  bool read_single(T &sref) {
    using U = to_unsigned_t<T>;
    if (!skip_space<50>()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    U ref = 0;
    do { ref = 10 * ref + (line[st++] & 0x0f); } while (line[st] >= '0');
    sref = neg ? -ref : ref;
    return true;
  }
  template <class U, is_unsigned_int_t<U> * = nullptr,
            enable_if_t<!is_same<U, char>::value> * = nullptr>
  bool read_single(U &ref) {
    if (!skip_space<50>()) return false;
    ref = 0;
    do { ref = 10 * ref + (line[st++] & 0x0f); } while (line[st] >= '0');
    return true;
  }

  bool reread() {
    if (ed - st >= 50) return true;
    if (st > SIZE / 2) {
      std::memmove(line.data(), line.data() + st, ed - st);
      ed -= st;
      st = 0;
    }
    if (eof) return false;
    auto u = ::read(fd, line.data() + ed, SIZE - ed);
    if (u == 0) {
      eof = true;
      line[ed] = '\0';
      u = 1;
    }
    ed += int(u);
    line[ed] = char(127);
    return true;
  }

  char top() {
    if (st == ed) {
      bool f = reread();
      assert(f);
    }
    return line[st];
  }

  template <int TOKEN_LEN = 0>
  bool skip_space() {
    while (true) {
      while (line[st] <= ' ') st++;
      if (ed - st > TOKEN_LEN) return true;
      if (st > ed) st = ed;
      for (auto i = st; i < ed; i++) {
        if (line[i] <= ' ') return true;
      }
      if (!reread()) return false;
    }
  }
};

struct Printer {
public:
  template <char sep = ' ', bool F = false>
  void write() {}
  template <char sep = ' ', bool F = false, class H, class... T>
  void write(const H &h, const T &... t) {
    if (F) write_single(sep);
    write_single(h);
    write<true>(t...);
  }
  template <char sep = ' ', class... T>
  void writeln(const T &... t) {
    write<sep>(t...);
    write_single('\n');
  }

  Printer(FILE *_fp) : fd(fileno(_fp)) {}
  ~Printer() { flush(); }

  int close() {
    flush();
    return ::close(fd);
  }

  void flush() {
    if (pos) {
      auto res = ::write(fd, line.data(), pos);
      assert(res != -1);
      pos = 0;
    }
  }

private:
  static array<array<char, 2>, 100> small;
  static array<unsigned long long, 20> tens;

  static constexpr size_t SIZE = 1 << 15;
  int fd;
  array<char, SIZE> line;
  size_t pos = 0;
  std::stringstream ss;

  template <class T, enable_if_t<is_same<char, T>::value> * = nullptr>
  void write_single(const T &val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }

  template <class T, is_signed_int_t<T> * = nullptr,
            enable_if_t<!is_same<char, T>::value> * = nullptr>
  void write_single(const T &val) {
    using U = to_unsigned_t<T>;
    if (val == 0) {
      write_single('0');
      return;
    }
    if (pos > SIZE - 50) flush();
    U uval = val;
    if (val < 0) {
      write_single('-');
      uval = -uval;
    }
    write_unsigned(uval);
  }

  template <class T, is_modint_t<T> * = nullptr>
  void write_single(const T &val) {
    write_single(val.val);
  }

  static int bsr(unsigned int n) {
    return 8 * (int)sizeof(unsigned int) - 1 - __builtin_clz(n);
  }
  static int bsr(unsigned long n) {
    return 8 * (int)sizeof(unsigned long) - 1 - __builtin_clzl(n);
  }
  static int bsr(unsigned long long n) {
    return 8 * (int)sizeof(unsigned long long) - 1 - __builtin_clzll(n);
  }

  template <class U, is_unsigned_int_t<U> * = nullptr>
  void write_single(U uval) {
    if (uval == 0) {
      write_single('0');
      return;
    }
    if (pos > SIZE - 50) flush();

    write_unsigned(uval);
  }

  template <class U, is_unsigned_int_t<U> * = nullptr>
  static int calc_len(U x) {
    int i = (bsr(1ULL * x) * 3 + 3) / 10;
    if (x < tens[i])
      return i;
    else
      return i + 1;
  }

  template <class U, is_unsigned_int_t<U> * = nullptr,
            enable_if_t<2 >= sizeof(U)> * = nullptr>
  void write_unsigned(U uval) {
    size_t len = calc_len(uval);
    pos += len;

    char *ptr = line.data() + pos;
    while (uval >= 100) {
      ptr -= 2;
      memcpy(ptr, small[uval % 100].data(), 2);
      uval /= 100;
    }
    if (uval >= 10) {
      memcpy(ptr - 2, small[uval].data(), 2);
    } else {
      *(ptr - 1) = char('0' + uval);
    }
  }

  template <class U, is_unsigned_int_t<U> * = nullptr,
            enable_if_t<4 == sizeof(U)> * = nullptr>
  void write_unsigned(U uval) {
    array<char, 8> buf;
    memcpy(buf.data() + 6, small[uval % 100].data(), 2);
    memcpy(buf.data() + 4, small[uval / 100 % 100].data(), 2);
    memcpy(buf.data() + 2, small[uval / 10000 % 100].data(), 2);
    memcpy(buf.data() + 0, small[uval / 1000000 % 100].data(), 2);

    if (uval >= 100000000) {
      if (uval >= 1000000000) {
        memcpy(line.data() + pos, small[uval / 100000000 % 100].data(), 2);
        pos += 2;
      } else {
        line[pos] = char('0' + uval / 100000000);
        pos++;
      }
      memcpy(line.data() + pos, buf.data(), 8);
      pos += 8;
    } else {
      size_t len = calc_len(uval);
      memcpy(line.data() + pos, buf.data() + (8 - len), len);
      pos += len;
    }
  }

  template <class U, is_unsigned_int_t<U> * = nullptr,
            enable_if_t<8 == sizeof(U)> * = nullptr>
  void write_unsigned(U uval) {
    size_t len = calc_len(uval);
    pos += len;

    char *ptr = line.data() + pos;
    while (uval >= 100) {
      ptr -= 2;
      memcpy(ptr, small[uval % 100].data(), 2);
      uval /= 100;
    }
    if (uval >= 10) {
      memcpy(ptr - 2, small[uval].data(), 2);
    } else {
      *(ptr - 1) = char('0' + uval);
    }
  }

  template <class U, enable_if_t<is_unsigned_int128<U>::value> * = nullptr>
  void write_unsigned(U uval) {
    static array<char, 50> buf;
    size_t len = 0;
    while (uval > 0) {
      buf[len++] = char((uval % 10) + '0');
      uval /= 10;
    }
    std::reverse(buf.begin(), buf.begin() + len);
    memcpy(line.data() + pos, buf.data(), len);
    pos += len;
  }

  void write_single(const std::string &s) {
    for (char c: s) write_single(c);
  }
  void write_single(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write_single(s[i]);
  }
  template <class T>
  void write_single(const std::vector<T> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write_single(' ');
      write_single(val[i]);
    }
  }
};

array<array<char, 2>, 100> Printer::small = [] {
  array<array<char, 2>, 100> table;
  for (int i = 0; i <= 99; i++) {
    table[i][1] = char('0' + (i % 10));
    table[i][0] = char('0' + (i / 10 % 10));
  }
  return table;
}();
array<ull, 20> Printer::tens = [] {
  array<ull, 20> table;
  for (int i = 0; i < 20; i++) {
    table[i] = 1;
    for (int j = 0; j < i; j++) { table[i] *= 10; }
  }
  return table;
}();

} // namespace yosupo_IO

using namespace yosupo_IO;
Scanner scanner = Scanner(stdin);
Printer printer = Printer(stdout);

template <class T>
void scan(T &a) {scanner.read(a);}

void out() {}
template <class Head, class... Tail>
void out(Head &&head, Tail &&... tail) {
  printer.write(head);
  if (sizeof...(Tail)) printer.write(' ');
  out(forward<Tail>(tail)...);
}

template <class Head, class... Tail>
void outn(Head &&head, Tail &&... tail) {
  out(head , forward<Tail>(tail)...);
  printer.write('\n');
}

#define INT(...)   \
  int __VA_ARGS__; \
  inp(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  inp(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  inp(__VA_ARGS__)
#define CHR(...)    \
  char __VA_ARGS__; \
  inp(__VA_ARGS__)
#define DBL(...)           \
  long double __VA_ARGS__; \
  inp(__VA_ARGS__)

template <class T>
void scan(pair<T, T> &p) {scan(p.first), scan(p.second);}

template <class T>
void scan(vector<T> &a) {for (auto &&i: a) scan(i);}

void inp() {}
template <class Head, class... Tail>
void inp(Head &head, Tail &... tail) {
  scan(head);
  inp(tail...);
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
// Loops
#define loop(i,s,e) for (int (i)=(s);(i)<(e);++(i))
#define loope(i,s,e) for (int (i)=(s);(i)<=(e);++(i))
#define forc(c,s,e) for (char (c)=(s);(c)<=(e);++(c))
#define rep(i,n) loop(i,0,n)
#define repn(i,n) loope(i,1,n)

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Debug
void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);

template <class T> void _print(unordered_set <T> v);
template <class T> void _print(unordered_multiset <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(unordered_map <T, V> v);
template <class T, class V> void _print(unordered_multimap <T, V> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x << " = ";  _print(x); cerr << endl;
#else
#define deb(x)
#endif

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Segment_Tree
{
  public : 

  int n;
  ll NO_MOD_OP = -1;
  pll NEUTRAL_CALC_OP = {0 , INT_MIN};
  vl operation;
  vpll value; // --> {sum , mx}
  
  void apply_mod(int v, int lv , int rv, ll op)
  {
    value[v].ff = op * (rv-lv+1);
    value[v].ss = op;

    operation[v] = op;
  }

  void push(int v, int lv, int rv)
  {
    if(lv == rv or operation[v] == NO_MOD_OP) return;

    int m = (lv + rv)/2;
    apply_mod(2*v,lv,m,operation[v]);
    apply_mod(2*v+1,m+1,rv,operation[v]);

    operation[v] = NO_MOD_OP;
  }

  pll calc_op(pll x, pll y) {return {x.ff + y.ff , max(x.ss , y.ss)};}

  Segment_Tree(int n)
  {
    this->n = n;
    operation.resize(4*n + 5 , NO_MOD_OP);        
    value.resize(4*n + 5 , NEUTRAL_CALC_OP);        
  }

  pll calc(int l, int r)
  {
    return calc(l, r, 1 , 0, n-1);
  }

  pll calc(int l, int r, int v, int lv ,int rv)
  {
    if(r < lv or rv < l) return NEUTRAL_CALC_OP;
    if(l <= lv and rv <= r) return value[v];
    push(v,lv,rv);

    int m = (lv+rv)/2;
    pll left = calc(l, r, 2*v , lv , m);
    pll right = calc(l, r, 2*v + 1 , m+1 , rv);
    return calc_op(left , right);
  }

  void modify(int l, int r, int x)
  {
    return modify(l, r, x, 1, 0, n-1);
  }
  
  void modify(int l, int r, int x, int v, int lv, int rv)
  {
    if(r < lv or rv < l) return;
    if(l <= lv and rv <= r) 
    {
      apply_mod(v,lv,rv,x);
      return;
    }
    push(v,lv,rv);

    int m = (lv+rv)/2;
    modify(l, r, x, 2*v, lv, m);
    modify(l, r, x, 2*v + 1, m+1, rv);
    value[v] = calc_op(value[2*v] , value[2*v + 1]);
  }

    int get(int x, int l)
    {
        return get(x,l, 1, 0, n-1);
    }
    
    int get(int x, int l, int v, int lv, int rv)
    {
        if(value[v].ss < x or rv < l) return -1;
        if(lv == rv) return lv;

        int m = (lv+rv)/2;
        int temp = get(x,l, 2*v , lv , m);
        if(temp != -1) return temp;
        return get(x,l, 2*v + 1, m+1, rv);
    }
};

void SOLVE()
{
  INT(n);
  vi p(n); inp(p);
  vi v = p;

  for (int i = n-2; i >= 0; i--) v[i] = min(v[i+1] , p[i]);
  
  Segment_Tree s(2*n + 5);
  rep(i,n) s.modify(i,i,v[i]);

  ll ans = 0;
  rep(i,n) 
  {
    ll x = s.calc(1 + i , n-1 + i).ff;
    ans = max(ans , x);

    int j = s.get(p[i] , i+1);
    if(j == -1) j = n+i;

    s.modify(j , n+i , p[i]);
  }
  outn(ans + n);
}

int main()
{
  int t = 1;
  inp(t);
  while(t--) SOLVE();

  return 0;
}
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------