/***************************************************************

*    __    _____________      _______  _    ______             *

*     |\  /||    | |     |    | |   |  |    | |   |            *

*     | \/ ||____| |---| |____| |---|  |    | |---| -          *

*     |    ||    |     | |    | |   \  |____| |   \ |          *

*    --    --    --|------    ---   ----------------|          *

*                                                              *

*                Name: Mashrur Rashik                          *

*              Inst: University of Dhaka                       *

*                Country : Bangladesh                          *

***************************************************************/



#include<bits/stdc++.h>

using namespace std;

#define MAX 300300

#define clr(ar) memset(ar, 0, sizeof(ar))

#define fr(i,n); for(i=0;i<n;i++)

#define v_in(i,n,temp,a) for(i=1;i<=n;i++){cin>>temp;a.push_back(temp);}

#define v_out(i,a) for(i=0;i<a.size();i++){cout<<a[i]<<" ";}

#define sc(a) cin>>a

#define pr(a) cout<<a<<endl

typedef long long ll;

typedef unsigned long long ull;

#define inf (ll) 9e18

#define eps 1e-9

#define pii pair <ll,ll>

#define gcd(a,b) __gcd(a,b)

vector<ll>res;



/****************************************************************/



void lol(){

    vector<ll>a;

    ll i,j;



    for(i=2;i<=10;i+=2){

        a.push_back(4);

        a.push_back(7);

        sort(a.begin(),a.end());



        do{

          ll sum=0,t=1;

          for(j=a.size()-1;j>=0;j--){

            sum+=a[j]*t;

            t*=10;

           }

          res.push_back(sum);

          }while(std::next_permutation(a.begin(),a.end()) );



    }

}



int main(){

 lol();

 ll n,i;

 cin>>n;



    for(i=0;i<res.size();i++){

        if(res[i]>=n){

            cout<<res[i]<<endl;

            return 0;

        }

    }



}