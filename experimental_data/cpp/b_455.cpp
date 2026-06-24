#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <fstream>

#define INF 1000000007
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define Min(a,b) (((a) < (b))?(a):(b))
#define Max(a,b) (((a) > (b))?(a):(b))
#define S(a) ((a)*(a))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<int>::iterator viit;
typedef vector<long long> vll;
typedef vector<long long>::iterator vllit;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;

struct nodes {
	int len, flag;
	map<char,int> next;
}nds[100005];

int sz = 1;

void add_string ( char* str, int curr ) {
	int l = strlen(str);
	if(nds[curr].next.count(*str) == 0) {
		nds[curr].next[*str] = sz++;
		nds[sz-1].len = nds[curr].len+1;
	}
	if(l == 1) return; 
	add_string ( str+1, nds[curr].next[*str] );
	return;
}

pair<int,int> dfs ( int curr ) {
	if (nds[curr].next.size() == 0) {
		return MP(0,1);
	}
	map<char,int>::iterator it,itE = nds[curr].next.end();
	pair<int,int> fl0,ret;
	ret.X = ret.Y = -1;
	int fl1 = -1,fl2 = -1;
	for (it = nds[curr].next.begin() ; it != itE ; it++) {
		fl0 = dfs ( it->Y ); 
		//if(curr == 0) cout << fl0.X << " ";
		if (fl1 == -1) fl1 = fl0.X;
		if (fl2 == -1) fl2 = fl0.Y;
		if (fl1 != fl0.X) {
			//nds[curr].flag = 2;
			ret.X = 1;
		}
		if (fl2 != fl0.Y) ret.Y = 1; 
	}
	if(ret.X == -1) {
		if (fl1 == 1) {
			//nds[curr].flag = 0;
			ret.X = 0;
		}
		else {
			//nds[curr].flag = 1;
			ret.X = 1;
		}
	}
	if(ret.Y == -1) {
		if (fl2 == 1) {
			ret.Y = 0;
		}
		else ret.Y = 1;
	}
	return ret;
}


char s[100001];
int main() {
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	nds[0].len = 0;
	for (i = 0 ; i < n ; i++) {
		scanf("%s",s);
		add_string(s,0);
	}
	pii d = dfs (0); 
	//cout << d.X << " " << d.Y << endl;
	if(d.X+d.Y == 2) cout << "First\n";
	else if (d.X == 1) {
		if (k%2 == 1) cout << "First\n";
		else cout << "Second\n";
	}
	else if (d.Y == 1) cout << "Second\n";
	else cout <<"Second\n";
			
  return 0;
}