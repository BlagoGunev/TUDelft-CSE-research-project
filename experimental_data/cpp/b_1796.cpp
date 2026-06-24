#include <bits/stdc++.h>
using namespace std;

#define newline   '\n'
#define begend(x) (x).begin(), (x).end()
#define int       int64_t
#define debug(x)  cout<< ">>> " << #x << ": " << x << newline;

void solve_case()
{
	string strA; cin>> strA;
	string strB; cin>> strB;

	if(strA[0] == strB[0]) {
		cout<< "YES" << newline;
		cout<< strA[0] << "*" << newline;
		return;
	}
	if(strA.back() == strB.back()) {
		cout<< "YES" << newline;
		cout<< "*" << strA.back() << newline;
		return;
	}

	for(int indxA=0; indxA < strA.size()-1; indxA++) {
		string newA = string(1,strA[indxA]) + string(1,strA[indxA+1]);
		for(int indxB=0; indxB < strB.size()-1; indxB++) {
			string newB =
				string(1,strB[indxB]) +	string(1,strB[indxB+1]);
			if(newA == newB) {
				cout<< "Yes" << newline
					<< "*"
					<< newA
					<< "*"
					<< newline;
				return;
			}
		}
	}
	cout<< "No" << newline;

	return;
}

int32_t main()
{
	int cntCases; cin>> cntCases;
	for(int caseNo = 1; caseNo <= cntCases; caseNo++) {
		solve_case();
	}

	return 0;
}