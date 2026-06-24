#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
int n,q;
int a[N],Tree[4 * N];

int gcd(int a,int b){return (b==0?a:gcd(b,a%b));}

int buildTree(int l = 0, int r = n - 1, int id = 0) {
  int mid = (l + r) / 2;
  return Tree[id] = (l == r) ? a[r] : gcd(buildTree(l, mid,  2 * id + 1),buildTree(mid + 1, r, 2 * id + 2));
}

int getGcd(int ql, int qr, int l = 0, int r = n - 1, int id = 0) {
  if (l >= ql && r <= qr) {
    return Tree[id];
  }
  if (r < ql || l > qr) {
    return -1;
  }
  int mid = (l + r) / 2;
  if (r == l) {
    return Tree[id];
  } else {
    int gcd1 = getGcd(ql, qr, l, mid, 2 * id + 1);
    int gcd2 = getGcd(ql, qr, mid + 1, r, 2 * id + 2);
    if (min(gcd1, gcd2) == -1) {
      return max(gcd1, gcd2);
    }
    return gcd(gcd1, gcd2);
  }
}

int getRightBoundIndex(int l, int mid) {
  if (getGcd(l, n - 1) != 1) {
    return -1;
  }
  int hi = n - 1;
  if (getGcd(l, mid) == 1) {
    return mid;
  }
  int lo = mid;
  while(hi - lo > 1) {
    int m = (hi + lo) / 2;
    if (getGcd(l, m) == 1) {
      hi = m;
    } else {
      lo = m;
    }
  }
  return hi;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  buildTree();
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    if (getGcd(i, n - 1) != 1) {
      break;
    }
    int hi = n - 1;
    if (a[i] == 1) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (a[j] != 1) {
          cnt++;
        }
      }
      cout << cnt;
      return 0;
    }
    int lo = i;
    while (hi - lo > 1) {
      int mid = (hi + lo) / 2;
      if (getGcd(i, mid) == 1) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    ans = min(ans, hi - i - 1 + (n - 1));
  }
  if (ans == 1e9) {
    cout << -1;
  } else {
    cout << ans + 1;
  }
}