#include<bits/stdc++.h>
// #include<bits/extc++.h>
using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
#define fi first
#define se second
#define endl '\n'
#define mkp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define Cl(x) memset(x,0,sizeof(x))
const bool DC=0;
const ll mod=998244353;
const int N=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}
void NO(){cout<<"NO\n";}
void YES(){cout<<"YES\n";}
mt19937 rnd((unsigned long long)new char);
int rnad(){return abs((int)rnd());}
int rd(int l,int r){return rnad()%(r-l+1)+l;}

typedef long double db;
const db PI=3.141592653589793238462843383279;
const db inf=1e20;
const db eps=1e-15;
inline bool eq(db a,db b){return fabsl(a-b)<=eps;}
inline bool ls(db a,db b){return (a-b)<-eps;}
inline bool gt(db a,db b){return (a-b)>eps;}
inline bool le(db a,db b){return (a-b)<=eps;}
inline bool ge(db a,db b){return (a-b)>=-eps;}
short sig(db x){return x<-eps?-1:x>eps?1:0;}
struct point{
	db x,y;
	point operator+(const point&b)const{return {x+b.x,y+b.y};}
	point operator-(const point&b)const{return {x-b.x,y-b.y};}
	point operator+=(const point&b){return {x=x+b.x,y=y+b.y};}
	point operator-=(const point&b){return {x=x-b.x,y=y-b.y};}
	db operator~()const{return hypotl(x,y);}
	point operator*(const db&b)const{return {x*b,y*b};}
	void rot(db ang){db c=cosl(ang),s=sinl(ang);db X=x,Y=y;x=X*c+Y*s,y=Y*c-X*s;}
	db operator*(const point&b)const{return x*b.x+y*b.y;}
	db operator^(const point&b)const{return x*b.y-y*b.x;}
	bool operator==(const point&b)const{return eq(x,b.x)&&eq(y,b.y);}
	bool operator<(const point&b)const{return eq(y,b.y)?ls(x,b.x):ls(y,b.y);}
	bool operator()()const{return !eq(x,inf);}
	bool operator!()const{return eq(x,inf);};
};
void prt(point p,char ed='\n'){printf("%.15Lf %.15Lf%c",p.x,p.y,ed);}
void err(point p,char ed='\n'){cerr<<p.x<<" "<<p.y<<ed;}
point read(){point p;cin>>p.x>>p.y;return p;}
bool para(point a,point b){return eq(a.x/b.x,a.y/b.y);}
point atop(db ang){return {cosl(ang),sinl(ang)};}
point mid(point a,point b){return (a+b)*0.5;}
db dis(point a,point b){return ~(b-a);}
db tri(point a,point b,point c){return (b-a)^(c-a);}
db PtoL(point p,point t1,point t2){return fabsl(((t1.y-t2.y)*p.x-(t1.x-t2.x)*p.y+(t1^t2))/dis(t1,t2));}
db PtoS(point p,point t1,point t2){
	point t=t2-t1;
	db c=t*(p-t1)/~t;
	if(ge(c,0)&&le(c,~t))return ~(p-t1-t*(c/~t));
	return min(dis(p,t1),dis(p,t2));
}
point PvertL(point p,point t1,point t2){
	point t=t2-t1;
	db c=t*(p-t1)/~t;
	return t1+t*(c/~t);
}
point LiL(point p1,point p2,point q1,point q2){
	if(para(p2-p1,q2-q1))return {inf,inf};
	point a=p2-p1,b=q2-q1,u=q2-p2;
	return p2-a*((u^b)/(a^b));
}
point SiS(point p1,point p2,point q1,point q2){
	if(para(p2-p1,q2-q1))return {inf,inf};
	db abac=tri(p1,q1,p2),abad=tri(p1,p2,q2),cdca=tri(q1,p1,q2),cdcb=tri(q1,q2,p2);
	if(le(abac*abad,0)&&le(cdca*cdcb,0)){
		db lbd=abac/abad;
		return q1+(q2-q1)*(lbd/(lbd+1));
	}
	return {inf,inf};
}
bool sis(point a,point b,point c,point d){
	return max(min(a.x,b.x),min(c.x,d.x))<=min(max(a.x,b.x),max(c.x,d.x))
	&&max(min(a.y,b.y),min(c.y,d.y))<=min(max(a.y,b.y),max(c.y,d.y))
	&&tri(c,b,d)*tri(c,d,a)>=0&&tri(a,d,b)*tri(a,b,c)>=0;
}

