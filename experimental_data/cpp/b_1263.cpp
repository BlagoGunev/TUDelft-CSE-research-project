#include <bits/stdc++.h>
using namespace std;

 int main()
 {
     int t;
     cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        map<string,int> mp;
        vector<string> vp;
        for(int i=0;i<n;i++)
        {
            string x;
            cin>>x;
            vp.push_back(x);
            mp[x]++;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        if(mp[vp[i]]>1)
        {
            string s=vp[i];
            int fl=0;
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<10;k++)
                {
                    s=vp[i];
                    s[j]='0'+k;
                    if(mp[s]==0)
                    {
                        mp[vp[i]]--;
                        mp[s]++;
                        sum++;
                        vp[i]=s;
                        fl=1;break;
                    }
                }
                if(fl)break;
            }
        }
        cout<<sum<<"\n";
        for(int i=0;i<n;i++)
        cout<<vp[i]<<endl;
        
    }
 }