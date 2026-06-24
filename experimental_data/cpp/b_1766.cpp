// Problem: B. Notepad#

// Contest: Codeforces - Educational Codeforces Round 139 (Rated for Div. 2)

// URL: https://codeforces.com/problemset/problem/1766/B

// Memory Limit: 256 MB

// Time Limit: 3000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#include<bits/stdc++.h>

using namespace std;

int main()

{

    long long t,n,i;

    string ans,s,s1;

    cin>>t;

    while(t--)

    {

        cin>>n;

        cin>>s;

        ans="NO";

        unordered_map<string, long long> mp;

        

        for(i=0; i<n-1; i++)

        {

            s1=s[i];

            s1+=s[i+1];

            

            if(mp.find(s1)==mp.end()){

                mp[s1]=i;

            }else{

                if(mp[s1]!=i-1){

                    ans="YES";

                    break;

                }

            }

        }

        

        cout<<ans<<"\n";

    }

}