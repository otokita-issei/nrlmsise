#include <iostream>
#include <cmath>
#include <fstream>
#include <nrlmsise-00.h>
#include "optical_depth.h"

void Tz_pz_Ns(double z, double &Tz, double &pz, double &Ns){
  Ap_array Xp;
  NRLMSISE_Output Output;
  NRLMSISE_Input Input;
  NRLMSISE_Flag Flag;

  /* 以下のパラメタは特に気にしなくて良い */
  /* 磁気指数。データはNASAあたりのWebサイトにあるが、標準的な値を使う */
  for(int i = 0; i < 7; i++){
    Xp.a[i] = 100.0;
  }

  /* 計算する機能を設定するフラグ */
  Flag.switches[0] = 0; /* 1 -> kg, m を使用, 0 -> g, cm を使用 */
  for(int i = 1; i < 24; i++){
    Flag.switches[i] = 1;
  }
  /* 以上のパラメタは特に気にしなくて良い */

  Input.year = 2019; /* 年は機能していないと思う */
  Input.doy = 172; /* Day of Year; 1月1日を1、2月1日を32、...、12月31日を365とする(除く閏年) */
  Input.sec = 43200; /* 0時0分を 0、23時59分を86400-1 */
  Input.lst = 21.0; /* [hours] local apparent solar time, lst = sec/3600 + g_long/15 にする */
  Input.f107A = 150.; /* F10.7フラックスの81日平均。標準的な値 */
  Input.f107 = 150.; /* 当日のF10.7フラックス。標準的な値 */
  Input.ap = 4.0; /* 磁気指数。標準的な値 */
  Input.ap_a = &Xp; /* 同上 */
  Input.g_lat = lat; /* [deg] 緯度 */
  Input.g_long = lng;/* [deg] 経度、西経は負 */

    double z_km = z*1.0e-3;
    Input.alt = z_km;
    gtd7(&Input, &Flag, &Output);

    double n = 0.0;
    for(int j = 0; j < 5; j++){
      n += Output.d[j];
    }
    n += Output.d[6] + Output.d[7]; 
    n = n*1.0e6;

    double p = n * kB * Output.t[1];

    Tz = Output.t[1];
    pz = p;
    Ns = n;
}





// double Tz(double z){
//   Ap_array Xp;
//   NRLMSISE_Input Input;
//   NRLMSISE_Flag Flag;
//   NRLMSISE_Output Output;
//   /* 以下のパラメタは特に気にしなくて良い */
//   /* 磁気指数。データはNASAあたりのWebサイトにあるが、標準的な値を使う */
//   for(int i = 0; i < 7; i++){
//     Xp.a[i] = 100.0;
//   }

//   /* 計算する機能を設定するフラグ */
//   Flag.switches[0] = 0; /* 1 -> kg, m を使用, 0 -> g, cm を使用 */
//   for(int i = 1; i < 24; i++){
//     Flag.switches[i] = 1;
//   }
//   /* 以上のパラメタは特に気にしなくて良い */

//   Input.year = 2019; /* 年は機能していないと思う */
//   Input.doy = 172; /* Day of Year; 1月1日を1、2月1日を32、...、12月31日を365とする(除く閏年) */
//   Input.sec = 43200; /* 0時0分を 0、23時59分を86400-1 */
//   Input.lst = 21.0; /* [hours] local apparent solar time, lst = sec/3600 + g_long/15 にする */
//   Input.f107A = 150.; /* F10.7フラックスの81日平均。標準的な値 */
//   Input.f107 = 150.; /* 当日のF10.7フラックス。標準的な値 */
//   Input.ap = 4.0; /* 磁気指数。標準的な値 */
//   Input.ap_a = &Xp; /* 同上 */
//   Input.g_lat = lat; /* [deg] 緯度 */
//   Input.g_long = lng;/* [deg] 経度、西経は負 */

//     double z_km = z*1.0e-3;
//     Input.alt = double(z_km);
//     gtd7(&Input, &Flag, &Output);

//     return Output.t[1];
// }

// double Ns(double z){
//   Ap_array Xp;
//   NRLMSISE_Input Input;
//   NRLMSISE_Flag Flag;
//   NRLMSISE_Output Output;
//   /* 以下のパラメタは特に気にしなくて良い */
//   /* 磁気指数。データはNASAあたりのWebサイトにあるが、標準的な値を使う */
//   for(int i = 0; i < 7; i++){
//     Xp.a[i] = 100.0;
//   }

//   /* 計算する機能を設定するフラグ */
//   Flag.switches[0] = 0; /* 1 -> kg, m を使用, 0 -> g, cm を使用 */
//   for(int i = 1; i < 24; i++){
//     Flag.switches[i] = 1;
//   }
//   /* 以上のパラメタは特に気にしなくて良い */

