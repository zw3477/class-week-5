// xll_template.h - common includes
#pragma once
// Uncomment to build for pre 2007 Excel
//#define XLOPERX XLOPER
#include "xll/xll/xll.h"

// Black Model F = f exp(sZ - s*2/2), Z standard normal
// put value E[(k - f)^+] = E[(k - f) 1(F <= k)]
//                        = k E[1(F <= k)] - E[F 1(F <= k)]
//						  = k P(F <= k) - E[F] E[1(F exp(s^2) <= k)]
//						  = k P(Z <= m) - f E[1(F <= k exp(-s^2))]
//						  = k P(Z <= m) - f E[1(Z <= m')]

// F <= k iff Z <= log(k/f)/s - s/2

double moneyness(double f, double s, double k)
{
	return log(k / f) / s - s / 2;
}

double put_value(double f, double s, double x)
{
	double m = mopneyness(f, s, k);

	return k = normaldistinv(m) - f * normainv(m - s);
}