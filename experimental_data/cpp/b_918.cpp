#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

using namespace std;

struct con
{
 string name;
 string ip;
}a[1010];
int main()
{
 ios::sync_with_stdio(false);
 int n,m;
 string com,ip0;
 cin>>n>>m;
 for(int i=0;i<n;i++)
 {
  cin>>a[i].name>>a[i].ip;
 }
 for(int i=0;i<m;i++)
 {
  cin>>com>>ip0;
  ip0.pop_back();
  //cout<<com<<" "<<ip0<<endl;  
  for(int j=0;j<1010;j++)
  {
   if(ip0==a[j].ip)
   {
    cout<<com<<" "<<ip0<<"; #"<<a[j].name<<endl;
    break;
   }
  }
 }
 return 0;
}