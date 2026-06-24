#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifdef LOCAL
#include<debug.h>
#include<writeout.h>
#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
#define debug(...) 28
#define write_output(...) 03
#define eprintf(...) 2003
#endif

template<typename T> void print_impl(const T& arg) { std::cout << arg; }
template<typename T, typename... Args> void print_impl(const T& arg, const Args&... rest) { std::cout << arg << ' '; print_impl(rest...); }
template<typename... Args> 
void print(const Args&... args) { 
	print_impl(args...); 	
#ifdef LOCAL
	std::cout << std::endl; 
#else
	std::cout << '\n';
#endif
}

void solve(){
	int n;
	cin >> n;

	vector<int> res;
	res.push_back(n);

	while(__builtin_popcount(n) != 1){
		n -= n & -n;
		res.push_back(n);
	}

	while(n != 1){
		res.push_back(n >> 1);
		n >>= 1;
	}

	print(res.size());
	for(int i: res)
		cout << i << ' ';
	print("");
}

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
#ifdef LOCAL
	freopen("out.txt", "w", stdout);
#endif

	int test = 1;
	cin >> test;

	for(int itest = 1; itest <= test; ++itest){
		eprintf("------- Case %d -------\n", itest);
		solve();
		eprintf("----------------------\n");
	}
	write_output();	

	return 0;
}