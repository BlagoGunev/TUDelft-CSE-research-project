#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n,k,m;
    cin>>n>>k>>m;
    string s;
    cin>>s;
    string ans="";
    vector<int> a(k,0);
    int counter=0;
    for (int i=0;i<m;i++)
    {
        if (a[s[i]-'a']==0)
        {
            a[s[i]-'a']++;
        }
        char c='t';
        for (int i=0;i<k;i++)
        {
            if (a[i]==0)
            {
                c='f';
                break;
            }
        }
        if (c=='t')
        {
            counter++;
            ans+=s[i];
            for (int i=0;i<k;i++)
            {
                a[i]=0;
            }
        }
    }
    if (counter>=n)
    {
        cout<<"YES"<<endl;
        return;
    }
    else
    {
        cout<<"NO"<<endl;
        for (int i=0;i<k;i++)
        {
            if (a[i]==0)
            {
                ans+=(char)((int)'a'+i);
                break;
            }
        }
    }
    int temp=ans.size();
    while (temp<n)
    {
        ans+='a';
        temp++;
    }
    cout<<ans<<endl;
}

int main() {
  long long t;
  cin >> t;
  while (t--) 
  {
    solve();
  }
  return 0;
}