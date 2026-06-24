#include <bits/stdc++.h>

using namespace std;

#include<stdio.h>
#include<string.h>
int main()
{
    char str1[30],str2[30],str3[1000] ;
    int i,j,flag ;
    fgets(str1, sizeof(str1), stdin) ;
    fgets(str2, sizeof(str2), stdin) ;
    fgets(str3, sizeof(str3), stdin) ;
    for(i=0 ;i<strlen(str3) ;i++){
        flag=0 ;
        if(str3[i]>40&&str3[i]<60){
            	printf("%c",str3[i]) ;
			}
        else if(str3[i]<95){
            str3[i]=str3[i]+32 ;
            flag=1 ;
        }
        for(j=0 ;j<strlen(str1) ;j++){
            if(str1[j]==str3[i]){
                if(flag==1)printf("%c",str2[j]-32) ;
                else printf("%c",str2[j]) ;
            }
            
        }
        
    }
    return 0 ;
}