//   Input.year = 2019; /* 年は機能していないと思う */
//   Input.doy = 172; /* Day of Year; 1月1日を1、2月1日を32、...、12月31日を365とする(除く閏年) */
//   Input.sec = 43200; /* 0時0分を 0、23時59分を86400-1 */
//   Input.lst = 21.0; /* [hours] local apparent solar time, lst = sec/3600 + g_long/15 にする */
//   Input.f107A = 150.; /* F10.7フラックスの81日平均。標準的な値 */
//   Input.f107 = 150.; /* 当日のF10.7フラックス。標準的な値 */
//   Input.ap = 4.0; /* 磁気指数。標準的な値 */
//   Input.ap_a = &Xp; /* 同上 */
//   Input.g_lat = lat; /* [deg] 緯度 */
//   Input.g_long = lng;/* [deg] 経度、西経は負 */

//     double z_km = z*1.0e-3;
//     Input.alt = double(z_km);
//     gtd7(&Input, &Flag, &Output);

//     double n = 0.0;
//     for(int j = 0; j < 5; j++){
//       n += Output.d[j];
//     }
//     n += Output.d[6] + Output.d[7]; 
//     n = n*1.0e6;

//     return n;
// }

// double pz(double z){
//   Ap_array Xp;
//   NRLMSISE_Input Input;
//   NRLMSISE_Flag Flag;
//   NRLMSISE_Output Output;
//   constexpr double kB { BOLTZMANN_CONSTANT };
//   /* 以下のパラメタは特に気にしなくて良い */
//   /* 磁気指数。データはNASAあたりのWebサイトにあるが、標準的な値を使う */
//   for(int i = 0; i < 7; i++){
//     Xp.a[i] = 100.0;
//   }

//   /* 計算する機能を設定するフラグ */
//   Flag.switches[0] = 0; /* 1 -> kg, m を使用, 0 -> g, cm を使用 */
//   for(int i = 1; i < 24; i++){
//     Flag.switches[i] = 1;
//   }
//   /* 以上のパラメタは特に気にしなくて良い */

//   Input.year = 2019; /* 年は機能していないと思う */
//   Input.doy = 172; /* Day of Year; 1月1日を1、2月1日を32、...、12月31日を365とする(除く閏年) */
//   Input.sec = 43200; /* 0時0分を 0、23時59分を86400-1 */
//   Input.lst = 21.0; /* [hours] local apparent solar time, lst = sec/3600 + g_long/15 にする */
//   Input.f107A = 150.; /* F10.7フラックスの81日平均。標準的な値 */
//   Input.f107 = 150.; /* 当日のF10.7フラックス。標準的な値 */
//   Input.ap = 4.0; /* 磁気指数。標準的な値 */
//   Input.ap_a = &Xp; /* 同上 */
//   Input.g_lat = lat; /* [deg] 緯度 */
//   Input.g_long = lng;/* [deg] 経度、西経は負 */

//     double z_km = z*1.0e-3;
//     Input.alt = double(z_km);
//     gtd7(&Input, &Flag, &Output);

//     double n = 0.0;
//     for(int j = 0; j < 5; j++){
//       n += Output.d[j];
//     }
//     n += Output.d[6] + Output.d[7]; /* [cm^{-3}] */

//     double p = n*1.0e6 * kB * Output.t[1];

//     return p;
// }

// double Tz(double z){   /*気温の関数Tz*/
//     double Tz;
//     double z_km = z*1.0e-3;
//     if(0.0 <= z_km && z_km <= 11.0){
//           Tz = 273.15 + 15.04 - 6.49*z_km;  
//     }   
//     if(11.0 <= z_km && z_km <= 25.0){
//          Tz = 273.15 - 56.46;
//     }
//     if(25.0 <= z_km && z_km <= 45.0){
//          Tz = 273.15 - 131.21 + 2.99*z_km;
//     }
//     return Tz;
// }

// double pz(double z){   /*気圧の関数pz*/
//     double pz;
//     double z_km = z*1.0e-3;
//     if(0.0 <= z_km && z_km <= 11.0){  
//           pz = 101290*pow((Tz(z)/288.08), 5.256); 
//     }   
//     if(11.0 <= z_km && z_km <= 25.0){
//          pz = 22650*exp(1.73-0.157*z_km); 
//     }
//     if(25.0 <= z_km && z_km <= 45.0){
//          pz = 2488*pow((Tz(z)/216.6), -11.388);
//     }
//     return pz;
// }

// double Ns(double z){
//   double N = 2.547e25;
//   n = N*pz(z)*288.15/101325/Tz(z); 
//   return n;
// }
