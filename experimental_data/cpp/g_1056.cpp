#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


LL slow(LL n, LL m, LL s, LL t){
	LL a = s;
	LL curt = t;
	while(curt){
		if(a < m){
			a += curt;
		} else {
			a -= curt;
		}
		a %= n;
		if(a < 0) a += n;

		curt --;
	}
	return a;
}
LL fast(LL n, LL m, LL s, LL t){
	LL a = s;
	LL curt = t;
	while(1){
		if(a < m){
			a += curt;
		} else {
			a -= curt;
		}
		a %= n;
		if(a < 0) a += n;

		curt --;
		if(curt % n == 0) break;
	}
	LL rounds = curt / n;
	vector<LL> cycle(n, -1);
	for(LL x = 0; x < n; x++){
		LL cur = 1;
		LL pos = x;
		while(cur < n){
			if(pos < m){
				pos -= cur;
			} else {
				pos += cur;
			}
			pos %= n;
			if(pos < 0) pos += n;
			cur++;
		}
		cycle[x] = pos;
	}
	LL expo[n][60];
	for(int j = 0; j < 60; j++){
		if(j == 0){
			for(int i = 0; i < n; i++) expo[i][0] = cycle[i];
		} else {
			for(int i = 0; i < n; i++){
				expo[i][j] = expo[expo[i][j-1]][j-1];
			}
		}
	}
	LL pos = a;
	for(LL j = 59; j >= 0; j--){
		if(rounds >= (1LL << j)){
			rounds -= (1LL << j);
			pos = expo[pos][j];
		}
	}
	return pos;
}

LL calc(LL x, LL n, LL m){
	LL cur = 1;
	LL pos = x;
	int dostep = 0;
	while(cur < n){
		LL newpos = pos;
		if(newpos < m){
			newpos -= cur;
		} else {
			newpos += cur;
		}
		newpos %= n;
		if(newpos < 0) newpos += n;
		if(dostep){
			pos = newpos;
			cur++;
			dostep = 0;
			continue;
		}
		if((pos < m) == (newpos < m)){
			if(pos < m && newpos < m){
				dostep = 1;
				continue;
			} else if(pos >= m && newpos >= m){
				// help
			}
			dostep = 1;
			continue;
		} else {
			if(pos < m && newpos >= m){
				LL r = (n - cur) / 2;
				r = min(r, (m-1-pos));
				r = min(r, newpos - m);
				pos += r;
				cur += 2 * r;
				if(r == 0) dostep = 1;
				continue;
			} else if(pos >= m && newpos <= m){
				dostep = 1;
				continue;
			}
		}
	}
	return pos;
}

LL blazing(LL n, LL m, LL s, LL t){
	vector<LL> sqrt(n, -1);
	for(LL a = 0; a < n; a++){
		sqrt[(a*a) % n] = a;
	}

	if(m > n-m){
		LL g = (n - 1 - s);
		g %= n;
		if(g < 0) g += n;
		LL ans = blazing(n, n-m, g, t);
		ans = (n - 1 - ans);
		ans %= n;
		if(ans < 0) ans += n;
		return ans;
	}
	LL a = s;
	LL curt = t;
	while(1){
		if(a < m){
			a += curt;
		} else {
			a -= curt;
		}
		a %= n;
		if(a < 0) a += n;

		curt --;
		if(curt % n == 0) break;
	}
	LL rounds = curt / n;
	map<LL,LL> occ;

	LL pos = a;
	while(rounds > 0){
		LL cur = 1;
		if(occ.find(pos) != occ.end()){
			LL period = occ[pos] - rounds;
			rounds %= period;
		}
		occ[pos] = rounds;
		if(rounds > 0){
			while(cur < n){
				if(pos < m){
					pos -= cur;
				} else {
					pos += cur;
				}
				pos %= n;
				if(pos < 0) pos += n;
				cur++;
			}
			rounds--;
		}
	}
	return pos;
}

void test(){
	for(LL n = 3; n <= 15; n++){
		for(LL m = 1; m < n; m++){
			for(LL s = 0; s < n; s++){
				for(LL t = 1; t <= 15 * n; t++){
					assert(blazing(n,m,s,t) == fast(n,m,s,t));
					//assert(blazing(n,m,s,t) == slow(n,m,s,t));
				}
			}
		}
	}
	cerr << "tested" << endl;
}

int main(){
	LL n, m, s, t;
	cin >> n >> m >> s >> t;
	s = s-1;
	cout << blazing(n, m, s, t) + 1 << '\n';
	//test();
}