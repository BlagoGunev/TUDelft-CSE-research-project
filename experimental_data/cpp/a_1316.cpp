#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endo '\n'

#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

/*int isprime(int N){

    if(N<2 || (!(N&1) && N!=2))

        return 0;

    for(int i=3; i*i<=N; i+=2){

        if(!(N%i))

            return 0;

    }

    return 1;

}*/

int main(){

fast

int t;cin>>t;

while(t--)

{

ll n,m;cin>>n>>m;

ll sum=0;

vector<int>v(n);

for(auto &i:v){

        cin>>i;

        sum+=i;

}cout<<min(m,sum)<<endo;



}

return 0;

}