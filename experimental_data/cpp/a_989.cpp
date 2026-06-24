#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
using namespace std;
string s;
set<string> sv;
char token[10];
int main()
{
    sv.insert("ABC");
    sv.insert("CBA");
    sv.insert("BAC");
    sv.insert("CAB");
    sv.insert("ACB");
    sv.insert("BCA");
    cin>>s;
    int flag=0;
    int len=s.length();
    for(int i=1;i<len-1;++i)
    {
        token[0]=s[i-1];
        token[1]=s[i];
        token[2]=s[i+1];
        token[3]='\0';
        if(sv.find(token)!=sv.end())
        {
            flag=1;
            break;
        }
    }
    if(flag) printf("Yes");
    else printf("No");
    return 0;
}