#include<iostream>

#include<queue>

using namespace std;

int t[2000];

int main()

{

    cin.tie(0);

    cout.tie(0);

    ios_base::sync_with_stdio(0);

    long long g;

    cin>>g;

    while(g--)

    {

        long long n,k,m,co=0;

        cin>>n>>m;

        for(int i=0;i<n;i++)

        {

            cin>>k;

            t[k]=1;

        }

        for(int i=0;i<m;i++)

        {

            cin>>k;

            if(t[k]==1)

            {

                if(co==0)

                {

                cout<<"YES\n";

                cout<<"1"<<" "<<k<<"\n";

                co=1;

                }

            }

        }

        if(co==0)

            cout<<"NO\n";

        for(int i=0;i<2000;i++)

            t[i]=0;

    }

}