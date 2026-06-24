#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

struct line {
  ll a, b, c;
};

vector<line> lines;
ll res[101][16];

mat mult(mat &a, mat &b) {
  mat res(a.size(), vector<ll>(a.size()));
  for (int i = 0; i < (int)a.size(); i++) {
    for (int k = 0; k < (int)a.size(); k++) {
      for (int j = 0; j < (int)a.size(); j++) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 0; j < (int)a.size(); j++) {
      res[i][j] %= MOD;
    }
  }
  return res;
}

mat power(mat &a, ll e) {
  mat res(a.size(), vector<ll>(a.size()));
  for (int i = 0; i < (int)a.size(); i++) {
    res[i][i] = 1;
  }
  while (e >= 1) {
    if (e == 1) return mult(res, a);
    else if (e & 1) {
      res = mult(res, a);
      a = mult(a, a);
      e = (e - 1) / 2;
    } else {
      a = mult(a, a);
      e /= 2;
    }
  }
  return res;
}

mat init(int dim, int upper) {
  mat res(dim, vector<ll>(dim));
  for (int i = 0; i < dim; i++) {
    if (i > upper) break;
    else if (i == upper) {
      for (int j = max(0, i - 1); j <= i; j++) {
        res[i][j] = 1;
      }
    } else {
      for (int j = max(0, i - 1); j <= min(i + 1, dim); j++) {
        res[i][j] = 1;
      }
    }
  }
  return res;
}

vec vecMult(mat &m, vec &v) {
  vec res(v.size());
  for (int i = 0; i < (int)v.size(); i++) {
    for (int j = 0; j < (int)v.size(); j++) {
      res[i] += v[j] * m[i][j];
    }
    res[i] %= MOD;
  }
  return res;
}

void print(mat &m) {
  for (int i = 0; i < (int)m.size(); i++) {
    for (int j = 0; j < (int)m.size(); j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k;
  cin >> n >> k;
  lines.resize(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> lines[i].a >> lines[i].b >> lines[i].c;
  }
  res[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    ll diff = min(lines[i].b, k) - lines[i].a;
    mat lin = init(lines[i].c + 1, lines[i].c);

    //print(lin);

    lin = power(lin, diff);

    vec val(lines[i].c + 1);
    for (int j = 0; j < lines[i].c + 1; j++) {
      val[j] = res[i - 1][j];
    }
    vec tmp = vecMult(lin, val);
    for (int j = 0; j < lines[i].c + 1; j++) {
      res[i][j] = tmp[j];
    }
  }
  cout << res[n][0] << endl;
  return 0;
}