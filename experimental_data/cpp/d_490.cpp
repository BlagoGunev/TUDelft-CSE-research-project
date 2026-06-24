#include <bits/stdc++.h>

#define loop(i,n) for(int i = 0;i < (n);i++)

#define range(i,a,b) for(int i = (a);i <= (b);i++)

#define all(A) A.begin(),A.end()

#define PI acos(-1)

#define pb push_back

#define mp make_pair

#define sz(A) ((int)A.size())

#define vi vector<int>

#define vl vector<long long>

#define vd vector<double>

#define vp vector<pair<int,int> >

#define ll long long

#define pi pair<int,int>

#define point pair<double,double>

#define pl pair<ll,ll>

#define popcnt(x) __builtin_popcount(x)

#define LSOne(x) ((x) & (-(x)))

#define xx first

#define yy second

#define PQ priority_queue

#define print(A,t) cerr << #A << ": "; copy(all(A),ostream_iterator<t>(cerr," " )); cerr << endl

#define prp(p) cerr << "(" << (p).first << " ," << (p).second << ")";

#define prArr(A,n,t)  cerr << #A << ": "; copy(A,A + n,ostream_iterator<t>(cerr," " )); cerr << endl

#define PRESTDIO() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)

using namespace std;



int f(int x,int p,int & y){

	while(x%p == 0){

		x /= p;

		y++;

	}

	return x;

}



void do3(ll & a,ll & b,int k){

	while(k && a%3 == 0) {

		a /= 3; a <<= 1;	k--;

	}

	while(k && b%3 == 0) {

		b /= 3;	b <<= 1; k--;

	}	

}



void do2(ll & a,ll & b,int k){

	while(k && a%2 == 0) a >>= 1,k--;

	while(k && b%2 == 0) b >>= 1,k--;

}



int main(){

	ll a,b,c,d; cin >> a >> b >> c >> d;

	int x2 = 0,x3 = 0,y2 = 0,y3 = 0;

	int oa = f(a,2,x2); oa = f(oa,3,x3);

	int ob = f(b,2,x2); ob = f(ob,3,x3);

	int oc = f(c,2,y2); oc = f(oc,3,y3);

	int od = f(d,2,y2); od = f(od,3,y3);

	

	//cout << oa << " " << ob << " " << oc << " " << od << endl;

	if(oa*1LL*ob != oc*1LL*od){

		cout << -1 << endl;

		return 0;

	}

	int t = abs(x3 - y3);

	if(x3 < y3) y2 += (y3 - x3);

	else x2 += (x3 - y3);

	int target2 = min(x2,y2);

	t += abs(y2 - x2);

	cout << t << endl;

	do3(a,b,x3 - min(x3,y3));

	do3(c,d,y3 - min(x3,y3));

	do2(a,b,x2 - min(x2,y2));

	do2(c,d,y2 - min(x2,y2));

	cout << a << " " << b << endl;

	cout << c << " " << d << endl;

	return 0;

}