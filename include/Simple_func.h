#pragma once
#ifndef __Simple_func_H__
#define __Simple_func_H__
//This file contains simple functions needed by all algorithms of the program.( Google Translate =) )


#include <vector>
#include <cmath>
#include <iostream>


const double ksi = 0.4;
const double mu1 = 0;
const double mu2 = 1;
const double x0 = 0;
const double x1 = 1;
inline double k1(double x) { return (x + 1); }
inline double k2(double x) { return x; }
inline double q1(double x) { return x; }
inline double q2(double x) { return x * x; }
inline double f1(double x) { return x; }
inline double f2(double x) { return exp(-x); }

#endif