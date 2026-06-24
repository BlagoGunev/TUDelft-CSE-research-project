#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

template<class T> using pbmultiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;

#define f(i,a,b) for(long long i=a;i<b;i++)

#define rf(i,a,b) for(long long i=a;i>=b;i--)

#define ll long long

#define mp make_pair

#define pb push_back

#define vll vector<long long>

#define vvl vector<vll>

#define pll pair<ll,ll>

#define vc vector

#define fi first

#define se second

#define lb lower_bound

#define POW(a,b) (ll)(pow(a,b)+0.5)

#define gcd __gcd

#define remove_unique(x) x.erase(unique(x.begin(),x.end()),x.end())

#define to_lowercase(s) transform(s.begin(), s.end(), s.begin(), ::tolower)

#define to_uppercase(s) transform(s.begin(), s.end(), s.begin(), ::toupper)

#define p_q priority_queue

#define pqmax priority_queue<ll>

#define pqmin priority_queue<ll,vector<ll>,greater<ll>>

#define all(x) x.begin(),x.end()

#define inc(x,start) iota(x.begin(),x.end(),start)

#define pi  3.141592653589793238

#define inf  LONG_LONG_MAX

#define setbits(x) __builtin_popcountll(x)

#define zrobits(x) __builtin_ctzll(x)

#define IOS ios_base::sync_with_stdio(0)

#define tie cin.tie(NULL),cout.tie(NULL) 

#define endl '\n'

long long Ceil(long long a,long long b){return (a+b-1)/b;}

#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

#else

#define debug(x) 

#endif

template<class T> void _print(T t){ cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//--------------------------------------------------------------------------------------------------------------------------------------//

const int mod = 1e9 + 7;

//Optmization to prev solution

//Note: merging and storing very large string is inefficient

//      assigning is very small,so it is already very less time and space consuming

//Obs : we can just store count of haha and merging two string will only create additional haha's at the joining

struct word{

    ll count;

    string ff,ss;//first 3 and last 3 char

};

ll count_haha(string s)

{

  ll n=s.size();

  ll cc=0;

  f(i,0,n-3)

   cc+=(s.substr(i,4)=="haha");

  return cc;

}

void reduce(string &temp)

{

    ll n=temp.size();

    string temp2="";

    f(i,0,min(3ll,n))

     temp2+=temp[i];

    temp=temp2;

}

word merge(word a,word b)

{

   word temp;

   temp.count=a.count+b.count;

   temp.count+=count_haha(a.ss+b.ff);

   temp.ff=a.ff+b.ff;

   temp.ss=a.ss+b.ss;

   reverse(all(temp.ss));

   reduce(temp.ff),reduce(temp.ss);

   reverse(all(temp.ss));

   return temp; 

}

int main()

{  

   IOS;tie;

   int T;

   cin>>T;

   while(T--)

   {

     ll n;

     cin>>n;

     map<string,word> s; 

     string last;

     f(i,0,n)

     {

        string var;

        cin>>var;

        string op;

        cin>>op;

        if(op=="=")

        {

          string a,b,p;

          cin>>a>>p>>b;

          s[var]=merge(s[a],s[b]);

        }

        else

        {

          string z;

          cin>>z;

          word temp;

          temp.count=count_haha(z);

          temp.ff=temp.ss=z;

           reverse(all(temp.ss));

           reduce(temp.ff),reduce(temp.ss);

           reverse(all(temp.ss));

          s[var]=temp;

        }

        last=var;

     }

    cout<<s[last].count<<endl;

   }

    return 0;

}