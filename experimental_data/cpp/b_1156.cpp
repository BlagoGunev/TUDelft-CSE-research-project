#include<bits/stdc++.h>
using namespace std;
int mp[30];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(mp,0,sizeof mp);
        string s;
        cin>>s;
        //cout<<((s[0]+1)==s[1])<<endl;
        int len=s.size();
        for(int i=0;i<len;++i)
            mp[s[i]-'a']++;
        string ans="",ans1="";
        //cout<<"*"<<endl;
//        for(int i=0;i<26;++i)
//            if(mp[i]) cout<<(char)(i+'a');
        //cout<<endl;
        for(int i=24;i>=0;i-=2)
        {
            int tmp=mp[i];
            while(tmp>0)
            {
                //cout<<mp[s[i]-'a']<<endl;
                ans+=(char)('a'+i);
                tmp--;
            }
        }
        for(int i=25;i>=0;i-=2)
        {
            int tmp=mp[i];
            while(tmp>0)
            {
                //cout<<mp[s[i]-'a']<<endl;
                ans+=(char)('a'+i);
                tmp--;
            }
        }
        for(int i=0;i<26;i+=2)
        {
            int tmp=mp[i];
            while(tmp>0)
            {
                //cout<<mp[s[i]-'a']<<endl;
                ans1+=(char)('a'+i);
                tmp--;
            }
        }
        for(int i=1;i<26;i+=2)
        {
            int tmp=mp[i];
            while(tmp>0)
            {
                //cout<<mp[s[i]-'a']<<endl;
                ans1+=(char)('a'+i);
                tmp--;
            }
        }
        bool flag=0,flag1=0;
        for(int i=0;i<len-1;++i)
        {
            if((ans[i]+1==ans[i+1]) || (ans[i]-1==ans[i+1])) flag =true;
            if((ans1[i]+1==ans1[i+1]) || (ans1[i]-1==ans1[i+1])) flag1 =true;
        }
        //cout<<ans<<endl;
        if(!flag) cout<<ans<<endl;
        else if(!flag1) cout<<ans1<<endl;
        else cout<<"No answer"<<endl;
    }
}