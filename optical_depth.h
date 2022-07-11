/* -------------------------------------------------------------------- */
/* ---------  N R L M S I S E - 0 0    M O D E L    2 0 0 1  ---------- */
/* -------------------------------------------------------------------- */

/* This file is part of the NRLMSISE-00  C source code package - release
 * 20041227
 *
 * The NRLMSISE-00 model was developed by Mike Picone, Alan Hedin, and
 * Doug Drob. They also wrote a NRLMSISE-00 distribution package in 
 * FORTRAN which is available at
 * http://uap-www.nrl.navy.mil/models_web/msis/msis_home.htm
 *
 * Dominik Brodowski implemented and maintains this C version. You can
 * reach him at mail@brodo.de. See the file "DOCUMENTATION" for details,
 * and check http://www.brodo.de/english/pub/nrlmsise/index.html for
 * updated releases of this package.
 */

// constexpr double Lam {0.47e-6};        /*波長*/
// constexpr double Lam_um {Lam*1.0e6};  
// constexpr double ns_1 {(8060.51 + 2480990/(132.274 - 1/Lam_um/Lam_um) + 17445.7/(39.32957 - 1/Lam_um/Lam_um))*1.0e-8};       /*真空中の屈折率(n-1)*/
// constexpr double z {110.0e3};    /*高度*/
// constexpr double z_km {z*1.0e-3};

double Tz(double z);
double pz(double z);
double Ns(double z);
double nz_1(double z);
double beta(double z);
double integral(double(*beta)(double), double xmin, double xmax, int N);

//constexpr double BOLTZMANN_CONSTANT { 1.38064852e-23 };

