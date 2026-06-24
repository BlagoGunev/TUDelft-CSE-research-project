#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int INF=1e9+5;
int read(int &a){scanf("%d",&a);return a;}
int read(){int a;scanf("%d",&a);return a;}
int read(int &a,int &b){scanf("%d %d",&a,&b);return a;}
#define mem(a) memset(a,0,sizeof a)
string s;
bool check(string ss)
{
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]!=ss[ss.size()-i-1])
            return false;
    }
    return true;
}
int main()
{
    cin>>s;
    if(s.size()<=3)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    bool flag=true;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]!=s[i-1])
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(s.size()&1)
    {
        flag=true;
        for(int i=1;i<s.size()/2;i++)
        {
            if(s[i]!=s[i-1])
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    flag=false;
    string ss;
    for(int i=1;i<s.size();i++)
    {
        ss=s.substr(i,s.size()-i)+s.substr(0,i);
        //cout<<ss<<endl;
        if(check(ss)&&ss!=s)
        {
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<1<<endl;
    else
        cout<<2<<endl;
    return 0;
}