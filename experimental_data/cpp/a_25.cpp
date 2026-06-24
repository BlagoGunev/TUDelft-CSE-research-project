#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ne=0,no=0,le=0,lo=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x&1)no++,lo=i;
        else ne++,le=i;
    }
    //cout<<no<< " "<<ne;
    if(no==1)cout<<lo<<endl;
    else cout<<le<<endl;
	return 0;
}