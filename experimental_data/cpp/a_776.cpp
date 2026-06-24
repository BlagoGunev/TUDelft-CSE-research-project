#include<iostream>
#include<utility>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
int main(){
char *y;
char a[1001],b[1001],c[1001];
cin>>a>>b;
cout<<a<<" "<<b<<endl;
int n;
cin>>n;
while(n--){

    char d[1001], e[1001];
    cin>>d>>e;
    if(strcmp(d,a)==0)
    {
        strcpy(a,e);

    }
    else
        strcpy(b,e);

    cout<<a<<" "<<b<<endl;
}


return 0;

}