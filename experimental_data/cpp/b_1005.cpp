#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
 
      
 
int main(void)
{
    fio;
  string s,t;
  int i,n,n1,c,sum=0;
  cin>>s>>t;
  n=s.length();
  n1=t.length();
  c=n1-1;i=n-1;
  while(i>=0 && c>=0){
      if(s.at(i)==t.at(c)){
     
      c--;i--;
      }
      else{
      break;}
  }
  sum=c+i+2;
  cout<<sum;
    return 0;
}