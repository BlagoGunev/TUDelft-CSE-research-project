#include<iostream>

#include<algorithm>



using namespace std;



int main(){



    long long n,i,a[105],t,cnt=0,ans=0,j;

    cin >> n;

    for(i=1;i<=n;i++) {

        cin >> a[i];

    }

    cin >> t;

    for(i=1;i<=n;i++) {

        for(j=1;j<=n;j++) {

            if(a[j] < a[i]) {

              //  if(a[i] - a[j] <= t) cnt++;

            }

            else {

                if(a[j] - a[i] <= t) cnt++;

            }

        }

        ans = max(ans,cnt); cnt = 0;

    }

    cout << ans << "\n";

    return 0;

















}