#ifndef CALC_H
#define CALC_H

#include "../record/record.h"

void filter_expenses_by_category(const char *username, const char *category);
void calculate_monthly_total(const char *username, const char *month);
void analyze_spending_trend(const char *username);

#endif
