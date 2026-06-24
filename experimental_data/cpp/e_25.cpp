///      TANVIR HASAN



#include <bits/stdc++.h>

using namespace std;



#define uu         first

#define vv         second

#define pb         push_back

#define mp         make_pair

#define LL         long long

#define inf        INT_MAX/3

#define mod        1000000007ll

#define PI         acos(-1.0)

#define linf       (1ll<<60)-1

#define pii        pair<int,int>

#define vl        vector<LL>

#define vi        vector<int>

#define vs        vector<string>

#define pii        pair<int,int>



#define ALL(A)     (A).begin(),(A).end()

#define mset(a,v)     memset(a,v,sizeof a)

#define setinf(ar)  memset(ar,126,sizeof ar)

#define vsort(v)   sort(v.begin(),v.end())



#define FOR(I,A,B) for (__typeof (B) I = (A) ; I <= B ; ++I)

#define rof(i, a, b)    for (__typeof (b)i = (b) ; i >= a ; --i)

#define rep(I, n)       for (__typeof (n) I = 0 ; I < n ; ++I)

#define per(i, n)       for (__typeof (n)i = (n-1) ; i >= 0 ; --i)

#define forstl(I, s)    for (__typeof ((s).end ()) I = (s).begin (); I != (s).end (); ++I)

#define rofstl(I, s)    for (__typeof ((s).end ()) I = (s).end ()-1; I != (s).begin (); --I)



#define Int ({int a; scanf("%d", &a); a;})

#define I64 ({LL a; scanf("%lld", &a); a;})

#define Double ({double a; scanf("%lf", &a); a;})

#define Char ({char a; scanf("%c", &a); a;})

void FastIO()  {ios::sync_with_stdio(0);cin.tie(0);}



#define En "\n"

#define round(a,b,n) ((a-1+b)% n + n)% n + 1  /// 1 base round,, a starting index ,,+b for left to right,,-b for left,|b| turn,,total n gor

#define tata return 0

///           error////////////////////





vector<string> split(const string& s, char c) {

    vector<string> v;

    stringstream ss(s);

    string x;

    while (getline(ss, x, c))

        v.emplace_back(x);

    return move(v);

}



#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); puts(""); }

void err(vector<string>::iterator it) {}

template<typename T, typename... Args>

void err(vector<string>::iterator it, T a, Args... args) {

    cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << "  ";

    err(++it, args...);

}







#define dbg(x) cout<<#x<<" : "<<x<<endl

///          eeerrrrooooooorrrrrrr //////////////////



template <class T> inline T bigmod(T p,T e,T M){LL ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}

template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

template <class T> inline T bpow(T p,T e){LL ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p);p = (p * p);}return (T)ret;}





#define EPS numeric_limits<double>::epsilon()







/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////

///                                      Let's do it                                                        ///

///                                      Let's try it                                                       ///

/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////



const int maxN= 1e5 + 6;



int pi[3][maxN];

void prefix_func(string s,int pnt){

    int now=0,sz=s.size();

    for(int i=1;s[i];i++){

        while(now>0 && s[i]!=s[now]) now=pi[pnt][now-1];

        if(s[i]==s[now]) now++;

        pi[pnt][i]=now;

    }



}



string fnd(string a,string b,int pnt){



        int saz=a.size(),sbz=b.size(),m=0;

        for(int i=0;a[i];i++){



            while(m>0 && a[i]!=b[m]) m=pi[pnt][m-1];

            if(a[i]==b[m]) m++;

            if(m==sbz) return a;



        }

        return a+b.substr(m);



}







int main(){

   // freopen("in.txt","r",stdin);

   // freopen("output.txt","w",stdout);

    

    



   FastIO();



   string s[3];

   

   cin>>s[0];

   cin>>s[1];

   cin>>s[2];

   rep(i,3) prefix_func(s[i],i);



    int arr[3]={0,1,2};

    int ans=INT_MAX;

    do{

                  ans=min(ans, (int) fnd(fnd(s[arr[0]],s[arr[1]],arr[1]),s[arr[2]],arr[2]).size() );

    }while(next_permutation(arr,arr+3));



   cout<<ans<<En;

  

    return 0;

}