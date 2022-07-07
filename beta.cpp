#include <iostream>
#include <fstream>
#include <cmath>
#include "optical_depth.h"

// constexpr double Lam {0.47e-6};        /*波長*/
// double Tz(double z);
// double pz(double z);
// double Ns(double z);
// double nz_1(double z);

double beta(double z){     
    double Nz, Sig;
      Nz = Ns(z);      /*数密度*/
      Sig = 24*M_PI*M_PI*M_PI/Lam/Lam/Lam/Lam/Nz/Nz*(nz_1(z)*(nz_1(z)+2)/(nz_1(z)*nz_1(z)+3))*(nz_1(z)*(nz_1(z)+2)/(nz_1(z)*nz_1(z)+3));    /*全散乱断面積*/

     return Nz*Sig;    
}