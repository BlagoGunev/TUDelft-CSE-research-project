#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int MAXN = 2e5 + 3;

int n, a[MAXN];
int pre[MAXN], nxt[MAXN];
bool vis[MAXN];

bool check(int i){
  return (pre[i] > 0 && a[pre[i]] == a[i] - 1) || (nxt[i] > 0 && a[nxt[i]] == a[i] - 1);
}

void work(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i], vis[i] = 0;
    pre[i] = i - 1, nxt[i] = (i == n ? 0 : i + 1);
  }
  priority_queue<PII> que;
  
  for(int i = 1; i <= n; i++){
    if(check(i)) que.push({a[i], i}), vis[i] = 1;
  }
  while(!que.empty()){
    int i = que.top().second;
    que.pop();
    nxt[pre[i]] = nxt[i], pre[nxt[i]] = pre[i], vis[i] = 1;
    if(pre[i] > 0 && vis[pre[i]] != 1 && check(pre[i])) vis[pre[i]] = 1, que.push({a[pre[i]], pre[i]});
    if(nxt[i] > 0 && vis[nxt[i]] != 1 && check(nxt[i])) vis[nxt[i]] = 1, que.push({a[nxt[i]], nxt[i]});
  }
  int cnt = 0;
  for(int i = 1; i <= n; i++){
    if(a[i] > 0 && vis[i] == 0){
      cout << "NO\n";
      return;
    }
    cnt += a[i] == 0;
  }
  if(cnt != 1){
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int main(){
  int T;
  cin >> T;
  while(T--) work();
  return 0;
} 
/*
1
7
0 1 1 2 3 4 4

YES
*/