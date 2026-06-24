#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

char str[200005]={0};
string ans;

vector<long> cur;

int main()
{
 long n,k;
 long i,j;
 char ch;
 
 scanf("%s",str+1);
 scanf("%ld",&k);
 
 n=strlen(str+1);
 for(i=0;i<n;i++)
   cur.push_back(i);
   
 for(;cur.size();)
   {
    vector<long> sub;
    long long sum=0;
    
    for(ch='a';ch<='z';ch++)
      {
       for(i=0,sum=0;i<cur.size();i++)
         if(str[cur[i]+1]==ch)
          sum+=n-cur[i];
       if(sum<k)
        k-=sum;
       else
        break;
      }
    if(ch>'z')
     {
      printf("No such line.\n");
      return 0;
     }
    
    ans+=ch;
    for(i=0,sum=0;i<cur.size();i++)
      if(str[cur[i]+1]==ch)
       {
        sum++;
        if(cur[i]+1<n)
         sub.push_back(cur[i]+1);
       }
    if(sum>=k)
     {
      cout<<ans<<endl;
      return 0;
     }
    else
     k-=sum;
    cur=sub;
   }
 
 printf("No such line.\n");
 return 0;
}