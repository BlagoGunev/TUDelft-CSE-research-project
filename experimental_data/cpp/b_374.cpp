#include <bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char s[111111];
int main()
{
  fgets(s, sizeof(s), stdin);
  int len=strlen(s);
  int64_t ans=1;
  for(int i=0;i<len;i++){
    int cnt=0;
    while(s[i]+s[i+1]-'0'*2==9)
      {cnt++;i++;}
    if(cnt%2==0&&cnt) ans*=(cnt/2+1);  
  }cout<<ans<<endl;
  cin>>s[1];
}