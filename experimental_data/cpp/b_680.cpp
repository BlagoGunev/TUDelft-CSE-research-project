#include<bits/stdc++.h>

using namespace std;

int main()

{

    int n,a,x;

    vector<int>v;

    while(cin>>n>>a)

    {

        v.clear();

        for(int i=0; i<n; i++)

        {

            cin>>x;

            v.push_back(x);

        }

        int j=a-1;

        int i=a-1;

        int c=0;

        for(int i=0; i<n; i++)

        {

            if(v[i])

            {

                int d=i-(a-1);

                int j=a-1-d;

                if(j<0 or j>=n or v[i]==v[j])

                    c++;

            }

        }

        cout<<c<<endl;

    }

    return 0;

}