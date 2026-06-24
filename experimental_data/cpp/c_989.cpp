#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=100001;

ll cel[51][51];

bool vacio(ll a, ll b, ll c, ll d){
	if(b==0 && c==0 && d==1){
		return true;
	}else if(b==0 && c==1 && d==0){
		return true;
	}else if(b==1 && c==0 && d==0){
		return true;
	}
	return false;
}

int main(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll fil1=0;
	ll fil2;
	while(!vacio(a,b,c,d)){
		if(fil1%2==0){
			ll toca=0;
			for(ll i=0; i<50; i++){
				if(toca==0){
					cel[fil1][i]=toca;
				}else if(toca==1){
					if(vacio(a,b,c,d)){
						cel[fil1][i]=0;
					}else{
						if(b==0){
							cel[fil1][i]=cel[fil1][i-1];
						}else{
							cel[fil1][i]=toca;
							b--;
						}
					}
				}else if(toca==2){
					if(vacio(a,b,c,d)){
						cel[fil1][i]=0;
					}else{
						if(c==0){
							if((b==0 && d==1) || (b==1 && d==0)){
								cel[fil1][i]=0;
							}else{
								cel[fil1][i]=cel[fil1][i-1];
							}
						}else{
							cel[fil1][i]=toca;
							c--;
						}
					}
				}else if(toca==3){
					if(vacio(a,b,c,d)){
						cel[fil1][i]=0;
					}else{
						if(d==0){
							if((b==0 && c==1) || (b==1 && c==0)){
								cel[fil1][i]=0;
							}else{
								cel[fil1][i]=cel[fil1][i-1];
							}
						}else{
							cel[fil1][i]=toca;
							d--;
						}
					}
				}
				toca=(toca+1)%4;
			}
		}else{
			for(ll i=0; i<50; i++){
				cel[fil1][i]=0;
			}
		}
		fil1++;
	}
	for(ll i=0; i<50; i++){
		cel[fil1][i]=0;
	}
	fil1++;
	fil2=fil1;
	ll val;
	if(b==1){
		val=1;
	}else if(c==1){
		val=2;
	}else if(d==1){
		val=3;
	}
	for(ll i=0; i<50; i++){
		cel[fil2][i]=val;
	}
	fil2++;
	ll ini=fil2;
	a--;
	while(a>0){
		if((fil2-ini)%2==0){
			for(ll i=0; i<50; i++){
				if(i%2==0){
					cel[fil2][i]=val;
				}else{
					if(a==0){
						cel[fil2][i]=cel[fil2][i-1];
					}else{
						cel[fil2][i]=0;
						a--;
					}
				}
			}
		}else{
			for(ll i=0; i<50; i++){
				cel[fil2][i]=val;
			}
		}
		fil2++;
	}
	cout<<fil2<<" "<<50<<endl;
	for(ll i=0; i<fil2; i++){
		for(ll j=0; j<50; j++){
			cout<<char(cel[i][j]+'A');
		}
		cout<<endl;
	}
	return 0;
}