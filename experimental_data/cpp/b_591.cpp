#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
using namespace std;
inline void readchar(char &ch) {while ((ch=getchar())<'a' || ch>'z');}
inline void read(int &x) {char ch;while ((ch=getchar())<'0' || ch>'9');x=ch-'0';while ((ch=getchar())<='9' && ch>='0') x=x*10+ch-'0';}

char s[200010];
char tra[256],trb[256];
int n,m;

int main()
{
 scanf("%d%d",&n,&m);
 for (int i=1;i<=n;i++) readchar(s[i]);
 for (int i=0;i<256;i++) tra[i]=char(i),trb[i]=char(i);
 for (int i=1;i<=m;i++)
 {
  char ch1,ch2;
  readchar(ch1),readchar(ch2);
  swap(trb[ch1],trb[ch2]);
  tra[trb[ch1]]=ch1;tra[trb[ch2]]=ch2;
 }
 for (int i=1;i<=n;i++) putchar(char(tra[s[i]]));
 putchar('\n');
 return 0;
}