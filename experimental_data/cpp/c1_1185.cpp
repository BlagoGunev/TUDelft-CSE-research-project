#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, ttl = 0;
  vector<int> st;
  priority_queue<int> std;
  cin >> n >> m;
  st.resize(n);
  for(int x = 0; x < n; x++)
  {
    priority_queue<int> q = std;
    int acc, r = 0;
    cin >> st[x];
    ttl += st[x];
    acc = ttl;
    std.push(st[x]);
    while(acc > m)
    {
      acc -= q.top();
      q.pop();
      r++;
    }
    cout << r << " ";
  }
}