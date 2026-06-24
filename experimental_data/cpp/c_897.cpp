#include <bits/stdc++.h>

using namespace std;

#include<stdio.h>
#include<string.h>

const char ques[80]= "What are you doing at the end of the world? Are you busy? Will you save us?";//75
const char p1[50]="What are you doing while sending \"";//34
const char p2[50]="\"? Are you busy? Will you send \"";//32
const char p3[10]="\"?";//2
int ma;

int i,j,q,n;
long long t;
long long aaa[60];
long long getlen(int x){
	if(x>=ma)return 1000000000000000001L;
	return(aaa[x]);
}


int main(){
	aaa[0]=75;
	i=0;
	long long ttt;
	while(aaa[i]<=1000000000000000000){
		aaa[i+1]=2*aaa[i]+68;
		i++;
	}
	ma=i;
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&n);
		scanf("%lld",&t);
	while(1){

	if(t>getlen(n)){
		printf(".");break;
	}else
	if(n==0){printf("%c",ques[t-1]);break;
	}else{ 
		 	if(t<=34){printf("%c",p1[t-1]);break;}
			else if(t<=(getlen(n-1)+34)){n--;t=t-34;continue;}
			else if(t<=(getlen(n-1)+34+32)){printf("%c",p2[t-1-getlen(n-1)-34]);break;}
			else if((t<=2*getlen(n-1)+34+32)){n--;ttt=t=t-(getlen(n)+34+32);continue;}
			else {printf("%c",p3[t-1-(2*getlen(n-1)+34+32)]);break;}
		}
	}

	}
	return 0;
}