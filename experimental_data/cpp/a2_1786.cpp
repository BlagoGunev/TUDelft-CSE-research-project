// PARTHA BHOWMIK

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

template<class T> using oset=tree<T,null_type,greater_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

// greater, less_equal, greater_equal, *X.find_by_order(ind), X.order_of_key(elem)

#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x << " = " << x << nl;

#else

#define debug(x)

#endif 

void __BUG(){ 

#ifndef ONLINE_JUDGE

freopen("error.txt", "w", stderr);

#endif 

}

#define int long long

#define F first

#define S second

#define pb push_back

#define endl "\n"

#define nl "\n"

#define Nl "\n"

#define py cout<<"YES"<<endl

#define pn cout<<"NO"<<endl

#define all(x) x.begin(), x.end()

#define ff(i, a, b) for(int i=a; i<b; i++)

#define rf(i, a, b) for(int i=a; i>=b; i--)

#define ain(arr,a,b) for(int i=(a); i<(b); i++) cin>>(arr)[i];

#define aout(arr,a,b) for(int i=(a); i<(b); i++) cout<<(arr)[i]<<" ";

typedef long long ll;

typedef long double ld;

typedef pair<int,int> pii;

typedef vector<int> vi;

typedef map<int,int> mii;

typedef set<int> si;

int MOD = 1e9+7;

int MOD1 = 998244353;



int32_t main(){

    fastio(); __BUG();



    int t;

    cin>>t;



    while(t--){



        int n; cin>>n;



        int a1=1,a2=0, b1=0,b2=0;



        int i=2, start=2, alice=0;



        while(start<=n){

            int temp=fmin(i+(i+1),n-start+1);

            int w, b;

            if(temp&1){

                if(start&1) {w=(temp/2)+1; b=temp/2;}

                else {b=(temp/2)+1; w=temp/2;}

            }

            else{

                w=temp/2; b=temp/2;

            }

            if(alice){

                a1+=w; a2+=b;

                alice=0;

            }

            else{

                b1+=w; b2+=b;

                alice=1;

            }

            i+=2;

            start+=temp;

        }



        cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<nl;













    }

    return 0;

}