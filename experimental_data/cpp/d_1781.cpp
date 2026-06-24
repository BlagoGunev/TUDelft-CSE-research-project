#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL)

#define ll long long

vector<ll>vec;

map<ll,ll>mp;

ll a[51];

int main(){

    int t;cin>>t;

    while(t--){

        vec.clear();

        ll n,ans=0;cin>>n;

        for(int i=0;i<n; i++)cin>>a[i];

        for(int i=0;i<n; i++){

            for(int j=i+1;j<n; j++){

                if(i==j)continue;

                ll d=abs(a[i]-a[j]);

                ll mi=min(a[i],a[j]);

                ll ma=max(a[i],a[j]);

                ll sq=sqrt(mi);

                if(sq!=sqrt(mi))sq++;

                ll l=(sq+1)*2-1,m=1;

                if(d%2==0)m++;

                while(((m*(m-1))/2)*2+m*l<=d){

                    if(d%2==0){

                        ll mid=d/m;

                        ll inc=m/2;

                        if(mid%2==0)mid--;

                        ll f=mid-(inc-1)*2,la=mid+(inc)*2;

                        ll res=f*m+((m*(m-1))/2)*2;

                        if(f>=l && la<=d && res==d)vec.push_back((((la+1)/2)*((la+1)/2))-ma);

                    }

                    else{

                        ll mid=d/m;

                        ll inc=m/2;

                        if(mid%2==0)mid--;

                        ll f=mid-inc*2,la=mid+inc*2;

                        ll res=f*m+((m*(m-1))/2)*2;

                        if(f>=l && la<=d && res==d)vec.push_back((((la+1)/2)*((la+1)/2))-ma);

                    }

                    m+=2;

                }

            }

        }

        for(int i=0;i<vec.size();i++){

            ll sum=0;

            for(int j=0;j<n;j++){

                ll x=a[j]+vec[i];

                ll sq=sqrt(x);

                if(sq==sqrt(x))sum++;

            }

            ans=max(sum,ans);

        }

        if(ans==0)ans=1;

        cout<<ans<<endl;

    }

}