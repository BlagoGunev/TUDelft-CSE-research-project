#include <set>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
char ch[200001];
int len,fr[200010],s0[200010],cnt0,s1[200010],cnt1,tot;
inline int read()
{
 int x=0,f=1;char ch=getchar();
 while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
 while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
 return x*f;
}
inline void write(int x)
{
 if (x<0) putchar('-'),x=-x;
 if (x>9) write(x/10);
 putchar(x%10+'0');
}
void prin(int x)
{
 tot++;
 if (fr[x]) prin(fr[x]),putchar(' '),write(x);
 else write(tot),putchar(' '),write(x);
}
void getans()
{
 for (int i=1;i<=len;i++)
 if (ch[i]=='0')
 {
  if (cnt1) fr[i]=s1[cnt1--];
  s0[++cnt0]=i;
 }
 else
 {
  if (cnt0==0)
  {
      puts("-1");
   exit(0);
  }
  fr[i]=s0[cnt0--];
  s1[++cnt1]=i;
 } 
}
int main()
{
 scanf("%s",ch+1);len=strlen(ch+1);
    getans();
 if (cnt1) 
 {
     puts("-1");
  return 0;
 }
 write(cnt0),putchar('\n');
 for(int i=1;i<=cnt0;i++)tot=0,prin(s0[i]),putchar('\n');
 return 0;
}