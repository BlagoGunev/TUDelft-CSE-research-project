#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,z,b,c=0,r=0,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++) scanf("%d",&arr[i]);
	b=arr[0];
	for(i=1; i<n; i++){
	    z=arr[i];
	    if(i > 1) c=arr[i-2];
	    if(b == 1 && r!=-1){
	        if(z == 2){
	            if(c == 3) r+=2;
	            else r+=3;
	        }
	        else if(z == 3) r+=4;
	    }
	    else if(b == 2 && r!=-1){
	        if(z == 1) r+=3;
	        else if(z == 3) r=-1;
	    }
	    else if(b == 3 && r!=-1){
	        if(z == 1) r+=4;
	        else if(z == 2) r=-1;
	    }
	    b=z;
	}
	if(r == -1) printf("Infinite\n");
	else printf("Finite\n%d\n",r);
	return 0;
}