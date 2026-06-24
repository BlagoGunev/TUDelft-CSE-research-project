#include <cstdio>



using namespace std;





int main(){

    float i;

    int vp,vd,t,f,c,ret=0;scanf("%d %d%d%d%d",&vp,&vd,&t,&f,&c);

    if(vd>vp)

    for(i=vp*t+vp*t*1.0/(vd-vp)*vp;i<c;){

        ret++;

        i+=(i*1.0/vd+f)*vp;

        i+=i*1.0/(vd-vp)*vp;

    }

    printf("%d\n",ret);

    return 0;

}