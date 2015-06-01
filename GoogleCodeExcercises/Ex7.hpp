/*
 * Ex7.hpp
 *
 *  Created on: 1.06.2015 �.
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

public:
	SalaryCalc() {m_sales_per_week = 0;}
	SalaryCalc(unsigned sales):m_sales_per_week(sales){}
	~SalaryCalc() { }

	void SetSalesPerWeek(unsigned sales) { m_sales_per_week = sales;}

	double CalcMethod1(void);
	double CalcMethod2(void);
	double CalcMethod3(void);
};

void Ex7_test(void);

#endif /* EX7_HPP_ */