vector<point> S,T;
vector<point>rd(){
	int sz;cin>>sz;
	vector<point>ans;
	while(sz--)ans.push_back(read());
	return ans;
}
bool inpoly(point p,vector<point>pl){
	point q={1e9,1e9+1};
	int l=pl.size(),cnt=0;
	for(int i=0;i<l-1;i++)cnt+=sis(p,q,pl[i],pl[i+1]);
	cnt+=sis(p,q,pl[l-1],pl[0]);
	return cnt&1;
}
bool notinter(point p,point q,vector<point>pl){
	int l=pl.size();
	for(int i=0;i<l;i++){
		if(pl[i]==p||pl[i]==q||pl[(i+1)%l]==p||pl[(i+1)%l]==q)continue;
		if(sis(p,q,pl[i],pl[(i+1)%l]))return 0;
	}
	return 1;
}
int Cnt;
struct trg{point a,b,c;int id;};
void prt(trg t,char ed='\n'){cout<<"3 ";prt(t.a,' '),prt(t.b,' '),prt(t.c,ed);}
void Prt(vector<point>p,char ed='\n'){
	cout<<p.size()<<" ";
	for(int i=0;i<p.size();i++)prt(p[i],i==p.size()-1?ed:' ');
}
void Err(vector<point>p,char ed='\n'){
	// cout<<p.size()<<" ";
	for(int i=0;i<p.size();i++)err(p[i],i==p.size()-1?ed:' ');
}
vector<trg>trgl(vector<point>P){
	vector<trg>ans;
	if(P.size()<3)assert(0);
	if(P.size()==3){
		ans.push_back({P[0],P[1],P[2]});
		return ans;
	}
	int l=P.size();
	auto prv=[&](int id){return P[(id+l-1)%l];};
	auto nxt=[&](int id){return P[(id+1)%l];};
	for(int i=0;i<l;i++){
		point pr=prv(i),cr=P[i],nx=nxt(i);
		if(inpoly(mid(pr,nx),P)&&notinter(pr,nx,P)){
			P.erase(P.begin()+i);
            ans=trgl(P);
			ans.push_back({pr,cr,nx});
            return ans;
		}
	}
}
vector<pair<int,db>>ids;db Ht=1.14;

