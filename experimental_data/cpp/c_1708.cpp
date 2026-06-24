#include<bits/stdc++.h>

using namespace std;

#define fs(n) fixed<<setprecision(n)

#define all(v) v.begin(),v.end()

#define ll long long

#define f first

#define s second

#define nl cout<<"\n"

#define ci(v) for(auto&it:v){cin>>it;}

#define cip(v) for(auto&it:v){cin>>it.first>>it.second;}

#define cp(v) for(auto&it:v){cin>>it.first>>it.second;}

#define cii(n,m,v) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>v[i][j];}}

#define dbp(v) for(auto it:v)cout<<it.first<<" "<<it.second<<"\n";

#define dbi cout<<"(lol)\n"

#define db(n) cout<<"("<<n<<")\n"

#define dbb(x,y) cout<<"("<<x<<" "<<y<<")\n"

#define dbbb(x,y,z) cout<<"("<<x<<" "<<y<<" "<<z<<")\n"

#define dbbbb(a,b,c,d) cout<<"("<<a<<" "<<b<<" "<<c<<" "<<d<<")\n"

#define dbv(v) for(auto it:v){cout<<it<<" ";}cout<<"\n"

#define dbvv(n,m,v) for(int i=0;i<n;i++){if(i==0){cout<<"\n\\\\\\\\\\\\\\\\\n";}for(int j=0;j<m;j++){cout<<v[i][j]<<" ";}cout<<"\n";if(i==n-1){cout<<"\\\\\\\\\\\\\\\\\n";}}

#define dbbv(v) cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";for(auto it:v){for(auto it2:it){cout<<it2<<" ";}cout<<"\n";}cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n"

 

const long long mod=1e9+7;

const long long mod2=998244353;

 

struct str{

 

long long a,b;

 

};

 

bool cmp(str a,str b){

return a.a+a.b>b.a+b.b;

/*

if(a.a==b.a)return a.b<b.b;

return a.a>b.a;

*/

}

 

int main(){

 

    //freopen("input.in","r",stdin);

 

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

 

    int t=1,tt=0;

    cin>>t;

    while(++tt<=t){

 

        int n,q,qq=0;

        cin>>n>>q;

        vector<int>v(n);

        ci(v);

        string ans(n,'0');

        for(int i=n-1;i>=0;i--){

            if(v[i]<=qq){

                ans[i]='1';

            }

            else if(v[i]>qq){

                if(qq<q){

                    ans[i]='1';

                    qq++;

                }

            }

        }

        cout<<ans<<"\n";

 

    }

    return 0;

}