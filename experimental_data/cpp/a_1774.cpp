#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define rep(i,j,k) for(int i=j;i<=k;i++)

#define per(i,j,k) for(int i=j;i>=k;i--)

#define fast() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ms(a,sum) memset(a,sum,sizeof a); // sum ==0或-1

#define cte continue 

#define please return 

#define ac 0;

void solve(){

	char a[110];

	char ans[110];

	int n, sum = 0;

	cin >> n;

	rep(i,1,n) cin >> a[i];

	sum += a[1] - '0';

	ans[1] = '+';

	rep(i,2,n){

		if(a[i] - '0'==0) {

			ans[i] = '+';

			cte;

		}else{

			if(sum>0){

				sum-=a[i]-'0';

				ans[i] = '-';

			}else{

				sum+=a[i]-'0';

				ans[i] = '+';

			}

		}

	}

	rep(i,2,n) cout << ans[i];

	cout << "\n";

	

}

signed main () {

	ios::sync_with_stdio(false);

	cin.tie(0);cout.tie(0);

	

	int _ = 1;

	cin >> _;

	while(_--){ 

		solve();

	}

	please ac

}

/*

In every life we have some trouble． When you worry you make it double．

Don't worry，be happy．

                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.

             __.'              ~.   .~              `.__

           .'//                  \./                  \`.

         .'//                     |                     \`.

       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.

     .'//.-"                 `-.  |  .-'                 "-.\`.

   .'//______.============-..   \ | /   ..-============.______\`.

 .'______________________________\|/______________________________`.

*/