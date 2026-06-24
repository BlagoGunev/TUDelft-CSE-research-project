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

string s;

int n,k;

//发现一个问题中间那一段是可以不回文得，只要边缘能形成k对字符并且两个指针还没碰到一起即可

void slove(){

	cin>>n>>k;

	cin>>s;

	if(k==0){

		cout<<"YES"<<endl;

		return;

	}

	int cnt=0;

	for(int i=0;i<(n+1)/2-1;i++){//中间字符不可为空

		if(s[i]==s[n-i-1]){

			cnt++;

		}

		else{

			break;

		}

	}

	if(cnt>=k){

		cout<<"YES"<<endl;

	}

	else{

		cout<<"NO"<<endl;

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