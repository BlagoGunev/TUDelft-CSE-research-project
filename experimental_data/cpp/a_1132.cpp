#include <bits/stdc++.h>

using namespace std;

int main() {
	int cnt1,cnt2,cnt3,cnt4;
	cin>>cnt1;
	cin>>cnt2;
	cin>>cnt3;
	cin>>cnt4;
	if(cnt1 == cnt4){
	    if(cnt3 == 0){
	        cout<<1;
	    }
	    else{
	        if(cnt1>=1){
	            cout<<1;
	        }
	        else{
	            cout<<0;
	        }
	    }
	}
	else{
	    cout<<0;
	}
}