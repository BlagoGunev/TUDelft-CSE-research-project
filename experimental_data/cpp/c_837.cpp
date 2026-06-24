#include<bits/stdc++.h>
using namespace std;
struct seal
{
	int x;
	int y;
};

bool check(int x1,int y1,int x2,int y2,int a,int b)
{
	if(y1<=b&&x1<=a)
	{
		if((x2<=b&&y2<=a-x1)||(y2<=b&&x2<=a-x1)||(x2<=b-y1&&y2<=a)||(y2<=b-y1&&x2<=a))
		return 1;
	}
	if(y1<=a&&x1<=b)
	{
		if((x2<=a&&y2<=b-x1)||(y2<=a&&x2<=b-x1)||(x2<=a-y1&&y2<=b)||(y2<=a-y1&&x2<=b))
		return 1;
	}
	return 0;
}



int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	seal  seals[n];
	int area_max=0;
	int area_curr=0;
	for(int i=0;i<n;i++)
	{
		cin>>seals[i].x>>seals[i].y;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
			    if(check(seals[i].x,seals[i].y,seals[j].x,seals[j].y,a,b))
			    {
			    	area_curr=seals[i].x*seals[i].y+seals[j].x*seals[j].y;
			    	if(area_curr>area_max)
			    	area_max=area_curr;
				}
			}
		}
	}
	cout<<area_max<<endl;
}