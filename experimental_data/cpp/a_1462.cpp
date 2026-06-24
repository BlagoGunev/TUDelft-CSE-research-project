#include <bits/stdc++.h>

#include <string>

using namespace std;

#define ll long long

#define endl '\n'

#define f(x) for(auto &x:x)

#define w(x) while (x--)

#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL)

#define TT int t;cin>>t;while(t--)

#define soort(x) sort(x.begin(),x.end())

#define cin(a) f(a)cin>>a

#define cout(a) f(a)cout <<a<<' '

int main()

{

	fast;

	TT{

		ll n;

	cin >> n;

	deque <ll>a(n);

	cin(a);

	while (!a.empty())

	{

		cout << a.front() << ' ';

		a.pop_front();

		if (!a.empty()) {

			cout << a.back() << ' ';

			a.pop_back();

		}

	}

	cout << endl;

	}

}

/*

* 



*/