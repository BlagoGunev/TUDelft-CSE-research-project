#include <iostream> 

#include <stdio.h> 

#include <algorithm> 

#include <cmath> 

#include <string> 

#include <cstring> 

#include <vector> 

#include <deque> 

#include <list> 

#include <set> 

#include <map> 

#include <ctime> 

#include <cstdlib> 

#include <queue>



using namespace std; 



typedef long long LL; 

typedef unsigned long long ULL; 

typedef short int int16; 

typedef long double ldouble; 



typedef set<int>::iterator sit;

typedef map<int,int>::iterator mit;

typedef vector<int>::iterator vit;



template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }

template<typename X> inline X sqr(const X& a) { return a * a; }



const int INF = 1e9+1; 

const LL INF1 = 1e18 + 1; 

const int size = 1e5 + 2; 

const double eps = 0.0001; 

const ldouble PI = 3.1415926535897932384626433832795;



#define MEMS(a,b) memset((a),(b),sizeof(a))

#define mp make_pair

#define pb push_back

#define fi first

#define se second

#define all(x) (x).begin(), (x).end()

void solution(); 

void include_file(); 

LL bin_search(LL left, LL right); 



int main(){ 

//srand(time(0)); 

//include_file(); 

solution(); 

return 0; 

} 

void include_file(){ 

freopen("input.txt","r",stdin); 

freopen("output.txt","w",stdout); 

} 



vector <vector<int> > g;

int was[100];

void dfs(int v)

{

	if (was[v]) return;

	was[v]=1;

	for (int i=0;i<g[v].size();++i)

	{

		dfs(g[v][i]);

	}

}

int bfs(int s,int toto)

{	

queue<int> q;

vector<bool> used (1001);

vector<int> d (1001), p (1001);



q.push (s);

used[s] = true;

p[s] = 1;

d[s]=0;

while (!q.empty()) {

	int v = q.front();

	q.pop();

	for (size_t i=0; i<g[v].size(); ++i) {

		int to = g[v][i];

		if (!used[to]) {

			used[to] = true;

			q.push (to);

			d[to] = d[v] + 1;

			p[to] = v;

		}

	}

}



return d[toto];

}



///////////////////SOLUTION

void solution() 

{ 

	int n,a[90],res=0;

	cin>>n;

	for(int i=0;i<n;++i)cin>>a[i];

	if(a[0]>15){cout<<15;return;}

	for(int i=1;i<n;++i)

		if(a[i]-a[i-1]>15)

		{

			cout<<a[i-1]+15;

			return;

		}

		cout<<min(90,a[n-1]+15);

}