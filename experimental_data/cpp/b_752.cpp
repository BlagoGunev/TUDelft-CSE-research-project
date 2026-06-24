/* (Codeforces)     ::

    coded by-> @draco_nian
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long lld;

#define    MAX       1000005
#define    pb        push_back
#define  rep(i,a,b)  for(lld i=a;i<b;i++)
#define  repe(i,a,b) for(lld i=a;i<=b;i++)
#define  reps(it,o)  for(auto it=o.begin();it!=o.end();it++)

lld v[300];
int main()
{
  std::ios::sync_with_stdio(false);	
  
  string s,t;
  cin>>s>>t;
  
  lld l=s.size();
  
  map<char,char > m1,m2;
  set<pair<char,char > > se;
  set<pair<char,char > > ::iterator it; 
  rep(i,0,l)
  {
  	
  	if((v[s[i]]==0 && v[t[i]]==0)||(v[s[i]]==t[i] && v[t[i]]==s[i]))
  	{
	   v[s[i]]=t[i];
  	   v[t[i]]=s[i];
  	   
  	   //cout<<s[i]<<" "<<t[i]<<"\n";
  	   if(t[i]<s[i])
  	   se.insert(make_pair(t[i],s[i]));
  	   else if(t[i]>s[i])
  	   se.insert(make_pair(s[i],t[i]));
  	   
  	   
    }
    else
    {
    	cout<<"-1\n";
    	return 0;
	}
  	
  }
  
  cout<<se.size()<<"\n";
  
  for(it=se.begin();it!=se.end();it++)
  cout<<it->first<<" "<<it->second<<"\n";
  
  
  
  
  

}