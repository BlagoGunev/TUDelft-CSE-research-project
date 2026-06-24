#include<bits/stdc++.h>

using namespace std;

#include <string>

#include <algorithm>

#include <cmath>

#define ll long long

#define endl '\n'

#define pb push_back

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);



void solve()

{

    int n,l,r,s;

    cin>>n>>l>>r>>s;

    ll ans[n+1]={0},flag[n+1]={0};

    int diff=r-l+1;

    if(s<diff*(diff+1)/2 || s>diff*(2*n+1-diff)/2)

    cout<<-1<<endl;

    else{

        for(int i=n;i>0;i--){

            if(s-i>=(1+r-l)*(r-l)/2 && s>=i){

                s-=i;

                ans[l++]=i;

                flag[i]=1;

            } 

        }

        for(int i=1;i<=n;i++){

            int j=1;

            if(flag[i]==0){

                while(ans[j]!=0)

                j++;

                ans[j++]=i;

            }

        }

    for(int i=1;i<=n;i++)

	cout<<ans[i]<<" ";

	cout<<endl;    

    }

    

}

int main()

{

    fastio();

    ll t=1;

    cin>>t;



    while(t--)

    {

        solve();

    }

    return 0;

}