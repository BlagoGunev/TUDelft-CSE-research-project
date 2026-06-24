#include <bits/stdc++.h>

using namespace std;

int main(){
    
    char a;
    int frea[300], freb[300], x = 0, y = 0, aux;
    
    memset(frea, 0, sizeof frea);
    memset(freb, 0, sizeof freb);
    
    while(a = getchar(), a != '\n'){
        frea[(int)a]++;
    }
    
    while(a = getchar(), a != '\n'){
        freb[(int)a]++;
    }
    
    for(int i = 0; i < 300; i++){
        if(frea[i]){
            aux = min(frea[i], freb[i]);            
            freb[i] -= aux;
            frea[i] -= aux;
            x += aux;
        }
    }
    
    for(int i = 0; i < 300; i++){
        if(frea[i]){
            if(isalpha(i)){
                if(isupper(i)){
                    aux = min(frea[i], freb[tolower(i)]);           
                    freb[tolower(i)] -= aux;
                    frea[i] -= aux;
                    y += aux;
                }else{
                    aux = min(frea[i], freb[toupper(i)]);           
                    freb[toupper(i)] -= aux;
                    frea[i] -= aux;
                    y += aux;
                }
            }
        }
    }
    
    printf("%d %d", x, y);
    
    return 0;
}