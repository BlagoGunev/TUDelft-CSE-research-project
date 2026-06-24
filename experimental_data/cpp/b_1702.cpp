#include<bits/stdc++.h>

#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;



#define f first

#define s second

#define mp make_pair

#define pb push_back

#define REP(i,k,n) for(int i=k;i<n;i++)

#define REPREV(i,k,n) for(int i=n-1;i>=k;i--)

#define pii pair<int,int>

#define vpi vector<pair<int,int>>

#define vi vector<int>

#define sortv(v) sort(v.begin(),v.end())

#define sortrev(v) sort(v.begin(),v.end(),greater<int>())

#define int long long int



signed main(){

fast;

    int t;

    cin>>t;

    REP(i,0,t)

    {

        string s;

        cin>>s;

        map<char,int>m;

        int ans=1;

        m[s[0]]++;

        REP(i,1,s.length())

        {

            m[s[i]]++;

            if (m.size()>3)

            {

                ans++;

                m.clear();

                m[s[i]]++;

            }

            

        }

        cout<<ans<<endl;



    }

}