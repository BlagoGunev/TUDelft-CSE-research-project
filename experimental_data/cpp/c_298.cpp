#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>

using namespace std;

int main ()
{
  string a,b;
  int i,j,n,a1=0,b1=0;
  cin>>a;
  cin>>b;
  n=a.size();
  for(i=0;i<n;i++)
  {
    if(a[i]=='1')a1++;
  }
  n=b.size();
  for(i=0;i<n;i++)
  {
    if(b[i]=='1')b1++;
  }
  if(a1%2==1)a1++;
  if(a1>=b1)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
    return 0;
}