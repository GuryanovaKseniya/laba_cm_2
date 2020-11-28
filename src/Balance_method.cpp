#include "Balance_method.h"
//This file contains balance algorithm and the functions needed by this algorithm.

using std::cout;


double integrate_func(double left, double right, double(*func)(double))
{
	return ((func(left) + func(right)) / 2) * (right - left);
}

void create_coeff(double beg, double end, vector<double> &coeff, double h)
{
	coeff.resize(0);
	double i = beg;
	for (i = beg; (i + h) < ksi; i += h)
	{
		coeff.push_back((1 / h) * (1 / integrate_func(i, i + h, k1)));
	}
	coeff.push_back((1 / h) * (1 / (integrate_func(i, ksi, k1) + integrate_func(ksi, i + h, k2) ) ) );
	i += h;
	for (i; i < x1; i += h)
	{
		coeff.push_back((1 / h) * (1 / integrate_func(i, i + h, k2)));
	}
}

vector<vector <double>> balance_method(int n, double h)
{
	vector<vector <double>> answer;
	vector<double> a, d, phi;
	create_coeff(x0, x1, a, h);
	create_coeff(x0 + h * 0.5, x1, d, h);
	create_coeff(x0 + h * 0.5, x1, phi, h);
	answer.resize(n);
	for (int i = 0; i < answer.size(); i++)
	{
		answer[i].resize(n + 1);
		for (int j = 0; j < answer[i].size(); j++)
			answer[i][j] = 0;
	}
	int i; 
	answer[0][0] = 1;
	answer[0][1] = -(a[1] / (a[0] + a[1] + d[0] * h * h));
	answer[0][n] = (h * h * phi[0] + mu1 * a[0]) / (a[0] + a[1] + d[0] * h * h);
	for (i = 1; i < n - 1; i++)
	{
		answer[i][i - 1] = a[i - 1] / (h * h);
		answer[i][i] = -( (a[i - 1] + a[i]) / (h * h) + d[i - 1]);
		answer[i][i + 1] = a[i] / (h * h);
		answer[i][n] = -phi[i - 1];
	}
	answer[n - 1][n - 2] = -(a[n - 2] / (a[n - 2] + a[n - 1] + d[n - 2] * h * h));
	answer[n - 1][n - 1] = 1;
	answer[n - 1][n] = (phi[n - 2] * h * h + mu2 * a[n - 1]) / (a[n - 2] + a[n - 1] + d[n - 2] * h * h);
	return answer;
};
