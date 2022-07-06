#include <iostream>
#include <fstream>
#include <cmath>
#include "optical_depth.h"

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