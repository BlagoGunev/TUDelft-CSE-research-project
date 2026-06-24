#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ff first
#define ss second
#define pb push_back
#define mod 1000000007
#define pl pair<lli,lli>
#define vl vector<lli>
#define vvl vector<vl>
#define INF (lli)1e15

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t=1;
    cin>>t;
    while(t--)
    {
        lli n,i,prev=0,curr=0,ans=0,c=0;        
        cin>>n;
        string s;
        char ch;
        cin>>s;
        i=0;
        while(i<n)
        {
            if(s[i]=='.')
            {
                i++;
                continue;
            }
            prev=max(i,prev);
            while(s[prev]=='.')
                prev++;
            curr=max(curr,prev+1);
            while(curr<n)
            {
                if(s[curr]=='.')
                    curr++;
                else if(s[curr]!=s[prev])
                {
                    prev=curr;
                    curr++;
                }
                else
                    break;
            }
            if(curr<n)
                s[curr]='.';
            else
            {
                c=0;
                while(i<n)
                {
                    if(s[i]!='.')
                        c++;
                    i++;
                }
                ans+=(c+1)/2;
                break;
            }
            ch=s[i];
            while(i<n&&(s[i]=='.'||s[i]==ch))
            {
                s[i]='.';
                i++;
            }
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}