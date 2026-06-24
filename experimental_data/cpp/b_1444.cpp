#include <bits/stdc++.h>



using namespace std;



#ifndef ONLINE_JUDGE

  #include "dbg.h" 

#else

  #define dbg(x...)

#endif



using ll = long long;

 

const int N = 3e5+5;



const int mod = 998244353;

 

template <int MOD=998'244'353>

struct Modular {

  int value;

  static const int MOD_value = MOD;

   

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}

  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

   

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}

  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}

  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

   

  friend Modular mexp(Modular a, long long e) {

  Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }

  return res;

  }

  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

   

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }

  friend Modular operator+(Modular a, Modular const b) { return a += b; }

  friend Modular operator-(Modular a, Modular const b) { return a -= b; }

  friend Modular operator-(Modular const a) { return 0 - a; }

  friend Modular operator*(Modular a, Modular const b) { return a *= b; }

  friend Modular operator/(Modular a, Modular const b) { return a /= b; }

  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}

  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}

  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}

};

using mint = Modular<mod>;

 

struct factorials {

  std::vector<mint> f;

  factorials() {

    f.emplace_back(1);

    for (int i = 1;i < N;i++) 

      f.push_back(f.back() * i);

  }

  mint operator()(int x){

    return f[x];

  }

}fact;

 

auto modpow(mint b, long long e) {

  mint ans = 1;

  for (; e; b *= b, e /= 2)

    if (e & 1) ans *= b;

  return ans;

}

 

mint ncr(int n,int r){

  if (r > n)

    return 0;

  return fact(n) * modpow(fact(r).value , mod - 2) * modpow(fact(n - r).value , mod - 2);

}



int main() 

{

  ios_base::sync_with_stdio(false);

  cin.tie(nullptr);



  int n;

  cin >> n;

  vector<int> a(2*n);

  for (int& i : a)

    cin >> i;

  sort(a.begin() , a.end());

  mint ans = 0;

  for (int i = 0;i < n;i++) {

    ans += -a[i] + a[i + n];

  }

  ans *= ncr(2 * n,n);

  cout << ans.value << endl;



  return 0;

}