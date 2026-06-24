#include<bits/stdc++.h>

#define ll long long

#define rep(i,a,b) for(int i=a;i<b;i++)

#define rrep(i,a,b) for(int i=a;i>=b;i--)

#define repin rep(i,0,n)

#define int long long

#define di(a) int a;cin>>a;

#define precise(i) cout<<fixed<<setprecision(i)

#define vi vector<int>

#define si set<int>

#define mii map<int,int>

#define take(a,n) for(int j=0;j<n;j++) cin>>a[j];

#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' ';

#define vpii vector<pair<int,int>>

#define sis string s;

#define sin string s;cin>>s;

#define db double

#define be(x) x.begin(),x.end()

#define pii pair<int,int>

#define pb push_back

#define pob pop_back

#define ff first

#define ss second

using namespace std;

 

 

int power( int N, int M){

    int power = N, sum = 1;

    if(N == 0) sum = 0;

    while(M > 0){if((M & 1) == 1){sum *= power;}

    power = power * power;M = M >> 1;}

    return sum;

}

 



struct segtree{

 

    int size;

    vector<int> values;

 

    int merge(int a,int b){

        return a+b;

    }

 

    void init(int n){

        size=1;

        while(size<n)size*=2;

        values.assign(2*size,0LL);

    }

 

    void set(int l,int r,int v,int x,int lx,int rx){

        if(lx>=r || l>=rx)return;

        if(lx>=l && rx<=r){values[x]=merge(values[x],{v});return;}

        int m = (lx+rx)/2;

        set(l,r,v,2*x+1,lx,m);

        set(l,r,v,2*x+2,m,rx);

    }

 

    void set(int l,int r,int v){

        return set(l,r,v,0,0,size);

    }

 

    int get(int i,int x,int lx,int rx){

        if(rx-lx==1){

            return values[x];

        }

        int m = (lx+rx)/2;

        int res;

        if(i<m){

            res = get(i,2*x+1,lx,m);

        }

        else {

            res = get(i,2*x+2,m,rx);

        }

        return merge(res,values[x]);

    }

 

    int get(int i){

        return get(i,0,0,size);

    }

};



void solve()

{

    di(n)

    int a[n];

    take(a,n);

    segtree st;

    st.init(n);

    int cnt=0;

    repin{

        st.set(i+2,min(n,i+2+a[i]-1),1);

    }

    repin{

        int temp = a[i]-st.get(i)-1;

        // cout<<temp<<" ";

        if(temp>0){

        cnt+=temp;}

        else{

            if(i+1<n)

            st.set(i+1,i+2,-temp);

        }

    }

    cout<<"\n";

    cout<<cnt<<"\n";





}

signed main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    di(t)

    while(t--)

        solve();

    return 0;

}