#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);cout.tie(0);

    int t; cin>>t;

    while(t--)

    {

        int n; cin>>n;

        string s; cin>>s;

        if(count(s.begin(),s.end(),'?')==n)

        {

            s[0]='B';

            for(int i=1;i<n;i++)

            {

               if(s[i-1]=='B') s[i]='R';

               else s[i]='B';

            }

        }

        for(int i=1;i<n;i++)

        {

            if(s[i]=='?')

            {

                if(s[i-1]=='R') s[i]='B';

                else if(s[i-1]=='B') s[i]='R';

            }

        }

        for(int i=n-1;i>=0;i--)

        {

            if(s[i]=='?')

            {

                if(s[i+1]=='R') s[i]='B';

                else if(s[i+1]=='B') s[i]='R';

            }

        }

        

        cout<<s<<endl;

    }

}