#include <iostream>
#include <fstream>
#include <cmath>
#include "optical_depth.h"

double beta(double z){     
    double Nz, Sig, Tz, pz, Ns;
      Tz_pz_Ns(z, Tz, pz, Ns);
      Nz = Ns;      /*数密度*/
      Sig = 24*M_PI*M_PI*M_PI/Lam/Lam/Lam/Lam/Nz/Nz*(nz_1(z)*(nz_1(z)+2)/(nz_1(z)*nz_1(z)+2*nz_1(z)+3))*(nz_1(z)*(nz_1(z)+2)/(nz_1(z)*nz_1(z)+2*nz_1(z)+3));    /*全散乱断面積*/

     return Nz*Sig;    
}