#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<bitset>
#include<queue>
#include<ctime>
using namespace std;

typedef long long int64;
const int maxn=1010;
bool b[maxn];
int a[maxn];
int n,m,k,l,r;
string st;

void init()
  {
   cin>>st;
  }

void solve()
  {
   memset(b,0,sizeof(b));
   st+=',';k=0;n=0;
   for (int i=0;i<st.length();i++)
     {
      if (st[i]==',')
        {
         if (!b[k]) {b[k]=true;a[n++]=k;}
         k=0;
        }
      else k=k*10+st[i]-'0';
     }
   sort(a,a+n);
   bool flag=false;
   l=r=a[0];
   for (int i=1;i<n;i++)
     if (a[i]==r+1)
       {
        r=a[i];
       }
     else 
       {
        if (!flag) flag=true; else cout<<",";
        if (l==r) cout<<l; else cout<<l<<"-"<<r;
        l=r=a[i];
       }
   if (!flag) flag=true; else cout<<",";
   if (l==r) cout<<l; else cout<<l<<"-"<<r;
   cout<<endl;
  }

int main()
  {
   //freopen("page.in","r",stdin);
   //freopen("page.out","w",stdout);
   init();
   solve();
   return 0;
  }