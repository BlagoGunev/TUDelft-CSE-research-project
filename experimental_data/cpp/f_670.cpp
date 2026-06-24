#include <bits/stdc++.h>

#define F first
#define S second
#define llong long long
#define ullong unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define sz(v) (int)v.size()

using namespace std;

const int MXN = (int)1e6 + 10;
const int INF = (int)1e9 + 7;
const llong LINF = (llong)1e18 + 10;
const double EPS = (double)1e-9;
const double PI = (double)acos(-1.0);

string s1, s2;
int cnt[20], cnt1[20];
int flag;
string s[30];

inline int len_num(int x){
  int res = 0;
  for(;x ;x /= 10, ++res);
  return res;
}

inline bool can(int x){
  for(int i = 0; i < 10; ++i){
    cnt1[i] = 0;
  }
  while(x){
    cnt1[x % 10]++;
    x /= 10;
  }
  for(int i = 0; i < 10; ++i){
    if(cnt1[i] > cnt[i])
      return false;
  }
  return true;
}

string del(int x){
  int num = sz(s1) - x;
  if(!(x < sz(s1) && can(num) && len_num(num) == x))
    return "A";
  for(int i = 0; i < 10; ++i){
    cnt1[i] = cnt[i];
  }
  int num1 = num;
  while(num1){
    cnt1[num1 % 10]--;
    num1 /= 10;
  }
  string ret = "";
  for(int i = 1; i < 10; ++i){
    if(cnt1[i]){
      ret += char('0' + i);
      cnt1[i]--;
      break;
    }
  }
  for(int i = 0; i < 10; ++i){
    if((s2[0] - '0') == i && flag <= 1)
      ret += s2;
    for(int j = 0; j < cnt1[i]; ++j){
      ret += char(i + '0');
    }
    if((s2[0] - '0') == i && flag == 2)
     ret += s2;
  }
  if(sz(ret) > 1 && ret[0] == '0')
    return "A";
  return ret;
}

string del1(int x){
  int num = sz(s1) - x;
  if(!(x < sz(s1) && can(num) && len_num(num) == x))
    return "A";
  for(int i = 0; i < 10; ++i){
    cnt1[i] = cnt[i];
  }
  int num1 = num;
  while(num1){
    cnt1[num1 % 10]--;
    num1 /= 10;
  }
  string ret = "";
  if(s2[0] == '0'){
    for(int i = 1; i < 10; ++i){
      if(cnt1[i]){
        ret += char('0' + i);
        cnt1[i]--;
        break;
      }
    }
  }
  ret += s2;
  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < cnt1[i]; ++j){
      ret += char(i + '0');
    }
  }
  if(sz(ret) > 1 && ret[0] == '0')
    return "A";
  return ret;
}

int main(){
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin >> s1 >> s2;
  for(int i = 0; i < sz(s1); ++i){
    cnt[s1[i] - '0']++;
  }
  //0 -> all are equal
  //1 -> smaller
  //2 -> bigger
  flag = 0;
  for(int i = 1; i < sz(s2); ++i){
    if(s2[i] != s2[0]){
      if(s2[i] > s2[0])
        flag = 2;
      else
        flag = 1;
      break;
    }
  }
  for(int i = 0; i < sz(s2); ++i){
    cnt[s2[i] - '0']--;
  }
  for(int i = 1; i <= 7; ++i){
    s[i] = del(i);
  }
  for(int i = 1; i <= 7; ++i){
    s[i + 7] = del1(i);
  }
  string ans = "B";
  for(int i = 1; i <= 14; ++i){
    ans = min(ans, s[i]);
    //cerr << s[i] << "\n";
  }
  assert(isdigit(ans[0]));
  cout << ans;
  return 0;
}