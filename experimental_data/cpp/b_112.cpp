#include<iostream>
using namespace std;
int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout); 
	int n,x,y;
	bool z=true;
	cin>>n>>x>>y;
	n=n/2;
	if(x==n||x==n+1)
		if(y==n||y==n+1)z=false;
	if(z)cout<<"YES";
	else cout<<"NO";
}