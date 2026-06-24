#include<bits/stdc++.h>
using namespace std;
typedef int sign;
typedef long long ll;
#define For(i,a,b) for(register sign i=(sign)a;i<=(sign)b;++i)
#define Fordown(i,a,b) for(register sign i=(sign)a;i>=(sign)b;--i)
const int N=1e5+5;
bool cmax(sign &a,sign b){return (a<b)?a=b,1:0;}
bool cmin(sign &a,sign b){return (a>b)?a=b,1:0;}
template<typename T>T read()
{
  T ans=0,f=1;
  char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch-'0'),ch=getchar();
  return ans*f;
}
template<typename T>void write(T x,char y)
{
  if(x==0)
  {
      putchar('0');putchar(y);
      return;
  }
  if(x<0)
  {
      putchar('-');
      x=-x;
  }
  static char wr[20];
  int top=0;
  for(;x;x/=10)wr[++top]=x%10+'0';
  while(top)putchar(wr[top--]);
  putchar(y);
}
void file()
{
  #ifndef ONLINE_JUDGE
      freopen("c.in","r",stdin);
      freopen("c.out","w",stdout);
  #endif
}
int n;
ll a[N];
void input()
{
 n=read<int>();
 For(i,1,n)a[i]=read<ll>();
}
ll ans=0,dp[N];
void work()
{
 For(i,1,n)dp[i]=max(dp[i-1],a[i]);
 //For(i,1,n)write(dp[i],i==n?'\n':' ');
 Fordown(i,n,1)dp[i]=max(dp[i],dp[i+1]-1);
 //For(i,1,n)write(dp[i],i==n?'\n':' ');
 For(i,1,n)ans+=dp[i]-a[i];
 write(ans,'\n');
}
int main()
{
 file();
 input();
 work();
 return 0;
}