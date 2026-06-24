#include<bits/stdc++.h>
    using namespace std;

    #define LOCAL 0

    #define length(a) (sizeof(a)/sizeof(a[0]))
    #define print(v,i,x) for(int j=i;j<=x;j++){cout<<v[j]<<" ";}cout<<endl;
    #define pb push_back
    #define mp make_pair
    #define lli long long int
    #define ulli unsigned long long int
    #define all(x) x.begin(),x.end()
    #define f first
    #define s second

    #define si(x) scanf("%d",&x);
    #define sli(x) scanf("%ld",&x);
    #define slli(x) scanf("%lld",&x);
    #define si2(x,y) {si(x);si(y);}
    #define si3(x,y,z) {si(x);si(y);si(z);}
    #define slli2(x,y) {slli(x);slli(y);}
    #define slli3(x,y,z) {slli(x);slli(y);slli(z);}

    #define pi(x) printf("%d",x);
    #define pli(x) printf("%ld",x);
    #define plli(x) printf("%lld",x);
    #define pn printf("\n");
    #define ps printf(" ");
    #define pc(c) printf("%c",c);

    #define FOR(n) for(int i=0;i<n;i++)
    #define FORi(x,n) for(int i=x;i<=n;i++)
    #define FORj(x,n) for(int j=x;j<=n;j++)
    #define FORk(x,n) for(int k=x;k<=n;k++)
    #define ROFi(x,n) for(int i=x;i>=n;i--)
    #define ROFj(x,n) for(int j=x;j>=n;j--)
    #define ROFk(x,n) for(int k=x;k>=n;k--)

    #define debug(x) cout << "  - " << #x << ": " << x << endl;
    #define debugs(x, y) cout << "  - " << #x << ": " << x << "         " << #y << ": " << y << endl;
    #define debugss(x, y, z) cout << "  - " << #x << ": " << x << "         " << #y << ": " << y << "         " << #z << ": " << z <<  endl;
    #define fastIO 	std::ios::sync_with_stdio(false);cin.tie(NULL);

    typedef vector<int> vi;
    typedef vector<long> vli;
    typedef vector<long long> vlli;
    typedef vector<string> vstr;

    typedef pair<int,int> prii;
    typedef pair<int,lli> prilli;
    typedef pair<lli,int> prllii;
    typedef pair<lli,lli> prllilli;

    template <class T>T max3(T a,T b,T c){return max2(max2(a,b),c);}
    template <class T>T min3(T a,T b,T c){return min2(min2(a,b),c);}
    template <class T>T max4(T a,T b,T c,T d){return max2(max2(a,b),max2(c,d));}
    template <class T>T min4(T a,T b,T c,T d){return min2(min2(a,b),max2(c,d));}

    const lli mod = 1000000007ll;
    const lli MOD = 1000000009ll;

    lli count_bit(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
    lli check_bit(lli _mask,lli _i){lli x=1;return (_mask&(x<<_i))==0?0:1;}
    lli set_bit(lli _mask,lli _i){lli x=1;_mask=_mask|(x<<_i);return _mask;}
    lli powermod(lli _a,lli _b,lli _m=mod){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
    lli power(lli _a,lli _b){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a);_b/=2;_a=(_a*_a);}return _r;}
    lli add(lli a,lli b,lli m=mod){lli x=a+b;while(x>=m)x-=m;return x;}
    lli sub(lli a,lli b,lli m=mod){lli x=a-b;while(x<0)x+=m;return x;}
    lli mul(lli a,lli b,lli m=mod){lli x=a*b;x%=m;return x;}
    lli gcd(lli a,lli b){ if(a<b) {a=a^b;b=a^b;a=a^b;} if(b==0)return a; lli t; while(b){t=b; b=a%b; a=t;}return a;}
    lli lcm(lli a,lli b){ return (a*b)/gcd(a,b); }

     vector<string> _split(const string& s, char c) {
        vector<string> v;
        stringstream ss(s);
        string x;
        while (getline(ss, x, c))
            v.emplace_back(x);
        return v;
    }

    //	int dx[]={-1,-1,0,1,1,1,0,-1};
    //	int dy[]={0,1,1,1,0,-1,-1,-1};

    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};

    /*
    bool prime[100010];
    void sieve(){
        fill(prime,prime+100010,true);
        prime[0]=prime[1]=false;

        for(lli i=2;i<100010;i++){
            if(prime[i]){
                for(lli j=i*i;j<100010;j+=i)
                {prime[j]=false;}
            }
        }
    }
*/
     prii operator +(const prii& l , const prii& r){
         prii ret;
         ret.f=l.f+r.f;
         ret.s=l.s+r.s;
         return ret;
     }

    struct cmp{
        bool operator()(prii const & l,prii const & r) {
            return l.f>r.f;
        }
    }myobject;

    int n,w,a[110],ans[110];

    int main(){

        if(LOCAL){
            freopen("C:\\Users\\Smit Patel\\Desktop\\Questions\\This week\\input6.txt","r",stdin);
            freopen("C:\\Users\\Smit Patel\\Desktop\\Questions\\This week\\output6.txt","w",stdout);
        }

        si2(n,w);

        int req=0;
        int idx,mx=0;
        FORi(1,n){
            si(a[i]);
            if(mx<a[i]){
                mx=a[i];
                idx=i;
            }
            ans[i]=a[i]/2;
            if(a[i]%2==1)ans[i]++;
            req+=ans[i];
        }

        if(req>w){
            cout<<"-1";
            return 0;
        }

        vector<prii> v;

        FORi(1,n)v.pb(mp(a[i],i));
        sort(all(v),myobject);



        w-=req;

        FOR(n){
            int idx=v[i].s;
            int x=min(a[idx]-ans[idx],w);
            ans[idx]+=x;
            w-=x;
        }

        if(w>0){
            cout<<"-1";
            return 0;
        }


        FORi(1,n)cout<<ans[i]<<" ";

        return 0;
    }