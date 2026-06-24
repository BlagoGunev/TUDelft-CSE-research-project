#include <bits/stdc++.h>
using namespace std;
const int x=1000005;
int main()
{
  int testcases;
  cin>>testcases;
  while(testcases--)
  {
      string s1,s2;
      cin>>s1>>s2;
      int n=s1.size();
      int m=s2.size();
      bool flag=1;
      for(int i=0;i<n;i++)
      {
          if(s1[i]==s2[0])
          {
              string res="";
          for(int j=i;j<n;j++)
          {
              res+=s1[j];
              if(res.size()>m) break;
              int cnt=0;
              for(int k=j-1;k>=0;k--)
              {
                  if(res.size()==m) break;
                  res+=s1[k];
                  cnt++;
              }
              if(res==s2)
              {
                  cout<<"Yes\n";
                  flag=0;
                  break;
              }
              while(cnt--) res.pop_back();
          }
          }
          if(flag==0) break;
      }
      if(flag==1)
      {
          cout<<"No\n";
      }
  }
    return 0;
}