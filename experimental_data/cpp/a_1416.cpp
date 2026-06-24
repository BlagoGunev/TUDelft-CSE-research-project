#include <bits/stdc++.h>

#define int long long

#define endl '\n'

#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef pair<int,int> PII;

const int INF=0x3f;

const int max1=3e5+7;

const int mod=1e9+7;

int n,m,k;

int a[max1];

int b[max1];

vector<int> q[max1];

signed main()

{

    ios;

    int t=1;

    cin>>t;

    while(t--)

    {

        cin>>n;

        b[0]=1e14;

        for(int i=1;i<=n;i++)

        {

            q[i].clear();

            b[i]=1e14;

        }

        for(int i=1;i<=n;i++)

        {

            cin>>a[i];

            q[a[i]].push_back(i);

        }

        for(int i=1;i<=n;i++)

        {

            int maxn=0;

            for(int j=1;j<q[i].size();j++)

            {

                maxn=max(maxn,q[i][j]-q[i][j-1]);

            }

            if(q[i].size()!=0)

            {

                maxn=max(q[i][0],maxn);

                maxn=max(n+1-q[i][q[i].size()-1],maxn);

                b[maxn]=min(b[maxn],i);

            }

        }

        for(int i=1;i<=n;i++)

        {

            b[i]=min(b[i],b[i-1]);

            if(b[i]==1e14)

            {

                cout<<"-1 ";

            }

            else

            {

                cout<<b[i]<<" ";

            }

        }

        cout<<endl;

    }

    return 0;

}