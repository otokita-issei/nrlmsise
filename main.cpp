#include <iostream>
#include <fstream>
#include <cmath>
#include "nrlmsise-00.h"

int main(void){
    double I0 = 1.0;
    double Delta, I;  
    double h_max = z;
    double h_min = 0.0e3;
    double h_step = (h_max - h_min) / z_km;
    int N = z_km;

    std::ofstream ofs("optical_depth.dat");

    for(int i = N; i >= 0; i--){
        double h = h_min + i*h_step; 
        Delta = Delta + integral(beta, h, h+h_step, 1000);
        I = I0*exp(-Delta);
        ofs << I << " " << i << "\n";
        }

    ofs.close();

    return 0;
}
