//#pragma GCC optimize(3)

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

#define int ll

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



const int N = 3e5 + 10;

int a[N], b[N], c[N], d[N], f[N];

int n, q, mod;



void init()

{

	f[1] = 1; f[2] = 1;

	fer(i, 3, 3e5)

	{

		f[i] = f[i - 1] + f[i - 2];

		f[i] %= mod;

	}

}



void add(int& a, int b)

{

	a = (a + b + mod) % mod;

}



void solve()

{

	cin >> n >> q >> mod;

	init();

	fer(i, 1, n)cin >> a[i];

	fer(i, 1, n)

	{

		cin >> b[i];

		c[i] = b[i] - a[i];

	}

	int cnt = 0;

	fer(i, 1, n)

	{

		if (i == 1)d[i] = c[i];

		else

		{

			d[i] = c[i] - c[i - 1] - c[i - 2];

		}

		d[i] = (d[i] + mod) % mod;

		cnt += d[i] != 0;

	}

	while (q--)

	{

		char op;

		int l, r;

		cin >> op >> l >> r;

		int t = 1;

		if (op == 'A')t = -1;

		if (d[l] == 0)cnt++;

		if (r + 1 <= n && d[r + 1] == 0)cnt++;

		if (r + 2 <= n && d[r + 2] == 0)cnt++;

		add(d[l], t);

		add(d[r + 1], -t* f[r - l + 2]);

		add(d[r + 2], -t* f[r - l + 1]);

		if (d[l] == 0)cnt--;

		if (r + 1 <= n && d[r + 1] == 0)cnt--;

		if (r + 2 <= n && d[r + 2] == 0)cnt--;

		if (!cnt)

			cout << "yes" << endl;

		else

			cout << "no" << endl;

	}

}



AC