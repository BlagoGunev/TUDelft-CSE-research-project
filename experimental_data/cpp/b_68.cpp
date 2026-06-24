#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#define MM 10000

int P[MM],N,K;
double Ans;

FILE *in = stdin;
FILE *out = stdout;

int MIN(int a,int b){
	return (a<b)?a:b;
}

int main(void){
	int min,i,max;
	int high,mid,low;
	int64_t sur1,sur2;
	fscanf(in,"%d%d",&N,&K);
	for(i=0;i<N;i++){
		fscanf(in,"%d",&P[i]);
		P[i]*=1000000;
		if(i==0)min=P[i],max=P[i];
		min=MIN(P[i],min);
		max=-MIN(-P[i],-max);
	}
	low=min,high=max;
	Ans=min;
	for(;;){
		if(high<low)break;
		mid=(high+low)/2;
		for(i=0,sur1=0,sur2=0;i<N;i++){
			if(P[i]<mid)sur1+=mid-P[i];
			else sur2+=P[i]-mid;
		}
		if(double(sur2)*(100-K)/100<sur1)high=mid-1;
		else {
			low=mid+1;
			if(Ans<mid)Ans=mid;
		}
	}fprintf(out,"%.10lf\n",double(Ans)/1000000);
	return 0;
}