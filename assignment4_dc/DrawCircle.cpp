#include<bits/stdc++.h>
using namespace std;

#define Abigail inline void
typedef long long LL;

const int N=200000;
const double INF=1e200;

int n;
struct point{
  double x,y;
}d[N+9],t[N+9];

bool cmp1(const point &a,const point &b){return a.x<b.x;}
bool cmp2(const point &a,const point &b){return a.y<b.y;}

double sqr(double x){return x*x;}
double Get_dis(point a,point b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}

double Divide(point *d,int L,int R){
  if (L==R) return INF;
  int mid=L+R>>1,tt=0;
  double res=min(Divide(d,L,mid),Divide(d,mid+1,R));
  for (int i=L;i<=R;++i)
    if (abs(d[i].x-d[mid].x)<=res) t[++tt]=d[i];
  sort(t+1,t+1+tt,cmp2);
  for (int i=1;i<=tt;++i)
    for (int j=i+1;j<=tt&&t[j].y-t[i].y<res;++j)
      res=min(res,Get_dis(t[i],t[j]));
  return res;
}

double Solve(point *d,int n){
  sort(d+1,d+1+n,cmp1);
  return Divide(d,1,n);
}

Abigail into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
    scanf("%lf%lf",&d[i].x,&d[i].y);
}

Abigail outo(){
  printf("%.3lf\n",Solve(d,n)/2);
}

int main(){
  into();
  outo();
  return 0;
}
