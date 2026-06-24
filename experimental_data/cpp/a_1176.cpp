#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll minSteps(ll n) 
{ 
	if(n<1)
		return -1;
	if (n == 1) 
        return 0;
  
	if (n%2!=0 && n%3!=0 && n%5!=0){ 
        // break;
        return -100000; 
	}
	
	if(n%2==0 && n%3==0 && n%5==0 ){
		// return min(1+ minSteps(n/2),min(1 + minSteps((n*2)/3), 
  //             1 + minSteps((n*4)/5))); 	
		return 1 + minSteps(n/2);
	}
	if(n%2==0 && n%3==0){
		// return min(1+ minSteps(n/2), 1 + minSteps((n*2)/3));
	
		return 1 + minSteps(n/2);
	}
	
	if(n%2==0 && n%5==0){
		// return min(1+ minSteps(n/2), 1 + minSteps((n*4)/5));
	
		return 1 + minSteps(n/2);
	}
	
	if(n%5==0 && n%3==0){
		// return min(1+ minSteps((n*4)/5), 1 + minSteps((n*2)/3));
	
		return 1 + minSteps((n*2)/3);
	}
	
	if(n%2==0)
	return 1+ minSteps(n/2);
	
	if(n%3==0)
	return 1+ minSteps((n*2)/3);
	
	if(n%5==0)
	return 1+ minSteps((n*4)/5);
	
	// if (n%2!=0 && n%3!=0 && n%5!=0) 
 //       return 100000000; 
	// else
    // return min(1+ minSteps(n/2),min(1 + minSteps((n*2)/3), 
    //           1 + minSteps((n*4)/5))); 
} 

int main() {
	// your code goes here
	ll  t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int x = minSteps(n);
		if(x<0)
		cout<<"-1\n";
		else
		cout<<x<<"\n";
	}
	return 0;
}