#include <bits/stdc++.h>
#define mp mkae_pair
#define pb push_back
#define ll long long
#define all(x) x.begin(),x.end()

using namespace std;

const int MX=3000000;
int lp[MX+1];
map<int,int> was;
vector<int> pr;
int a[100005];


vector<int> f( int x)
{
          vector<int> res;
          for(int i=2;i*i<=x;i++)
                    if(x%i==0)
                    {
                              res.pb(i);
                              while(x%i==0)
                                        x/=i;
                    }
          if(x>1)
                    res.pb(x);
          return res;
}
int main()
{
          ios_base::sync_with_stdio(0);
          for (int i=2; i<MX; ++i)
          {
                    if (lp[i] == 0)
                    {
                              lp[i]=i;
                              pr.push_back(i);
                    }
                    for (int j=0; j<pr.size() && pr[j]<=lp[i] && i*pr[j]<MX; ++j)
                              lp[i*pr[j]] = pr[j];
          }
          int n;
          cin>>n;
          vector<int> ans;
          for(int i=0;i<n;i++)
          {
                    cin>>a[i];
                    vector<int> dils=f(a[i]);
                    bool have=0;
                    for(int j=0;j<dils.size();j++)
                              if(was.count(dils[j]))
                                        have=1;
                    if(have)
                    {
                              bool fnd=0;
                              for(int k=a[i]+1;k<a[i]+10000;k++)
                              {
                                        vector<int> cur=f(k);
                                        bool hav=0;
                                        for(int j=0;j<cur.size();j++)
                                                  if(was.count(cur[j]))
                                                            hav=1;
                                        if(!hav)
                                        {
                                                  ans.pb(k);
                                                  for(int j=0;j<cur.size();j++)
                                                            was[cur[j]]=1;
                                                  break;
                                        }
                              }
                              for(int j=0;j<pr.size();j++)
                                        if(!was.count(pr[j]))
                                                  ans.pb(pr[j]);
                              break;
                    }
                    else
                    {
                              ans.pb(a[i]);
                              for(int j=0;j<dils.size();j++)
                                        was[dils[j]]=1;
                    }
          }
          for(int i=0;i<n;i++)
                    cout<<ans[i]<<" ";
}