#include <bits/stdc++.h>



#define forn for(int i=0;i<n;i++)

#define form for(int i=0;i<m;i++)

#define fornj for(int j=0;j<n;j++)

#define pb push_back

#define F first

#define S second

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef vector<int> vi;

typedef vector<vector<int> > vii;

typedef vector<long long> vll;

typedef vector<vector<long long> > vllll;

int main()

{

    ios_base::sync_with_stdio(0);

    int n;

    cin>>n;

    vi v(n);

    forn cin>>v[i];

    int co=0;

    int tmp=0;

    bool b=1;

    while(co!=n)

    {

        if(b)

        {

            for(int i=0;i<n;i++)

            {

                if(v[i]<=co){co++;v[i]=INT_MAX;}

            }

            b=0;

        }

        else

        {

            for(int i=n-1;i>=0;i--)

            {

                if(v[i]<=co){co++;v[i]=INT_MAX;}

            }

            b=1;

        }

        if(co!=n)tmp++;

    }

    cout<<tmp;



    return 0;

}