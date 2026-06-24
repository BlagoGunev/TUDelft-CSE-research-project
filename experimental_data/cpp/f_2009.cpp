#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 t, n, l, r, k, flag, x, temp, last, maxx, sub, m, y, summ, q, res;
i64 a[200005];
i64 qz[400005];
void solve(){
    cin >> n;
    cin >> q;
    qz[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        qz[i] = qz[i-1] + a[i];
    }
    for(int i = n+1; i <= 2*n; i++){
    	qz[i] = qz[i-1] + a[i-n];
    }
    for(int o = 1; o <= q; o++){
    	cin >> l;
    	cin >> r;
    	if((l-1)/n == (r-1)/n){
    		temp = (l-1)/n + 1;
    		x = l % n;
    		if(x == 0){
    			x = n;
    		}
    		y = r % n;
    		if(y == 0){
    			y = n;
    		}
    		res = qz[y + temp - 1] - qz[x + temp - 1 - 1];
    		//cout << y + temp - 1 << '?' << endl;
    		cout << res << endl;
    		continue;
    	}
    	res = 0;
    	res += ((r-1)/n - (l-1)/n - 1) * qz[n];
    	
    	x = l % n;
    	if(x == 0){
    		x = n;
    	}
    	temp = (l-1)/n + 1;
    	res += qz[n + temp - 1] - qz[x + temp - 2];
    	
    	
    	x = r % n;
    	if(x == 0){
    		x = n;
    	}
    	temp = (r-1)/n + 1;
    	res += qz[x + temp - 1] - qz[temp - 1];
    	//qz[x] - qz[0];
    	cout << res << endl;
    	
    }
    
    
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

	long long tt = 1;
	cin >> tt;
	while(tt--){
		solve();
	}

    return 0;
}