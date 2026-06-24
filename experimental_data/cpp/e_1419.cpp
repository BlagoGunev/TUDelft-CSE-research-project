#include<bits/stdc++.h>

using namespace std;



#define lli long long int

const long long int mod = 1e9 + 7;

const long long int INF = 1e18 ;





void solve()

{

    lli n;

    cin>>n;

    lli m=n;

    vector<pair<lli,lli>> vp;

    for(lli i=2;i*i<=n;i++)

    {

        if(n%i==0)

        {

            lli cnt=0;

            while(n%i==0)

                n/=i,cnt++;

            vp.push_back({cnt,i});

        }

    }

    if(n>1)

        vp.push_back({1,n});



    sort(vp.begin(),vp.end());



    vector<lli> v;

    v.push_back(1);

    lli si=vp.size();

    //cout<<endl;

    for(lli i=0;i<si;i++)

    {

        lli cnt=vp[i].first;

        lli p=vp[i].second;

        //cout<<p<<" "<<cnt<<endl;

        lli num=p;

        vector<lli> New=v;

        for(lli j=v.size()-1;j>=0;j--)

        {

            New.push_back(v[j]*num);

        }



        for(lli j=2;j<=cnt;j++)

        {

            num*=p;

            for(lli k=0;k<v.size();k++)

                New.push_back(v[k]*num);

        }

        v=New;

    }

    //cout<<endl;

    assert(v[0]==1);

    v.erase(v.begin());



    si=v.size();

    //cout<<si<<endl;



    for(lli i=0;i<(si-1);i++)

    {

        if(__gcd(v[i],v[i+1])==1)

        {

            assert(1==2);

        }

    }

    lli cost=0;

    if(__gcd(v[0],v.back())==1)

    {

        for(lli j=1;j<(si-1);j++)

        {

            if(v[j]==m)

            {

                if(__gcd(v[j-1],v[j+1])>1)

                {

                    for(lli k=0;k<j;k++)

                        cout<<v[k]<<" ";



                    for(lli k=j+1;k<si;k++)

                        cout<<v[k]<<" ";



                    cout<<m<<endl;



                    cout<<0<<endl;

                    return;

                }

            }

        }

        cost=1;

    }

    for(lli ele:v)

        cout<<ele<<" ";

    cout<<endl;

    cout<<cost<<endl;





    



}





int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    // freopen("output.txt", "w", stdout);

    //seive();

    int t=1;

    cin>>t;

    while(t--)

    {

        solve();

    }

}