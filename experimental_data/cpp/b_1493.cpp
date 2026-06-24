#include<bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define fel(i,x,y) for(int i=x;i<=y;i++)

#define fhl(i,x,y) for(int i=x;i>=y;i--)

#define inf 0x3fffffff

#define ll long long

#define pb push_back

#define endl "\n"

#define int long long

//发现只有0,1，2，5，8可以投影//其他数字投过去是看不清得

int t[10]={0,1,5,-1,-1,2,-1,-1,8,-1};

int h,m;

int nh,nm;

char x;

void slove()

{	

	cin>>h>>m;

	cin>>nh>>x>>nm;

	while(1){

		if(nm>=m){

			nm=0;

			nh++;

			if(nh>=h) nh=0;

		}

		if(t[nm%10]<0||t[nm/10]<0||t[nh%10]<0||t[nh/10]<0){

			nm++;

			continue;

		}

		int mh=t[nm%10]*10+t[nm/10];

		int mm=t[nh%10]*10+t[nh/10];

		if(mh<h&&mm<m){

			if(nh<10){

				cout<<0<<nh<<":";

			}

			else cout<<nh<<":";

			if(nm<10){

				cout<<0<<nm<<endl;

			}

			else{

				cout<<nm<<endl;

			}

			break;

		}

		nm++;

	}	

}

signed main()

{

	IOS

    int t;

    cin>>t;

    while(t--) {

        slove();

    }

    return 0;

}