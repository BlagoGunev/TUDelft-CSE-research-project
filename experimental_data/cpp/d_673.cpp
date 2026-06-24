#include <iostream>
using namespace std;

int main() {
  int n, k, a, b, c, d;
	cin>>n>>k;
  cin>>a>>b>>c>>d;
	if(n == 4 || k < n+1) {
		cout<<-1<<endl;
	}
  else {
  	cout<<a<<' '<<c<<' ';
  	for (int i = 1; i <= n; i++) {
  		if (i != a && i != b && i != c && i != d) {
  			cout<<i<<' ';
      }
    }
  	cout<<d<<' '<<b<<' '<<endl<<c<<' '<<a<<' ';
  	for (int i = 1; i <= n; i++) {
  		if (i != a && i != b && i != c && i != d) {
  			cout<<i<<' ';
      }
    }
  	cout<<b<<' '<<d;
  }
}