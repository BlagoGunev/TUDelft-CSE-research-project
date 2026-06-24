//Author: Saikat_deb [2022-07-31 10:05]	

#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>



//C:\msys64\mingw64\include\c++\11.2.0\ext\pb_ds\detail\resize_policy

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace std:: chrono;

using namespace __gnu_pbds;



typedef long long LL;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef vector<LL> vl;



//less, greater or less_equal

//fn: find_by_order(index), order_of_key(element)-> all the elements that are less than element , lower and upper_bound, erase

template <typename T> using Oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



#ifndef ONLINE_JUDGE

#define START auto start=high_resolution_clock :: now();

#define END auto stop=high_resolution_clock :: now();auto duration=duration_cast<microseconds> (stop-start);

#define __print() cerr<<"Time: "<<duration.count()<<"ms\n";

#else

#define START

#define END

#define __print()

#endif



/*dubug code, from: https://github.com/BidhanRoy/Algorithm-Code-Library/blob/master/Templates/Debug%20Extensions.cpp*/

template < typename F, typename S >

ostream& operator << ( ostream& os, const pair< F, S > & p ) {

    return os << "(" << p.first << ", " << p.second << ")";

}



template < typename T >

ostream &operator << ( ostream & os, const vector< T > &v ) {

    os << "{";

    typename vector< T > :: const_iterator it;

    for( it = v.begin(); it != v.end(); it++ ) {

        if( it != v.begin() ) os << ", ";

        os << *it;

    }

    return os << "}";

}



template < typename T >

ostream &operator << ( ostream & os, const set< T > &v ) {

    os << "[";

    typename set< T > :: const_iterator it;

    for ( it = v.begin(); it != v.end(); it++ ) {

        if( it != v.begin() ) os << ", ";

        os << *it;

    }

    return os << "]";

}



template < typename F, typename S >

ostream &operator << ( ostream & os, const map< F, S > &v ) {

    os << "[";

    typename map< F , S >::const_iterator it;

    for( it = v.begin(); it != v.end(); it++ ) {

        if( it != v.begin() ) os << ", ";

        os << it -> first << " = " << it -> second ;

    }

    return os << "]";

}



#define dbg(x) cerr << #x << " = " << x << endl;



#define itr(i, n) for(int i=0; i<(int)n; i++)

#define itr_n(i, n) for(int i=1; i<=n; i++)

#define RESET(a, b) memset(a, b, sizeof(a))

//#define PERMUTE next_permutation

#define inf_p INT_MAX

#define inf_n INT_MIN

#define inf_pll LONG_LONG_MAX

#define inf_nll LONG_LONG_MIN

#define read(a) for(auto &i: a) cin>>i;

#define write(a) for(auto &i: a) cout<<i<<" "; cout<<"\n";

#define write_pair(a) for(auto T: a) cout<<T.first<<" "<<T.second<<"\n";

#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

#define MOD 1000000007

#define MOD1 998244353

#define PI 3.141592653589793238462



LL inverse(LL i){

    if(i==1) return 1;

    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;

}



LL power(LL a,LL b)

{

    if(b==0) return 1;

    if(b==1) return a%MOD;

    LL temp=power(a,b/2);

    if(b%2==0) return (temp*temp)%MOD;

    else return (((temp*temp)%MOD)*a)%MOD;

}



bool isPrime(int n) {

    if (n <= 1) return false;

    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i = i + 6)

        if (n % i == 0 || n % (i + 2) == 0)

            return false;

    return true;

}



void init_code(){

	IOS()

	#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt","w", stdout);

	#endif

}



/*



*/



void solve(){

	int n; cin>>n;

	string s; cin>>s;

	if(s[0]!='1' || s[n-1]!='1'){

		cout<<"NO\n";

		return;

	}

	//i know it will not work:



	string a, b;

	a.push_back('(');

	b.push_back('(');

	int flip=1;

	for(int i=1; i<n-1; i++){

		if(s[i]=='1'){

			if(flip){

				a.push_back('(');

				b.push_back('(');

			}

			else{

				a.push_back(')');

				b.push_back(')');

				// a[i]='(', b[i]='(';

			}

			flip^=1;

		}

		else{

			a.push_back('0');

			b.push_back('0');

		}

	}



	a.push_back(')');

	b.push_back(')');



	// cout<<a<<" "<<b<<"\n";



	flip=1;

	itr(i, n){

		if(a[i]=='0'){

			if(flip){

				a[i]=')';

				b[i]='(';

			}

			else{

				a[i]='(';

				b[i]=')';

			}

			flip^=1;

		}

	}



	int sum1=0, sum2=0;

	itr(i, n){

		if(a[i]=='(') sum1++;

		if(b[i]=='(') sum2++;

		if(a[i]==')') sum1--;

		if(b[i]==')') sum2--;

	}



// 	dbg(sum1<<" "<<sum2)

	if(sum1!=0 || sum2!=0)

		cout<<"NO\n";

	else{

		cout<<"YES\n";

		cout<<a<<"\n"<<b<<"\n";

	}



}



int main()

{

	//init_code();

	IOS();

	#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("error.txt", "w", stderr);

	#endif

	cout<<fixed<<setprecision(15);

	int test=1;

	cin>>test;

	//START

	itr(each, test)

	{

		solve();

	}



	//END

	//__print();

	return 0;

}