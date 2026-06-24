#include<bits/stdc++.h>

using namespace std;



#define MAXN 100 + 5



int a[MAXN];



int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	

	int n,m;

	cin >> n >> m;

	for(int i =0 ; i < n; i++)

	    cin >> a[i];

	

	int solve = 0;

	int cant= 0;

	for(int i = 0; i < n; i++){

	    cant += a[i];

	    if(cant > m)

	    {

	        solve++;

	        cant =0;

	        i--;

	    }

	}

	if(cant > 0 && cant <= m)solve++;

	cout << solve << endl;

	

}