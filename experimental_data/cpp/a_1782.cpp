#include <bits/stdc++.h>

using namespace std;

#define looklols    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define T           ll T;  cin>>T; while(T--)

#define ll          long long

#define lld         long double

#define ld          long double

#define F           first

#define S           second

#define pb          push_back

#define pf          push_front

#define all(x)      x.begin(),x.end()

#define allr(x)     x.rbegin(),x.rend()

#define ones(x) __builtin_popcountll(x)

#define sin(a) sin((a)*PI/180)

#define cos(a) cos((a)*PI/180)

#define endl        "\n"

const lld pi = 3.14159265358979323846;

const ll N=2e5+2;

const ll MOD = 998244353 , LOG = 25;

/*

  ℒ◎øкℓ☺łṧ

 */



int main () {

    looklols

    T {

        int w,d,h;

        cin>>w>>d>>h;

        int a,b,f,g;

        cin>>a>>b>>f>>g;

        int ans =1e9,cnt;

        ans = min(ans, abs(w-f)+ abs(w-a)+abs(b-g));

        cnt=ans;

        cnt= min(cnt, abs(0-a)+ abs(b-g)+ abs(0-f));

        ans=cnt;

        ans= min(ans, abs(0-b)+ abs(0-g)+ abs(a-f));

        cnt=ans;

        cnt= min(cnt, abs(d-b)+ abs(a-f)+ abs(d-g));

        ans=cnt;

        cout<<ans+h<<endl;

    }



}