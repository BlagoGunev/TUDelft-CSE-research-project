#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define f first
#define s second
#define M 1000000007
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int N = 2e6+1 , inf = 2e9;
void testCase(){
	int n;
	scanf("%d" , &n);
	string ans = "";
	if(n >= 1)ans += '9';
	if(n >= 2) ans += '8';
	int now = 9;
	for (int i = 0; i < n-2; ++i){
		ans += (char) now + '0';
		now++;
		now %= 10;
	}
	cout << ans << endl;
}
int main(){
	int T = 1;
	scanf("%d",&T);
	while(T--){
		testCase();
	}


}