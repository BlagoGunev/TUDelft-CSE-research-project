#include<bits/stdc++.h>

using namespace std;

const int N = 111;
int n;
string s[N];
set<int> v[5];
int rev[300];
int ex[7][7];

int on(int msk,int i) { return (msk>>i) & 1; }

int main(){
	rev['R'] = 0,rev['G'] = 1,rev['B'] = 2,rev['Y'] = 3,rev['W'] = 4;
	cin>>n;
	for(int i = 0; i < n ; i++){
		cin>>s[i];
		v[rev[s[i][0]]].insert(s[i][1]-'1');
		ex[rev[s[i][0]]][s[i][1]-'1'] = 1;
	}

	int ans = 100;

	for(int msk = 0; msk < 1024; msk++){
		int vague = 0;
//		cout<<msk<<endl;
		for(int i = 0; i < 5; i ++){
//			cout<<" "<<i<<"\n";
			for(int x : v[i]){
//				cout<<"  "<<x<<":\n";
				if(on(msk,i) && on(msk,5+x)) continue;
				int sc = 0, sn = 0;
				if(on(msk,i)) {
					sn = 1;
					for(int k = 0; k <5 ; k++)
						if(k!= x && ex[i][k] && !on(msk,5+k)) sn = 0;
				}
				if(on(msk,5+x)){
					sc = 1;
					for(int k = 0; k<5; k++)
						if(k!=i && ex[k][x] && !on(msk,k)) sc =  0;
				}
				if(sc || sn) continue;
				vague ++;
			}
		}
		if(vague > 1) continue;
		ans = min(ans,__builtin_popcount(msk));
//		cout<<vague<<endl;
//		cin>>vague;
	}

	cout<<ans<<endl;

	return 0;
}