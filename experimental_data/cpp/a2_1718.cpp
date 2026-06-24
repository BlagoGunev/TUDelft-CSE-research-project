////

/*------------------------This  code  is  written  by  'yabhist'------------------------*/  



#include<bits/stdc++.h>

using namespace std;



typedef int I;

typedef unsigned int ui;

typedef unsigned long long ull;

typedef long double ld;



#define int long long



int32_t main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    int life;

    cin>>life;

    while(life--)

    {

        int n;

        cin>>n;

        vector<int>a(n);

        for(int i=0;i<n;i++)

        {

            cin>>a[i];

        }

        int temp=0;

        set<int>s;

        int ct=0;

        for(int i=0;i<n;i++)

        {

            temp^=a[i];

            if(s.find(temp)!=s.end() || temp==0)

            {

                ct++;

                s.clear();

                temp=0;

            }

            else s.insert(temp);

        }

        cout<<n-ct<<'\n';

    }

}