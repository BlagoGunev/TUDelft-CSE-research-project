#include <iostream>

#include<bits/stdc++.h>

#define ll long long

#define endl '\n'

using namespace std;

int start_up()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    return 0;

}

int main()

{

    start_up();

    int t;

    cin>>t;

    while(t--)

    {

        ll x;

        cin>>x;

        ll arr[x],pos[x+1];

        for(int i=0;i<x;i++)

        {

            cin>>arr[i];

            pos[arr[i]]=i;

        }

        int en=x;

        for(int i=x;i>=1;i--)

        {

            if(pos[i]>=en)

            {

                continue;

            }

            for(int j=pos[i];j<en;j++)

            {

                cout<<arr[j]<<" ";

            }

            en=pos[i];

        }

        cout<<endl;

    }

}