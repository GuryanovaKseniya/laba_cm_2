#include "Func_for_lab.h"
#include <gtest.h>
#include <iomanip>


using std::cout;
using std::ios;

void print_matrix(vector<vector <double>> &matrix)
{
	cout << "\n";
	for (int i = 0; i < matrix.size(); i++)
	{
		cout.setf(ios::fixed);
		cout.precision(6);
		for (int j = 0; j < matrix[i].size(); j++)
			cout << std::setw(15)  << matrix[i][j];
		cout << '\n';
	}
}

TEST(balace_method, integration_cause_no_error_with_simple_func)
{
	ASSERT_NO_THROW(cout << integrate_func(0, 0.5, k1) << '\n');
}

TEST(balace_method, integration_cause_no_error_with_difficult_func)
{
	ASSERT_NO_THROW(cout << integrate_func(0, 0.01, f2) << '\n');
}

TEST(balance_method, balance_method_cause_no_error_with_simple_task)
{
	vector<vector <double>> test = balance_method(5, 0.2);
	ASSERT_NO_THROW(print_matrix(test));
}
