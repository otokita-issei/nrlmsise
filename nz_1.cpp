#include <iostream>
#include <fstream>
#include <cmath>
#include "optical_depth.h"

double nz_1(double z){
    double nz_1, Tz, pz, Ns;
    Tz_pz_Ns(z, Tz, pz, Ns);
    nz_1 = pz*288.15*ns_1/101325/Tz; 
    
    return nz_1;
}