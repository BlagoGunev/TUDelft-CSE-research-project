#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
char s[100005];
int cnt[26];
int main()
{
    while(~scanf("%s",s))
    {
        memset(cnt,0,sizeof(cnt));
        int len=strlen(s);
        if(len<4)
        {
            puts("No");
            continue;
        }
        for(int i=0;i<len;++i)
            cnt[s[i]-'a']++;
        int p=0;
        vector<int>vec;
        for(int i=0;i<26;++i)
            if(cnt[i]>0)
            {
                p++;
                vec.push_back(cnt[i]);
            }
        if(p>4||p==1)
            puts("No");
        else if(p==4||p==3)
        {
            puts("Yes");
        }
        else
        {
            if(vec[0]==1||vec[1]==1)
                puts("No");
            else
                puts("Yes");
        }
    }
}