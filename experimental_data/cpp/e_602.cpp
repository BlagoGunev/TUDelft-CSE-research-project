//                              <...................... be name khoda ....................>
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e2;
const int maxm = 1e3;
const int maxs = 1e5;

int inp(){
	int x;
	scanf("%I64d",&x);
	return x;
}

int sum,m,n;
double knp[ maxs + maxm + 2], upd;
int in[ maxn ];
main(){
	scanf("%I64d%I64d", &n, &m);
	if( m == 1 ) return printf("1.00000000"),0;
	for(int i = 0;i < n; i++){
		in[ i ] = inp();
		sum += in[ i ];
	}
	for(int i = 1; i <= m; i++)
		if( i != in[ n - 1 ] ) knp[ i ] = 1;
	
	int num = n-1;	
	while( num-- ){
		upd = 0;
		for(int i = maxs + maxm+1; i > -1 ; i--){
			upd -= knp[ i ];
			if( i - m > -1 ) upd += knp[ i - m ];
			if( i - in[ num ] > -1 ) knp[ i ] = upd - knp[ i - in[ num ] ];	
			else knp[ i ] = upd;
		}
	}
	
	double ans = 0;
	for(int i = 0; i < sum; i++)
		ans +=  knp[ i ];
//		cout << knp[ i ] << endl;
	ans = 1.0 * ans * pow((double)1/(m-1), n-1);
	printf("%4.15f",1.0+ans);	
}