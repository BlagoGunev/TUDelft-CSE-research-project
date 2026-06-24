#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;

typedef pair<int,ll> pil;

typedef vector<ll> vll;

typedef vector<int> vi;

typedef vector<vector<int>> vvi;

typedef vector<vector<ll>> vvll;

#define fo(i,s,e) for(ll i = s; i<=e; i++)

#define mp make_pair

#define pb push_back

#define all(v) v.begin(), v.end()

#define all2(v) v.begin()+1, v.end()

#define sz(x) x.size()

#define isodd &1!=0

#define iseven &1==0

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int t;

    cin>>t;

    while(t--){

        int n;

        cin>>n;

        string s;

        cin>>s;

        vector<char> v(n+1);

        int count_zero=0,index;

        fo(i,1,n){

            v[i]=s[i-1];

            if(v[i]=='0') count_zero++,index=i;

        }

        if(!count_zero){

            cout<<"1 "<<n-1<<" 2 "<<n<<endl;

        }

        else{

            if(n-index+1>index){

                cout<<index<<" "<<n<<" "<<index+1<<" "<<n<<endl;

            }

            else{

                cout<<"1 "<<index<<" 1 "<<index-1<<endl;

            }

        }

    }

return 0;

}