#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define int long long int
#define mod 1000000007

struct pt {
	int x1,x2,y1,y2;
};

int32_t main()
{
	fastIO;
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	
	int n,i;
	pt a,b,c;
	cin>>a.x1>>a.y1>>a.x2>>a.y2;
	cin>>b.x1>>b.y1>>b.x2>>b.y2;
	cin>>c.x1>>c.y1>>c.x2>>c.y2;
	if(a.x1>=b.x1 && a.x2<=b.x2 && a.y1>=b.y1 && a.y2<=b.y2)
		return cout<<"NO",0;
	if(a.x1>=c.x1 && a.x2<=c.x2 && a.y1>=c.y1 && a.y2<=c.y2)
		return cout<<"NO",0;
	if(a.x1>=b.x1 && a.x2<=b.x2 && a.y2<=b.y2 && a.x1>=c.x1 && a.x2<=c.x2 && a.y1>=c.y1 && b.y1<=c.y2)
		return cout<<"NO",0;
	if(a.x1>=c.x1 && a.x2<=c.x2 && a.y2<=c.y2 && a.x1>=b.x1 && a.x2<=b.x2 && a.y1>=b.y1 && c.y1<=b.y2)
		return cout<<"NO",0;
	if(a.x1>=b.x1 && a.y1>=b.y1 && a.y2<=b.y2 && a.x2<=c.x2 && a.y1>=c.y1 && a.y2<=c.y2 && b.x2>=c.x1)
		return cout<<"NO",0;
	if(a.x1>=c.x1 && a.y1>=c.y1 && a.y2<=c.y2 && a.x2<=b.x2 && a.y1>=b.y1 && a.y2<=b.y2 && c.x2>=b.x1)
		return cout<<"NO",0;
	cout<<"YES";
	return 0;
}