#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll SIZE = (ll)1e5;
const ll INF = (ll)1e9 + 7;
const ld EPS = (ld)1e-9;

int mpd(int x)
{
 int res = 1;
    for (int i = 2; i*i <= x; i++)
  if (x % i == 0)
        {
            while (x % i == 0)
    x /= i;
   res = i;
        }
 return (res == 1) ? 1 : max(res, x);
}

int main()
{
 cin.tie(NULL);
 cout.tie(NULL);
 ios_base::sync_with_stdio(false);
/*
 int n, nn;
 cin >> n;
 nn = n;
    for (int i = 2; i <= (int)sqrt(n); i++)
  if (nn % i == 0)
  {
   while (nn % i == 0)
    nn /= i;
   cout << i << ' ';
  }
 if ((nn > 1) && (nn < n))
  cout << nn;
/**/
    int n;
    cin >> n;

    int div = mpd(n);

 int mn = INF;
    for (int i = n - div + 1, ii; i <= n; i++)
    {
  div = mpd(i);
     mn = min(mn, i - div + 1);
        if (2*div == i)
   break;
 }
    cout << mn;
/**/
    return 0;
}