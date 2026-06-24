//Dinar Perseüs

#include<bits/stdc++.h>

#define ll              long long int

#define fo(i,n)         for (int i = 0; i < n; i++)

#define Fo(i,n,m)       for(int i=n;n<m?i<m:i>m;n<m?i++:i--)

#define cy              cout<<"YES\n"

#define cn              cout<<"NO\n"

#define ce              cout<<'\n'

#define PB              push_back

#define pb              pop_back

#define vi              vector<int>

#define mod             1e9+7



bool doub_comp (double a,double b){return (abs(a-b)<1e-9);}





using namespace std;







void solve(){

    int n,m;

    cin>>n>>m;

    cout<<(n^m);

    ce;



    

}



int main(int argc, char const *argv[])

{

ios_base::sync_with_stdio(0);

cin.tie(0);

cout.tie(0);

#ifndef ONLINE_JUDGE

freopen("input.txt","r",stdin);

freopen("output.txt","w",stdout);

#endif

    

    // clock_t z = clock();

    int t=1;

    cin>>t;

    while (t--)solve();

    // cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);

    return 0;

}