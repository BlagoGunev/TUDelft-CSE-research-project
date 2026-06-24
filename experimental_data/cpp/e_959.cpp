#include <map>
#include <iostream>
#include <cassert>

using namespace std;

int main(){
 unsigned long long int n;
 unsigned long long int res = 0;
 cin>>n;
int stepen = 0;
 for(int i= 0; i<64; i++){
    if((n-1)>>i ==0){
        stepen = i;
        break;
    }
 }
// cout<<"stepen je: "<<stepen<<endl;
 for(int i =0; i<stepen; i++){
    res += (((unsigned long long int)1) <<i);
 }
//cout<<"current: "<<res<<endl;
 unsigned long long int tmp = 0;
 for(int i = stepen-1; i>=0; i--){
        res += tmp * (((unsigned long long int)1) <<(i));
    if(tmp>0 && ((n-1) & (((unsigned long long int)1) <<i)) == 0){
        res -= (((unsigned long long int)1) <<(i));
    }
 tmp  = tmp*2;
 if(((n-1) & (((unsigned long long int)1) <<i)) != 0){
    tmp +=1;
 }
 }
cout<<res;
}