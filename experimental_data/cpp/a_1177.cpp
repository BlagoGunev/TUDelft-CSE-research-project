#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long int K;
    while(cin>>K){
    
    long long prev = 0;
    long long next = 0;
    long long cur = 9;
    int curdig = 1;
    while(true){
        next = prev+cur*curdig;
        if(next>=K){
            break;
        }
        curdig++;
        cur = cur*10;
        prev = next;
    }
    
    long long idx = (K-prev-1)/curdig;
    long long pos = (K-prev-1)%curdig;
    
    long long st = 1;
    for(int i = 1; i<curdig; ++i)st = st*10;
    
    st = st+idx;
    
    string mystr = "";
    
    while(st){
        mystr.push_back(st%10+'0');
        st/=10;
    }
    
    reverse(mystr.begin(),mystr.end());
    
    cout<<mystr[pos]<<"\n";
    }
    return 0;
}