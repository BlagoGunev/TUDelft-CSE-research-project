#include<bits/stdc++.h>

#include<algorithm>

typedef long long ll;

using namespace std;

typedef string str;

#define X first

#define Y second

#define selim_on_the_code() (ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL));



int main()

{

    selim_on_the_code();

    int n;  cin>>n;

    while(n--)

    {

        int t;  cin>>t;

        if(t%2==1)cout<<__gcd(((t-1)/2),(t-1))<<'\n';

        else cout<<__gcd(t/2,t)<<'\n';

    }

}