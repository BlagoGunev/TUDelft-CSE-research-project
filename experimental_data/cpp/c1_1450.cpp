#include <bits/stdc++.h>
using namespace std;
#define l1 long long int
#define mod 1000000007
#define pb push_back
#define vi vector<int>

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//ios_base& scientific (ios_base& str);
int t=1;
cin>>t;
while(t--){
int n;cin>>n;
int a[3]={};
char xy[n][n];
for(int i = 0 ;i<n;i++){
    for(int j = 0 ; j<n;j++)
{
    cin>>xy[i][j];
    if(xy[i][j]=='X')a[(i+j)%3]++;
}
}
int id = 0;
if(a[id] > a[1])id=1;
if(a[id] > a[2])id=2;
for (size_t i = 0; i < n; i++)
{
    for (size_t j = 0; j < n; j++)
    {
        if(xy[i][j]=='.')cout<<'.';
        else if((i+j)%3==id)cout<<"O";
        else cout<<"X";
    }
    cout<<"\n";
    
}


}
return 0;
}