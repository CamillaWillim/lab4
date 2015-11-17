#include <iostream>
#include <cmath>

using namespace std;

void fillarray(int N, const double xmax, const double xmin, const double dx, double* f);
void print(double* p, const int N, const double dx,const double xmin);
void deriva(int N, const double dx, double* f);


int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  fillarray(N,xmax,xmin,dx,p);
  deriva(N,dx,p);
  print(p,N,dx,xmin);
  

  return 0;
}

void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void fillarray(int N, const double xmax, const double xmin, const double dx, double* f){
  double x=xmin;
  for(int i=0; i<N; i++){
    f[i]=exp(-pow(x,2));
    x+=dx;
  }
}

void deriva(int N, const double dx, double* f){
  double falt;
  double fs;
  f[0]=f[1]/(2*dx);
  f[N-1]=-f[N-2]/(2*dx);
  falt = f[0];
  for(int i=1; i<N-1; i++){
    fs=(f[i+1]-falt)/(2*dx);
    falt = f[i];
    f[i]=fs;
  }
}
    
