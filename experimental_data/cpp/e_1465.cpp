#include<bits/stdc++.h>

using namespace std;



#define lli long long int

const long long int mod = 998244353 ;

const long long int INF = 1e9 ;

#define endl '\n'



//greddy idea of how to consider sign for each for making the sum equal to t:-https://codeforces.com/blog/entry/85792?#comment-735688



lli power[55];



void init()

{

    power[0]=1;

    for(lli i=1;i<55;i++)

        power[i]=2*power[i-1];

}



void solve()

{

    init();

    lli n,t;

    cin>>n>>t;

    string s;

    cin>>s;

    lli cnt[55];

    for(lli i=0;i<55;i++)

        cnt[i]=0;



    lli x=-power[s[n-2]-'a']+power[s[n-1]-'a'];

    t-=x;

    t=abs(t);

    lli sum=0;

    for(lli i=0;i<n-2;i++)

    {

        lli d=s[i]-'a';

        sum+=power[d];

        cnt[d+1]++;

    }



    t+=sum;









    for(lli i=0;i<54;i++)

    {

        if(t&power[i])

        {

            if(cnt[i]==0)

            {

                cout<<"NO"<<endl;

                return;

            }

            cnt[i]--;

        }

        cnt[i+1]+=cnt[i]/2;

    }

    cout<<"YES"<<endl;

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

    //cin>>t;

    while(t--)

    {

        solve();

    }

}