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
double k1(double x) { return (x + 1); }
double k2(double x) { return x; }
double q1(double x) { return x; }
double q2(double x) { return x * x; }
double f1(double x) { return x; }
double f2(double x) { return exp(-x); }

#endif