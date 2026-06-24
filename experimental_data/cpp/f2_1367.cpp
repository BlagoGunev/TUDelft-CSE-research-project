// I know that I'm not that important to you

// But to me, girl, you're so much more than gorgeous

// So much more than perfect

// Right now I know that I'm not really worth it

// If you give me time, I could work on it

// Give me some time while I work on it



#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 

#include <ext/pb_ds/tree_policy.hpp>

typedef long long ll;

#define pb push_back

#define ff first

#define ss second

const int N=2e3+7;

const int mod=1e9+7;

const double eps=1e-9;

const double pi=    3.14159265358979323846;

using namespace std;  

using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,

             tree_order_statistics_node_update>

    op_set;



// Can't keep bein' laid off

// Know you need the money if you gon' survive

// Every night shit, every day shit



// You know I can't hear none of that spend the night shit

// That kumbaya shit

// Wanna see nirvana, but don't wanna die yet



int32_t main() 

{

   ios_base::sync_with_stdio(false);

   cin.tie(0);



   int t;

   cin >> t;

   while(t--)

   {

        int n;

        cin >> n;



        vector<int> ar(n);

        map<int,int> mp;

        int curr=1;

        for(int i=0;i<n;i++)

        {

            cin >> ar[i];

            mp[ar[i]];

        }



        for(auto &[val,comp] : mp)

            comp=curr++;



        for(auto &val : ar)

            val=mp[val];



        vector<int> last(curr,-100);

        vector<int> first(curr);

        for(int i=n;i>=1;i--)

        {

            first[ar[i-1]]=i;

            last[ar[i-1]]=std::max(last[ar[i-1]],i);

        }



        vector<int> prev(curr);

        vector<array<int,3>> dp(n+1);//1 is for start it always start from the very start

        //2 beech main kahi bhi ghus jau

        //3 is completely in sync always after a 2

        for(int i=1;i<=n;i++)

        {

            if(first[ar[i-1]]==i)

                dp[i][0]=1;

            else

                dp[i][0]=dp[prev[ar[i-1]]][0]+1;



            if(first[ar[i-1]]==i)

            {

                if(prev[ar[i-1]-1]==last[ar[i-1]-1])

                    dp[i][1]=std::max(dp[i][1],dp[prev[ar[i-1]-1]][1]+1);

                dp[i][1]=std::max(dp[i][1],dp[prev[ar[i-1]-1]][0]+1);

            }

            else

                dp[i][1]=std::max(dp[i][1],dp[prev[ar[i-1]]][1]+1);



            dp[i][2]=dp[prev[ar[i-1]-1]][0]+1;

            if(prev[ar[i-1]-1]==last[ar[i-1]-1])

                dp[i][2]=std::max(dp[i][2],dp[prev[ar[i-1]-1]][1]+1);

            if(first[ar[i-1]]!=i)

                dp[i][2]=std::max(dp[i][2],dp[prev[ar[i-1]]][2]+1);



            prev[ar[i-1]]=i;

        }



        int ans=0;

        for(auto &[a,b,c] : dp)

            ans=std::max({ans,a,b,c});

    

        cout << n-ans << "\n";

    }

}



/*

I can't fall in love it's fucking up my mental.



Fuck love , sigma bano

*/