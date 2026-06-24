#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	int n,m;
	int map[60][60];
	int countr[60][2];
	int countc[60][2];
	memset(countr,0,sizeof(countr));
	memset(countc,0,sizeof(countc));
	cin>>n>>m;
	long long ans = 0;
	long double flagsum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==0){
				countr[i][0]++;
			}
			if(map[i][j]==1){
				countr[i][1]++;
			}
		}
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(map[i][j]==0){
				countc[j][0]++;
			}
			if(map[i][j]==1){
				countc[j][1]++;
			}
		}
	}
	for(int i=0;i<n;i++){
//		cout<<"ceshi"<<countr[i][0]<<' '<<countr[i][1]<<endl;
		flagsum = pow(2,countr[i][0]);
		ans += flagsum; 
//		cout<<flagsum<<' '<<ans<<endl;
		flagsum = pow(2,countr[i][1]);
		ans += flagsum; 
//		ans -= (countr[i][0]+countr[i][1]);
	}
	
	for(int j=0;j<m;j++){
//		cout<<"ceshi"<<countc[j][0]<<' '<<countc[j][1]<<endl;
		flagsum = pow(2,countc[j][0]);
		ans += flagsum; 
		flagsum = pow(2,countc[j][1]);
		ans += flagsum; 
//		ans -= (countr[j][0]+countr[j][1]);
	}
	
	cout<<ans-2*n-2*m-n*m<<endl;
	return 0;
}