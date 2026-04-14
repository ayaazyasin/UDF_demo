/* Gaussian volumetric heat source
   Centerline at y = 0, half-width h = 0.05 m
   Q0    = 10000 W/m^3
   (x0,y0) = (0.5, 0.04) m  -- near top wall
   sigma = 0.05 m                                              */

#include "udf.h"

DEFINE_SOURCE(gaussian_heat_source, cell, thread, dS, eqn)
{
    real x[ND_ND];
    real Q0    = 1e7;
    real x0    = 0.1;
    real y0    = 0.04;      
    real sigma = 0.05;
    real source;

    C_CENTROID(x, cell, thread);

    source = Q0 * exp(-(pow(x[0] - x0, 2.0) + pow(x[1] - y0, 2.0)) / (2.0 * sigma * sigma));

    dS[eqn] = 0.0;

    return source;
}