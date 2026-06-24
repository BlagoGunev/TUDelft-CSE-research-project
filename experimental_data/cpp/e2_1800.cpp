#include <bits/stdc++.h>
using namespace std;
const int N=114514*2;
int a[N],T,b[N],num,n,m,k;
string s,s1,s2,ss;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>s>>ss;
        memset(a,0,sizeof a);memset(b,0,sizeof b);
        bool flag=1;
        for(int i=0;i<n;i++) a[s[i]]++,b[ss[i]]++;
        for(int i=0;i<26;i++)
        {
            if(a['a'+i]!=b['a'+i])
            {
                flag=0;
                cout<<"NO"<<endl;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i+k>=n&&i-k<0&&s[i]!=ss[i]&&flag==1)
            {
                flag=0;
                cout<<"NO"<<endl;
            }
        }
        if(flag) cout<<"YES"<<endl;
    }
    return 0;
}