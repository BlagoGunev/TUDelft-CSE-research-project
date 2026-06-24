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

//发先每一个数如果加上一个数那我的一只能向更高位进，所以后缀1的个数x肯定是大于y的，

int x,y;

void slove(){

	cin>>x>>y;

	if(x>y){

		cout<<"NO"<<endl;

		return;

	}

	int cntx=0,cnty=0;

	for(int i=0;i<30;i++){

		if((x>>i)&1) cntx++;

		if((y>>i)&1) cnty++;

		if(cntx<cnty){

			cout<<"NO"<<endl;

			return;

		}

	}

	cout<<"YES"<<endl;

	

}

signed main(){

	IOS

	int t;

	cin>>t;

	while(t--){

		slove();

	}

	return 0;

}