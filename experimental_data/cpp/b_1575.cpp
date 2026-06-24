#include<bits/stdc++.h>

using namespace std;

const double eps=1e-6;



int n,m;

int qq[1000010],cnt;

bool qq2[1000010],qq3[1000010];

struct node{

	double x,y,z,s;

}a[100010];



vector <pair<double,int> > ve1,ve2;

vector <pair<double,int> >::iterator it;



bool cmp1(pair<double,int> s1,pair<double,int> s2)

{

	return s1.first<s2.first;

}



bool cmp2(pair<double,int> s1,pair<double,int> s2)

{

	return s1.first>s2.first;

}



int main()

{

	scanf("%d%d",&n,&m);

	for (int i=1;i<=n;i++)

	{

		scanf("%lf%lf",&a[i].x,&a[i].y);

		if (a[i].x==0&&a[i].y==0) m--;

		if (a[i].y!=0)

			a[i].z=-a[i].x/a[i].y;

		else a[i].z=1e18;

//		cout<<a[i].x<<"   "<<a[i].y<<endl;

		a[i].s=a[i].x*a[i].x+a[i].y*a[i].y;

		double x=a[i].x/2,y=a[i].y/2;

	}

	if (m<=0)

	{

		puts("0.00000000000000000000000000000000000000000");

		return 0;

	}

	double l=0.0,r=200000.0;

	while (r-l>eps)

	{

		ve1.clear();

		ve2.clear();

		cnt=0;

		double mid=(l+r)/2;

		for (int i=1;i<=n;i++)

		{

			qq3[i]=0;

			if (a[i].s<=mid*4*mid&&(a[i].x||a[i].y))

			{

				if (a[i].y==0)

				{

					if  (a[i].x>0)

					{

						double x=a[i].x/2;

						ve1.push_back(make_pair(x,++cnt));

						qq[cnt]=i;

//						qq3[cnt]=0;

						qq2[cnt]=1;

						ve2.push_back(make_pair(x,++cnt));

						qq[cnt]=i;

//						qq3[cnt]=0;

						qq2[cnt]=0;

					}

					else

					{

						double x=a[i].x/2;

						ve1.push_back(make_pair(x,++cnt));

						qq[cnt]=i;

//						qq3[cnt]=0;

						qq2[cnt]=0;

						ve2.push_back(make_pair(x,++cnt));

						qq[cnt]=i;

						qq2[cnt]=1;

//						qq3[cnt]=0;

					}

					continue;

				}

//				cout<<a[i].s<<endl;

				double ss=sqrt(mid*mid-a[i].s/4);

//				cout<<ss<<"   "<<a[i].z<<endl;

				double x=a[i].x/2,y=a[i].y/2;

				double dou=sqrt(1+a[i].z*a[i].z);

				double dd=ss/dou;

				

				if (a[i].y>0)

				{

					double xxx=x-dd,yyy=y-dd*a[i].z;

					if (yyy>=0)

					{

						ve1.push_back(make_pair(xxx,++cnt));

						qq[cnt]=i;

//						qq3[cnt]=0;

						qq2[cnt]=1;

					}

					else

					{

						ve2.push_back(make_pair(xxx,++cnt));

						qq[cnt]=i;

//						qq3[cnt]=0;

						qq2[cnt]=1;

					}

//					cout<<xxx<<"  "<<yyy<<endl;

					xxx=x+dd,yyy=y+dd*a[i].z;

					if (yyy>=0)

					{

						ve1.push_back(make_pair(xxx,++cnt));

						qq[cnt]=i;

//						qq3[cnt]=0;

						qq2[cnt]=0;

//						cout<<"#@$%^&*("<<cnt<<"   "<<qq2[cnt]<<endl;

					}

					else

					{

						ve2.push_back(make_pair(xxx,++cnt));

						qq[cnt]=i;

//						qq3[cnt]=0;

						qq2[cnt]=0;

					}

//					cout<<xxx<<"  "<<yyy<<endl;

					

				}

				else

				{

					double xxx=x-dd,yyy=y-dd*a[i].z;

					if (yyy>=0)

					{

						ve1.push_back(make_pair(xxx,++cnt));

						qq[cnt]=i;

//						qq3[cnt]=0;

						qq2[cnt]=0;

					}

					else

					{

						ve2.push_back(make_pair(xxx,++cnt));

						qq[cnt]=i;

						qq2[cnt]=0;

//						qq3[cnt]=0;

					}

//					cout<<xxx<<"  "<<yyy<<endl;

					xxx=x+dd,yyy=y+dd*a[i].z;

					if (yyy>=0)

					{

						ve1.push_back(make_pair(xxx,++cnt));

						qq[cnt]=i;

//						qq3[cnt]=0;

						qq2[cnt]=1;

					}

					else

					{

						ve2.push_back(make_pair(xxx,++cnt));

						qq[cnt]=i;

						qq2[cnt]=1;

//						qq3[cnt]=0;

					}

//					cout<<xxx<<"  "<<yyy<<endl;

				}

			}

		}

		sort(ve1.begin(),ve1.end(),cmp1);

		sort(ve2.begin(),ve2.end(),cmp2);

		int ww=0;

		bool bo=0;

		for (it=ve1.begin();it!=ve1.end();it++)

		{

			pair<double,int> pa=*it;

			int t=pa.second;

			if (qq2[t])

			{

				ww++;

				qq3[qq[t]]=1;

			}

			else

			{

				if (qq3[qq[t]]) ww--;

			}

			if (ww>=m)

			{

				bo=1;

			}

//			cout<<t<<"   "<<pa.first<<"   "<<qq[t]<<"  "<<qq[qq[t]]<<"   "<<ww<<"   "<<qq2[t]<<endl;

		}

		for (it=ve2.begin();it!=ve2.end();it++)

		{

			pair<double,int> pa=*it;

			int t=pa.second;

			if (qq2[t])

			{

				ww++;

				qq3[qq[t]]=1;

			}

			else

			{

				if (qq3[qq[t]]) ww--;

			}

			if (ww>=m)

			{

				bo=1;

			}

//			cout<<t<<"   "<<pa.first<<"   "<<qq[t]<<"  "<<qq[qq[t]]<<"   "<<ww<<"   "<<qq2[t]<<endl;

		}

		for (it=ve1.begin();it!=ve1.end();it++)

		{

			pair<double,int> pa=*it;

			int t=pa.second;

			if (qq2[t])

			{

				ww++;

				qq3[qq[t]]=1;

			}

			else

			{

				if (qq3[qq[t]]) ww--;

			}

			if (ww>=m)

			{

				bo=1;

			}

//			cout<<t<<"   "<<pa.first<<"   "<<qq[t]<<"  "<<qq[qq[t]]<<"   "<<ww<<"   "<<qq2[t]<<endl;

		}

		for (it=ve2.begin();it!=ve2.end();it++)

		{

			pair<double,int> pa=*it;

			int t=pa.second;

			if (qq2[t])

			{

				ww++;

				qq3[qq[t]]=1;

			}

			else

			{

				if (qq3[qq[t]]) ww--;

			}

			if (ww>=m)

			{

				bo=1;

			}

//			cout<<t<<"   "<<pa.first<<"   "<<qq[t]<<"  "<<qq[qq[t]]<<"   "<<ww<<"   "<<qq2[t]<<endl;

		}

		if (bo) r=mid;

		else l=mid;

//		cout<<bo<<endl;

	}

	double mid=(l+r)/2;

	printf("%.8lf",mid);

	return 0;

}