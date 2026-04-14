/* Temperature-dependent viscosity: exponential (Arrhenius-type)
   mu(T) = mu_ref * exp(-beta * (T - T_ref))
   mu_ref = 0.001 Pa.s,  T_ref = 300 K,  beta = 0.02 1/K      */

#include "udf.h"

DEFINE_PROPERTY(viscosityTemp, cell, thread)
{
    real T;
    real mu_ref = 0.001;
    real T_ref  = 300.0;
    real beta   = 0.02;
    real mu;

    T  = C_T(cell, thread);
    mu = mu_ref * exp(-beta * (T - T_ref));

    return mu;
}