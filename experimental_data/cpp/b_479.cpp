#include <bits/stdc++.h>



#define fst first

#define snd second

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define clr(a, v) memset( a , v , sizeof(a) )

#define pb push_back

#define mp make_pair

#define sz size()

#define FORN( i , s , n ) for( int i = (s) ; i < (n) ; i++ )

#define FOR( i , n ) FORN( i , 0 , n )

#define FORIT( i , x ) for( typeof x.begin() i = x.begin() ; i != x.end() ; i++ )

#define trace(x)    cout << #x << ": " << x << endl;

#define trace2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl;

#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define read ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



using namespace std;



typedef long long int64;

typedef vector <int> vi;

typedef pair <int,int> ii;

typedef vector <string> vs;

typedef vector <ii> vii;



#define MAXN 105



int v[MAXN];

int N,M;

int main(){

	read;

	int N,M;

	cin>>N>>M;

	FOR(i,N) cin>>v[i];

	int k = 0, lst = 1e9;

	vii ans;

	while(k<M) {

		int maxi = 0, mini = 0;

		FOR(i,N) if (v[i]>v[maxi]) {maxi = i;}

		FOR(i,N) if (v[i]<v[mini]) {mini = i;}

		if (maxi != mini and v[maxi] -1 >= v[mini] +1) ans.pb(ii(maxi+1,mini+1));

		else break;

		v[maxi]--;

		v[mini]++;

		

		lst = v[maxi] - v[mini];

		k++;

	}

	int maxi = 0, mini = 0;

	FOR(i,N) if (v[i]>v[maxi]) {maxi = i;}

	FOR(i,N) if (v[i]<v[mini]) {mini = i;}

	cout<<v[maxi] - v[mini]<<" "<<k<<endl;

	FOR(i,ans.sz) cout<<ans[i].fst<<" "<<ans[i].snd<<endl;

}