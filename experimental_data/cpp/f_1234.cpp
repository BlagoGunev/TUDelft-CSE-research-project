#include <bits/stdc++.h>
using namespace std;
string s;
int n,start,fin,ans[1100000],state,num,fuck;
set<char> st;
int main()
{
    cin>>s;
    n=s.size();
    for(;start<n;start++)
    {
        while(fin<n&&st.find(s[fin])==st.end())
        {
            st.insert(s[fin]);
            state+=(1<<(s[fin]-'a'));
            num++;
            ans[state]=num;
            fin++;
        }
        st.erase(s[start]);
        state-=(1<<(s[start]-'a'));
        num--;
        ans[state]=num;
    }
    for(int i=1;i<(1<<20);i++)
    {
        if(ans[i]!=0)
            continue;
        for(int j=0;j<20;j++)
            if(i&(1<<j))
                ans[i]=max(ans[i],ans[i-(1<<j)]);
    }
    for(int i=1;i<(1<<20);i++)
        fuck=max(fuck,ans[i]+ans[(1<<20)-1-i]);
    cout<<fuck;
}