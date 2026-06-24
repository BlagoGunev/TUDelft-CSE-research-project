/*

                    Genius is diligence

                                                             */

#include <bits/stdc++.h>

using namespace std;

#define speed           std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define tcase           int t;cin>>t;while(t--)

#define kill(x)         {cout<<x<<'\n';return;}

#define fxst(x)         cout<<fixed<<setprecision(x);

#define low(x)          transform(x.begin(),x.end(),x.begin(),::tolower)

#define up(x)           transform(x.begin(),x.end(),x.begin(),::toupper)

#define rplcs(s,x,y)    regex _(x); s=regex_replace(s, _, y)

#define rtt(s)          rotate(s.begin(),s.begin()+1,s.end());

#define mem(dp,x)       memset(dp,x,sizeof dp);

#define fr              first

#define sc              second

#define sz              size()

#define pb              push_back

#define pf              push_front

#define ppb             pop_back()

#define ppf             pop_front()

#define pr(x,y)         pair<x,y>

#define dbl             double

#define ll              long long

#define ull             unsigned long long

#define dl              dbl long

#define all(v)          v.begin(),v.end()

#define allr(v)         v.rbegin(),v.rend()

#define mx(v)           *max_element(all(v))

#define mn(v)           *min_element(all(v))

#define sm(v)          accumulate(v.begin(),v.end(),0ll);

#define rvrs(v)         reverse(all(v))

#define srt(v)          sort(all(v))

#define srtr(v)         sort(allr(v))

#define rplcv(v,x,y)    replace(all(v),x,y)

#define unq(v)          auto ittt=unique(all(v));v.resize(distance(v.begin(),ittt));

#define cin(v)          for(auto &i : v) cin>>i

#define cinpr(v)        for(auto &i : v) cin>>i.fr>>i.sc

#define cinrpr(v)       for(auto &i : v) cin>>i.sc>>i.fr

#define cout(v)         for(auto &i : v)  cout<<i<<' '; cout<<'\n'

void sol(){

    int n;cin>>n;

    vector<string>v[3];

    for(int i=0;i<3;i++){

        v[i].resize(n);cin(v[i]);

    }

    map<string,int>mp;

    for(int i=0;i<3;i++){

        for(auto s:v[i]) mp[s]++;

    }

    for(int i=0;i<3;i++){

        int sm=0;

        for(auto s:v[i]) {

            if(mp[s]==1)sm+=3;

            else if(mp[s]==2)sm++;

        }

        cout<<sm<<" ";

    }

    kill("");

    

}

int main(){speed;

    tcase

    sol();

}