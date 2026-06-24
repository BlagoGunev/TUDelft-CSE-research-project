#include "bits/stdc++.h"
using namespace std;

int main()
{
	int x;
	cin>>x;
	int w;
	w=x%4;
	
	if(w==0)
	{
	    
	    cout<<"1"<<" "<<"A"<<endl;
	}
	else if(w==1)
	{
	    
	    cout<<"0"<<" "<<"A"<<endl;
	}
	else if(w==2)
	{
	    
	    cout<<"1"<<" "<<"B"<<endl;
	}
	else if(w==3)
	{
	    
	    cout<<"2"<<" "<<"A"<<endl;
	}
}