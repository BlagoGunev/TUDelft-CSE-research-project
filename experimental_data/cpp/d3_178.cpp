#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <sstream>

#define For(i,a,n) for(int i =a ; i < n ; ++i )
#define feach(i,a) for(typeof (a.begin()) i = a.begin() ; i != a.end() ; ++i)
#define all(x) (x).begin(),(x).end()
#define n(x) (int)(x).size()
#define pb(x) push_back(x)
#define fr first
#define sc second

using namespace std;
typedef pair<int,int> pii;
const int maxn = 4;
int sp;
int n;
map <int,int> mp;
int a[maxn][maxn];
int mark[maxn][maxn];
int s;
struct dastur
{
	int typ;
	pii tar;
	pii x;
	pii y;
	pii z;

	dastur(int ty=0,pii tr = pii(0,0),pii xx=pii(0,0),pii yy=pii(0,0),pii zz=pii(0,0))
	{
		typ = ty;
	        tar = tr;
       		x=xx;
 		y=yy;
		z=zz;
	}

};
vector <dastur> vec;
void output()
{
	cout << s << endl;
	For(i,0,n)
	{
		For(j,0,n)
			cout << a[i][j] << " " ;
		cout << endl;
	}
	exit(0);
}
int ttt;

void bt(int now)
{
	if(now == 3)
		if(a[0][0]!=sp && a[1][1] != sp && a[0][1] != sp)
			return;
	if(now==n(vec))
		output();
	vector <int> ve;
	if(vec[now].typ == 0)
	{
		feach(it,mp)
		{
			if(!it->sc)
				continue;
			int val = it->fr;	
			ve.pb(val);
		}
		For(i,0,n(ve))
		{
			int val = ve[i];
			mp[val]--;
			a[vec[now].tar.fr][vec[now].tar.sc] = val;
			bt(now+1);
			mp[val]++;
		}

	}
	else
	{
		if(vec[now].typ == 1)
		{
			int val = s-(a[vec[now].x.fr][vec[now].x.sc]+a[vec[now].y.fr][vec[now].y.sc]+a[vec[now].z.fr][vec[now].z.sc]);
			if(!mp[val])
			{
				mp.erase(val);
				return ;
			}
			mp[val]--;
			a[vec[now].tar.fr][vec[now].tar.sc] = val;
			bt(now+1);
			mp[val]++;
		}
		if(vec[now].typ == 2)
		{
			int val = (a[vec[now].tar.fr][vec[now].tar.sc]+a[vec[now].x.fr][vec[now].x.sc]+a[vec[now].y.fr][vec[now].y.sc]+a[vec[now].z.fr][vec[now].z.sc]);
			if(val!=s)
				return ;
			bt(now+1);
		}
	}
}

void check()
{
	a[2][0] = s-a[0][0]-a[1][0];
	if(!mp[a[2][0]])
		return;
	a[2][2] = s-a[1][1]-a[0][0];
	if(!mp[a[2][2]])
		return;
	a[0][2] = s-a[0][0]-a[0][1];
	if(!mp[a[0][2]])
		return;
	a[1][2] = s-a[1][0]-a[1][1];
	if(!mp[a[1][2]])
		return;
	a[2][1] = s-a[0][1]-a[1][1];
	if(!mp[a[2][0]])
		return;
	if(a[2][1]+a[2][0]+a[2][2]!=s)
		return;
	if(a[1][2]+a[0][2]+a[2][2]!=s)
		return;
	if(a[0][2]+a[2][0]+a[1][1]!=s)
		return;
	output();
}

void bt2(int x, int y)
{
	vector <int> ve;
	if( x == n-1)
	{
		y++;
		x=0;
	}
	if(y == n-1)
		return check();
	feach(it,mp)
	{
		if(!it->sc)
			continue;
		int val = it->fr;	
		ve.pb(val);
	}
	For(i,0,n(ve))
	{
		int val = ve[i];
		mp[val]--;
		a[x][y] = val;
		bt2(x+1,y);
		mp[val]++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	int t1;
	For(i,0,n*n)
	{
		cin >> t1;
		if(!i)
			sp=t1;
		mp[t1]++;
		s+=t1;
	}
	s/=n;
	if(n==4)
	{
		vec.pb(dastur(0,pii(0,0)));
		vec.pb(dastur(0,pii(0,1)));
		vec.pb(dastur(0,pii(1,1)));
		vec.pb(dastur(0,pii(0,2)));
		vec.pb(dastur(1,pii(0,3),pii(0,2),pii(0,1),pii(0,0)));
		vec.pb(dastur(0,pii(2,2)));
		vec.pb(dastur(1,pii(3,3),pii(2,2),pii(1,1),pii(0,0)));
		vec.pb(dastur(0,pii(1,2)));
		vec.pb(dastur(1,pii(3,2),pii(2,2),pii(1,2),pii(0,2)));
		vec.pb(dastur(0,pii(2,1)));
		vec.pb(dastur(1,pii(3,1),pii(2,1),pii(1,1),pii(0,1)));
		vec.pb(dastur(1,pii(3,0),pii(2,1),pii(1,2),pii(0,3)));
		vec.pb(dastur(2,pii(3,0),pii(3,1),pii(3,2),pii(3,3)));
		vec.pb(dastur(0,pii(1,0)));
		vec.pb(dastur(1,pii(2,0),pii(3,0),pii(1,0),pii(0,0)));
		vec.pb(dastur(1,pii(1,3),pii(1,1),pii(1,2),pii(1,0)));
		vec.pb(dastur(1,pii(2,3),pii(2,1),pii(2,2),pii(2,0)));
		vec.pb(dastur(2,pii(0,3),pii(1,3),pii(2,3),pii(3,3)));
		bt(0);
	}
	else
	{
		if(n==1)
		{
			a[0][0] = s;
			output();
		}
		if(n==2)
		{
			a[0][1] = t1;
			a[1][1] = s-t1;
			a[1][0] = t1;
			a[0][0] = s-t1;
			output();
		}
		bt2(0,0);
	}
	return 0;
}