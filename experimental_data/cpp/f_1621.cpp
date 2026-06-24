#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007 
#define oo 1000000010
const int N = 100010;

int n , a,b,c;

char s[N];
 	
void solve(){
	scanf("%d%d%d%d",&n,&a,&b,&c);
	scanf("%s",s);
	int A = 0, B = 0 , cnt = 1;
	int z = 0 , o = 0;
	if(s[0] == '0') z++; else o++;
	for(int i = 1 ;i < n;i++){
		if(s[i] == '0') z++; else o++;
		if(s[i] != s[i - 1]){
			if(s[i - 1] == '0')
				A += cnt - 1;
			else
				B += cnt - 1;
			cnt = 0;
		}
		cnt++;
	}
	if(s[n - 1] == '0') A += cnt - 1; else B += cnt - 1;
	long long ans = 0;
	if(B >= A){
		ans = (long long)A * a;
		ans += (long long)A * b;
		o -= A;
		z -= A;
		B -= A;
		if(B > 0){
			ans += b;
			B--;
			o--;
		}
		while(c < b && o > 1 && z > 0){
			z--;
			o--;
			ans += b - c;
		}
		printf("%lld\n",ans);
		return;
	}
	ans = (long long)B * (a + b);
	o -= B;
	z -= B;
	if(A > B){
		ans += a;
	}
	A = B;

	int start = 0;
	while(start < n && s[start] == '0') start++;
	if(start == n){
		printf("%lld\n",ans);
		return;
	}
	vector< int > v;
	for(int i = start;i < n;i++){
		if(i != start && s[i] != s[i - 1]){
			if(s[i - 1] == '0')
				v.push_back(cnt - 1);
			cnt = 0;
		}
		cnt++;
	}
	sort(v.begin(),v.end());
	for(int i = 0 ;i < (int)v.size();i++){
		if(o > 1 && z > 0 && v[i] <= A){
			o--;
			z--;
			A -= v[i];
			ans += max(0 , b - c);
		}
	}
	printf("%lld\n",ans);

}


int main(){
	int t ;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;	
}