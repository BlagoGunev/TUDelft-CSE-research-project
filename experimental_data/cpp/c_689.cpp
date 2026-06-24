#include <bits/stdc++.h>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll a[10][10],x[11],y[11],n;





int main()

{

    ll  mx= pow(2,62);

    ll i,j,n;

    scanf("%lld",&n);

    ll left =0;

    ll right = mx;

    ll a,b,ans=-1;

    while(left<right){

        ll mid = (left+right)/2;

        //cout<<left<<" "<<mid<<" "<<right<<endl;

        ll tw=0;

        for(a=2;;a++){

            ll w=0;

            /*for(b=1;;b++){

                if(b*a*a*a>mid) break;

                if(b*a*a*a<=mid){

                    tw++;

                    w++;

                }

                if(tw>n) break;

            }*/

            w = mid/(a*a*a);

            tw+=w;

            if(!w || tw>n) break;

        }

        //cout<<tw<<endl;

        if(tw>=n){

            right = mid;

        }

        else left = mid+1;

        if(tw == n) ans=mid;

    }

    printf("%lld\n",ans);

    return 0;

}