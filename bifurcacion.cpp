#include <iostream>
#include <cmath>
#include <stdlib.h>
#include<fstream>
const double G=9.8;
const double dt=0.01;
const double eps=0.001;
class Pendulum
{
public:
  double L; 
  double q; 
  double Fd; 
  double Omega; 
  double W; 
  double Theta; 
  Pendulum();
  ~Pendulum();
};
Pendulum::Pendulum()
{
  L=0.0;
  q=0.0;
  Fd=0.0;
  Omega=0.0;
  W=0.0;
  Theta=0.0;
}
Pendulum::~Pendulum()
{
}
void initial_conditions(Pendulum & p);
void euler_cromer(Pendulum & p,double dt,double t);
int main(int argc, char** argv)
{
  Pendulum p;
  double tm=0.0;
  double Fdmaximo = 1.5;
  double t=0.0;
  int N=atoi(argv[1]);
  initial_conditions(p);
  int NumFd=1000;
  double dervFd=(Fdmaximo-p.Fd)/NumFd;
  
  for (int jj=0; jj<=NFd; jj++)
  {
    for (int ii=1; ii<=N; ii++)
    {
      t+=dt;
      t_modulo+=dt;
      euler_cromer(p,dt,t);
      if(tm>3*M_PI){
          tm=0;
          std::cout << p.Fd << "\t" << p.Theta << std::endl;
      }
    }
    p.Fd+=dervFd;
  }
  return 0;
}
void euler_cromer(Pendulum & p,double dt,double t)
{
  p.W=p.W+(-(G/p.L)*sin(p.Theta) - p.q*p.W + p.Fd*sin(p.Omega*t))*dt;
  p.Theta=p.Theta + p.W*dt;
  if(p.Theta < - M_PI)
    {
      p.Theta += 2*M_PI;
    }
  else if(p.Theta > M_PI)
    {
      p.Theta += -2*M_PI;
    }
} 
 
void initial_conditions(Pendulum & p)
{
  p.q=0.5;
  p.Fd=1.35;
  p.Omega=0.666;
  p.L=G;
  p.W=0.0;
  p.Theta=0.2;  
}