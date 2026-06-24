#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

#define inf 1023456789
#define linf 1023456789123456789ll
#define pii pair<int,int>
#define pipii pair<int, pii >
#define pll pair<long long,long long>
#define vint vector<int>
#define vvint vector<vint >
#define ll long long
#define pdd pair<double, double>
#define plpii pair<ll, pii >

#define DEBUG
#ifdef DEBUG
#define db(x) cerr << #x << " = " << x << endl
#else
#define db(x)
#endif

int dX[2] = {1,-1};

int main()
{
	int n;
	scanf("%d",&n);
	vector<ll> x(n+2), d(n+2);
	for(int i=0; i<n+2; i++)
	{
		int a;
		scanf("%d",&a);
		x[i] = a*2;
	}
	d[0] = linf;
	d[n+1] = linf;
	for(int i=1; i<=n; i++)
	{
		int a;
		scanf("%d",&a);
		d[i] = a*2;
	}
	vector<ll> sup_left(n+2, linf), sup_right(n+2, -linf);
	for(int smer = 0; smer < 2; smer++)
	{
		vector<int> sus_l(n+2), sus_r(n+2);
		vector<int> exists(n+2, 1);
		for(int i=0; i<n+2; i++)
		{
			sus_l[i] = i-1;
			sus_r[i] = i+1;
		}
		priority_queue<pll > to_fall;
		for(int i=1; i<=n; i++)
		{
			if((x[sus_r[i]] - x[sus_l[i]])/2 > d[i])to_fall.push(pll(-dX[smer] * x[i],i));
		}
		while(!to_fall.empty())
		{
			pll tp = to_fall.top();
			to_fall.pop();
			int cur = tp.second;
			if(!exists[cur])continue;
			exists[cur] = 0;
			if(smer == 0)
			{
				sup_right[cur] = x[sus_l[cur]] + 2*d[cur];
			}
			else
			{
				sup_left[cur] = x[sus_r[cur]] - 2*d[cur];
			}
			sus_l[sus_r[cur]] = sus_l[cur];
			sus_r[sus_l[cur]] = sus_r[cur];
			vint tc(2);
			tc[0] = sus_l[cur];
			tc[1] = sus_r[cur];
			for(int i=0; i<2; i++)
			{
				if(tc[i] > 0 && tc[i] <= n)
				{
					if((x[sus_r[tc[i]]] - x[sus_l[tc[i]]])/2 > d[tc[i]])
					{
						to_fall.push(pll(-dX[smer] * x[tc[i]], tc[i]));
					}
				}
			}
		}
		if(sus_r[0] != n+1)
		{
			printf("0\n");
			return 0;
		}
	}
	sup_left[0] = linf;
	sup_left[n+1] = -linf;
	sup_right[0] = linf;
	sup_right[n+1] = -linf;
	
	vector<plpii > event;
	
	vector<int> stack;
	stack.push_back(0);
	
	vector<pll > skoncil;
	ll sur = x[0];
	for(int i=1; i<=n+1; i++)
	{
		while(sup_right[stack.back()] <= x[i])
		{
			if(sup_right[stack.back()] > sur)
			{
				sur = sup_right[stack.back()];
				skoncil.push_back(pll(sur, stack.back()));
			}
			stack.pop_back();
		}
		if(sup_right[i] > x[i])
		{
			sur = x[i]+1;
			skoncil.push_back(pll(sur, stack.back()));
			stack.push_back(i);
		}
	}
	event.push_back(plpii(0,pii(1,0)));
	for(int i=1; i<skoncil.size(); i++)
	{
		event.push_back(plpii(skoncil[i-1].first, pii(1,skoncil[i].second)));
	}
	if(skoncil.size() > 0)event.push_back(plpii(skoncil.back().first, pii(1, stack.back())));
	stack = vint(1, n+1);
	sur = x[n+1];
	for(int i=n; i>=0; i--)
	{
		while(sup_left[stack.back()] >= x[i])
		{
			if(sup_left[stack.back()] < sur)
			{
				sur = sup_left[stack.back()];
				event.push_back(plpii(sur, pii(0, stack.back())));
			}
			stack.pop_back();
		}
		if(sup_left[i] < x[i])
		{
			sur = x[i]-1;
			event.push_back(plpii(sur, pii(0, stack.back())));
			stack.push_back(i);
		}
	}
	event.push_back(plpii(0, pii(0, stack.back())));
	
	sort(event.begin(), event.end());
	
	ll res = linf;
	int left_best = 0, right_best = n+1;
	for(int i=0; i<event.size(); i++)
	{
		if(event[i].second.first == 0)
		{
			right_best = event[i].second.second;
			res = min(res, (x[right_best] - x[left_best])/2);
		}
		else
		{
			left_best = event[i].second.second;
			res = min(res, (x[right_best] - x[left_best])/2);
		}
	}
	printf("%.2f\n", (double)(res)/2.0);
	return 0;
}