#include<bits/stdc++.h>

using namespace std;

#define int long long

#define N 45

#define K 12



int n,k;

int online[K],new_pos[K];

int op[K][N];



bool calc(int msk,int ind){

    if(ind==k-1){

        int srt=((1ll<<__builtin_popcountll(msk))-1ll)<<(n-__builtin_popcountll(msk));

        return ((msk^srt)&op[ind][0])==(msk^srt);

    }

    int pmsk=__builtin_popcountll(msk&op[ind][0]);

    msk|=op[ind][0];

    for(int a=0;a<=new_pos[ind];++a){

        if(!calc(msk&((1ll<<n)-1-op[ind][a+pmsk]),ind+1)){return false;}

    }

    return true;

}



signed main(){

    cin>>n>>k;

    if(n==1){cout<<"ACCEPTED"<<endl;return 0;}

    for(int a=0;a<k;++a){

        int sz;cin>>sz;

        if(sz==n){cout<<"ACCEPTED"<<endl;return 0;}

        op[a][sz]=0;

        for(int b=0;b<sz;++b){

            int c;cin>>c;

            --c;

            op[a][sz-b-1]=op[a][sz-b]|(1ll<<c);

        }

        new_pos[a]=__builtin_popcountll(op[a][0]&(~online[a]));

        online[a+1]=online[a]|op[a][0];

    }

    if(online[k-1]!=(1ll<<n)-1){cout<<"REJECTED"<<endl;return 0;}

    if(calc(0,0)){cout<<"ACCEPTED"<<endl;return 0;}

    cout<<"REJECTED"<<endl;

    return 0;

}