#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
#define pb push_back
#define mp make_pair
#define st first
#define nd second 
#define girdi freopen("in.gir", "r", stdin);
#define cikti freopen("out.cik", "w", stdout);  
typedef pair < int, int > ii;
typedef long long lint;

int main()
{
	//girdi cikti
	int n;
	cin >> n;
	if(n <= 2) cout << "No\n";
	else if(n%2){
		cout << "Yes\n";
		cout << "1 "<< (n+1)/2 << endl;
		cout << n-1 << " ";
		for(int i = 1; i < n; i++)
			if(i != (n+1)/2) cout << i << " ";
		cout << n;
	}
	else{
		cout << "Yes\n";
		cout << n/2 << " ";
		for(int i = 1; i <= n; i+=2)
			cout << i << " ";
		cout << endl << n/2 << " ";
		for(int i = 2; i < n; i+=2)
			cout << i << " ";
		cout << n;
	}
	
    return 0;
}