#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int max=0,j=0,k=0;
    for(int i=0;i<s.size();i++)
    {
        int len=0;
        for(j=i+1;j<s.size();j++)
        {
            if(s[i+len]==s[j])
            {
                len++;
                if(max<len)max=len;
            }
            else
            {
            j-=len;
            len=0;
            }
        }

    }
    cout<<max<<endl;
}