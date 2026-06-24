#include<bits/stdc++.h>

#include<iostream>

#include<stdio.h>

#include<iomanip>

#include<string.h>

#include<cmath>

#include<iterator>

#define pb push_back

#define w(t) while(t--)

#define NN "\n"

#define ll long long

#define fi(x,y) for(ll i=x;i<y;i++)

#define fj(p,q) for(ll j=p;j>=q;j++)

#define vct vector<int>v

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

void solve();

ll power(ll n,ll m);

int main()/// HI..!!

{

    fast

    ll t;

    cin>>t;

    while(t--)

    {

        solve();

    }

    return 0;

}

void solve()

{

    ll n,k,b,s;

    cin>>n>>k>>b>>s;



    ll mn=(ll)(k*b);

    ll mx=(ll)(((ll)(b+1)*k)-1+(ll)((k-1)*(n-1)));

    if(s<=mx && s>=mn)

    {

        s-=mn;

        fi(0,n-1){

            cout<<min(s,k-1)<<" ";

            s-=min(s,k-1);

        }

        cout<<((ll)(b*k)+s)<<NN;

    }

    else  //38>=31

    {

        cout<<-1<<NN;

    }

}

//void printvc(vector<int>v)

//{

//    for(auto z: v)

//    {

//        cout<<z;

//    }

//    cout<<NN;

//}