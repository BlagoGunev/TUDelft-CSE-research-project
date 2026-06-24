#include<bits/stdc++.h>
using namespace std;
string ito(int n)
{
    string s;
    while(n!=0)
    {
        int p=n%10;
        s+=(char)(p+'0');
        n/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}

main()
{
    int l,r;
    cin>>l>>r;
    for(int i=l;i<=r;i++)
    {
        string s=ito(i);
 //       itoa(i,s,10);
        int c[10];
        memset(c,0,sizeof c);
        bool f=true;
        for(int j=0;j<s.size();j++)
        {
            if(c[s[j]-'0']==0)
            {

            }
            else f=false;
            c[s[j]-'0']=1;
        }
        if(f)
        {
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<-1;
}