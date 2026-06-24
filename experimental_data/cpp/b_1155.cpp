#include <bits/stdc++.h>
using namespace std;

/*** Template Begins ***/

typedef long long                   ll;
typedef pair<int,int>               PII;
typedef pair<ll, pair<int, int> >   PIII;
typedef vector<int>                 vi;
typedef vector<pair<int, int> >     vii;

#define endl         '\n'
#define pb           push_back
#define INF          INT_MAX/10
#define F            first
#define S            second
#define mp           make_pair
#define ios          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define hell         1000000007
#define all(a)       (a).begin(),(a).end()
#define fr(i,a,b)    for(int i=a;i<=b;i++)
#define lp(i,a)      for(int i=0;i< a;i++)

// Debug //

#define trace(x)                 cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

// Constants //

const int N = 1e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);

/*** Template Ends ***/
int n, p1, p2;
string s;

void solve(){
    
    cin >> n >> s;
    int rem = n;
    bool valid = true;

    int i = 0;
    while(rem > 11)
    {
    	if (i%2 == 0)
    	{
    		while(p1 < n && (s[p1]=='8'||s[p1]=='A') ) p1++;
    		if (p1 == n){	cout << "YES" << endl;	return;	}

    		s[p1] = 'A';
    		//trace(p1);
    		p1++;
    	}
    	else
    	{
    		while(p2 < n && (s[p2]!='8'||s[p2]=='A') ) p2++;
    		if (p2 == n){	cout << "NO" << endl;	return;	}

    		s[p2] = 'A';
    		//trace(p2);
    		p2++;
    	}
    	rem--;
    	i = 1-i;
    }
    assert(rem == 11);
    
    for(int i = 0; i < n; i++)
    	if (s[i] != 'A')
    	{
    		if (s[i] == '8')	cout << "YES" << endl;
    		else cout << "NO" << endl;
    		return;
    	}

}

signed main(){
    
    ios;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    //cin >> t;
    t = 1;
    while(t--)
        solve();

    return 0;
}