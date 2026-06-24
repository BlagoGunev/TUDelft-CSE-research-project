#include <iostream>
#include<cstring>
using namespace std;
string s,t;
int main()
{
    cin>>s>>t;
    int i=0,j=0;
    while(t[j]!='\0')
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else
            j++;
    }
    cout<<i+1;
    return 0;
}