#include <bits/stdc++.h>

using namespace std;

#define  N  12345678

struct Trie {
 int id;
 Trie *ch[2], *fail;
}pool[N], *cur = pool, *root;

Trie *newNode() {
 cur->ch[0] = cur->ch[1] = cur->fail = NULL;
 cur->id = -1;
 return cur++;
}

void insert(char s[], int len, int id) {
 Trie *now = root;
 for (int i = 0; i < len; i++) {
  if (now->ch[s[i]-'a'] == NULL)
   now->ch[s[i]-'a'] = newNode();
  now = now->ch[s[i]-'a'];
 }
 now->id = id;
}

void buildFail() {
 queue<Trie*> que;
 que.push(root);
 while (!que.empty()) {
  Trie *u = que.front();
  que.pop();
  for (int i = 0; i < 2; i++) {
   if (u->ch[i] != NULL) {
    Trie *tmp = u->fail;
    while (tmp != NULL && tmp->ch[i] == NULL)
     tmp = tmp->fail;
    u->ch[i]->fail = tmp != NULL ? tmp->ch[i] : root;
    if (u->ch[i]->id == -1)
     u->ch[i]->id = u->ch[i]->fail->id;
    que.push(u->ch[i]);
   }
  }
 }
}

bool contain[800][800];
void getContain(char s[], int len, int id) {
 Trie *now = root;
 for (int i = 0; i < len; i++) {
  now = now->ch[s[i]-'a'];
  if (now->id != -1)
   contain[id][now->id] = true;
  if (now->fail && now->fail->id != -1)
   contain[id][now->fail->id] = true;
 }
}

int n;
bool visit[800];
int lx[800], ly[800];
bool find(int u) {
 for (int v = 0; v < n; v++) {
  if (contain[u][v] && !visit[v]) {
   visit[v] = true;
   if (ly[v] == -1 || find(ly[v])) {
    lx[u] = v, ly[v] = u;
    return true;
   }
  }
 }
 return false;
}

char name[N];
int off[800], len[800];
bool process[800];
int main() {
 scanf("%d", &n);

 int slen = 0;
 for (int i = 0; i < n; i++) {
  scanf("%s", &name[slen]);
  off[i] = slen;
  len[i] = strlen(name+slen);
  slen += len[i];
 }

 root = newNode();
 for (int i = 0; i < n; i++)
  insert(name + off[i], len[i], i);

 buildFail();
 for (int i = 0; i < n; i++)
  getContain(name + off[i], len[i], i);

 vector<pair<int, int>> sname;
 for (int i = 0; i < n; i++)
  sname.push_back({len[i], i});
 sort(sname.begin(), sname.end());

 for (auto p : sname) {
  int i = p.second;
  for (int j = 0; j < n; j++) {
   if (contain[i][j] && i != j) {
    for (int k = 0; k < n; k++)
     contain[i][k] |= contain[j][k];
   }
  }
 }


 for (int i = 0; i < n; i++)
  contain[i][i] = false;

 memset(lx, -1, sizeof lx);
 memset(ly, -1, sizeof ly);
 int num = 0;
 for (int i = 0; i < n; i++) {
  memset(visit, false, sizeof visit);
  if (find(i))
   num++;
 }
 vector<int> ans;
 for (int i = 0; i < n; i++)
  if (ly[i] == -1)
   ans.push_back(i);

 while (true) {
  bool noContain = true;
  for (int i = 0; i < ans.size(); i++) {
   for (int j = 0; j < ans.size(); j++) {
    if (contain[ans[i]][ans[j]]) {
     noContain = false;
     ans[i] = lx[ans[i]];
    }
   }
  }
  if (noContain)
   break;
 }
 cout << ans.size() << endl;
 for (int v : ans)
  cout << v + 1 << " ";

 return 0;
}