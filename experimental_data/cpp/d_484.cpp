#include <bits/stdc++.h>



using namespace std;



#define rep(i,a,n) for (int i=(a);i<(n);i++)

#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)

#define pb push_back

#define mp make_pair

#define all(x) (x).begin(),(x).end()

#define fi first

#define se second

#define SZ(x) (int)x.size()



typedef long long ll;

typedef long double ld;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef pair<int,int> pii;



template<typename T>

T getint() {

    T x=0,p=1;

    char ch;

    do{ch=getchar();}while(ch <= ' ');

    if(ch=='-')p=-1,ch=getchar();

    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();

    return x*p;

}



template<typename T1,typename T2>

bool umin(T1 &x,const T2&y){

    if(x>y)return x=y,true;

    return false;

}

template<typename T1,typename T2>

bool umax(T1 &x,const T2&y){

    if(x<y)return x=y,true;

    return false;

}



const int maxn=(int)1e6+10;

const int inf=(int)1e9+5;

const int mod=(int)1e9+7;

const ll llinf=(ll)1e18+5;

const ld pi=acos(-1.0);



struct maxstack {

    maxstack(){}

    stack <pair<ll,ll> > s;

    void push(ll x,ll y){

        //cout<<x<<endl;

        if(s.empty()){

            s.push(mp(x,y));

        }else{

            s.push(mp(x,max(y,s.top().se)));

        }

    }

    ll getmax(){

        if(s.empty())return -llinf;

        return s.top().se;

    }

    ll top() { return empty()? -llinf : s.top().fi; }

    void pop(){

        s.pop();

    }

    size_t empty() const { return s.empty(); }

};



int main(){



  //  freopen("input.txt","r",stdin);

  //  freopen("output.txt","w",stdout);



    int n=getint<int>();



    vector<int> a(n);

    vector<ll> dp(n);



    maxstack mx,mn;



    rep(i,0,n){

        a[i]=getint<int>();

        if(i>0)dp[i]=dp[i-1];

        umax(dp[i],a[i]+mn.getmax());

        umax(dp[i],-a[i]+mx.getmax());

        while(!mx.empty()&&a[i]>mx.top()){

            mx.pop();

        }

        while(!mn.empty()&&a[i]<mn.top()){

            mn.pop();

        }

        mn.push(a[i],(i>0?dp[i-1]:0)-a[i]);

        mx.push(a[i],(i>0?dp[i-1]:0)+a[i]);

    }

    printf("%I64d\n",dp[n-1]);

    return 0;

}