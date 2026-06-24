#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int vasya[10];
int petya[10];

int solvre(int n, int x){
    int den = 1;
    int cont = 0;
    if(x==0){
        cont = 6;
        den = 64;
    }
    else{
        while(x<=n/den && cont<6){
            cont++;
            den*=2;
        }
    }

    return cont;
}
bool condition(int i){
    if(vasya[i]!=-1 && petya[i]!=-1 && vasya[i]>petya[i]){
        return true;
    }
    return false;
}
const int MOD = 1999999999;
int tonext(int n, int x, int i){
    int den = 1;
    int cont = 0;
    if(x==0){
        cont = 6;
        den = 64;
    }
    else{
        while(x<=n/den && cont<6){
            cont++;
            den*=2;
        }
    }
    int ans;
    if(condition(i)){
        if(cont==1) ans = MOD;
        else ans = (den*x - 2*n)/(2 - den);
    }else{
        if(cont==6) ans = MOD;
        else ans = den*x - n;
    }

    return ans;
}

int calcP(int* vet, int* valor){
    int atual = 0;
    for(int i = 0; i<5; i++){
        if(vet[i]==-1) continue;
        atual = atual + valor[i]*500*(1.0 - vet[i]/250.0);
    }
    return atual;
}

int solvre(){
    int valor[10];
    int cont[10] = {0};
    int prox[10];
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i<5; i++){
        cin>>vasya[i];
        if(vasya[i]>=0) cont[i]++;
    }
    for(int i = 0; i<5; i++){
        cin>>petya[i];
        if(petya[i]>=0) cont[i]++;
    }
    for(int j = 2; j<n; j++){
        for(int i = 0; i<5; i++){
            cin>>x;
            if(x>=0) cont[i]++;
        }
    }


    for(int i = 0; i<5; i++){
        valor[i] = solvre(n, cont[i]);
        prox[i] = tonext(n, cont[i], i);
        // cout<<prox[i]<<" "<<n<<" "<<cont[i]<<" "<<endl;
    }
    int ans = 0;
    for(int i = 0; i<50; i++){

        // cout<<"PROX: ";
        // for(int j = 0; j<5; j++){
        //     cout<<prox[j]<<" ";
        // }
        // cout<<endl;
        // cout<<"CONT: ";
        // for(int j = 0; j<5; j++){
        //     cout<<cont[j]<<" ";
        // }
        // cout<<endl;
        // cout<<"VALOR: ";
        // for(int j = 0; j<5; j++){
        //     cout<<valor[j]<<" ";
        // }
        // cout<<endl;

        int v = calcP(vasya, valor);
        int p = calcP(petya, valor);
        // cout<<"vasya = "<<v<<"\tpetya = "<<p<<endl;
        if(v>p) return ans;

        int menor = 0;
        for(int j = 0; j<5; j++){
            if(prox[menor]>prox[j]) menor = j;
        }
        menor = prox[menor];
        if(menor==MOD){
            return -1;
        }
        n+=menor;
        ans += menor;
        if(ans>1000000007) return -1;

        for(int j = 0; j<5; j++){
            if(condition(j)){
                cont[j]+=menor;
            }
        }
        for(int j = 0; j<5; j++){
            valor[j] = solvre(n, cont[j]);
            prox[j] = tonext(n, cont[j], j);
            // cout<<prox[j]<<" "<<n<<" "<<cont[j]<<" "<<endl;
        }
    }
    return -1;
}

int main(){
    cout<<solvre()<<endl;
}