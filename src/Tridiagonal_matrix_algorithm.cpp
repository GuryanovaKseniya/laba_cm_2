#include "Tridiagonal_matrix_algorithm.h"
//This file contains tridiagonal matrix algorithm and the functions needed by this algorithm.


vector<double> tridiagonal_matrix_algorithm(vector <vector <double>> &coeff_matrix_vi)
{
	int n = coeff_matrix_vi.size();
	vector <double> answer(n);
	vector <double> alfa(n - 1);
	vector <double> beta(n - 1);
	alfa[0] = -coeff_matrix_vi[0][1];
	beta[0] = coeff_matrix_vi[0][coeff_matrix_vi[0].size() - 1];
	for (int i = 0; i < alfa.size() - 1; i++)
	{
		alfa[i + 1] = coeff_matrix_vi[i + 1][i + 2] / (-coeff_matrix_vi[i + 1][i + 1] - coeff_matrix_vi[i + 1][i] * alfa[i]);
		beta[i + 1] = (-coeff_matrix_vi[i + 1][coeff_matrix_vi[i + 1].size() - 1] + coeff_matrix_vi[i + 1][i] * beta[i]) / (-coeff_matrix_vi[i + 1][i + 1] - coeff_matrix_vi[i + 1][i] * alfa[i]);
	}
	answer[n - 1] = (coeff_matrix_vi[n - 1][coeff_matrix_vi[n - 1].size() - 3] * beta[beta.size() - 1] - coeff_matrix_vi[n - 1][coeff_matrix_vi[n - 1].size() - 1]) / (-coeff_matrix_vi[n - 1][coeff_matrix_vi[n - 1].size() - 3] * alfa[alfa.size() - 1] - 1);
	for (int i = n - 2; i >= 0; i--)
	{
		answer[i] = alfa[i] * answer[i + 1] + beta[i];
	}
	
	return answer;
};