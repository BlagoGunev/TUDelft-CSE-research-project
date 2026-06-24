#include<iostream>

#include<cmath>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<sstream>

#include<vector>

#include<queue>

#include<stack>

#include<deque>

#include<map>

#include<set>

#include<utility>

#include<cstdlib>

#include<ctime>

#include<cctype>

#include<string>

#include<iomanip>

using namespace std;



#define sqr(x) ((x)*(x))

#define mp make_pair

#define pb push_back

#define pf push_front

#define X first

#define Y second

typedef long long ll;

typedef unsigned long long ull;

typedef unsigned int uint;

typedef double dbl;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



template<typename T> T qmin(const T a,const T b) {return a<b?a:b;} 

template<typename T> T qmax(const T a,const T b) {return a>b?a:b;}

template<typename T> void getmin(T &a,const T b) {if(a>b) a=b;}

template<typename T> void getmax(T &a,const T b) {if(a<b) a=b;}



void fileio(string s){

	if(s.empty()) return ;

	freopen((s+".in").c_str(),"r",stdin);

	freopen((s+".out").c_str(),"w",stdout);

}



const int inf=1e9+7;

const ll linf=1e16+7;



const int N=105;



map<string,int> id;



struct team{

	int scored,missed,points;

	string name;

}a[N];



bool cmp_score(const team &a,const team &b){

	if(a.points!=b.points) return a.points>b.points;

	if(a.scored-a.missed!=b.scored-b.missed) return a.scored-a.missed>b.scored-b.missed;

	return a.scored>b.scored;

}



bool cmp_name(const team &a,const team &b){

	return a.name<b.name;

}



char tmp[N],tmp1[N],tmp2[N];

string temp;

int n;



int main(){

	scanf("%d\n",&n);

	for(int i=1;i<=n;i++){

		getline(cin,a[i].name);

		id[a[i].name]=i;

	}

	for(int i=0;i<n*(n-1)/2;i++){

		getline(cin,temp);

		int name1,name2,s1,s2;

		sscanf(temp.c_str(),"%[^-]-%s %d:%d",tmp1,tmp2,&s1,&s2);

		name1=id[string(tmp1)];

		name2=id[string(tmp2)];

		a[name1].scored+=s1,a[name2].missed+=s1;

		a[name2].scored+=s2,a[name1].missed+=s2;

		if(s1>s2) a[name1].points+=3;

		else if(s2>s1) a[name2].points+=3;

		else ++a[name1].points,++a[name2].points;

	}

	sort(a+1,a+n+1,cmp_score);

	sort(a+1,a+n/2+1,cmp_name);

	for(int i=1;i<=n/2;i++) printf("%s\n",a[i].name.c_str());

	return 0;

}