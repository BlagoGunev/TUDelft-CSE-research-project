#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
//using namespace __gnu_pbds;


#define INF (1<<30)
#define INFll (1ll<<62)
#define F first
#define S second
#define MOD 1000000007
#define mkp(a, b) make_pair(a, b)


//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


#define FOR(I, A, B) for(int (I) = (A); (I) < (B); (I)++)
#define ROF(I, A, B) for(int (I) = (A); (I) >= (B); (I)--)


#define SQR(A) 1ll*(A)*(A)


const char array_sep[] = " ";
const char array_end[] = "";


const char pair_sep[] = " ";
const char pair_end[] = "";


const char map_sep[] = "->";
const char map_end[] = "\n";


const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int ddx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};


template<typename A> ostream & operator<<(ostream & os, const vector<A> & x)
{
    for(int i = 0; i < x.size(); i++)
        os << x[i] << array_sep;
    os << array_end;
    return os;
}


template<typename A, typename B> ostream & operator<<(ostream & os, const pair<A, B> & x)
{
    os << x.first << pair_sep << x.second << pair_end;
    return os;
}


template<typename A> istream & operator>>(istream & is, vector<A> & x)
{
    for(int i = 0; i < x.size(); i++)
        is >> x[i];
    return is;
}


template<typename A, typename B> istream & operator>>(istream & is, pair<A, B> & x)
{
    is >> x.first >> x.second;
    return is;
}


template<typename _key, typename _val> ostream & operator<<(ostream & os, map<_key, _val> & mp)
{
    for(auto it : mp)   // not for C++98 or earlier
        os << it->F << map_sep << it->S << map_end;
    return os;
}


template<typename _response> void die(_response ans)
{
    cout << ans << endl;
    exit(0);
}


int a, b, n, k;
string s;
vector<int> ans;

int main()
{
    srand((unsigned int) time(0));
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//	freopen("errlog.log", "w", stderr);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("friends.in", "r", stdin);
#endif

    cin >> n >> a >> b >> k >> s;

    int cnt = 0;
    int l = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == '0')
            l++;
        else
            cnt += l / b,
                    l = 0;
    cnt += l / b;
//    cerr << cnt << endl;
    int seq = 0;
    for(int i = 0; i < n && cnt >= a; i++)
    {
        if(s[i] == '0')
        {
            seq++;
            if(seq == b)
            {
                s[i] = '1';
                ans.push_back(i + 1);
                seq = 0;
                cnt--;
            }
        }
        else
            seq = 0;
    }


    cout << ans.size( ) << endl << ans << endl;

    return 0;
}