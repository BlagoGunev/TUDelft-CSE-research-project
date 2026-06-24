#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define endl '\n'

#define T int t;cin>>t;while(t--)

#define vi vector<int>

#define vii vector<vector<int>>

#define vl vector<ll>

#define read2d(v) for(auto &it:v){for(auto &ig:it)cin>>ig;}

#define read(v) for(auto &it:v)cin>>it;

#define print(v) for(auto &it:v)cout<<it<<" ";cout<<endl;

#define sz(v) v.size()

#define for1(x,n) for(int i=x;i<n;++i)

#define for2(x,n) for(int j=x;j<n;++j)

#define all(v) v.begin(), v.end()

#define mod 1000000007

int lol(ll sum)

{

    int ret=0;

    string s=to_string(sum);

    for(int i=0; i<sz(s); ++i)

    {

        ret+=s[i]-48;

    }

    return ret;



}

int msb(int n)

{

    int cnt=0;

    while(n)

    {

        n/=2;

        cnt++;

    }

    return (1<<(cnt-1));

}

int main()

{

    IOS

    T

    {

        int xxx;

        cin>>xxx;

        vi vec(xxx);

        int cnt=0;

        for(auto &it:vec)cin>>it;

        bool f=0;

        for(int i=0;i<xxx-1;++i)

        {

            if( vec[i]>vec[i+1] )cnt++,i++;

        }cout<<cnt<<endl;





    }























































}