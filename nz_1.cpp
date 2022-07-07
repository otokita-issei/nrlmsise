#include <iostream>
#include <fstream>
#include <cmath>
#include "optical_depth.h"

// constexpr double Lam {0.47e-6};        /*波長*/
// constexpr double Lam_um {Lam*1.0e6};  
// constexpr double ns_1 {(8060.51 + 2480990/(132.274 - 1/Lam_um/Lam_um) + 17445.7/(39.32957 - 1/Lam_um/Lam_um))*1.0e-8}; 
// double Tz(double z);
// double pz(double z);

double nz_1(double z){
    double nz_1;
    //double z_km = z*1.0e-3;
    nz_1 = pz(z)*288.15*ns_1/101325/Tz(z); 
    
    return nz_1;
}