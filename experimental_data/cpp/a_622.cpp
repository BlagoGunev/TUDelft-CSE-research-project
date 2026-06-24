#include<bits/stdc++.h>

using namespace std;

#define gcd(n,m)       __gcd(n,m);

#define faster         ios_base::sync_with_stdio(false); cin.tie(0);

#define sfD(x)         scanf("%d",&x)

#define sfL(x)         scanf("%lld",&x)

#define line           printf("\n")

#define space          printf(" ")

#define end            return 0

#define ll             long long

#define N              5234567



int main() {

    ll  n;

    while(cin>>n) {

        ll low,high;

        ll ans;

        low=0,high=10e9;

        while(low<=high) {

            ll mid=(low+high)/2;

            if((mid*(mid+1))/2>=n) {

                high=mid-1;

                }

            else {

                low=mid+1;

                ans=mid;

                }

            }

        ans= (ans*(ans+1))/2;

        cout<<n-ans<<"\n";

        }

    end;

    }