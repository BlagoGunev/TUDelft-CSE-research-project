#include<bits/stdc++.h>

using namespace std;

#define int long long

#define double long double

#define debug(x) cout << #x << ": " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))

#define inc(x,start,end) for(auto x=start;x<=end;x++)

#define dec(x,end,start) for(auto x=end;x>=start;x--)

#define sys cin.tie(0)->sync_with_stdio(0),cout.tie(0)->sync_with_stdio(0)

const int inf=1ll<<50;

const int N=2e5+5;

const int mod=1e9+7;

const double eps=1e-8;

const double pi=acos(-1);

inline void read() {}

template <typename T1, typename... T2>

inline void read(T1 &x,T2 &...lx)

{

    char c;

    bool f=0;

    x=0;

    while(c=getchar(),c<'0'||c>'9')f=c=='-'&&!f;

    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();

    x=f?-x:x;

    read(lx...);

}

template<class T>

inline void write(T x)

{

    if(x<0)putchar('-'),x=-x;

    if(x>9)write(x/10);

    putchar(x%10+'0');

}

template<class T>

inline void ws(T x){write(x);putchar(' ');}

template<class T>

inline void we(T x){write(x);putchar('\n');}

signed main()

{

    sys;

    int _;

    cin >> _;

    while (_--)

    {

        int n;

        string s;

        cin >> n >> s;

        if (n>=3)

        {

            cout << "NO" << endl;

        }

        else if (s=="00"||s=="11")

        {

            cout << "NO" << endl;

        }

        else

        {

            cout << "YES" << endl;

        }

        

    }

    

    return 0;

}//脑弹