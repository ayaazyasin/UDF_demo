/* Parabolic inlet velocity profile
   Centerline at y = 0, half-width h = 0.05 m
   U_in = 0.001 m/s  =>  U_max = 1.5 * U_avg = 0.015 m/s     */

#include "udf.h"

DEFINE_PROFILE(inletProfile, thread, index)
{
    real x[ND_ND];
    real y;
    real h    = 0.05;          //half channel width [m]
    real Umax = 0.0015;       //centerline velocity [m/s]
    face_t f;

    begin_f_loop(f, thread)
    {
        F_CENTROID(x, f, thread);
        y = x[1];
	
        /* Poiseuille: U(y) = Umax * (1 - (y/h)^2) */
        F_PROFILE(f, thread, index) = Umax * (1.0 - pow(y / h, 2.0));
    }
    end_f_loop(f, thread)
}