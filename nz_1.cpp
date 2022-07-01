#include <iostream>
#include <fstream>
#include <cmath>
#include "nrlmsise-00.h"

double nz_1(double z){
    double nz_1;
    //double z_km = z*1.0e-3;
    nz_1 = pz(z)*288.15*ns_1/101325/Tz(z); 
    
    return nz_1;
}