#include <bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
#pragma GCC optimize("Ofast,inline")
#define all(x) x.begin(),x.end()
void YES()
{
    cout<<"YES\n";
}
void NO()
{
    cout<<"NO\n";
}
struct Line
{
    ll slope,intercept;
    Line(ll slope , ll intercept) : slope(slope),intercept(intercept){};
    ll value(ll x)
    {
        return x*slope+intercept;
    }
    ll intersection(Line y)
    {
        return ((y.intercept - intercept + slope - y.slope - 1ll) / (slope-y.slope));
    }
    void print()
    {
    	cout<<slope<<" "<<intercept<<" ";
    }
};
struct Point
{
	ll x,y;
	Point(ll nx,ll ny)
	{
		x = nx;
		y = ny;
	}
	Point operator + (Point p2)
	{
		return Point(x+p2.x,y+p2.y);
	}
	Point operator - (Point p2)
	{
		return Point(x-p2.x,y-p2.y);
	}
	ll operator * (Point p2)
	{
		return x*p2.y-y*p2.x;
	}
};
bool comp(Point a,Point b)
{
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
vector<Point> ch(vector<Point> & pts)
{
	vector<Point> answer;
	answer.push_back(pts[0]);
	ll l = 0;
	for (ll e = 1;e<pts.size();e++)
	{
		while (answer.size() > 1 && (pts[e]-answer[l-1])*(answer[l]-answer[l-1])>0)
		{
			answer.erase(--answer.end());
			l--;
		}
		answer.push_back(pts[e]);
		l++;
	}
	answer.erase(--answer.end());
	return answer;
}
vector<Point> CH(vector<Point> & pts)
{
	sort(pts.begin(),pts.end(),comp);
	vector<Point> answer = ch(pts);
	reverse(pts.begin(),pts.end());
	vector<Point> h = ch(pts);
	for (Point i : h) answer.push_back(i);
	return answer;
}
ll A(vector<Point> & pts)
{
	ll answer = 0;
	ll n = pts.size();
	for (ll i = 0;i<n;i++)
	{
		answer += pts[i]*pts[(i+1)%n];
	}
	return abs(answer);
}
struct CHT
{
    deque<pair<Line,ll>> lines;
    void insert(ll m,ll c)
    {
        Line line(m,c);
        while (lines.size() > 1 && lines.back().second >= lines.back().first.intersection(line))
        {
            lines.pop_back();
        }
        if (lines.empty())
        {
            lines.emplace_back(line,0);
            return;
        }
        lines.emplace_back(line,lines.back().first.intersection(line));
        // for (auto i : lines)
        // {
        	// i.first.print();
        	// cout<<i.second<<"\n";
        // }
    }
    ll query(ll x)
    {
        while (lines.size() > 1)
        {
            if (lines[1].first.value(x) > lines[0].first.value(x)) lines.pop_front();
            else break;
        }
        // lines.front().first.print();
        return lines.front().first.value(x);
    }
    ll query2(ll x)
    {
        auto qry = *lower_bound(lines.rbegin(), lines.rend(),
                                make_pair(Line(0, 0), x),
                                [&](const pair<Line, int> &a, const pair<Line, int> &b) {
                                    return a.second > b.second;
                                });
        return qry.first.value(x);
    }
};
const int ALPHABET_SIZE = 26;
struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == NULL) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    
    void deleteWord(const string& word) {
        deleteWordRecursive(root, word, 0);
    }
    
    bool deleteWordRecursive(TrieNode* node, const string& word, int depth) {
        if (node == nullptr) {
            return false;
        }

        if (depth == word.length()) {
            if (!node->isEndOfWord) {
                return false; // Word not present in the trie
            }

            node->isEndOfWord = false;

            // If the node has no children, it can be safely removed
            return nodeHasNoChildren(node);
        }

        int index = word[depth] - 'a';
        if (deleteWordRecursive(node->children[index], word, depth + 1)) {
            // Delete the child node if it can be deleted
            delete node->children[index];
            node->children[index] = nullptr;

            // Check if the current node has no children and is not an end-of-word node
            return nodeHasNoChildren(node);
        }

        return false;
    }

    bool nodeHasNoChildren(TrieNode* node) {
        for (TrieNode* child : node->children) {
            if (child != nullptr) {
                return false;
            }
        }
        return !node->isEndOfWord;
    }
    
    bool search(const string& word) {
        TrieNode* node = searchNode(word);
        return (node != NULL && node->isEndOfWord);
    }
    
    TrieNode* searchNode(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == NULL) {
                return NULL; // Character not found in the trie
            }
            current = current->children[index];
        }
        return current;
    }
    
    void printAllWords() {
        string currentWord;
        printWordsRecursive(root, currentWord);
    }
    
    void printWordsRecursive(TrieNode* node, string& currentWord) {
        if (node == NULL) {
            return;
        }

        if (node->isEndOfWord) {
            cout << currentWord << endl;
        }

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (node->children[i] != NULL) {
                currentWord.push_back('a' + i);
                printWordsRecursive(node->children[i], currentWord);
                currentWord.pop_back();
            }
        }
    }
};

