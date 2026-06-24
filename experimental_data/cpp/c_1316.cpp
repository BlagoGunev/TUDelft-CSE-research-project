#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, p;
signed main()
{
cin.sync_with_stdio(false);
cin.tie(0);
cin >> n >> m >> p;
int a = -1, b = -1;
for(int x, i = 0; i < n; i++)
{
cin >> x;
if(x % p && a == -1) a = i;
}
for(int x, i = 0; i < m; i++)
{
cin >> x;
if(x % p && b == -1) b = i;
}
cout << a + b;
return 0;
}