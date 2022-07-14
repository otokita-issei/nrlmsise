
constexpr double Lam {0.47e-6};        /*波長*/
constexpr double Lam_um {Lam*1.0e6};  
constexpr double ns_1 {(8060.51 + 2480990/(132.274 - 1/Lam_um/Lam_um) + 17445.7/(39.32957 - 1/Lam_um/Lam_um))*1.0e-8};       /*真空中の屈折率(n-1)*/
constexpr double z {100.0e3};    /*高度*/
constexpr double z_km {z*1.0e-3};
constexpr double BOLTZMANN_CONSTANT { 1.38064852e-23 };
constexpr double kB { BOLTZMANN_CONSTANT };
constexpr double lat {40};  /*緯度*/
constexpr double lng {0}; /*経度*/

/* NRL-MSISE00の入出力用 */
using Ap_array = struct ap_array;
using NRLMSISE_Input = struct nrlmsise_input;
using NRLMSISE_Flag = struct nrlmsise_flags;
using NRLMSISE_Output = struct nrlmsise_output;

double nz_1(double z);
double beta(double z);
double integral(double(*beta)(double), double xmin, double xmax, int N);
void Tz_pz_Ns(double z, double &Tz, double &pz, double &Ns);



