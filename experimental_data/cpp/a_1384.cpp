#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    int t;

    cin>>t;

    while(t--)

    {

        ll n;

        cin>>n;

        ll arr[n];

        for(int i=0;i<n;i++)

        {

            cin>>arr[i];

        }

    string s(200,'a');

    cout<<s<<endl;

    for(int i=0;i<n;i++)

    {

        if(s[arr[i]]=='a')

        {

            s[arr[i]]='b';

        }

        else

        {

            s[arr[i]]='a';

        }

        cout<<s<<endl;

    }

    }

}