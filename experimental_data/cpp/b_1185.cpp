#include<bits/stdc++.h>
using namespace std;
int n;
char s[1000001], t[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int k=1; k<=n; k++)
    {
        bool ok=1;
        cin>>s;
        cin>>t;
        int i=0;
        int j=0;
        if(s[i]!=t[i]) ok=0, i=strlen(s);
        while(i<strlen(s))
        {
            if(s[i]==t[j]) i++, j++;
            else
            {
                if(t[j]==t[j-1])
                {
                    while(t[j]==t[j-1])
                        j++;
                }
                else ok=0, i=strlen(s);
            }
        }
        if(j<strlen(t) && ok==1)
        {
            while(j<strlen(t))
            {
                if(t[j]!=s[strlen(s)-1]) ok=0, j=strlen(t);
                else j++;
            }
        }
        if(ok==0) cout<<"NO";
        else cout<<"YES";
        cout<<'\n';
    }
    return 0;
}