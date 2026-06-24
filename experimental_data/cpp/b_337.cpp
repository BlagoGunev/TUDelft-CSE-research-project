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



/****************************************************************/



int main(){



 ll a,b,c,d,p,q,t;

 cin>>a>>b>>c>>d;

 p=b*c; q=a*d;

 if(p>q) swap(p,q);

 p=q-p;

 t=gcd(p,q);

 p/=t; q/=t;

 cout<<p<<"/"<<q<<endl;

 return 0;

}