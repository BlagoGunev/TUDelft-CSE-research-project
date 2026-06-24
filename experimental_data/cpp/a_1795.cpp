#include <bits/stdc++.h>

using namespace std;

/*          defines             */

#define endl                   '\n'

#define fast                   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define all(v)                 v.begin(), v.end()

#define rall(v)                v.rbegin(), v.rend()

#define line                   cout<<endl

#define F                      first

#define S                      second

#define _mx(n,m)               n = max(n,m)

#define _mn(n,m)               n = min(n,m)

#define cont                   continue

/*          typedef             */

typedef long long              ll;

typedef vector<int>            vi;

typedef vector<pair<int, int>> vpi;



/*          const             */

const int   MOD = 1e9 + 7;

const ll    OOO = (ll)2e18;

const int   OO = INT_MAX;







/**          functions

//cout << fixed << setprecision(9);



void usaco(string s="")

{

    if(s.size()!=0)

    {

        freopen((s+".in").c_str(),"r",stdin);

        freopen((s+".out").c_str(),"w",stdout);

    }

}



int dx[] = { 1,1,1,0,0,-1,-1,-1 };

int dy[] = { 1,0,-1,1,-1,1,0,-1 };

int n, m;

int dx[] = { 1,0,0,-1 };

int dy[] = { 0,1,-1,0 };



bool valid(int x, int y)

{

	return x > -1 && x < n&& y >= 0 && y < m;

}

int GCD(int a,int b)

{

	int gcd;

	if(a%b==0)

		return b;

	while(a%b!=0)

	{

		gcd=a%b;

		a=b;

		b=gcd;

	}



	return gcd;

}

int LCM(int a,int b){

	return a*b/GCD(a,b);

}



*/











///Hussein Rajab

///19.2.2023

///codeblocks is S.h.I.t and i hate it

///set لا تحذف و انت ماشي على







void solve() {



    int n,m;

    cin>>n>>m;

    /// n : a.size()

    /// m : b.size()

    string a,b;

    cin>>a>>b;

    int aa=0,bb=0;

    for(int i=1;i<a.size();i++){

        if(a[i] == a[i-1])

            aa++;

    }

    for(int i=1;i<b.size();i++){

        if(b[i] == b[i-1])

            bb++;

    }

    cout<<((aa > 1 || bb > 1) || (aa == 1 && bb == 1) || ((aa == 1 || bb == 1) && a[a.size()-1] == b[b.size()-1]) ? "NO" : "YES");





}



int main() {

	fast

		int T = 1;

	//usaco("div7");



        cin>>T;

	while (T--) {

		solve();

		line;

	}







}