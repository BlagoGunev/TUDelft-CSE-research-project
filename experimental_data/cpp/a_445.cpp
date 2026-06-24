#include<bits/stdc++.h>

using namespace std;

int main(){

	int n,m,i,j;

	cin>>n>>m;

	char a[n][m],b[n][m];

	for(i=0;i<n;i++){

		for(j=0;j<m;j++){

			if((i+j)%2==0){

				b[i][j] = 'W';

			}else{

				b[i][j] = 'B';

			}

		}

	}

	/*for(i=0;i<n;i++){

		for(j=0;j<m;j++){

			cout<<b[i][j];

		}cout<<endl;

	}*/

	for(i=0;i<n;i++){

		for(j=0;j<m;j++){

			cin>>a[i][j];

			if(a[i][j]=='.'){

				;

			}else{

				b[i][j] = '-';

			}

		}

	}

	for(i=0;i<n;i++){

		for(j=0;j<m;j++){

			cout<<b[i][j];

		}cout<<endl;

	}

	return 0;

	

}