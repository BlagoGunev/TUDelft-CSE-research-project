// Ideone_Language_Id:1
/* Don't remove the first line! */
#include <bits/stdc++.h>
/*more #includes. Don't write "using namespace std" here*/

#ifdef __WIN32__
#define getchar_unlocked getchar
#endif
//Input-output macros
#define s(n) scan(&n)
#define sf(n) scanf("%f",&n)
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",n)
// Useful constants
#define INF (int)1e9
#define MOD 1000000007
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define lz __builtin_clz
#define tz __builtin_ctz
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i,a,b) for(int i=a;i<b;i++)
#define forrev(i,a,b) for(int i=a;i>b;i--)
#define foreach(v,c) for(typeof((c).begin()) v=(c).begin();v!=(c).end();++v)
#define all(a) a.begin(),a.end()
#define in(a,b) ((b).find(a)!=(b).end())
#define pb push_back
#define fill(a,v) memset(a,v,sizeof a)
#define sz(a) ((int)(a.size()))
#define mp make_pair
#define checkbit(n,b) ((n>>b)&1)
#define DREP(a) sort(all(a));a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define re return
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int > ii;
typedef vector<ii > vii;
typedef vector<string> vs;
typedef vector<vi > vvi;
typedef istringstream iss;
typedef ostringstream oss;

/*Faster input functions*/
void scan(int* i){int t=0;char c;bool negative=false;c=getchar_unlocked();while(c<'0'||c>'9'){if(c=='-')negative=true;c=getchar_unlocked();}while(c>='0'&&c<='9'){t=(t<<3)+(t<<1)+c-'0';c=getchar_unlocked();}if(negative)t=~(t-1);*i=t;}
void scan(long long int* i){long long int t=0;char c;bool negative=false;c=getchar_unlocked();while(c<'0'||c>'9'){if(c=='-')negative=true;c=getchar_unlocked();}while(c>='0'&&c<='9'){t=(t<<3)+(t<<1)+c-'0';c=getchar_unlocked();}if(negative)t=~(t-1);*i=t;}
/*debug functions*/
#ifdef DEBUG
	#define debug(args...) {dbg,args;std::cout<<std::endl;}
#else
	#define debug(args...) // Just strip off all debug tokens
#endif
struct debugger{template<typename T> debugger& operator ,(const T& v){std::cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline std::ostream& operator<<(std::ostream& os,const std::pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline std::ostream&operator<<(std::ostream& os,const std::vector<T>& v){std::string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline std::ostream&operator<<(std::ostream& os,const std::set<T>& v){std::string delim="[";for (typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline std::ostream&operator<<(std::ostream& os,const std::map<T1,T2>& v){std::string delim="[";for (typename std::map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}

int toInt(string a){int i; iss(a)>>i; return i;}
string toString(int a){oss ss;ss<<a;return ss.str();}

/*structs and typedefs*/

int T;/*number of test cases*/
/*integers to be scanned every loop*/
/*more global variables*/

/*functions*/

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	s(n);
	vvi g(n,vi());
	int u,v;
	forall(i,0,n-1){
		s(u);s(v);
		u--;
		v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	//debug(g);
	vi a(n,0),b(n,0);
	forall(i,0,n){
		s(a[i]);
	}
	forall(i,0,n){
		s(b[i]);
	}
	deque<pair<int,ii> > Q;
	Q.pb(mp(0,mp(0,0)));

	int ans = 0;
	vi aaa;
	int c = 0;
	vb visited(n,false);
	while(!Q.empty()){
		pair<int,ii> p = Q.front();
		Q.pop_front();
		int chu = 0;
		int u = p.first,v = p.second.first;
		int level = p.second.second;
		//debug(u,level);
		//c++;
		//if(c>10)break;
		if(u==-1){
			level++;
			continue;
		}
		visited[u] = true;

		if(v==0){
			if(a[u] == b[u]){
				chu = 0;
			}
			else if(a[u]!=b[u]){
				aaa.pb(u);
				ans++;
				if(level%2==0){
					chu = 1;
				}
				else chu = 2;
			}
		}
		else if(v==1){
			if(level%2==0){
				if(a[u] == b[u]){
					chu = 0;
					aaa.pb(u);
					ans++;

				}
				else chu = 1;
			}
			else{
				if(a[u] == b[u]){
					chu = 1;
				}
				else{
					aaa.pb(u);chu = 3;ans++;

				}
			}
		}
		else if(v == 2){
			if(level%2==1){
				if(a[u] == b[u]){
					chu = 0;
					aaa.pb(u);
					ans++;

				}
				else chu = 2;
			}
			else{
				if(a[u] == b[u]){
					chu = 2;
				}
				else{
					aaa.pb(u);chu = 3;ans++;

				}
			}
		}
		else if(v == 3){
			if(a[u]!=b[u]){
				chu = 3;
			}
			else {
				if(level%2==0){
					chu = 2;
					aaa.pb(u);
					ans++;
				}
				else {chu = 1;
					aaa.pb(u);
					ans++;
				}
			}
		}

		int l = sz(g[u]);
		//debug(l);
		int flag  =0;
		forall(i,0,l)if(!visited[g[u][i]]){
			//debug("hello",g[u][i]);
			flag = 1;
			int ll = g[u][i];
			Q.pb(mp(ll,mp(chu,1+level)));
		}
		//if(flag)Q.pb(mp(-1,-1));



	}
	//debug(aaa);

	cout<<ans<<"\n";
	forall(i,0,ans){
		cout<<aaa[i]+1<<"\n";
			}

	return 0;
}