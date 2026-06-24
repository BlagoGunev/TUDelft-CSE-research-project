#include<bits/stdc++.h>

#define ll long long //unsigned long long

#define mem(b,t) memset(b,t,sizeof(b))

#define INF 0x3f3f3f3f

#define rep(i,n,m) for(int i=n;i<=m;i++)

#define per(i,n,m) for(int i=n;i>=m;i--)

#define repp(i,n) for(int i=0;i<n;i++)

#define bug1(i) cout<<i<<endl

#define bug2(i,j) cout<<i<<" "<<j<<endl

#define bug3(i,j,k) cout<<i<<" "<<j<<" "<<k<<endl

#define mod 1000000007 //998244353

#define maxn 200005

#define eps 1e-4

#define pi acos(-1)

using namespace std;



inline double readdb()

{

    long long s = 0, w = 1, k = 0, n = 0, m = 0;

    char ch = getchar();

    while(ch < '0' || ch > '9')

    {

        if(ch == '-') w = -1;

        ch = getchar();

    }

    while((ch >= '0' && ch <= '9') || ch == '.')

    {

        if (ch == '.')

            n = 1;

        else if (n == 0)

            s = s * 10 + ch - '0';

           else k = k * 10 + ch - '0', m++;

        ch = getchar();

    }

    return (pow(0.1, m) * k + s) * w;

}



inline int readint()

{

    char ch = getchar();

    int s = 0, w = 1;

    while(ch < '0' || ch > '9')

    {

        if(ch == '-') w = -1;

        ch = getchar();

    }

    while(ch >= '0' && ch <= '9')

    {

        s = s * 10 + ch - '0',

        ch = getchar();

    }

    return s * w;

}



int sgn(long double d){

    if(fabs(d) < eps)

        return 0;

    if(d > 0)

        return 1;

    return -1;

}



struct Point{

    long double x, y;

    Point(long double x = 0, long double y = 0):x(x),y(y){}

};



typedef Point Vector;



inline Vector operator - (Point A, Point B){

    return Vector(A.x-B.x, A.y-B.y);

}



inline long double Dot(Vector A, Vector B){

    return A.x*B.x + A.y*B.y;

}



long double Length(Vector A){

	return sqrt(Dot(A, A));

}



inline long double Cross(Vector A, Vector B){

    return A.x*B.y-A.y*B.x;

}



bool operator == (const Point& a, const Point& b){

	return !sgn(a.x - b.x) && !sgn(a.y - b.y);

}



long double DistanceToSegment(Point P, Point A, Point B)

{

    if(A == B) return Length(P - A);//������غ���ô����������֮��ľ��룬ֱ��ת����������뼴�ɣ�

    Vector v1 = B - A, v2 = P - A, v3 = P - B;

    if(sgn(Dot(v1, v2)) < 0) return Length(v2);//A�����

    if(sgn(Dot(v1, v3)) > 0)return Length(v3);//B���ұ�

    return fabs(Cross(v1, v2) / Length(v1));//���ߵľ���

}



int n,m,q;

long double w,h,x,y,r;

vector <Point> v[1000005];

long double area[1000005];

int main(){

	w=readdb();

	h=readdb();

	n=readint();

//	scanf("%lf %lf %d",&w,&h,&n);

	rep(i,0,n-1){

		m=readint();

//		scanf("%d",&m);

		rep(j,0,m-1){

			Point temp;

			temp.x=readdb();

			temp.y=readdb();

//			scanf("%lf %lf",&temp.x,&temp.y);

			v[i].push_back(temp);

		}

		long double t=0;

		rep(j,0,m-2){

			t+=Cross(v[i][j],v[i][j+1]);

		}

		t+=Cross(v[i][m-1],v[i][0]);

		area[i]=t/2;

	}

	q=readint();

//	scanf("%d",&q);

	rep(ca,1,q){

		Point o;

		o.x=readdb();

		o.y=readdb();

		r=readdb();

//		scanf("%lf %lf %lf",&o.x,&o.y,&r);

		long double ans=0;

		vector <int> id;

		id.clear();

		rep(i,0,n-1){

			int f=0;

			int wn=0;

			int nn=v[i].size();

			for(int j=0;j<nn;j++){

				if(o==v[i][j]){

					f=1;

					break;

				}

				int k=sgn(Cross(v[i][(j+1)%nn]-v[i][j],o-v[i][j]));

				int d1=sgn(v[i][j].y-o.y);

				int d2=sgn(v[i][(j+1)%nn].y-o.y);

				if(k > 0 && d1 <= 0 && d2 > 0) wn++;

        		if(k < 0 && d2 <= 0 && d1 > 0) wn--;

			}

			if(wn!=0) f=1;

			for(int j=0;j<v[i].size()-1;j++){

				if(sgn(DistanceToSegment(o,v[i][j],v[i][j+1])-r)<=0){

					f=1;

					break;

				}

			}

			

			if(sgn(DistanceToSegment(o,v[i][0],v[i][(int)v[i].size()-1])-r)<=0){

				f=1;

			}

			if(f){

				ans+=area[i];

				id.push_back(i);

			}

		}

		printf("%Lf %d",ans,(int)id.size());

		for(int i=0;i<id.size();i++){

			printf(" %d",id[i]);

		}

		puts("");

//		cout<<endl;

	}

	return 0;

}