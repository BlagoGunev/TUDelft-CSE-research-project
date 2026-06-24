/*
    「出そうと思えば。（全完意思)」
    「出しちゃっていいすか～？」
*/
#include <iostream>
#include <cstdio>
using namespace std;
int in() {
    int x = 0, c;
    for (; (unsigned int)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
    do { x = (x << 3) + (x << 1) + (c - '0'); } while ((unsigned int)((c = getchar()) - '0') < 10);
    return x;
}


/*
    1 1 1 1 
    a b c
      a b c
    0 3    
*/
             
long long yjsnpimos[100001] = {};
long long value[100001] = {};

int main(){
    int n = in() , m = in() , c = in();
    
    int len = n - m + 1;
    
    for(int i = 0 ; i < n ; i++) value[i] = in();
    long long ans = 0;
    for(int i = 0 ; i < m ; i++){
        int v = in();
        yjsnpimos[i] += v;
        yjsnpimos[i+len] += -v;
    }
    for(int i = 1 ; i < n ; i++) yjsnpimos[i] += yjsnpimos[i-1];
    for(int i = 0 ; i < n ; i++){
        cout << ((yjsnpimos[i]+value[i])%c+c)%c << " ";
    }
    cout << endl;
    
}