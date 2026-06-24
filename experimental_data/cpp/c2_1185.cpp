#include <bits/stdc++.h>
#define sqr(a) ((a)*(a))
#define rsz resize
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
#define PI 3.1415926535897932384626
#define MAXN 200010;

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main()
{
	#ifdef REJUNTE
	freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,M,x;
	map<int,int> m;
	cin >> n >> M;
	forn(i,n)
	{
		int ans=i;
		int auxM = M;
		cin >> x;
		auxM-=x;
		forall(it,m)
		{
			if(auxM>=it->fst*it->snd)
			{
				ans-=it->snd;
				auxM-=it->fst*it->snd;
			}
			else
			{
				ans-=auxM/it->fst;
				break;
			}
		}
		cout << ans << ' ';
		m[x]++;
	}
	return 0;
}