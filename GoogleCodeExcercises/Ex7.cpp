/*
 * Ex7.cpp
 *
 *  Created on: 1.06.2015 �.
 *      Author: Momchil
 */
#include "Ex7.hpp"
#include <list>

using namespace std;


// ------===== Shoe Shop ======------
// Shoe pair: $225
#define PAIR_VALUE                  225
//
// ------===== Methods ======------
// Method 1:
//    $600 per week
#define STRAIGHT_SALARY             600

// Methond 2:
//    $7 per hour + 10% of sales
#define DOLARS_PER_HOUR             7
#define M2_PERCENT_OF_SALES			.1
#define HOURS_PER_WEEK              40

// Methond 3:
//    20% of sales + $20 per pair
#define M3_PERCENT_OF_SALES         .2
#define M3_BONUS_PER_PAIR           20


double SalaryCalc::CalcMethod1(void)
{
    return (double)STRAIGHT_SALARY;
}

double SalaryCalc::CalcMethod2(void)
{
    return (double)(HOURS_PER_WEEK * DOLARS_PER_HOUR + m_sales_per_week * M2_PERCENT_OF_SALES * PAIR_VALUE);
}

double SalaryCalc::CalcMethod3(void)
{
    return (double)(m_sales_per_week * (M3_PERCENT_OF_SALES * PAIR_VALUE + M3_BONUS_PER_PAIR));
}

template <class ValueType>
unsigned index_of_max_value(list<ValueType> values_list, ValueType &value)
{
	unsigned abs_position = 0;
    ValueType max_value = values_list.front();
    typename list<ValueType>::iterator list_iter;
    for (list_iter = values_list.begin(); list_iter != values_list.end(); ++list_iter)
        if (*list_iter > max_value)
        {
            max_value = *list_iter;
            abs_position = std::distance(values_list.begin(), list_iter);
        }

    value = max_value;
    // abs_position -> zero based converted to one based
    return abs_position + 1;
}


void Ex7_test(void)
{
    list<double> methods_lst;

    SalaryCalc salary_calc;
#if 0
    SalaryCalc salary_calc(8);
    cout << "Sales per week: " << sales << endl;

    double calc = salary_calc.CalcMethod1();
    methods_lst.push_back(calc);
    cout << "Calculated salary Method 1: " << calc << endl;

    calc = salary_calc.CalcMethod2();
    methods_lst.push_back(calc);
    cout << "Calculated salary Method 2: " << calc << endl;

    calc = salary_calc.CalcMethod3();
    methods_lst.push_back(calc);
    cout << "Calculated salary Method 3: " << calc << endl;
#endif
    for(unsigned sales = 1; sales < 200; sales++)
    {
    	methods_lst.clear();
    	salary_calc.SetSalesPerWeek(sales);
    	methods_lst.push_back(salary_calc.CalcMethod1());
    	methods_lst.push_back(salary_calc.CalcMethod2());
    	methods_lst.push_back(salary_calc.CalcMethod3());

    	double best_salary;
    	cout << "Sales per week: " << sales << endl;
		cout << "Best method: Method " << index_of_max_value(methods_lst, best_salary) << endl;
		cout << "Net Salary: " << best_salary << endl << endl;
    }


    int test1;
    cin >> test1;
}


