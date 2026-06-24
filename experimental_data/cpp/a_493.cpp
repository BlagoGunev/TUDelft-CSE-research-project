#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define INF 1000000000
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;

string com1, com2;
int n,t,m;
char ch, x;
int h[110], a[110];

int main(){
	// com1 - дома
	// com2 - гости
	//
	cin >> com1;
	cin >> com2;
	cin >> n;
	for(int i = 0; i < 110; i++){
		h[i] = -1;
		a[i] = -1;
	}
	for(int i = 0; i < n; i++){
		cin >> t;
		cin >> ch;
		cin >> m;
		cin >> x;
		if(ch == 'h'){
			if(x == 'y' && h[m] == -1){
				h[m] = 0;
			}else if((x == 'r' && h[m]<=0) || (h[m] == 0 && x == 'y')){
				h[m] = 1;
				cout << com1 << " " << m << " " << t << endl;
			}
		}else{
			if(x == 'y' && a[m] == -1){
				a[m] = 0;
			}else if((x == 'r' && a[m] <= 0) || (a[m] == 0 && x == 'y')){
				a[m] = 1;
				cout << com2 << " " << m << " " << t << endl;
			}
		}
	}
	// sort(f.begin(), f.end());
	return 0;
}