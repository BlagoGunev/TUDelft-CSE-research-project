//program 383A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}

void output(int x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[10];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

int main()
{
  int n=get(),counter=0;
  long long ans=0;
  for(int i=0;i<n;i++)
    if(get())
      counter++;
    else
      ans+=counter;
  cout<<ans<<endl;
  return 0;
}