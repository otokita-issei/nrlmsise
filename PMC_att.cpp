#include <iostream>
#include <fstream>
#include <cmath>

constexpr double Ns {2.547e25};     /*数密度*/
constexpr double Lam {0.38e-6};        /*波長*/
constexpr double Lam_um {Lam*1.0e6};  
constexpr double ns_1 {(8060.51 + 2480990/(132.274 - 1/Lam_um/Lam_um) + 17445.7/(39.32957 - 1/Lam_um/Lam_um))*1.0e-8};       /*真空中の屈折率(n-1)*/
constexpr double z {110.0e3};    /*高度*/
constexpr double z_km {z*1.0e-3};


double Tz(double z){   /*気温の関数Tz*/
    double Tz;
    double z_km = z*1.0e-3;
    if(0.0 <= z_km && z_km <= 11.0){
          Tz = 273.15 + 15.04 - 6.49*z_km;  
    }   
    if(11.0 <= z_km && z_km <= 25.0){
         Tz = 273.15 - 56.46;
    }
    if(25.0 <= z_km && z_km <= 45.0){
         Tz = 273.15 - 131.21 + 2.99*z_km;
    }
    return Tz;
}

double pz(double z){   /*気圧の関数pz*/
    double pz;
    double z_km = z*1.0e-3;
    if(0.0 <= z_km && z_km <= 11.0){  
          pz = 101290*pow((Tz(z)/288.08), 5.256); 
    }   
    if(11.0 <= z_km && z_km <= 25.0){
         pz = 22650*exp(1.73-0.157*z_km); 
    }
    if(25.0 <= z_km && z_km <= 45.0){
         pz = 2488*pow((Tz(z)/216.6), -11.388);
    }
    return pz;
}

double nz_1(double z){
    double nz_1;
    double z_km = z*1.0e-3;
    //if(0.0 <= z_km && z_km <= 11.0){  
    nz_1 = pz(z)*288.15*ns_1/101325/Tz(z); 
    //}   
    //if(11.0 <= z_km && z_km <= 25.0){
    //    nz_1 = pz(z)*288.15*ns_1/101325/Tz(z);
    //}
    //if(25.0 <= z_km && z_km <= 45.0){
    //    nz_1 = pz(z)*288.15*ns_1/101325/Tz(z);
    //}
    return nz_1;
}

double beta(double z){     
    double Nz, Sig;
      Nz = Ns*pz(z)*288.15/101325/Tz(z);      /*数密度*/
      Sig = 24*M_PI*M_PI*M_PI/Lam/Lam/Lam/Lam/Nz/Nz*(nz_1(z)*(nz_1(z)+2)/(nz_1(z)*nz_1(z)+3))*(nz_1(z)*(nz_1(z)+2)/(nz_1(z)*nz_1(z)+3));    /*全散乱断面積*/

     return Nz*Sig;    
}

double integral(double(*beta)(double), double xmin, double xmax, int N){     
        double dx = 0.0;
        double y = 0.0;
        double S = 0.0;
        dx = (xmax - xmin) / N;
        for (int i = 0; i < N; i++){
        y = (((*beta)(xmin + dx*i) + (*beta)(xmin + dx*(i+1))) / 2.0) * dx;
        S = S + y;
        }
        return S;
    }

int main(void){
    double I0 = 1.0;
    double Delta = 0.0;
    double I;
    double h_max = z;
    double h_min = 0.0e3;
    double h_step = (h_max - h_min) / z_km;
    int N = z_km;

    std::ofstream ofs("PMC.dat");

    for(int i = N; i >= 0; i--){
        //if(i <= 45){
        double h = h_min + i*h_step; 
        Delta = Delta + integral(beta, h, h+h_step, 1000);
        //}
        //if(i >= 45){
        //    Delta = 0.0;
        //}
        I = I0*exp(-Delta);
        ofs << I << " " << i << "\n";
        }
        
    ofs.close();

    return 0;
}
