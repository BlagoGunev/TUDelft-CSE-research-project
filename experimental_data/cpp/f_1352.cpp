#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

typedef pair<int,int>PII;





void solve(){



	//11 :1

	//111:2

	//1111:3

	//11111:4



	//000101

	int a,b,c;

	cin>>a>>b>>c;

	if(!a&&!b){

		cout<<string(c+1,'1')<<endl;

	}else if(!a&&!c){

		//10

		//101

		//1010

		for(int i=1;i<=b+1;i++){

			if(i&1)cout<<'1';

			else cout<<'0';

		}

		cout<<endl;

	}else if(!b&&!c){

		cout<<string(a+1,'0')<<endl;

	}else if(!a){

		string s=string(c+1,'1');

		for(int i=2;i<=b+1;i++){

			if(i&1)s+='1';

			else s+='0';

		}

		cout<<s<<endl;

	}else if(!c){

		string s=string(a+1,'0');

		for(int i=1;i<=b;i++){

			if(i&1)s+='1';

			else s+='0';

		}

		cout<<s<<endl;

	}else{

		//三个都有

		string s=string(a+1,'0')+string(c+1,'1');

		b--;

		for(int i=2;i<=b+1;i++){

			if(i&1)s+='1';

			else s+='0';

		}

		cout<<s<<endl;

	}

} 





int main()

{

    

    

    int T;

    //T=1;

    scanf("%d",&T);

    while(T--){

        solve();

    }

    

    return 0;

}