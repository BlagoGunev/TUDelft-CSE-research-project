#include<bits/stdc++.h>

using namespace std;

const int nmax=1e3+42;

int t[nmax],n;

int main()

{

cin>>n;

for(int i=0;i<n;i++)cin>>t[i];

sort(t,t+n);

if(t[0]==1)cout<<-1<<endl;

else cout<<1<<endl;

return 0;

}