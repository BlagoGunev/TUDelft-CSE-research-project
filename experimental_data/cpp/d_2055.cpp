#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 t, n, l, r, k, flag, x, temp, last, maxx, sub, m, y, summ, la;
i64 a[200005];
void solve(){
    cin >> n;
    cin >> k;
    cin >> la;
    la *= 2;
    k *= 2;
    i64 res = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] *= 2;
    }
    l = 0;
    flag = 0;
    temp = 0;
    for(int i = 1; i <= n; i++){
    	if(l >= la){
    		break;
    	}
    	//cout << i << ' ' << temp << ' ' << l << endl;
    	if(a[i] - temp > l){
    		if(flag == 0){
    			temp += (a[i] - temp - l);
    			l = l + k;
    		}
    		else{
    			x = (a[i] - temp - l);
    			l = l + x / 2 + k;
    			temp += x / 2;
    		}
    		flag = 1;
    	}
    	else{
    		y = min(l, a[i] + temp);
    		l = y + k;
    		flag = 1;
    	}
    }
    if(l < la){
    	temp += (la - l);
    }
    
    cout << temp << endl;
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