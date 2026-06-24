#include<iostream>
#include<string.h>
using namespace std;
int main(){
    long long int T, i, j, two, three, ten, num;
    string str;
    cin>>T;
    for(i=0; i<T; i++){
        ten = 0; three = 0; two = 0; num = 0;
        cin>>str;
        for(j=0; j<str.length(); j++){
            if(str[j] == '0'){
                ten++;
            }
            num = str[j] - '0';
            three = three + num;
            if(num%2 == 0){
                two++;
            }
        }
        if(three%3 == 0 && ten > 0 && two > 1){
            cout<<"red"<<endl;
        }
        else{
            cout<<"cyan"<<endl;
        }
    }
}