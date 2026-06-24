#include<iostream>
using namespace std;
bool b[1001];
int n;
int gcd(int a,int b){
	if(a%b==0)return b;
	return gcd(b,a%b);
}
int main(){
    cin>>n;
    for(int i=n/2;i;i--){
    	//;
    	if(gcd(i,n-i)==1){
    		cout<<i<<' '<<n-i<<endl;
    		break;
    	}
    }
    return 0;
}