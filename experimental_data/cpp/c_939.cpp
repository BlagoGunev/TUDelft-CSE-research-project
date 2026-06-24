#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <climits>
using namespace std;
inline int read(){
 int k=0,f=1;char ch=getchar();
 while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
 while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
 return k*f;
}
inline void write(int x){
 if(x<0)x=-x,putchar('-');
 if(x>9)write(x/10);putchar(x%10+'0');
}
inline void writeln(int x){
 write(x);puts("");
}

const int N=100005;
int n;
int a[N];
int S,F;

int main(){
 n = read();
 for(int i = 1;i <= n;++i) a[i] = read();
 S = read(); F = read();
 int now = 0;
 for(int i = S;i < F;++i) now = now+a[i];
 int l = S,r = F-1;
 int ans = now,ans1 = 1;
 for(int i = 2;i <= n;++i){
  now = now-a[r];
  --r; r = r+n;r %= n; if(r == 0) r = n;
  --l; l = l+n;l %= n; if(l == 0) l = n;
  now = now+a[l];
  if(now > ans){
   ans = now;
   ans1 = i;
  }
 }
 writeln(ans1);
 return 0;
}