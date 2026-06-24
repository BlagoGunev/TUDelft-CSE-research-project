#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<int> v;
        vector<int> v1;
        for(int i=0;i<s.size();i++)
        {
            int a=int(s[i])-48;
            v.push_back(a);
        }
        int help=0;
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]>=5)
            {
                help++;
            }
            v1.push_back(help);
        }
        int dis=0;
        for(int i=v.size()-1;i>0;i--)
        {
            if(v[i]>=5)
            {
                v[i]=0;
                v[i-1]+=1;
                dis=1;
            }
            else if(v1[i-1]>0)
            {
                v[i]=0;
            }
        }
        if(v[0]>=5)
        {
            dis=1;
            v[0]=10;
        }
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i];
        }
        cout<<endl;
    }
}