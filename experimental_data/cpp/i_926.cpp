#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <iostream>
#include <functional>
#include <complex>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pii, int> p3i;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vii;
typedef vector<p3i> v3i;
typedef vector<vii> vvii;
typedef vector<p3i> vp3i;
typedef long double ld;
typedef vector<ld> vld;
typedef vector<pii> vpii;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define REPD(i, n) for (int (i) = (n) - 1; (i) >= 0; (i)--)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define FORD(i,a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rv(v) reverse(all(v))
#define CL(v, val) memset((v), (val), sizeof((v)))
#define SORT(a) sort(all(a))
#define un(v) SORT(v), (v).resize(unique(all(v)) - (v).begin())
#define eps 1.0e-6
#define X first
#define Y second
#define bit(n) (1 << (n))
#define bit64(n) (ll(1) << (n))
#define sqr(n) ((n) * (n))
#define INF 1000000007
#define MAXN 10000+5

struct cl
{

};

int F(string str)
{
 int res = 0;
 if (sz(str) == 2)
 {
  res = (int)(str[0] - '0') * 10 + (int)(str[1] - '0');
 }
 else
 {
  res = (int)(str[0] - '0');
 }
 return res;
}

int main()
{
 int n;
 cin >> n;
 vi arr;
 REP(i, n)
 {
  string str;
  cin >> str;
  int h, m, c;
  string str1;
  str1 += str[0];
  str1 += str[1];
  h = F(str1);
  str1 = "";
  str1 += str[3];
  str1 += str[4];
  m = F(str1);
  c = 60 * m + 3600 * h;
  arr.pb(c);
 }
 SORT(arr);
 int ans = 0;
 REP(i, sz(arr) - 1)
 {
  ans = max(ans, arr[i + 1] - arr[i] - 60);
 }
 if (n == 1)
 {
  cout << "23:59";
  return 0;
 }
 ans = max(ans, (24 * 3600 + arr[0]) - arr[n - 1] - 60);
 int ansH = ans / 3600;
 int ansM = (ans - ansH * 3600) / 60;
 string out;
 if (ansH < 10)
 {
  out += "0";
  out += (char)('0' + ansH);
  out += ":";
 }
 else
 {
  out += (char)('0' + ansH / 10);
  out += (char)('0' + ansH % 10);
  out += ":";
 }
 if (ansM < 10)
 {
  out += "0";
  out += (char)('0' + ansM);
 }
 else
 {
  out += (char)('0' + ansM / 10);
  out += (char)('0' + ansM % 10);
 }
 cout << out;
 return 0;
}