#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int ar[10]={0};
	int n;cin>>n;
	int c=0;
	/*for(int i=9;i>=1;i--){
		if(n/i >0){
			ar[i] = n/i;
			c+=ar[i];
			n%=i;
			
		}
		if(n==0)break;
	}
	*/
	cout<<n<<'\n';
	
	//for(int i=9;i>=1;i--){
	//	int t=ar[i];
		
		while(n--){
			cout<<1<<" ";
		}
	
	
	cout<<'\n';
	
	return 0;
}