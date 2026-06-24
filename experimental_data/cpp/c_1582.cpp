#include<bits/stdc++.h>

#define ll long long int

using namespace std;

int main()

{

     ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int t;

    cin>>t;

    while(t--)

    {

int n;

cin>>n;

string s;

cin>>s;





unordered_map<char,int> mp;





    int mini=INT_MAX;

    for(char ch:s)

    {

        if(mp.find(ch)==mp.end())

        {

        int l=0,h=n-1;

        int c=0;

        while(l<=h)

        {

            if(s[l]==s[h])

            {

                l++;

                h--;

            }

            else if(s[l]==ch)

            {

                l++;

                c++;

            }

            else if(s[h]==ch)

            {

                h--;

                c++;

            }

            else

            {

                c=-1;

                break;

            }

        }

        mp[ch]=c;

        if(mp[ch]!=-1)

        mini=min(mini,mp[ch]);

        }

    }

    if(mini==INT_MAX)

    cout<<-1<<endl;

    else

    cout<<mini<<endl;



    }

    return 0;

}