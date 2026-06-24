//#define _GLIBCXX_DEBUG 1
//#pragma optimize( "", on )
//#pragma GCC optimize("Ofast")
#include <iostream>
#include <cassert>
#include <list>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <list>
#include <unordered_map>
#include <memory>
#include <random>
#include <deque>
#include <signal.h>

using namespace std;

//#define map unordered_map
#define int long long
#define endl '\n'
#define endlf '\n'<<flush
#define pb push_back
#define pf push_front
#define ins insert
#define x first
#define sz size
#define era erase
#define pp pop_back
#define ppf pop_front
#define y second
#define fori(i, n) for(int i=0;i<(n);++i)
#define fori1(i, n) for(int i=1;i<(n);++i)
#define forir(i, n) for(int i=(n-1);i>=(0);--i)
#define foris(i, n) for(int i=0;i<(n.sz());++i)
#define foriab(i, a, b) for(int i=(a);i<(b);++i)
#define forirab(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define VI vector<int>
#define DI deque<int>
#define VVI vector<VI>
#define VVVI vector<VVI>
#define SI set<int>
#define SPII set<PII>
#define SP set<PAR>
#define MII map<int, int>
#define MSI map<string, int>
#define PII pair<int, int>
#define PAR PII
#define VP vector<PAR>
#define VB vector<char>
#define VVP vector<VP>
#define INF 1000000000000000LL
#define BIG 1000000LL
#define EPS 1e-8
#define MIMII map<int, MII>
#define VMII vector<MII>
#define MIVI map<int, VI>
#define MIPII map<int, PII>
#define UMIPII unordered_map<int, PII>
#define wall(x) ((x).begin()), ((x).end())
#define ld long double
#define MOD 1000000007LL
#define VPII vector<PII>
#define VVPII vector<VPII>
#define VMIPII vector<MIPII>
#define VUMIPII vector<UMIPII>
#define VPIPII vector<PIPII>
#define PIPII pair<int, PII>
#define ava(X) cout<<(X)<<endl;exit(0);
#define VS vector<string>
#define VSI vector<SI>
#define MPIPIII map<PIPII, int>
#define VC vector<char>

template<class A, class B> bool rmax(A& a, const B& b){
	A t=b;
	if(a<t){
		a=move(t);
		return 1;
	}
	return 0;
}
template<class A, class B> bool rmin(A& a, const B& b){
	A t=b;
	if(a>t){
		a=move(t);
		return 1;
	}
	return 0;
}
template<class T> istream& operator>>(istream& i, vector<T>& v){
	for(auto& x:v){
		i>>x;
	}
	return i;
}
template<class T, class U> istream& operator>>(istream& i, pair<T, U>& v){
	return i>>v.x>>v.y;
}
template<class T> ostream& operator<<(ostream& i, const set<T>& v){
	for(auto& x:v){
		i<<x<<' ';
	}
	return i<<endl;
}
template<class T> ostream& operator<<(ostream& i, const vector<T>& v){
	for(auto& x:v){
		i<<x<<' ';
	}
	return i<<endl;
}
template<class T, class U> ostream& operator<<(ostream& i, const pair<T, U>& v){
	return i<<v.x<<' '<<v.y<<endl;
}
template<class T> set<T> merge(const set<T>& a, const set<T>& b){
	set<T> ans;
	for(auto x:a){
		ans.ins(x);
	}
	for(auto x:b){
		ans.ins(x);
	}
	return ans;
}
PII operator+(PII a, PII b){
	return {a.x+b.x, a.y+b.y};
}
int fpowm(int i, int k){
	if(k){
		int t=fpowm((i*i)%MOD, k>>1);
		if(k&1){
			t*=i;
			t%=MOD;
		}
		return t;
	}
	return 1;
}
int invm(int k){
	return fpowm(k, MOD-2);
}
int fpow(int a, int b){
	if(b){
		int t=fpow(a, b>>1);
		if(b&1){
			t*=a;
		}
		return t;
	}
	return 1;
}
int mabs(int x){
	if(x<0){
		return -x;
	}
	return x;
}
int delup(int a, int b){
	int c=a/b;
	if(a%b){
		++c;
	}
	return c;
}
int fpowmod(int a, int k, int MOO){
	if(k){
		int y=fpowmod(a, k/2, MOO);
		y=y*y;
		y%=MOO;
		if(k&1){
			y*=a;
			y%=MOO;
		}
		return y;
	}
	return 1;
}
int invmod(int k, int MOO){
	return fpowmod(k, MOO-2, MOO);
}
#define YES cout<<"YES"<<endl;return;
#define NO cout<<"NO"<<endl;return;
#define NE1 cout<<"-1"<<endl;return;
#define ANS(x) cout<<(x)<<endl;return;
#define YESNO(x) if(x){YES;}NO;

