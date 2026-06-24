#define _CRT_SECURE_NO_WARNINGS

#define IO ios::sync_with_stdio(false);cin.tie(0) 

#include<unordered_map>

#include<unordered_set>

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int>pi;

//#define x first

//#define y second

//#define int ll

#define fer(i,a,n) for(int i=a;i<=n;i++)

#define ref(i,n,a) for(int i=n;i>=a;i--)

#define endl '\n'

#define mem(a,x) memset(a,x,sizeof a)

#define ac IO;int t;cin>>t;while(t--)solve()

#define AC signed main(){IO;solve();}

ofstream fout("out.txt", ios::out);

ifstream fin("in.txt", ios::in);

//#define cout fout

//#define cin fin

//--------------------预处理分界线--------------------



const int N = 2e5 + 10;

int a[N], st[N][21];

int n;



int gcd(int a, int b)

{

	return b ? gcd(b, a % b) : a;

}



void init()

{

	fer(i, 1, n)

	{

		st[i][0] = a[i];

	}

	for (int j = 1; (1 << j) <= n; j++)

	{

		for (int i = 1; i + (1 << j) - 1 <= n; i++)

		{

			st[i][j] = gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);

		}

	}

}



int query(int l, int r)

{

	int k = log2(r - l + 1);

	return gcd(st[l][k], st[r - (1 << k) + 1][k]);

}



void solve()

{

	cin >> n;

	fer(i, 1, n)

	{

		cin >> a[i];

	}

	init();

	int ans = 0, r = -1, l = 1;

	for (int i = 1; i <= n; i++)

	{

		while (l <= i && query(l, i) < i - l + 1)l++;

		if (query(l, i) == i - l + 1 && l > r)

		{

			r = i;

			ans++;

		}

		cout << ans << ' ';

	}

}



AC