#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define MX 1e18

vector<ll>pre;

int main(){



    int t;cin>>t;

    while(t--)

    {

        int n,x,y;

        cin>>n>>x>>y;

        vector<int>v;

        for(int i=1;i*i<=y-x;i++){

            if((y-x)%i==0){

                v.push_back(i);

                v.push_back((y-x)/i);

            }

        }

        sort(v.begin(),v.end());

        int i=0,cnt=n-2;

        while((y-x-1)/v[i]>cnt)i++;

        int d=v[i],ini;



        int ans=0;

        ini=x;

        while(ans<n&&ini<=y){

            cout<<ini<<" ";

            ini+=d;ans++;

        }

        ini=x-d;

        while(ini>=1&&ans<n){

            cout<<ini<<" ";ini-=d;ans++;

        }

        ini=y+d;

        while(ans<n){

            cout<<ini<<" ";ini+=d;ans++;

        }

        cout<<endl;

    }

}