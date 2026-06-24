#include<bits/stdc++.h>

using namespace std;

#define lp(i,a,b) for(int i=a;i<b;i++)

#define lpi(i,a,b) for(int i=a;i>=b;i--)

#define ll long long

#define pb push_back

#define mp make_pair

const int M = 1e5+9;

ll l,r,a,b,c;

int main(){

	cin>>l>>r;

	if(l&1)l++;

	if(l+2ll>r){cout<<-1;return 0;}

	cout<<l<<" "<<l+1<<" "<<l+2;

    return 0;

}