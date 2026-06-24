#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cntp=0,cntm=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='+')
            cntp++;
            else
            cntm++;
        }
        cout<<abs(cntm-cntp)<<'\n';
    }
    return 0;
}