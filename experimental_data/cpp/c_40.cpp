#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i=0;i!=n;i++)
#define pb(a) push_back(a)
#define ALL(x) x.begin(),x.end()
#define forAll(it,x) for(it=x.begin();it!=x.end();it++)
typedef long long ll;
inline ll ABS(ll a) {return a<0?-a:a;}
inline void swap(ll &x, ll &y) {ll tmp=x;x=y;y=tmp;}
ll x,y,x2,y2;
ll rez, rast,nom, nom2, nom3;
int main(){
	cin>>x>>x2>>y>>y2;
	rast=ABS(x2-y2);
	rez=x+y+1;
	if (x>y) swap(x,y);
	if (rast<x+y){
		nom=x+y-rast;
		if (nom>x) nom=x;
		if (nom>rast) nom=rast;
		rez+=nom*nom;
		nom3=0;
		if (rast<x){
			nom=x-rast;
			nom3=nom;
			rez+=((rast*nom)<<2L)-(nom<<1L);
		}
		if (rast<y){
			nom=y-rast;
			if (nom>0){
				if (nom>y) nom=y;
				nom-=nom3;
				nom2=x-nom3-1;
				forn(i,nom){
					if (nom2==0) break;
					rez+=nom2<<1L;
					nom2--;
				}
			}
		}
	}
	cout<<rez;
	return 0;
}