/*
int NodeF(int a, int b){
	return a+b;
}
#define NEU 0
*/
/*
struct Node{
	Node* l;
	Node* r;
	int st;
	int en;
	int val;
	Node(){
		l=r=nullptr;
	}
	Node(int f, int t){
		st=f;
		en=t;
		if(sz()==1){
			val=f;
			l=r=nullptr;
		}else{
			int m=st+en>>1;
			l=new Node(st, m);
			r=new Node(m, en);
			val=-1;
		}
	}
	int sz(){
		return en-st;
	}
	int get(int f, int t){
		if(en<=f){
			return NEU;
		}
		if(t<=st){
			return NEU;
		}
		if(f<=st&&en<=t){
			return val;
		}
		int v1=l->get(f, t);
		int v2=r->get(f, t);
		return ::NodeF(v1, v2);
	}
	Node* set(int pos, int x){
		if(pos<st){
			return this;
		}
		if(pos>=en){
			return this;
		}
		if(sz()==1){
			Node* n=new Node();
			n->st=st;
			n->en=en;
			n->val=x;
			return n;
		}
		Node* n=new Node();
		n->st=st;
		n->en=en;
		n->l=l->set(pos, x);
		n->r=r->set(pos, x);
		n->val=f(n->l->val, n->r->val);
		return n;
	}
};
*/
/*
struct Node{
	Node* l;
	Node* r;
	int st;
	int en;
	int val;
	int del;
	Node(int f, int t){
		st=f;
		en=t;
		l=r=nullptr;
		del=val=0;
		if(sz()-1){
			int m=f+t>>1;
			l=new Node(f, m);
			r=new Node(m, t);
		}
	}
	int sz(){
		return en-st;
	}
	void push(){
		l->del+=del;
		r->del+=del;
		l->val+=del*l->sz();
		r->val+=del*r->sz();
		del=0;
	}
	void update(){
		val=l->val+r->val;
	}
	int get(int f, int t){
		if(f>=en){
			return 0;
		}
		if(t<=st){
			return 0;
		}
		if(f<=st&&en<=t){
			return val;
		}
		push();
		int v1=l->get(f, t);
		int v2=r->get(f, t);
		return v1+v2;
	}
	void add(int f, int t, int x){
		if(f>=en){
			return;
		}
		if(t<=st){
			return;
		}
		if(f<=st&&en<=t){
			del+=x;
			val+=x*sz();
			return;
		}
		push();
		l->add(f, t, x);
		r->add(f, t, x);
		update();
	}
};
*/
void solve(){
	int n;
	cin>>n;
	VS a;
	a.pb("KS QD 8D QC 8S 8C JD 9H AC TH 9S 9D QH 7H 8H TS 7S 9C");
	a.pb("6D JS 7D KH QS TC AD AS KC 6C 7C TD AH KD 6S JC JH 6H");
	a.pb("6C 6S 7C 7H 7S 8C 8H 8S 9D 9H TS JC QD QH QS KC KD KS");
	a.pb("6D 6H 7D 8D 9C 9S TC TD TH JD JH JS QC KH AC AD AH AS");
	a.pb("6S KC TD 8S AC 9S KD TS TH 7D 7C KH TC QC JH QD JC JD");
	a.pb("QH AS 9H 6C 8C 9C 6D AH AD KS JS 7H 6H 8H 9D QS 7S 8D");
	a.pb("6D 7D 7H 7S 8D 9C 9S TH JD JH JS QC QH KD KS AC AH AS");
	a.pb("6C 6H 6S 7C 8C 8H 8S 9D 9H TC TD TS JC QD QS KC KH AD");
	a.pb("JC JS 8S TD JD KH 7D 9C KC TH QD 8D 7H TC KD 9H 8C 6D");
	a.pb("7S AC QH AD 8H TS 6H JH 6C AH 7C 6S 9D QC AS QS KS 9S");
	a.pb("6D 6H 6S 7D 7H 7S 8D 8H 9C 9H TC TD TS JD QD QS KS AC");
	a.pb("6C 7C 8C 8S 9D 9S TH JC JH JS QC QH KC KD KH AD AH AS");
	a.pb("JS KS JD TH KH JC KC QD AS JH 6H 9H 7H 6C 9D AC 6D 9S");
	a.pb("8D 8H 7C 7S KD 7D 6S QH 8C TS AD TD TC 9C QC 8S QS AH");
	a.pb("6C 6H 7C 7H 7S 8C 8D 8S 9C TC JD JH QH QS KC KS AD AS");
	a.pb("6D 6S 7D 8H 9D 9H 9S TD TH TS JC JS QC QD KD KH AC AH");
	a.pb("AD KH JC JS TD AH TC KS JH QH 7D JD 8D 9S TH QD 6H 9C");
	a.pb("6S 7S KD 6D 9D 8H 8C AC QC QS 9H AS 7C 8S 7H KC TS 6C");
	a.pb("6C 7C 7S 8D 8H 8S 9C 9H TD TS JC JS QC QH KH AC AD AH");
	a.pb("6D 6H 6S 7D 7H 8C 9D 9S TC TH JD JH QD QS KC KD KS AS");
	a.pb("6H 7H 8C 8D 9H 9S TH JC JD JH JS QC QD QS KC KD KS AS");
	a.pb("6C 6D 6S 7C 7D 7S 8H 8S 9C 9D TC TD TS QH KH AC AD AH");
	a.pb("6C 6D 6S 7C 7D 7S 8S 9C 9H TH TS JC JD QC QD KC AC AH");
	a.pb("6H 7H 8C 8D 8H 9D 9S TC TD JH JS QH QS KD KH KS AD AS");
	a.pb("6D 7H 8C 8S 9D 9H 9S TS JD QC QH QS KC KH KS AC AH AS");
	a.pb("6C 6H 6S 7C 7D 7S 8D 8H 9C TC TD TH JC JH JS QD KD AD");
	a.pb("6C 6S 7C 7S 8C 8D 8S 9H TD TH JC JD JH JS QH QS KS AS");
	a.pb("6D 6H 7D 7H 8H 9C 9D 9S TC TS QC QD KC KD KH AC AD AH");
	fori(i, n){
		cout<<a[2*i]<<endl<<a[2*i+1]<<endl<<endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	//srand(time(0));
	while(t--){
		solve();
	}
	return 0;
}