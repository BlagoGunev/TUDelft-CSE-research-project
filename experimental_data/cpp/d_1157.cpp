#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <string>
#include<list>
#include<map>
#define fast ios::sync_with_stdio(false); cin.tie(0);



using namespace std;




int main(){
	long long  n,k;	
	cin >> n >> k;
	
	if ((k*(k+1))/2 > n){
		cout<<"NO";
		return 0;
	}
	if (k==1){
		cout << "YES\n"<<n;
		return 0;
	}
	if (k==2){
		if (n==4){
			cout<<"NO";
			return 0;
		}
		cout<<"YES\n";
		if (n%2==0){
			cout<<n/2-1<<" "<<n/2+1;
		}
		else cout<<n/2<<" "<<n/2+1;
		return 0;
	}
	
	long long extra = (n - ((k*(k+1))/2)) / k;
	long long rem = (n - ((k*(k+1))/2)) - (extra*k);
	if ((rem<k-1) or (extra!=0)){
		cout<<"YES\n";
		for (long long i=1;i<k;i++) cout<<extra+i<<" ";
		cout<<extra+k+rem;
		return 0;
	}
	else {
		if (k!=3){
			cout<<"YES\n";
			for (long long i=1;i<k-1;i++){
				cout << i<<" ";
			}
			cout << k << " " << 2*k-2;
			return 0;
		}
		else{
			cout<< "NO";
			return 0;
		}
	}
	
	
	
	
	return 0;
}