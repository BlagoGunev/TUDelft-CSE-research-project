#include<iostream>
using namespace std;
int aa[10000];
int main(){
    int n, kk, s= 0, r;
    cin>>n>>kk;
    for(int i=1; i<=n; i++){
        cin>>aa[i];
    }
    for(int i=1; i<=n; i++){
        s += aa[i];
        if(s>8){
            s -= 8;
            kk -= 8;
            if(kk<=0){
                return cout<<i, 0;
            }
        }
        else{
            kk -= s;
            s= 0;
            if(kk<=0){
                return cout<<i, 0;
            }
        }
    }
    cout<<-1;
}