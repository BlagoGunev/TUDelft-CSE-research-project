#include<stdio.h>
int main(){
int a,b,c,d,e,f,g;
scanf("%d%d%d",&a,&b,&c);
d=b/2;
e=c/4;
if(a<d){
if(a<e){
f=a+(2*a)+(4*a);
printf("%d",f);
}
else{
f=e+(2*e)+(4*e);
printf("%d",f);
}
}
else if(d<a){
if(d<e){
f=d+(2*d)+(4*d);
printf("%d",f);
}
else{
f=e+(2*e)+(4*e);
printf("%d",f);
}
}
else{
if(a<e){
f=a+(2*a)+(4*a);
printf("%d",f);
}
else{
f=e+(2*e)+(4*e);
printf("%d",f);
}


}







}