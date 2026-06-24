#include<bits/stdc++.h>



using namespace std;



#define finout() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define forn(i,n) for(int i = 0; i < n; ++i)

#define fi first

#define se second

#define lb "\n"

#define pb push_back

#define mp make_pair

#define mod 1000000007

#define fr(i,j,n) for(int i=j; i<n; i++)





typedef long long int ll;

typedef unsigned long long ull;

typedef long double lld;



void testcase(){

    int n, k;

    cin>>n>>k;

    string s;

    cin>>s;

    string r(k,'?'), ans = "Yes";

    map<char, int> mp;

    for(int i=0; i<n; i++){

        if(s[i] == '?') continue;

        else{

            if(r[i%k] == '?' ){

                r[i%k] = s[i];

                mp[s[i]]++;

            }

        }

    }

    int cnt1=0, cnt0 =0;



    for(int i=0; i<k; i++){

        if(r[i] == '?'){

            if(mp['0'] > mp['1']){

                r[i] = '1';

                mp['1']++;

            }

            else{

                r[i] = '0';

                mp['0']++;

            }

        }

    }

    if(mp['0'] == mp['1']){

        for(int i=k; i<n; i++){

            if(s[i] == '?') continue;



            else if( s[i] !=  r[i%k] ){

                ans = "No";

                break;

            }

        }

    }

    else{

        ans = "No";

    }



    // cout<<r<<" , "<<s<<lb;

    cout<<ans<<lb;

   

}



int main(){

    finout();

    int t;

    cin>>t;

    while(t--){

        testcase();

    }

    return 0;

}