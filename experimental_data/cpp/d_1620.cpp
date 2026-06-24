#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int T,n,arr[101];
int32_t main()
{
cin.tie(0),iostream::sync_with_stdio(0);
cin>>T;
while(T--){
cin>>n;
for(int i=0;i<n;i++)
cin>>arr[i];
sort(arr,arr+n);
int SPEA=0,SPEB=0;
int Z=0,O=0,T=0;
for(int i=0;i<n;i++)
if(arr[i]%3==0)Z++;
else if(arr[i]%3==1)O++;
else
T++;
if(O&&T)
SPEB=2;
else if(O)
SPEA=1;
else if(T)
SPEB=1;
int ANS=0;
//cout<<SPEA<<' '<<SPEB<<endl;
sort(arr,arr+n);
if(arr[0]==1&&SPEB==2)
SPEB--,SPEA++;
for(int i=0;i<n;i++){
if(arr[i]%3==0){
if(SPEA&&SPEB)
ANS=max(arr[i]/3-1,ANS);
else
ANS=max(arr[i]/3,ANS);
}
else if(arr[i]%3==1){
if(SPEB==2)
ANS=max(arr[i]/3-1,ANS);
else
ANS=max(arr[i]/3,ANS);
}
else if(arr[i]%3==2){
ANS=max(arr[i]/3,ANS);
}
}
int ANS2=ANS+SPEA+SPEB;
SPEA=1,SPEB=1;
ANS=0;
for(int i=0;i<n;i++){
if(arr[i]%3==0){
if(SPEA&&SPEB)
ANS=max(arr[i]/3-1,ANS);
else
ANS=max(arr[i]/3,ANS);
}
else if(arr[i]%3==1){
if(SPEB==2)
ANS=max(arr[i]/3-1,ANS);
else
ANS=max(arr[i]/3,ANS);
}
else if(arr[i]%3==2){
ANS=max(arr[i]/3,ANS);
}
}
cout<<min(ANS+SPEA+SPEB,ANS2)<<endl;
}
}