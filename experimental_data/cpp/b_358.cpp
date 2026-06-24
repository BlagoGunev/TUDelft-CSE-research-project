#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int n;
char a[100009],b[100009],tmp[100009];
int top=-1;
int cur=-1;
int len,len2;

int findchar(char c){
    for (int i=cur+1;i<len2;i++)
        if (b[i]==c) return i;
    return -1;
}

void spb(){
    a[top+1]='<';
    a[top+2]='3';
    top+=2;
    strcpy(a+top+1,tmp);
    top+=strlen(tmp);
}

int main(){
    scanf("%d\n",&n);
    for (int i=1;i<=n;i++){
        scanf("%s\n",tmp);
        spb();
    }
    a[top+1]='<';
    a[top+2]='3';
    scanf("%s",b);
    len=strlen(a);
    len2=strlen(b);
    bool flag=true;
    for (int i=0;i<len;i++){
        cur=findchar(a[i]);
        if (cur==-1){
            //cout<<i<<endl;
            flag=false;
            break;
        }
    }
    //puts(a);
    if (flag) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}