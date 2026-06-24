#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <map>
#include <set>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cassert>
#include <math.h>
#include <iomanip>
#include <limits>

///LLONG_MAX,INT_MA
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define sz size()
#define FORA(i,c) REP(i,size(c))

#define itype(c) __typeof((c).begin())
#define FORE(e,c) for(itype(c) e=(c).begin();e!=(c).end();e++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))
#define CLEAR(x,c) memset(x,c,sizeof(x)) 
#define amfor(Iterator, Container) 	for ( auto Iterator = begin(Container); (Iterator) != end(Container); ++(Iterator) )
#define ramfor(Iterator, Container) for ( auto Iterator = Container.rbegin(); (Iterator) != Container.rend(); ++(Iterator) )
template<class C, class E> inline bool contains(const C& container, const E& element) { return container.find(element) != container.end(); }
#define  NP(nn,ta,a,tb,b) struct nn : pair<ta,tb> { nn():pair<ta,tb>(){}; nn(ta pa,tb pb):pair<ta,tb>(pa,pb){} ta& a(){return first;} tb& b(){return second;} };
template<class T> inline void checkmin(T &a, T b) { if (b < a) a = b; }//asigna en a el minimo
template<class T> inline void checkmax(T &a, T b) { if (b > a) a = b; }//asigna en a el maximo


typedef long long ll;
using namespace std; // since cin and cout are both in namespace std, this saves some text
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
int n, k;
vector<int> d;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << std::setprecision(15);
	cout << std::fixed;
	cin >> n >> k;
	d.resize(k);
	REP(i, k)
		cin >> d[i];
	vector<bool> foundA(n+1);

	vector<bool> canPlus(n+1,true);
	vector<bool> canMin(n + 1, true);
	canPlus[n] = false;
	canMin[1] = false;
	for(int v:d)
	{
		if (v > 1 && foundA[v - 1])
			canPlus[v - 1] = false;
		if (v < n && foundA[v + 1])
			canMin[v + 1] = false;
		foundA[v] = true;
	}
	int total =0;
	FOR(i, 1, n)
	{
		if (!foundA[i])
			total++;
		if(canMin[i])
			total++;
		if (canPlus[i])
			total++;
	}
	cout << total;
}