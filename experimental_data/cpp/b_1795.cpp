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



    int n,k;

    cin>>n>>k;

    int lk=0,rk=0;

    for(int i=0;i<n;i++){

        int l,r;

        cin>>l>>r;

        if(k == l)

            lk++;

        if(k == r)

            rk++;



    }

    cout<<(lk > 0 && rk > 0 ? "YES" : "NO");



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