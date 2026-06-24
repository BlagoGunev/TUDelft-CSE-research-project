#include<bits/stdc++.h>

#define ll long long int

#define mp make_pair

#define pb push_back

#define si(x) scanf("%d",&x)

#define pi(x) printf("%d\n",x)

#define s(x) scanf("%I64d",&x)

#define p(x) printf("%I64d\n",x)

#define sc(x) scanf("%s",x)

#define pc(x) printf("%s",x)

#define F first

#define S second

#define M 1000000007

#define inf 1e9



using namespace std;



char c[9][9];

int main(){



for(int i=0;i<8;i++){

    cin>>c[i];

}



int w=inf;

for(int i=0;i<8;i++) {

    for(int j=0;j<8;j++) {

        if (c[j][i]=='B') {

            break;

        }

        else if(c[j][i]=='W') {

            w=min(w,j);

        }

    }

}



int b=inf;

for(int i=0;i<8;i++) {

    for(int j=7;j>=0;j--) {

        if (c[j][i]=='W') {

            break;

        }

        else if(c[j][i]=='B') {

            b=min(b, 8-j-1);

        }

    }

}



if (w<=b) {

    cout<< "A";

}

else cout<<"B";





return 0;

}