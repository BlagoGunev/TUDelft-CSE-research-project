#include <cstdio>

#include <cmath>

using namespace std;

#define llu unsigned long long

#define ll long long

llu l;

int arr1[18];

int arr2[18];

int length(llu n,int arr[]){

    int length=0;

    while(n){

        arr[length++]=n%10;

        n/=10;

    }

    return length;

}

llu solve(int length,llu n,int arr[]){

    llu ret=0;

    if(length<2)

        return n;

    else {

        ret+=(llu)n/10;

              ret-=(llu)pow(10,length-2);

        if(arr[length-1]<=arr[0]) ret+=1;

        ret+=9;

        for (int i=1; i<length-1; i++) {

            ret+=(llu)(9*pow(10,i-1));

        }

    }

    return ret;

}

int main() {

    llu r;scanf("%llu %llu",&l,&r);

    int length1,length2;

    length1=length(l-1,arr1);

    length2=length(r,arr2);

    llu ret=0;

    ret=solve(length2, r,arr2)-solve(length1, l-1,arr1);

    printf("%llu\n",ret);

    return 0;

}