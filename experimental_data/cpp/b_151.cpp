#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define PB push_back

#define FOR(prom,a,b) for( ll prom = (a); prom < (ll)(b); ++prom )
#define F(a) FOR(i,0,a)
#define FF(a) FOR(j,0,a)

#define EPS (1e-10)
#define INF ((1LL<<62LL)-1LL)

struct person{
	string name;
	int a, b, c;
	int pos;

};
bool cmpA(const person&a, const person &b){
	if(a.a==b.a)
		return a.pos<b.pos;
	return a.a>b.a;
}
bool cmpB(const person&a, const person &b){
	if(a.b==b.b)
		return a.pos<b.pos;
	return a.b>b.b;
}
bool cmpC(const person&a, const person &b){
	if(a.c==b.c)
		return a.pos<b.pos;
	return a.c>b.c;
}
int main(){
	int N, X;
	string S, T;
	vector<person> v;
	cin>>N;
	F(N){
		cin>>X>>S;
		person tmp={S, 0, 0, 0, i};
		F(X){
			cin>>T;
			if(T[0]==T[1] && T[1]==T[3] && T[3]==T[4] && T[4]==T[6] && T[6]==T[7])
				tmp.a++;
			else if (T[0]>T[1] && T[1]>T[3] && T[3]>T[4] && T[4]>T[6] && T[6]>T[7])
				tmp.b++;
			else 
				tmp.c++;
		}
		v.PB(tmp);
	}
	sort(v.begin(), v.end(), cmpA);
	vector<string> A, B, C;
	int mmax=v[0].a;
	int i=0;
	while(i<v.size() && v[i].a==mmax)
		A.PB(v[i++].name);
	cout<<"If you want to call a taxi, you should call:";
	F(A.size()){
		cout<<" "<<A[i];
		cout<<(i==A.size()-1?".":",");
	}
	cout<<endl;
	sort(v.begin(), v.end(), cmpB);
	 mmax=v[0].b;
	 i=0;
	while(i<v.size() && v[i].b==mmax)
		B.PB(v[i++].name);

	cout<<"If you want to order a pizza, you should call:";
	F(B.size()){
		cout<<" "<<B[i];
		cout<<(i==B.size()-1?".":",");
	}
	cout<<endl;
	sort(v.begin(), v.end(), cmpC);
	 mmax=v[0].c;
	 i=0;
	while(i<v.size() &&v[i].c==mmax)
		C.PB(v[i++].name);
	cout<<"If you want to go to a cafe with a wonderful girl, you should call:";
	F(C.size()){
		cout<<" "<<C[i];
		cout<<(i==C.size()-1?".":",");
	}
	cout<<endl;

	return 0;
}