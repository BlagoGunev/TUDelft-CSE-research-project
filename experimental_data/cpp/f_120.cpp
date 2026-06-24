#include <bits/stdc++.h>

#define ll  long long

#define node pair<long long,long long >

#define sc second

#define f first

#define islam  ios::sync_with_stdio(false); cin.tie(0);





using namespace std;

ll n,mx=0;

vector<vector<int> > vec(105);

void bc(int i,int par=-1,int len=0)

{

    for(int j=0;j<vec[i].size();j++)

    {

        if(vec[i][j]!=par)

            bc(vec[i][j],i,len+1);

    }

    mx=max(mx,(ll)len);

}

int main()

{

    islam

    

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    ll m;

    cin>>n;

    ll ans=0;

    for(int i=0;i<n;i++)

    {

        cin>>m;

        ll tmp=m;

        m--;

        mx=0;

        vec=vector<vector<int> >(105);

        while(m--)

        {

            int a,b;

            cin>>a>>b;

            a--;

            b--;

            vec[a].push_back(b);

            vec[b].push_back(a);

        }

        for(int k=0;k<tmp;k++)

            bc(k);

        //cout<<mx<<endl;

        ans+=mx;

    }

    cout<<ans;

    return 0;



}