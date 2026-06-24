#define _CRT_SECURE_NO_WARNINGS

#define IO ios::sync_with_stdio(false);cin.tie(0) 

#include<unordered_map>

#include<unordered_set>

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll ,ll>pi;

//#define x first

//#define y second

//#define int ll

#define fer(i,a,n) for(int i=a;i<=n;i++)

#define ref(i,n,a) for(int i=n;i>=a;i--)

#define endl '\n'

#define mem(a,x) memset(a,x,sizeof a)

#define ac IO;int t;cin>>t;while(t--)solve()

#define AC signed main(){IO;solve();}

//--------------------预处理分界线--------------------



const int N = 1e6 + 10, mod = 998244353;

ll v[N];



void solve()

{

	int n, k;

	cin >> n >> k;

	fer(i, 1, n)cin >> v[i];

	ll ans = 1;

	fer(i, 1, k)

	{

		ans = (ans * i) % mod;

	}

	fer(i, k + 1, n)

	{

		if (v[i - k] == 0)

		{

			ans = (ans * (k + 1)) % mod;

		}

		else if (v[i - k] == -1)

		{

			ans = (ans * i) % mod;

		}

	}

	fer(i, n - k + 1, n)

	{

		if (v[i] > 0)

		{

			cout << 0 << endl;

			return;

		}

	}

	cout << ans << endl;

}



int main()

{

	ac;

}