#include  <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int used[11][11];
int str[11]={0};
int st[11]={0};
int main () {
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);
	int r ,c;	
	int s=0;
	char a[11][11];
	cin>>r>>c;
	for (int i=0;i<11;i++) {
		for (int j=0;j<11;j++) {
			used[i][j]=0;
		}
	}
	for (int i=0;i<r;i++) {
		for (int j=0;j<c;j++) {
			cin>>a[i][j];
			if (a[i][j]=='S') {
				str[i]=1;
				st[j]=1;
			}
		}
	}
	int ans=0;
	for (int i=0;i<r;i++) {
		for (int j=0;j<c;j++) {
			if (str[i]==1) {
				break;
			}
			if (used[i][j]==0) {
				ans++;
				used[i][j]=1;
			}	
		}
	}
	for (int i=0;i<c;i++) {
		for (int j=0;j<r;j++) {
			if (st[i]==1) {
				break;
			}
			if (used[j][i]==0) {
				ans++;				
				used[j][i]=1;
			}
		}
	}
	cout<<ans;





	return 0;
}