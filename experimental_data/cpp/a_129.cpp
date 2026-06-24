#include <bits/stdc++.h>

using namespace std;

int main ()

{

int n,sum=0,count=0;

cin>>n;

int seq[n];

for(int i=0;i<n;i++){cin>>seq[i];sum+=seq[i];}

for(int i=0;i<n;i++)

{

if ((sum-seq[i])%2==0)

    count++;

}

cout<<count<<endl;

return 0;

}