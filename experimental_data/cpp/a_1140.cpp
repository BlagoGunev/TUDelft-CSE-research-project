#include <bits/stdc++.h>
#ifdef __DEBUG__
// #include <compdebug>
#else
#define dbg() do {} while(0)
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template<typename T>
void read(T &first) { cin >> first; }
template<typename T, typename... Args>
void read(T &first, Args&... args) { cin >> first; read(args...); }

template<typename T>
void println(T const &first) { cout << first << endl; }
template<typename T, typename... Args>
void println(T const &first, const Args&... args) { cout << first << " "; write(args...); }

template<typename T, typename V>
inline void present(T const& container, V const& value) { return container.find(value) != container.end(); }

#define iread(...) int __VA_ARGS__; read(__VA_ARGS__)
#define llread(...) ll __VA_ARGS__; read(__VA_ARGS__)
#define sread(...) string __VA_ARGS__; read(__VA_ARGS__)
#define for0(v, N) for (int v = 0; v < N; v++)
#define forr0(v, N) for (int v = N-1; v >= 0; v--)
#define for1(v, N) for (int v = 1; v <= N; v++)
#define forr1(v, N) for (int v = N-1; v >= 1; v--)
#define maxrep(a, b) (a)=max((a), (b))


int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  iread(N);

  int mval = 0;

  int days = 0;
  for1(i, N) {
      iread(ai);
      maxrep(mval, ai);
      if (mval <= i) {
          // println(ai);
          days++;
      }
  }
  println(days);
}