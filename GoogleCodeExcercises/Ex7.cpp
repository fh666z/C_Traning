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
ValueType max_of_values(list<ValueType> values_list)
{
    ValueType max_value = values_list.front();
    list<ValueType*>::iterator list_iter;
    for (list_iter = values_list.begin(); list_iter < values_list.end(); ++list_iter)
        if (*list_iter > max_value)
            max_value = *list_iter;

    return max_value;
}


void Ex7_test(void)
{
    list<int> lst(10);
    cout << "Test: " << max_of_values<int>(lst) << endl;

    const unsigned sales = 10;
    SalaryCalc salary_calc1(sales);
    cout << "Sales per week: " << sales << endl;
    cout << "Calculated salary Method 1: " << salary_calc1.CalcMethod1() << endl;
    cout << "Calculated salary Method 2: " << salary_calc1.CalcMethod2() << endl;
    cout << "Calculated salary Method 3: " << salary_calc1.CalcMethod3() << endl;
}


