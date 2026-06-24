# include <bits/stdc++.h>

# define rep(i,n) for(int i=0;i<n;i++)
# define repv(i,n) for(auto i : n)
# define eb emplace_back
# define all(v) v.begin(),v.end()

using namespace std;

int main() 
{
	int n,k,temp;
	cin >> n >> k;
	vector <int> v(k,0);

	rep(i,n)
	{
		cin >> temp;
		v[temp-1] += 1;
	}
	
	int num = ceil((float)n/2);
	
	rep(i,num)
	{
		// cout << "i: " << i << endl;
		// repv(i,v) 
		// {
		// 	cout << i << " ";
		// }
		// cout << endl;
		sort(all(v));
		v[k-1] -= 2;
		if(v[k-1] < 0)
		{
			v[k-1] = 0;
		}
		// repv(i,v) 
		// {
		// 	cout << i << " ";
		// }
		// cout << endl;
	}
	
	// repv(i,v) 
	// {
	// 	cout << i << " ";
	// }
	// cout << endl;
	cout << (n- accumulate(all(v), 0)) << endl;
	return 0;
}