#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

//order_of_key (k) : Number of items strictly smaller than k .

//find_by_order(k) : K-th element in a set (counting from zero).

typedef long long int ll;

ll fun(ll x)

{

	ll temp=1;

	int c=0;

	while(temp<x)

	{

		temp*=2;

		c++;

	}

	return c;

}

ll Binexp(ll a, ll b)

{

	ll res=1;

	while(b>0)

	{

		if(b%2)

		{

			res=(res*a);

		}

		a=(a*a);

		b=b/2;

	}

	return res;

}

int main()

{

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

    auto start=chrono::high_resolution_clock::now();

    default_random_engine generator;

    //uniform_int_distribution<int> distribution(l,r); 

    //int nn=distribution(generator); A random number from l to r

    //code here

    int t=1;

    cin>>t;

    while(t--)

    {

    	ll n, k;

    	cin>>n>>k;

    	int ans[n];

    	for(int i=0;i<n;i++)

    		ans[i]=-1;

    	int ttt=fun(k);

    	if(ttt>n-1)

    	{

    		cout<<-1<<endl;

    		continue;

    	}

    	int p=n-2;

    	int c=1;

    	int pos=0;

    	int tp=0;

    	while(p>=-1)

    	{

    		int temp=fun(k);

    		if(p==-1)

    		{

    			int pp=pos;

	    		while(ans[pp]==-1 && pp>=tp)

	    		{

	    			ans[pp]=c;

	    			c++;

	    			pp--;

	    		}

	    		break;

    		}

    		if(temp>p)

    		{

    			k-=(Binexp(2,p));

    			p--;

    			pos++;

    			continue;

    		}

    		int pp=pos;

    		while(ans[pp]==-1 && pp>=tp)

    		{

    			ans[pp]=c;

    			c++;

    			pp--;

    		}

    		pos++;

    		tp=pos;

    		p--;

    	}

    	int fl=1;

    	for(int i=0;i<n;i++)

    	{

    		if(ans[i]==-1)

    		{

    			fl=0;

    			break;

    		}

    	}

    	if(fl==0)

    	{

    		cout<<-1<<endl;

    		continue;

    	}

    	for(int i=0;i<n;i++)

    	{

    		cout<<ans[i]<<" ";

    	}

    	cout<<endl;

    }

    auto stop=chrono::high_resolution_clock::now();

    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);

    cerr<<duration.count()/1000.0<<" ms\n";

}