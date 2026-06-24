#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int t;

    cin >> t;

    while (t--)

    {

        int i,j;

        int n;

        cin>>n;

        vector<int> a(n);

        vector<vector<int>> mp(n+1,vector<int>());

        for(i=0;i<n;i++)

        {

            cin>>a[i];

            mp[a[i]].push_back(i);

        }

        vector<int> p(n),q(n);

        int curr=0;

        vector<int> rem1;

        vector<int> rem2;

        int flag = 1;

        for(i=1;i<=n;i++)

        {

            if(mp[i].size()==1)

            {

                curr = mp[i][0];

                p[curr]=i;

                q[curr]=i;

            }

            else if(mp[i].size()==0)

            {

                rem1.push_back(i);

                rem2.push_back(i);

            }

            else if(mp[i].size()==2)

            {

                if(rem1.size()==0 || rem2.size()==0)

                {

                    flag=0;

                    break;

                }

                curr = mp[i][0];

                p[curr]=i;

                q[curr]=rem2.back();

                rem2.pop_back();

                curr=mp[i][1];

                q[curr]=i;

                p[curr]=rem1.back();

                rem1.pop_back();

                curr++;

            }

            else

            {

                flag=0;

                break;

            }

        }

        if(rem1.size() || rem2.size())

            flag=0;

        if(flag==0)

            cout<<"NO"<<endl;

        else

        {

            cout<<"YES"<<endl;

            for(i=0;i<n;i++)

                cout<<p[i]<<" ";

            cout<<endl;

            for(i=0;i<n;i++)

                cout<<q[i]<<" ";

            cout<<endl;

        }

    }

    return 0;

}