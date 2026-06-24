#include<bits/stdc++.h>
using namespace std;

int main()
{
    char p[24][5]={
        "0123","0132","0213","0231","0312","0321",
        "1023","1032","1203","1230","1302","1320",
        "2013","2031","2103","2130","2301","2310",
        "3012","3021","3102","3120","3201","3210"
    };
    char ch[55][55],g[105];
    int n,m,j,k=0, i,an=0,si,sj,ei,ej,x;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>ch[i][j];
            if(ch[i][j]=='S'){
                si=i;
                sj=j;
            }
            if(ch[i][j]=='E'){
                ei=i;
                ej=j;
            }
        }
    }
    cin>>g;
    //cout<<given;

    for(x=0;x<24;x++){
        int w,a,s,d,flag=0;
        w=p[x][0]-48;
        a=p[x][1]-48;
        s=p[x][2]-48;
        d=p[x][3]-48;
        i=si;
        j=sj;
        for(k=0;g[k]!='\0';k++){
            switch(g[k]){
                case '0': 
                if(w==0){
                                i--;
                            }
                            else if(a==0){
                                j--;
                            }
                            else if(s==0){
                                i++;
                            }
                            else{
                                j++;
                            }
                            break;
                 case '1':
                    if(w==1){
                                i--;
                            }
                            else if(a==1){
                                j--;
                            }
                            else if(s==1){
                                i++;
                            }
                            else{
                                j++;
                            }
                            break;
                  case '2':
                    if(w==2){
                                i--;
                            }
                     else if(a==2){
                                j--;
                            }
                            else if(s==2){
                                i++;
                            }
                            else{
                                j++;
                            }
                            break;
                    case '3':
                    if(w==3){
                                i--;
                            }
                            else if(a==3){
                                j--;
                            }
                            else if(s==3){
                                i++;
                            }
                            else{
                                j++;
                            }
                            break;
                }

                if(i<0||i>=n||j<0||j>=m)
                    break;
                if(ch[i][j]=='#')
                    break;
                if(ch[i][j]=='E'){
                    an++;
                    break;
                }
        }
    }
    cout<<an;

    return 0;
}