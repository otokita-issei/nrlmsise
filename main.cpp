#include <iostream>
#include <fstream>
#include <cmath>
#include "optical_depth.h"

int main(void){
    double I0 = 1.0;
    double Delta = 0.0;
    double I = 0.0;  
    double h_max = z;
    double h_min = 0.0e3;
    double h_step = (h_max - h_min) / z_km;
    int N = z_km;

    //std::ofstream ofs640("optical_depth_640.dat");
    std::ofstream ofs470("optical_depth_470.dat");

    for(int i = N; i >= 0; i--){
        if(i <= N){
            double h = h_min + i*h_step; 
            Delta = Delta + integral(beta, h, h+h_step, 1000);
            //std::cout << i << " " <<integral(beta, h, h+h_step, 1000) << std::endl;
            //std::cout << i << " " << Tz(h) << " " << pz(h) << " " << Ns(h) << std::endl;
        }
        if(i >= N){
            Delta = 0.0;
        }
        I = I0*exp(-Delta);
        //ofs640 << I << " " << i << "\n";
        ofs470 << I << " " << i << "\n";
        }

    //ofs640.close();
    ofs470.close();

    return 0;
}

