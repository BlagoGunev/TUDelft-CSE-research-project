#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int n;
int m;
char s[200000+10];
int dist[200000+10][3][3];
vector<vector<int>> all_cases;
int res[10];
void precalculate(){
  int i;
  int PiIOrLma;
  for(PiIOrLma=(0);PiIOrLma<(3);PiIOrLma++){
    res[PiIOrLma] = PiIOrLma;
  }
  do{
    {
      int i;
      vector<int> casex;
      for(i=(0);i<(3);i++){
        casex.push_back(res[i]);
      }
      all_cases.push_back(casex);
    }
  }
  while(next_permutation(res,res+3));
  for(i=(0);i<(n);i++){
    int j;
    for(j=(0);j<(3);j++){
      int k;
      for(k=(0);k<(3);k++){
        dist[i][j][k] = 0;
      }
    }
  }
  for(i=(0);i<(n);i++){
    dist[i][i % 3][s[i]] ++;
  }
  for(i=(1);i<(n);i++){
    int j;
    for(j=(0);j<(3);j++){
      int k;
      for(k=(0);k<(3);k++){
        dist[i][j][k]  += dist[i-1][j][k] ;
      }
    }
  }
}
int resdiff[3][3];
void disdiff(int x, int y){
  int j;
  memset(resdiff, 0, sizeof(resdiff));
  if(x > y){
    return;
  }
  for(j=(0);j<(3);j++){
    int k;
    for(k=(0);k<(3);k++){
      resdiff[j][k] = dist[y][j][k];
    }
  }
  if(x == 0){
    return;
  }
  for(j=(0);j<(3);j++){
    int k;
    for(k=(0);k<(3);k++){
      resdiff[j][k] -= dist[x-1][j][k];
    }
  }
  return;
}
int main(){
  int i;
  rd(n);
  rd(m);
  rd(s);
  for(i=(0);i<(n);i++){
    s[i] -= 'a';
  }
  precalculate();
  int ucases = all_cases.size();
  for(i=(0);i<(m);i++){
    int j;
    int l;
    int r;
    rd(l);
    rd(r);
    --l;
    --r;
    disdiff(l, r);
    int ansx = 0;
    for(j=(0);j<(3);j++){
      int zjTyjRzb;
      cLtraits_try_make_signed<remove_reference<decltype((*((int*)NULL)))>::type>::type cq90pge_;
      if(3==0){
        cq90pge_ = 0;
      }
      else{
        cq90pge_ = resdiff[j][0];
        for(zjTyjRzb=(1);zjTyjRzb<(3);zjTyjRzb++){
          cq90pge_ += resdiff[j][zjTyjRzb];
        }
      }
      ansx +=cq90pge_;
    }
    int ans = 1073709056;
    for(j=(0);j<(ucases);j++){
      int k;
      vector<int>& a = all_cases[j];
      int tmp = 0;
      for(k=(0);k<(3);k++){
        tmp += resdiff[k][a[k]];
      }
      chmin(ans, ansx - tmp);
    }
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int n, m;
// char s[2d5+10];
// int dist[2d5+10][3][3];
// vector<vector<int>> all_cases;
// int res[10]; 
// void precalculate(){
//     rep_perm( res, 3){
//         vector<int> casex;
//         rep(i, 3){
//             casex.push_back(res[i]);
//         }
//         all_cases.push_back(casex);
//     }
//     rep(i, n) rep(j, 3) rep(k, 3) dist[i][j][k] = 0;
//     rep(i, n){
//         dist[i][i % 3][s[i]] ++;
//     }
//     rep(i, 1,  n){
//         rep(j, 3) rep(k, 3)dist[i][j][k]  += dist[i-1][j][k] ;
//     }
// }
// int resdiff[3][3];
// 
// void disdiff(int x, int y){
//     memset(resdiff, 0, sizeof(resdiff));
//     if(x > y) return;
//     rep(j, 3) rep(k, 3) resdiff[j][k] = dist[y][j][k];
//     if(x == 0){
//         return;
//     }
//     rep(j, 3) rep(k, 3) resdiff[j][k] -= dist[x-1][j][k];
//     return;
// }
// 
// { 
//     rd(n, m, s);
//     rep(i, n) s[i] -= 'a';
//     precalculate();
//     int ucases = all_cases.size();
//     rep(i, m){
//         int l, r;
//         rd(l, r);
//         --l; --r;
//         disdiff(l, r);
//         int ansx = 0;
//         rep(j , 3) {
//             ansx += sum(resdiff[j](3));
//         }
//         int ans = int_inf;
//         rep(j, ucases){
//             vector<int> & a = all_cases[j];
//             int tmp = 0;
//             rep(k, 3){
//                 tmp += resdiff[k][a[k]];
//             }
//             ans <?= ansx - tmp;
//         }
//         wt(ans);
//         
//     }
// }