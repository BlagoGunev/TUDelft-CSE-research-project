// Author:  liqing

// Created: Sat Jul  2 21:11:46 2022

#include<bits/stdc++.h>



using namespace std;

const int N=5;

struct node

{

	int x,y;

}a[N];

bool cmp(node X,node Y){return X.y<Y.y;}

double getdis(int i,int j)

{

	return 1.0*sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));

}



int main()

{

    //freopen("a.in","r",stdin);

    //freopen("a.out","w",stdout);

    cin.tie(nullptr)->sync_with_stdio(false);

    int T;cin>>T;

	while(T--)

	{

		int n,m;cin>>n>>m;

		if(n>m)swap(n,m);

		if(n==1)

		{

			if(m==1)cout<<0<<endl;

			else if(m==2)cout<<1<<endl;

			else cout<<-1<<endl;

		}

		else cout<<(n-1)*2+(m-n)/2*4+(m-n)%2<<endl;

	}

    return 0;

}