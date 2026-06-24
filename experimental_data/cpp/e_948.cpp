//It is made by Awson on 2018.3.11
#include <bits/stdc++.h>
#define LL long long
#define dob complex<double>
#define Abs(a) ((a) < 0 ? (-(a)) : (a))
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Swap(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))
#define writeln(x) (write(x), putchar('\n'))
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int N = 1e5;
void read(int &x) {
    char ch; bool flag = 0;
    for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1); ch = getchar());
    for (x = 0; isdigit(ch); x = (x<<1)+(x<<3)+ch-48, ch = getchar());
    x *= 1-2*flag;
}
void print(int x) {if (x > 9) print(x/10); putchar(x%10+48); }
void write(int x) {if (x < 0) putchar('-'); print(Abs(x)); } 

char ch[N+5];
int s1[N+5], s2[N+5], len, q, a, b, c, d;
int l1[N+5], l2[N+5];

void work() {
 scanf("%s", ch+1); len = strlen(ch+1);
 for (int i = 1; i <= len; i++) s1[i] = s1[i-1]+(ch[i] != 'A'), l1[i] = (ch[i] == 'A' ? l1[i-1]+1 : 0);
 scanf("%s", ch+1); len = strlen(ch+1);
 for (int i = 1; i <= len; i++) s2[i] = s2[i-1]+(ch[i] != 'A'), l2[i] = (ch[i] == 'A' ? l2[i-1]+1 : 0);
 read(q);
 while (q--) {
  read(a), read(b), read(c), read(d);
  int ss = s1[b]-s1[a-1], st = s2[d]-s2[c-1], ls = Min(b-a+1, l1[b]), lt = Min(d-c+1, l2[d]);
  if (ss > st) {write(0); continue; }
  if (ss == st) {
   if (ls < lt) {write(0); continue; }
   if ((ls-lt)%3) write(0); else write(1);
   continue;
  }
  if (ss == 0) {
   if (st%2) {write(0); continue; }
   if (ls <= lt) {write(0); continue; }
   if ((ls-lt)%3 > st) write(0); else write(1);
   continue;
  }
  if (ss < st) {
   if ((st-ss)%2) {write(0); continue; }
   if (ls < lt) {write(0); continue; }
   if ((ls-lt)%3 > st-ss) write(0); else write(1);
   continue;
  }
 }
}
int main() {
 work(); return 0;
}