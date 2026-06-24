#include<stdio.h>

#include<bits/stdc++.h>

#include<iostream>

using namespace std;

int main()

{



    int t;

    scanf("%d",&t);

    while(t--){

        int n;

        scanf("%d",&n);

        char s[n+1];

        scanf("%s",&s);

        int c=0;

        for(int i=0;i<strlen(s)-1;i++){

            if(s[i]=='R'&&s[i+1]=='L'){printf("0\n");c++;break;}

            else if(s[i]=='L'&&s[i+1]=='R'){printf("%d\n",i+1); c++;break;}

        }

        if(c==0)printf("-1\n");



    }

    return 0;



}