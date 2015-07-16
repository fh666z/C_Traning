/*
 * Ex7.hpp
 *
 *  Created on: 1.06.2015 ã.
 *      Author: Momchil
 */

#ifndef EX7_HPP_
#define EX7_HPP_


// https://developers.google.com/edu/c++/getting-started

#include <iostream>

class SalaryCalc
{
private:
	unsigned m_sales_per_week;
	double   m_pair_value;
	struct
	{
		double const_salary;
	}m_method_1_params;

	struct
	{
		double usd_per_hour;
		double percentage_of_sales;
		double hours_per_week;
	}m_method_2_params;

	struct
	{
		double percentage_of_sales;
		double bonus_per_pair;
	}m_method_3_params;

public:
	SalaryCalc();
	SalaryCalc(unsigned sales);
	~SalaryCalc();

	void SetSalesPerWeek(unsigned sales) { m_sales_per_week = sales;}

	double CalcMethod1(void);
	double CalcMethod2(void);
	double CalcMethod3(void);
};

void Ex7_test(void);

#endif /* EX7_HPP_ */