vector<vector<ll>> ST(vector<ll> & a)
{
    ll n = a.size();
    vector<vector<ll>> st(n);
    for (ll e = 0;e<n;e++)
    {
        st[e].push_back(a[e]);
    }
    for (ll k = 1;k<=20;k++)
    {
        for (ll e = 0;e<n-(1<<k)+1;e++)
        {
            st[e].push_back(max(st[e][k-1],st[e+(1<<(k-1))][k-1]));
        }
    }
    return st;
}
vector<ll> twopows;
ll FINDST(vector<vector<ll>> & st,ll l,ll r)
{
    if (twopows.empty())
    {
        twopows = vector<ll>(200001);
        for (ll e = 1,d = 0;e<=200000;e++)
        {
            if ((1 << (d+1)) == e) d++;
            twopows[e] = d;
        }
    }
    ll k = twopows[r-l+1];
    return max(st[l][k],st[r-(1 << k)+1][k]);
}
struct LCT // queries are sorted in increasing order
{
	ll n;
	vector<Line> tree;
	vector<ll> Q;
	LCT(vector<ll> q)
	{
		Q = q;
		n = q.size()-1;
		tree.assign(4*n+4,Line(0,(ll)-1e18));
	}
	void add(Line curr,ll v = 1,ll l = 1,ll r = -1)
	{
		if (r == -1) r = n;
		if (l == r)
		{
			if (curr.value(Q[l]) > tree[v].value(Q[l])) swap(curr,tree[v]);
			return;
		}
		ll mid = (l+r)/2;
		if (curr.value(Q[mid]) > tree[v].value(Q[mid]))
		{
			swap(curr,tree[v]);
		}
		if (curr.slope > tree[v].slope) add(curr,v*2+1,mid+1,r);
		else add(curr,v*2,l,mid);
	}
	ll find(ll ind,ll v = 1,ll l = 1,ll r = -1)
	{
		// cout<<tree[v].slope<<" "<<tree[v].intercept<<"\n";
		if (r == -1) r = n;
		if (l == r) return tree[v].value(Q[ind]);
		ll mid = (l+r)/2;
		if (ind <= mid) return max(tree[v].value(Q[ind]),find(ind,v*2,l,mid));
		else return max(tree[v].value(Q[ind]),find(ind,v*2+1,mid+1,r));
	}
};
ll get(ll a,vector<ll> & pr)
{
	return pr[a] = (pr[a] == a ? a : get(pr[a],pr));
}
bool merge(ll a,ll b,vector<ll> & pr,vector<ll> & siz)
{
	 a = get(a,pr),b = get(b,pr);
	 if (a == b) return 0;
	 if (siz[a] > siz[b])
	 {
	 	pr[b] = a;
	 	siz[a] += siz[b];
	 }
	 else
	 {
	 	pr[a] = b;
	 	siz[b] += siz[a];
	 }
	 return 1;
}
mt19937 mt(time(0));
ld rnd()
{
	ld ANS = mt();
	ANS /= mt.max();
	return ANS;
}
void read(vector<ll> & a)
{
	for (ll & i : a) cin>>i;
}
void read(vector<vector<ll>> & a)
{
	for (vector<ll> & i : a)
	{
		for (ll & j : i) cin>>j;
	}
}
void print(vector<ll> & a)
{
	for (ll & i : a) cout<<i<<" ";
	cout<<"\n";
}
void print(vector<vector<ll>> & a)
{
	for (vector<ll> & i : a)
	{
		for (ll & j : i) cout<<j<<" ";
		cout<<"\n";
	}
}
struct BIGINT
{
	vector<ll> a;
	ll len;
	BIGINT(ll n)
	{
		len = n;
		a.assign(n,0ll);
	}
	void add(BIGINT b)
	{
		for (ll e = len-1;e>0;e--)
		{
			a[e] += b.a[e];
			if (a[e] >= 10)
			{
				a[e-1] += 1;
				a[e] -= 10;
			}
		}
	}
	void print()
	{
		bool f = 0;
		for (ll e = 0;e<len;e++)
		{
			if (a[e] > 0) f = 1;
			if (f) cout<<a[e];
		}
		if (!f) cout<<0;
		cout<<"\n";
	}
};
ll mod = 1e9+7;
ll mult(vector<ll> a)
{
	ll answer = 1;
	for (ll i : a)
	{
		answer *= i;
		answer %= mod;
	}
	return answer;
}
ll binpow(ll n,ll k = mod-2,ll M = mod)
{
	bitset<31> o(k);
	ll curr = 1;
	for (ll e = 30;e>-1;e--)
	{
		curr *= curr;
		curr %= M;
		if (o[e])
		{
			curr *= n;
			curr %= M;
		}
	}
	return curr;
}
vector<ll> fact,invfact;
ll bincoef(ll n,ll k)
{
	if (n < k || k < 0) return 0;
	if (fact.empty())
	{
		fact = invfact = vector<ll>(500001,1);
		for (ll e = 1;e<=500000;e++)
		{
			fact[e] = (fact[e-1]*e)%mod;
		}
		invfact[500000] = binpow(fact[500000]);
		for (ll e = 499999;e>=0;e--)
		{
			invfact[e] = (invfact[e+1]*(e+1))%mod;
		}
	}
	return mult({fact[n],invfact[n-k],invfact[k]});
}
vector<vector<ll>> G(ll n,ll m = -1)
{
	if (m == -1) m = n-1;
	vector<vector<ll>> ed(n);
	for (ll i = 0;i<m;i++)
	{
		ll u,v;cin>>u>>v;
		u--;v--;
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	return ed;
}
vector<ll> bfs(vector<ll> v,vector<vector<ll>> & ed)
{
	vector<ll> dist(ed.size(),-1);
	queue<ll> Q;
	for (ll i : v)
	{
		dist[i] = 0;
		Q.push(i);
	}
	while (!Q.empty())
	{
		ll v = Q.front();
		Q.pop();
		for (ll u : ed[v])
		{
			if (dist[u] == -1)
			{
				dist[u] = dist[v]+1;
				Q.push(u);
			}
		}
	}
	return dist;
}
vector<ll> dij(ll v,vector<vector<pair<ll,ll>>> & ed)
{
	set<pair<ll,ll>> vert;
	vector<ll> dist(ed.size(),1e18);
	dist[v] = 0;
	vert.insert({0,v});
	while (!vert.empty())
	{
		ll v = (*vert.begin()).second;
		vert.erase(vert.begin());
		for (pair<ll,ll> u : ed[v])
		{
			if (dist[u.first] > dist[v]+u.second)
			{
				vert.erase({dist[u.first],u.first});
				dist[u.first] = dist[v]+u.second;
				vert.insert({dist[u.first],u.first});
			}
		}
	}
	return dist;
}
ll x = 99901;
vector<ll> PX,INVX;
vector<ll> HASH(string & s)
{
	ll n = s.size();
	if (PX.empty())
	{
		PX.assign(1000001,1);INVX.assign(1000001,1);
		for (ll i = 1;i<=1000000;i++)
		{
			PX[i] = (PX[i-1]*x)%mod;
		}
		INVX[1000000] = binpow(PX[1000000]);
		for (ll i = 999999;i>=0;i--)
		{
			INVX[i] = (INVX[i+1]*x)%mod;
		}
	}
	vector<ll> hash(n);
	for (ll i = 0;i<n;i++)
	{
		hash[i] = ((i > 0 ? hash[i-1] : 0ll)+s[i]*PX[i])%mod;
	}
	return hash;
}
ll FH(vector<ll> & hash,ll l,ll r)
{
	return ((hash[r]-(l > 0 ? hash[l-1] : 0ll)+mod)*INVX[l])%mod;
}
vector<ll> Mob(ll n)
{
	vector<ll> mob(n+1,1),p(n+1,1);
	for (ll i = 2;i<=n;i++)
	{
		if (!p[i])
		{
			continue;
		}
		for (ll j = i;j<=n;j+=i)
		{
			p[j] = 0;
			if (j%(i*i) == 0) mob[j] = 0;
			mob[j] = -mob[j];
		}
	}
	return mob;
}
vector<ll> ModSqrt(ll c,ll p)
{
	if (c == 0) return {0};
	if (p == 2)
	{
		return {1};
	}
	if (binpow(c,(p-1)/2,p) != 1) return {};
	ll l = 0,q = p-1;
	while (q%2 == 0)
	{
		q /= 2;
		l++;
	}
	ll n = 1;
	while (binpow(n,(p-1)/2,p) == 1)
	{
		n = rand()%p;
	}
	ll e = 0;
	ll inv = binpow(n,p-2,p);
	for (ll i = 2;i<=l;i++)
	{
		ll x = (binpow(inv,e,p)*c)%p;
		if (binpow(x,(p-1)/(1ll << i),p) != 1) e += (1ll << (i-1));
	}
	ll a = (binpow(inv,e/2,p)*binpow(c,(q+1)/2,p))%p;
	ll b = (binpow(n,e/2,p)*a)%p;
	return {b,p-b};
}
pair<ll,ll> bez(ll a,ll b)
{
	if (a == 0) return {0,1};
	if (b == 0) return {1,0};
	pair<ll,ll> tmp;
	if (a > b)
	{
		tmp = bez(a%b,b);
		tmp.second -= a/b*tmp.first;
	}
	else
	{
		tmp = bez(a,b%a);
		tmp.first -= b/a*tmp.second;
	}
	return tmp;
}
vector<pair<ll,ll>> dir = {{1,0},{-1,0},{0,1},{0,-1}};





void ans()
{
	ll n,m;cin>>n>>m;
	vector<vector<vector<ll>>> num(n,vector<vector<ll>>(m,vector<ll>(4)));
	vector<string> gr(n);
	vector<vector<vector<vector<ll>>>> dist(n,vector<vector<vector<ll>>>(m,vector<vector<ll>>(4,vector<ll>(4,1e18))));
	for (ll i = 0;i<n;i++)
	{
		cin>>gr[i];
	}
	queue<vector<ll>> vert;
	for (ll i = 0;i<n;i++)
	{
		for (ll j = 0;j<m;j++)
		{
			if (gr[i][j] == 'S')
			{
				dist[i][j][0][0] = 0;
				vert.push({i,j,0,0});
			}
		}
	}
	while (!vert.empty())
	{
		ll x = vert.front()[0],y = vert.front()[1],t = vert.front()[2],N = vert.front()[3];
		// cout<<x<<" "<<y<<" "<<t<<" "<<N<<" "<<dist[x][y][t][N]<<"\n";
		vert.pop();
		for (ll i = 0;i<4;i++)
		{
			pair<ll,ll> D = dir[i];
			ll nx = x+D.first,ny = y+D.second;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || gr[nx][ny] == '#') continue;
			ll nxt = (t == i)+N;
			if (t == i) nxt = N+1;
			else nxt = 1;
			if (nxt > 3) continue;
			if (dist[nx][ny][i][nxt] > dist[x][y][t][N]+1)
			{
				dist[nx][ny][i][nxt] = dist[x][y][t][N]+1;
				vert.push({nx,ny,i,nxt});
			}
		}
	}
	for (ll i = 0;i<n;i++)
	{
		for (ll j = 0;j<m;j++)
		{
			if (gr[i][j] == 'T')
			{
				ll answer = 1e18;
				for (vector<ll> i : dist[i][j])
				{
					for (ll j : i) answer = min(answer,j);
				}
				if (answer == 1e18) answer = -1;
				cout<<answer<<"\n";
			}
		}
	}
}
int main()
{
    cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(0);
	srand(time(0));
	ll t = 1;
	cout<<fixed<<setprecision(11);
	for (ll e = 1;e<=t;e++)
	{
		ans();
	}
    return 0;
}