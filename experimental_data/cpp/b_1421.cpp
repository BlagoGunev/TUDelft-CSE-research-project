//yeh dil mange more...

#include<bits/stdc++.h>

using namespace std;

int main()

{

    int t;

    cin>>t;

    while(t--)

    {

        int n;

        cin>>n;

        string s[n];

        for(int i=0;i<n;i++)

        {

            cin>>s[i];

        }

        int cnt=0;

        vector<pair<int,int>> v1;

        if(s[0][1]==s[1][0])

        {

            if(s[0][1]=='0')

            {

                if(s[n-2][n-1]=='0')

                {

                    s[n-2][n-1]='1';

                    cnt++;

                    v1.push_back({n-2+1,n-1+1});

                }

                if(s[n-1][n-2]=='0')

                {

                    s[n-1][n-2]='1';

                    cnt++;

                    v1.push_back({n-1+1,n-2+1});

                }

            }

            if(s[0][1]=='1')

            {

                if(s[n-2][n-1]=='1')

                {

                    s[n-2][n-1]='0';

                    cnt++;

                    v1.push_back({n-2+1,n-1+1});

                }

                if(s[n-1][n-2]=='1')

                {

                    s[n-1][n-2]='0';

                    cnt++;

                    v1.push_back({n-1+1,n-2+1});

                }

            }

        }

        else if(s[0][1]!=s[1][0])

        {

            if(s[n-2][n-1]==s[n-1][n-2] && s[n-2][n-1]=='0')

            {

                if(s[0][1]=='0')

                {

                    s[0][1]='1';

                    cnt++;

                    v1.push_back({1,2});

                }

                if(s[1][0]=='0')

                {

                    s[1][0]='1';

                    cnt++;

                    v1.push_back({2,1});

                }

            }

            else if(s[n-2][n-1]==s[n-1][n-2] && s[n-2][n-1]=='1')

            {

                if(s[0][1]=='1')

                {

                    s[0][1]='0';

                    cnt++;

                    v1.push_back({1,2});

                }

                else if(s[1][0]=='1')

                {

                    s[1][0]='0';

                    cnt++;

                    v1.push_back({2,1});

                }

            }

            else if(s[n-2][n-1]!=s[n-1][n-2])

            {

                if(s[n-2][n-1]=='0')

                {

                    s[n-2][n-1]='1';

                    cnt++;

                    v1.push_back({n-2+1,n-1+1});

                    if(s[0][1]=='1')

                    {

                        s[0][1]='0';

                        cnt++;

                        v1.push_back({1,2});

                    }

                    else

                    {

                        s[1][0]='0';

                        cnt++;

                        v1.push_back({2,1});

                    }

                }

                else if(s[n-2][n-1]=='1')

                {

                    s[n-2][n-1]='0';

                    cnt++;

                    v1.push_back({n-2+1,n-1+1});

                    if(s[0][1]=='0')

                    {

                        s[0][1]='1';

                        cnt++;

                        v1.push_back({1,2});

                    }

                    else

                    {

                        s[1][0]='1';

                        cnt++;

                        v1.push_back({2,1});

                    }

                }

            }

        }

        cout<<cnt<<"\n";

        for(auto j : v1)

        {

            cout<<j.first<<" "<<j.second<<"\n";

        }

    }

    return 0;

}