int nc2nc(vector<point>rec1,int id1,vector<point>rec2){
	db h1=rec1[3].y,w1=rec1[1].x;
	db h2=rec2[3].y,w2=rec2[1].x;
	cerr<<"nc2nc "<<h1<<" "<<w1<<" "<<h2<<" "<<w2<<"\n";
	if(w1>w2){
		point X1={w1-w2,h1};
		point X2={w2,h2-h1};
		point H={w2,0};
		cout<<"scissors\n"<<id1<<" 3\n";
		Prt({rec1[0],H,X2,X1,rec1[3]});
		prt({H,rec1[1],X2});
		prt({rec1[1],rec1[2],X1});
		Cnt+=3;
		cout<<"tape\n3 "<<Cnt-2<<" "<<Cnt-1<<" "<<Cnt<<"\n";
		Prt({rec1[0],H,X2,X1,rec1[3]});
		prt({rec1[3],X1,rec2[3]});
		prt({X2,rec2[2],rec2[3]});
		Prt(rec2);
		return ++Cnt;
	}else{
		point X1={w2-w1,h2},X2={w1,h1-h2},H={0,h2};
		cout<<"scissors\n"<<id1<<" 3\n";
		Prt({rec1[0],rec1[1],X2,X1,H});
		prt({H,X1,rec1[3]});
		prt({X2,rec1[2],rec1[3]});
		Cnt+=3;
		cout<<"tape\n3 "<<Cnt-2<<" "<<Cnt-1<<" "<<Cnt<<"\n";
		Prt({rec1[0],rec1[1],X2,X1,H});
		prt({rec1[1],rec2[1],X2});
		prt({rec2[1],rec2[2],X1});
		Prt(rec2);
		return ++Cnt;
	}
}
vector<point>genr(db w,db h,point st={0,0}){point W={w,0},H={0,h};return{st,st+W,st+W+H,st+H};}
int Wdb(vector<point>rec,int id){
	db h=rec[3].y,w=rec[1].x;
	cout<<"scissors\n"<<id<<" 2\n";
	Prt(genr(w,h/2));
	Prt(genr(w,h/2,{0,h/2}));
	Cnt+=2;
	cout<<"tape\n2 "<<Cnt-1<<" "<<Cnt<<"\n";
	Prt(genr(w,h/2));
	Prt(genr(w,h/2,{w,0}));
	Prt(genr(w*2,h/2));
	return ++Cnt;
}
int Hdb(vector<point>rec,int id){
	db h=rec[3].y,w=rec[1].x;
	cout<<"scissors\n"<<id<<" 2\n";
	Prt(genr(w/2,h));
	Prt(genr(w/2,h,{w/2,0}));
	Cnt+=2;
	cout<<"tape\n2 "<<Cnt-1<<" "<<Cnt<<"\n";
	Prt(genr(w/2,h));
	Prt(genr(w/2,h,{0,h}));
	Prt(genr(w/2,h*2));
	return ++Cnt;
}
int rc2rc(vector<point>rec1,int id1,vector<point>rec2){
	db h1=rec1[3].y,w1=rec1[1].x;
	db h2=rec2[3].y,w2=rec2[1].x;
	cerr<<"rc2rc "<<h1<<" "<<w1<<" "<<h2<<" "<<w2<<"\n";
	if(h1>w1*2)return rc2rc(genr(w1*2,h1/2),Wdb(rec1,id1),rec2);
	if(w1>h1*2)return rc2rc(genr(w1/2,h1*2),Hdb(rec1,id1),rec2);
	if(h2>w2*2)return Hdb(genr(w2*2,h2/2),rc2rc(rec1,id1,genr(w2*2,h2/2)));
	if(w2>h2*2)return Wdb(genr(w2/2,h2*2),rc2rc(rec1,id1,genr(w2/2,h2*2)));
	return nc2nc(rec1,id1,rec2);
}

