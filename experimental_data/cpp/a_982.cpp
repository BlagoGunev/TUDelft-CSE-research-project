#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    char pre = s[0];
    bool flag = 1;
    int cnt = 0;
    if(n==1 && s[0]!='1') flag = 0;
    if(n==2)
    {
        if((s[0]=='1' && s[1]=='0') || (s[0]=='0' && s[1]=='1') )
        {
            ;
        }
        else flag = 0;
    }
    for(int i=0; i<n-1; i++)
    {
        if(s[i] == '1' && s[i+1] == '1') flag = 0;
    }
    for(int i=0; i<n-2; i++)
    {
        if(s[i] == '0' && s[i+1] == '0' && s[i+2]=='0') flag = 0;
    }
    if(n>2){
        if(s[0]=='0' && s[1]=='0')
            flag=0;
        if(s[n-1]=='0' && s[n-2]=='0')
            flag=0;
    }

    if(flag==0) cout << "No" << endl;
    else cout << "Yes" << endl;
//    main();
}