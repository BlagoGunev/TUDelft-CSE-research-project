#define _CRT_SECURE_NO_WARNINGS

#define IO ios::sync_with_stdio(false);cin.tie(0) 

#include<unordered_map>

#include<unordered_set>

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int,int>pi;

#define x first

#define y second

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



string s;



void solve()

{

	int n;

	cin >> n;

	cin >> s;

	s = "0" + s;

	bool flag = false;

	int sum = 0;

	fer(i, 1, n)

	{

		int t = s[i] - '0';

		flag |= t;

		sum += t;

	}

	if (!flag || sum & 1)

	{

		cout << "no" << endl;

		return;

	}

	cout << "yes" << endl;

	if (sum == n)

	{

		fer(i, 2, n)

		{

			cout << 1 << ' ' << i << endl;

		}

		return;

	}

	int root = 0;

	fer(i, 1, n)

	{

		if (s[i] == '0' && s[(i + n - 2) % n + 1] == '1')root = i;

	}

	int now = root % n + 1;

	while (now != root)

	{

		cout << root << ' ' << now << endl;

		while (s[now] != '1')

		{

			cout << now << ' ' << now % n + 1 << endl;

			now = now % n + 1;

		}

		now = now % n + 1;

	}

}



int main()

{

	ac;

}