void calc(trg cur){
	point a=cur.a,b=cur.b,c=cur.c,T,X;
	cout<<"tape\n1 "<<cur.id<<"\n";
	db ab=dis(a,b),ac=dis(a,c),bc=dis(b,c);
	if(ab>=ac&&ab>=bc){
		if(((b-a)^(c-a))>=0)T=a,X=b;
		else T=b,X=a;
	}else if(ac>=ab&&ac>=bc){
		if(((c-a)^(b-a))>=0)T=a,X=c;
		else T=c,X=a;
	}else{
		if(((b-c)^(a-c))>=0)T=c,X=b;
		else T=b,X=c;
	}
	b-=T,c-=T,a-=T,X-=T;
	db ang=-atan2l(X.y,X.x);
	a.rot(-ang),b.rot(-ang),c.rot(-ang);X.rot(-ang);
	prt({a,b,c});
	if(gt(a.y,c.y))c=a;
	if(gt(b.y,c.y))c=b;
	a={0,0},b=X;
	prt({a,b,c});++Cnt;
	point mac=mid(a,c),mbc=mid(b,c),H={c.x,c.y/2};
	cout<<"scissors\n"<<Cnt<<" 3\n";
	prt({mac,H,c}),prt({mbc,c,H}),Prt({a,b,mbc,mac});
	Cnt+=3;
	point d={a.x,c.y/2},e={b.x,c.y/2};
	cout<<"tape\n3 "<<Cnt-2<<" "<<Cnt-1<<" "<<Cnt<<"\n";
	prt({mac,d,a});prt({mbc,b,e});Prt({a,b,mbc,mac});
	Prt({a,b,e,d});
	cerr<<"triangle turned to ";Err({a,b,e,d});
	++Cnt;//exit(0);
	db S=e.x*e.y;
	ids.push_back({rc2rc({a,b,e,d},Cnt,genr(S/Ht,Ht)),S/Ht});
}
vector<int>ids2;
void calc2(trg cur){
	point a=cur.a,b=cur.b,c=cur.c,T,X;
	db ab=dis(a,b),ac=dis(a,c),bc=dis(b,c);
	if(ab>=ac&&ab>=bc){
		if(((b-a)^(c-a))>=0)T=a,X=b;
		else T=b,X=a;
	}else if(ac>=ab&&ac>=bc){
		if(((c-a)^(b-a))>=0)T=a,X=c;
		else T=c,X=a;
	}else{
		if(((b-c)^(a-c))>=0)T=c,X=b;
		else T=b,X=c;
	}
	b-=T,c-=T,a-=T,X-=T;
	db ang=-atan2l(X.y,X.x);
	a.rot(-ang),b.rot(-ang),c.rot(-ang);
	trg tmp={a,b,c};
	// prt({a,b,c});
	if(gt(a.y,c.y))c=a;
	if(gt(b.y,c.y))c=b;
	a={0,0},b=X,b.rot(-ang);
	point mac=mid(a,c),mbc=mid(b,c),H={c.x,c.y/2};
	point d={a.x,c.y/2},e={b.x,c.y/2};
	cout<<"tape\n1 "<<cur.id<<"\n";
	Prt(genr(e.x*e.y/Ht,Ht)),Prt(genr(e.x*e.y/Ht,Ht));
	++Cnt;
	cur.id=rc2rc(genr(e.x*e.y/Ht,Ht),Cnt,{a,b,e,d});
	cout<<"scissors\n"<<cur.id<<" 3\n";
	prt({mac,d,a});prt({mbc,b,e});Prt({a,b,mbc,mac});
	Cnt+=3;
	cout<<"tape\n3 "<<Cnt-2<<" "<<Cnt-1<<" "<<Cnt<<"\n";
	prt({mac,H,c}),prt({mbc,c,H}),Prt({a,b,mbc,mac});
	prt(tmp);
	ids2.push_back(++Cnt);
}

void __INIT__(){/*ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);*/}
void __SOLVE__(ll _case){
    // cout<<fixed<<setprecision(6);
	S=rd(),T=rd();
    vector<trg>trs=trgl(S),trt=trgl(T);
	Ht=0;
	for(auto i:trs)Ht+=fabs(tri(i.a,i.b,i.c))/2;
	Ht=sqrtl(Ht);
    cout<<"scissors\n0 "<<trs.size()<<"\n";
    for(auto&i:trs)prt(i),i.id=++Cnt;
	for(auto i:trs)calc(i);
	cout<<"tape\n"<<ids.size()<<" ";
	for(auto i:ids)cout<<i.fi<<" ";cout<<"\n";
	db sum=0;
	for(auto i:ids){
		Prt(genr(i.se,Ht,{sum,0}));
		sum+=i.se;
	}
	Prt(genr(sum,Ht));
	++Cnt;
	db sum2=0;
	cout<<"scissors\n"<<Cnt<<" "<<trt.size()<<"\n";
	for(auto&i:trt){
		db d=fabs(tri(i.a,i.b,i.c))/Ht/2;
		Prt(genr(d,Ht,{sum2,0}));
		sum2+=d;
		i.id=++Cnt;
	}
	for(auto i:trt)calc2(i);
	cout<<"tape\n"<<trt.size()<<" ";
	for(auto i:ids2)cout<<i<<" ";cout<<"\n";
	for(auto i:trt)prt(i);
	Prt(T);
}
int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	__INIT__();int T;DC?cin>>T,1:T=1;for(int _CASE=1;_CASE<=T;_CASE++)__SOLVE__(_CASE);return 0;}