#include <bits/stdc++.h>

#define ll long long

#define pb push_back

#define maxn 100010

#define mmaxn 1000000000

#define pii pair<int,int>

#define pll pair<ll int,ll int>

#define pdd pair<double,double>

#define MOD 1000000007

using namespace std;

int lex,n,p;

string s,t;

bool check(int i){

	

	if(i==n)	

		return true;

	

	if(lex==p)	

		return false;

	

	while(lex < p && ((i  && t[i-1] -'a' == lex) || (i - 2 >= 0 && t[i-2] - 'a' == lex)))

		lex++;

	

	if(lex>=p)

		return false;

	

	t[i]=lex +'a';

	

	lex = 0;

	

	return check(i+1);

}

int main(){

	ios_base::sync_with_stdio(0);

	cin >> n >> p >> s;

	t=s;

	for(int i=n-1;i>=0;i--){

		lex = s[i]-'a'+1;

		if(check(i)){

			cout << t << endl;

			return 0;

		}

	}

	cout << "NO"<<"\n";

	return 0;

}