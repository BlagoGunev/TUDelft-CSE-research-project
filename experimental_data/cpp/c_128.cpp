#include <iostream>

using namespace std;

long long r=1,w=1,m,n,k,k1=1,z=1,l=1,p=1000000007,z1=1,sigma=0,t=1,y;

long long poow(long long a,long long b,long long m){

    if(b!=1){

        long long pcur=poow(a%m,b/2,m)%m;

        if(b%2)

            return (((pcur*pcur)%m)*(a%m))%m;

        else

            return (pcur*pcur)%m;

    }

    if(b==1)

        return a%m;

}

int main(){

    cin>>n>>m>>k;

    k=k*2;

    k1=k;

    if(k>n-1||k>m-1)

        cout<<0;

    else{

    if(k<n-1/2){

        k = n - 1 - k;

    }

        for(int i=k+1;i<n;i++){

            z=(z*i)%p;

            //cout<<z<<endl;

        }

        for(int i=1;i<=n-k-1;i++){

            l=(l*i)%p;

            //cout<<l<<endl;

        }

        z1=poow(l,1000000005,1000000007);

        //cout<<z1<<endl;

        sigma=(z*z1)%p;

    if(k1<m-1/2){

        k1 = m - 1 - k1;

    }

    z=1;l=1;z1=1;

        for(int i=k1+1;i<m;i++){

            z=(z*i)%p;

        }

        for(int i=1;i<=m-k1-1;i++){

            l=(l*i)%p;

        }

        z1=poow(l,1000000005,1000000007);

        //cout<<z1<<endl;

        sigma=(sigma*((z*z1)%p))%p;

        cout<<sigma;

    }

}