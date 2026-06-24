#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pb push_back
#define mp make_pair

const int N=2e5+10;

int32_t main()
{
	IOS;
     
     int n,k,i,j;
     
     string s,t="";
     
     cin>>n>>k>>s;
     
     for(i=1;i<n;i++)
     {
          
          string t1="",t2="";
          //t1=s.substr(i,n-i);
          
          for(j=i;j<n;j++)
          t1+=s[j];
          
          for(j=0;j<=(n-i-1);j++)
          t2+=s[j];
          
         // t2=s.substr(0,n-i);
          
         // cout<<t1<<" "<<t2<<endl;
          
          if(t1==t2)
          {
               //t1=s.substr(n-i+1,i-1);
               
               for(j=(n-i);j<n;j++)
               t+=s[j];
               
               break;
          }
     }
     
     if(i==n)
     {
          for(i=1;i<=k;i++)
          cout<<s;
          
          return 0;
     }
     
    // cout<<t<<endl;
     
     cout<<s;

     
     for(i=2;i<=k;i++)
     cout<<t;
     
	return 0;
}