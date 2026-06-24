#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

#define pll pair<long long, long long>

const long long N1 = 1e9 + 7, N2 = 998244353;

void solve(){

	long long x,y;

	cin>>x>>y;

	if(x==y){

		cout<<"YES";

		return;

	}

	vector<int>vx,vy;

	while(x>0){

		vx.push_back(x&1);

		x>>=1;

	}

	while(y>0){

		vy.push_back(y&1);

		y>>=1;

	}

	reverse(vx.begin(),vx.end()),reverse(vy.begin(),vy.end());

	int xs=(int)vx.size(),ys=(int)vy.size();

	bool pass=false;

	for(int i=0;i<=ys-xs;i++){

		bool b=true;

		if(i==ys-xs&&vx[xs-1]==0)break;

		for(int j=0;j<xs;j++){

			if(vx[j]!=vy[i+j]){

				b=false;

				break;

			}

		}

		if(b){

			for(int index=i-1;index>=0;index--){

				if(vy[index]==0){

					b=false;

					break;

				}

			}

			for(int index=i+xs;index<ys;index++){

				if(vy[index]==0){

					b=false;

					break;

				}

			}

			if(b){

				pass=true;

				break;

			}

		}

	}

	if(pass){

		cout<<"YES";

		return;

	}

	reverse(vx.begin(),vx.end());

	for(int i=0;i<=ys-xs;i++){

		bool b=true;

		if(i==ys-xs&&vx[xs-1]==0)break;

		for(int j=0;j<xs;j++){

			if(vx[j]!=vy[i+j]){

				b=false;

				break;

			}

		}

		if(b){

			for(int index=i-1;index>=0;index--){

				if(vy[index]==0){

					b=false;

					break;

				}

			}

			for(int index=i+xs;index<ys;index++){

				if(vy[index]==0){

					b=false;

					break;

				}

			}

			if(b){

				pass=true;

				break;

			}

		}

	}

	if(pass){

		cout<<"YES";

		return;

	}

	reverse(vx.begin(),vx.end());

	int index=xs-1;

	for(;index>=0;index--){

		if(vx[index]==1)break;

	}

	vx.resize(index+1);

	xs=(int)vx.size();

	for(int i=0;i<=ys-xs;i++){

		bool b=true;

		for(int j=0;j<xs;j++){

			if(vx[j]!=vy[i+j]){

				b=false;

				break;

			}

		}

		if(b){

			for(int index=i-1;index>=0;index--){

				if(vy[index]==0){

					b=false;

					break;

				}

			}

			for(int index=i+xs;index<ys;index++){

				if(vy[index]==0){

					b=false;

					break;

				}

			}

			if(b){

				pass=true;

				break;

			}

		}

	}

	if(pass){

		cout<<"YES";

		return;

	}

	reverse(vx.begin(),vx.end());

	for(int i=0;i<=ys-xs;i++){

		bool b=true;

		for(int j=0;j<xs;j++){

			if(vx[j]!=vy[i+j]){

				b=false;

				break;

			}

		}

		if(b){

			for(int index=i-1;index>=0;index--){

				if(vy[index]==0){

					b=false;

					break;

				}

			}

			for(int index=i+xs;index<ys;index++){

				if(vy[index]==0){

					b=false;

					break;

				}

			}

			if(b){

				pass=true;

				break;

			}

		}

	}

	if(pass)cout<<"YES";

	else cout<<"NO";

}

int main(){

	ios::sync_with_stdio(false);

	cin.tie(0), cout.tie(0);

	solve();

	return 0;

}