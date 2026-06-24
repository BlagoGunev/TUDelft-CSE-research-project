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

	int n ; cin >> n;

	vector<int> bits(20 , 0);

	for(int i =0 ;i <n ;i++){

		int x; cin>>x;

		for(int id =0 ;id <20 ;id++){

			if(x&(1 << id))bits[id]++;

		}

	}

	

	set<pair<int , int > > st;

	

	for(int i =0 ;i < 20 ;i++){

		if(bits[i])

		st.insert(make_pair(bits[i] , i));

	}

	

	ll ans =0;

	while(st.empty() ==false){

		int mn = INT_MAX;

		ll cnt = 0;

		for(auto it : st){

			mn = min(mn ,it.first);

			cnt|=(1 << it.second);

		}

		set<pair<int , int > >stCopy = st;

		st.clear();

		for(auto it:stCopy){

			it.first-=mn;

			if(it.first)st.insert(it);

		}

		ans +=(cnt *cnt)*mn;

	}

	cout << ans <<"\n";

}



int main(){

	

	Rashed_To_Get_Accepted

	int tc;

	tc = 1;

	// cin >> tc;

	while(tc--){

		solve();

	}

	return 0;

}