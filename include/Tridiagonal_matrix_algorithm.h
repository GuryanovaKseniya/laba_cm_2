#pragma once
#ifndef __Tridiagonal_matrix_algorithm_H__
#define __Tridiagonal_matrix_algorithm_H__
#include "Simple_func.h"
//This file contains tridiagonal matrix algorithm and the functions needed by this algorithm.

using std::vector;


vector<double> tridiagonal_matrix_algorithm(vector <vector <double>> &coeff_matrix_vi); //maybe 2 vector(coeff_matrix_ABC, coeff_Phi)

#endif