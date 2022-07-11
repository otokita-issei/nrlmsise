#include <iostream>
#include <fstream>
#include <cmath>
#include "optical_depth.h"

constexpr double z {45.0e3};    /*高度*/
constexpr double z_km {z*1.0e-3};
// double beta(double z);
// double integral(double(*beta)(double), double xmin, double xmax, int N);

int main(void){
    double I0 = 1.0;
    double Delta = 0.0;
    double I = 0.0;  
    double h_max = z;
    double h_min = 0.0e3;
    double h_step = (h_max - h_min) / z_km;
    int N = z_km;

    std::ofstream ofs("lat85_long90_470.dat");

    for(int i = N; i >= 0; i--){
        if(i <= N){
            double h = h_min + i*h_step; 
            Delta = Delta + integral(beta, h, h+h_step, 1000);
            //std::cout << i << " " <<integral(beta, h, h+h_step, 1000) << std::endl;
            //std::cout << i << " " << Ns(h) << std::endl;
        }
        if(i >= N){
            Delta = 0.0;
        }
        I = I0*exp(-Delta);
        ofs << I << " " << i << "\n";
        }

    ofs.close();

    return 0;
}

