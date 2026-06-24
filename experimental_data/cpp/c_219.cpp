#include <iostream>
#include <string.h>
#include<cstring>
#include<stdio.h>
using namespace std;
char a[500001];
int main ()
{
    int n,p;
while(cin>>n>>p)
    {
        scanf("%s",a);
        int cou=0;
        if(p==2)
        {
            for(int i=1;i<n;i++){
                if(a[i]==a[i-1]){
                    cou++;
                    if(a[i]=='A')  a[i]='B';
                    else a[i]='A';
                }
            }
            if(cou<=n/2)
               printf("%d\n%s\n",cou,a);
            else {
                   for(int i=0;i<n;i++) a[i]='A'+'B'-a[i];
                   printf("%d\n%s\n",n-cou,a);
            }
        }
        else {
             for(int i=1;i<n;i++){
                 if(a[i]==a[i-1]){
                    cou++;
                    if(a[i]=='A') {
                        if(a[i+1]!='B')
                           a[i]='B';
                        else a[i]='C';
                    }
                    else {
                        if(a[i+1]!='A')
                             a[i]='A';
                        else {
                            if(a[i-1]!='B')
                               a[i]='B';
                            else a[i]='C';
                        }
                    }
                }
             }
            printf("%d\n%s\n",cou,a);
        }
}
}