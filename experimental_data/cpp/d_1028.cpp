#include<bits/stdc++.h>

using namespace std;

#define FOR(i, s, e) for(int i = (s); i < (e); i++)

#define FOE(i, s, e) for(int i = (s); i <= (e); i++)

#define FOD(i, s, e) for(int i = (s); i >= (e); i--)

#define ll long long

#define mp make_pair

#define pb push_back

#define pii pair<int, int>

#define pff pair<double, double>


int n, m, x, y, z, k, w;
char s[10];
int A[400005], B[400005];
ll res, mod = 1000000007ll;

vector< int > pending;
priority_queue<int> getmax;
priority_queue<int, vector<int>, greater<int> > getmin; 

void debug()
{
	printf("In pending: ");
	FOR(i, 0, pending.size()) printf("%d ", pending[i]);
	puts("");
}

int main ()
{
	scanf("%d", &n);
	FOR(i, 0, n) 
	{
		scanf("%s %d", s, &B[i]);
		if (s[1] == 'D') A[i] = 1;
		else A[i] = 2;
	}

	res = 1ll;
	FOR(i, 0, n)
	{
		if (A[i] == 1)
		{
			if (!getmin.empty() && B[i] > getmin.top()) getmin.push(B[i]);
			else if (!getmax.empty() && B[i] < getmax.top()) getmax.push(B[i]);
			else pending.pb(B[i]);
		}
		else
		{
			if (!getmin.empty() && B[i] > getmin.top()) { puts("0"); return 0; }
			if (!getmax.empty() && B[i] < getmax.top()) { puts("0"); return 0; }
			
			if (!getmin.empty() && B[i] == getmin.top()) 
			{
				getmin.pop();
				FOR(j, 0, pending.size()) getmax.push(pending[j]);
				pending.clear();
			}
			else if (!getmax.empty() && B[i] == getmax.top()) 
			{
				getmax.pop();
				FOR(j, 0, pending.size()) getmin.push(pending[j]);
				pending.clear();
			}
			else 
			{
				res *= 2ll;
				res %= mod;
				FOR(j, 0, pending.size())
				{
					//printf("pending = %d, B[i] = %d\n", pending[j], B[i]);
					if (pending[j] < B[i]) getmax.push(pending[j]);
					else if (pending[j] > B[i]) getmin.push(pending[j]);
				}
				pending.clear();
			}
		}

		//debug();
	}

	res *= (pending.size() + 1);
	res %= mod;

	printf("%lld\n", res);
	return 0;
}