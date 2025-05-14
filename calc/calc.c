#include <stdio.h>
#include <string.h>
#include "calc.h"

extern Expense expenses[];
extern int expense_count;

void filter_expenses_by_category(const char *username, const char *category) {
    printf("\n--- %s's Expenses in category: %s ---\n", username, category);
    for (int i = 0; i < expense_count; i++) {
        if (strcmp(expenses[i].username, username) == 0 &&
            strcmp(expenses[i].category, category) == 0) {
            printf("Amount: ₹%.2f | Date: %s\n", expenses[i].amount, expenses[i].date);
        }
    }
}

void calculate_monthly_total(const char *username, const char *month) {
    float total = 0.0;
    for (int i = 0; i < expense_count; i++) {
        if (strcmp(expenses[i].username, username) == 0 &&
            strstr(expenses[i].date, month)) {
            total += expenses[i].amount;
        }
    }
    printf("Total expenses for %s in %s: ₹%.2f\n", username, month, total);
}

void analyze_spending_trend(const char *username) {
    float food = 0, transport = 0, rent = 0, other = 0;

    for (int i = 0; i < expense_count; i++) {
        if (strcmp(expenses[i].username, username) != 0) continue;

        if (strcmp(expenses[i].category, "food") == 0)
            food += expenses[i].amount;
        else if (strcmp(expenses[i].category, "transport") == 0)
            transport += expenses[i].amount;
        else if (strcmp(expenses[i].category, "rent") == 0)
            rent += expenses[i].amount;
        else
            other += expenses[i].amount;
    }

    printf("\n--- %s's Spending Breakdown ---\n", username);
    printf("Food: ₹%.2f\n", food);
    printf("Transport: ₹%.2f\n", transport);
    printf("Rent: ₹%.2f\n", rent);
    printf("Other: ₹%.2f\n", other);
}
