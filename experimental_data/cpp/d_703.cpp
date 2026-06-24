#include <bits/stdc++.h>





#define gc getchar unlocked

#ifndef ONLINE JUDGE

#define gc getchar

#endif // ONLINE JUDGE



#define pc putchar_unlocked

#ifndef ONLINE JUDGE

#define pc putchar

#endif // ONLINE JUDGE



#define fRead           freopen("input.txt","r",stdin)

#define fWrite          freopen ("output.txt","w",stdout)



#define eps             1e-8

#define inf             0x3f3f3f3f

#define INF             2e18

#define LL              long long

#define ULL             unsigned long long

#define PI              acos(-1.0)

#define pb              push_back

#define mk              make_pair

#define pii             pair<int,int>

#define pLL             pair<LL,LL>

#define ff              first

#define ss              second

#define all(a)          a.begin(),a.end()

#define rall(a)         a.rbegin(),a.rend()

#define SQR(a)          ((a)*(a))

#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())

#define min3(a,b,c)     min(a,min(b,c))

#define max3(a,b,c)     max(a,max(b,c))

#define min4(a,b,c,d)   min(min(a,b),min(c,d))

#define max4(a,b,c,d)   max(max(a,b),max(c,d))

#define Iterator(a)     __typeof__(a.begin())

#define rIterator(a)    __typeof__(a.rbegin())

#define FOR(a,it)       for(Iterator(a) it = a.begin();it != a.end(); it++)

#define rFOR(a,it)      for(rIterator(a) it = a.rbegin();it != a.rend(); it++)



using namespace std;



const int MOD = 1e9 + 7;

int fx[] = {+1,-1,+0,+0,+1,+1,-1,-1,+0};

int fy[] = {+0,+0,+1,-1,+1,-1,+1,-1,+0};

template <typename T> inline T GCD (T a,T b ) {a = abs(a);b = abs(b);while ( b ) { a = a % b; swap ( a, b ); } return a;}

template <typename T> inline T LCM(T x,T y){T tp = GCD(x,y);if( (x / tp) * 1. * y > 9e18) return 9e18;return (x / tp) * y;}

template <typename T> inline T BigMod(T A,T B,T M){T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}

template <typename T> inline T InvMod (T A,T M){return BigMod(A,M-2,M);}

/*---------------------------fast I/O------------------------------------*/

#define scani2(a,b) scani(a) , scani(b)

#define scani3(a,b,c) scani(a), scani(b), scani(c)

#define scani4(a,b,c,d) scani(a), scani(b), scani(c), scani(d)

#define scani5(a,b,c,d,e) scani(a), scani(b), scani(c), scani(d) , scani(e)

template <typename T> bool scani(T &n){n = 0;bool got = false;bool negative = false;char c = gc();while( c < '0' || c > '9'){if(c == '-') negative = true;c = gc();}while(c >= '0' && c <= '9'){got = true;n = n*10 + c-48;c = gc();}if(negative) n = ~(n-1);return got;}

template <typename T> void write(T n,int type = true){if(n<0) {pc('-');n = -n;}if(!n) {pc('0');if(type==32) pc(' '); else if(type) pc('\n'); return;}char buff[22];int len = 0;while(n) buff[len++] = n%10+48,n/=10;for(int i=len-1;i>=0;i--) pc(buff[i]);if(type==32) pc(' '); else if(type) pc('\n');}

int scans(char *a){int i=0;char c = 0;while(c < 33) c = gc();while(c > 33){a[i++] = c;c = gc();}a[i] = 0;return i;}

/*********************************************** End of template *********************************************/



const int N = 1000006;

const int mod = 10000003;



struct data

{

  int xx,yy,pos;

  data(int x,int y,int p){

    xx = x;

    yy = y;

    pos = p;

  }

  bool operator <(const data &yoo) const{

    return yy < yoo.yy;

  }

};



//data Qs[N];

vector <data>  ques;

int Xor[N];

int Bit[N];

int ans[N];

int prv[N];

int in[N];

int n;

//unordered_map <int,int> Mp;



bool vis[mod + 10];

int val[mod + 10];

int Map[mod + 10];



inline int hash_me(int x)

{

  int pos = x % mod;

  while(vis[pos] && val[pos] != x){

    pos++;

    if(pos == 0) pos = mod;

  }

  return pos;

}



inline void add(int x,int val)

{

  while(x <= n){

    Bit[x] ^= val;

    x += x & (-x);

  }

}



inline int query(int x)

{

  int ret = 0;

  while(x){

    ret ^= Bit[x];

    x -= x & (-x);

  }

  return ret;

}



int main()

{

  scani(n);

  for(int i=1;i<=n;i++){

    scani(in[i]);

    Xor[i] = Xor[i - 1] ^ in[i];

    int pos = hash_me(in[i]);

    if(!vis[pos]){

      vis[pos] = true;

      val[pos] = in[i];

    }

    prv[i] = Map[pos];

    Map[pos] = i;

  }

  int qr;

  scani(qr);

  for(int i=1;i<=qr;i++){

    int x,y;

    scani2(x,y);

    ques.pb(data(x,y,i));

  }

  sort(all(ques));

  int id = 1;

  int last = 0;

  int tp;

  FOR(ques,it){

    int i = it->yy;

//    if(ques[i].empty()) continue;

    while(id <= i){

        add(id , in[id]);

        if(prv[id]) add(prv[id] , in[prv[id]]);

        id++;

    }

    if(last != i) {

      tp = query(i) ^ Xor[i];

      last = i;

    }

    int x = it->xx;

    ans[it->pos] = tp ^ Xor[x - 1] ^ query(x - 1);

  }

  for(int i=1;i<=qr;i++) write(ans[i]);

  return 0;

}