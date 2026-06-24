#include <bits/stdc++.h>



using namespace std;

#define ll long long 

#define sz(x) int(x.size())

#define Rashed_To_Get_Accepted ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

const int N = 200001;

const int MOD = 1e9+7 ;//998244353;

// iota(a.begin() , a.end() , x) , x here means start int



// sort(ord.begin(), ord.end(), [&cnt](int x, int y){

	// return cnt[x] > cnt[y];

// });



// stoi(str) to convert string to int  

// dp?, graph?, bs on answer?, stupid observation?

int dx[] = {1,  -1  ,0 , 0};

int dy[] = {0 , 0 , -1 , 1};

   

 

void solve()

{

	int n , k ; cin >> n >> k;

	int a[n];

	for(int i =0 ;i <n ;i++)cin>> a[i];

	

	vector<int> cnt(2*k+1);

	

	for(int i =0 ;i < n/2;i++){

		cnt[a[i]+ a[n-i-1]]++;

	}

	

	vector<int> pref(2*k+2);

	

	for(int i =0 ;i <n / 2 ;i++){

		int l1 = a[i]+1 , r1 = a[i]+k;

		int l2 = a[n - i - 1]+1 , r2 = a[n - i - 1]+k;

		assert(min(r1 , r2)>=max(l1, l2));

		++pref[min(l1 ,l2)];

		--pref[max(r1 , r2)+1];

	}

	

	for(int i =2 ; i <=2*k+1 ;i++){

		pref[i]+=pref[i-1];

	}

	

	int ans = n/2;

	for(int val = 2 ;val <=2*k ; val++){

		ans = min(ans , (pref[val] - cnt[val]) + (n / 2 - pref[val])*2);

	}

	

	cout << ans <<"\n";

}



int main(){

	

	Rashed_To_Get_Accepted

	int tc;

	tc = 1;

	cin >> tc;

	while(tc--){

		solve();

	}

	return 0;

}