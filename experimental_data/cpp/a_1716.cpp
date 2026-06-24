#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

#include <math.h>

#include<ios>



using namespace std;

typedef long long ll;

typedef vector<int> vi;

typedef vector<string> vs;

typedef pair<int,int> pi;

#define F first

#define S second

#define E end

#define PB push_back

#define MP make_pair



void getI(vi &out, int elementNum = 1){

    int temp;

    for(int i = 0; i < elementNum; i++){

        cin >> temp;

        out.PB(temp);

    }

}

void getI(vs &out, int elementNum = 1){

    string temp;

    for(int i = 0; i < elementNum; i++){

        cin >> temp;

        out.PB(temp);

    }

}

void getIW(vi &out){

    int elementnum;

    int temp;

    cin >> elementnum;

    for(int i = 0; i < elementnum;i++){

        cin >> temp;

        out.push_back(temp);

    }

}

void getIW(vs &out){

    int elementnum;

    string temp;

    cin >> elementnum;

    for(int i = 0; i < elementnum;i++){

        cin >> temp;

        out.push_back(temp);

    }

}

void prArr(vi in){

    for(int i : in){

        cout << i;

    }

}

void start(){

    ios::sync_with_stdio(0);

    cin.tie(0);

}

int main(){

    start();

    //code here

    vi a;

    int temp;

    getIW(a);

    for(int i : a){

        if(i==1){cout << 2 << endl;continue;}

        if(i%3==0){

            cout << i/3 << endl;

        }else if((i+1)%3==0){

            cout << (i+1)/3 << endl;

        }else if((i+2)%3==0){

            cout << (i+2)/3 << endl; 

        }



    }

    return 0;

}