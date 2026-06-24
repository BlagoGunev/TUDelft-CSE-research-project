#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define bug() cout << "BUG" << endl ;
#define X first
#define Y second
#define Size(x) (int)x.size()
typedef long long ll;
const ll INF = 1e18 ;

const int N = 1e3 + 100 ; 
int n , a[N] , b[N] ; 

int main ()
{
	cin >> n ;
	for(int i=0 ; i < n ; i++){
		cin >> a[i] >> b[i] ;
		if(b[i] != a[i])
		{
			cout << "rated" ; 
			return 0 ; 		
		}
	}
	for(int i=0 ; i < n ; i++){
		for(int k = 0 ; k < i ; k++)
			if(a[k] < a[i])
			{
				cout << "unrated" ;
				return 0 ; 
			}
	}
	// wow // 
	cout << "maybe" ;
	return 0 ; 
}