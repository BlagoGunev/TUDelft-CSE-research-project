#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef vector<ll> vi;

typedef pair<ll,ll> ii;



#define pb push_back

#define fst first

#define snd second

#define ALL(cont) cont.begin(), cont.end()

#define mset(a,b) memset(a,b,sizeof(a));

#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)

#define fore(k, a, b) for (int k = a, almo5t = b; k < almo5t; ++k)

#define SZ(x) ((ll)x.size())

#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)



const int MOD=1e9+7;

int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}

int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}

int mul(ll a, ll b){return a*b%MOD;}

const int MAXN = 200;

vector<int> divs;



/*

    Want to maximize cool buildings

    with minimum additions



    h1 < h2

    h3 < h2

    cool!





*/



ll ans[100];





int main(){

    FIN;

    ll t;cin>>t;



    while(t--){

        int n;cin>>n;

        map<char,int> l;

        fore(i,0,2*n + 1){

            string a;cin>>a;

            fore(j,0,a.size()){

                l[a[j]]++;

            }

        }



        fore(i,0,27){

            if(l['a'+i]%2){

                cout<<(char)('a'+i)<<"\n";

            }

        }

    }

    

}