#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"

#define MAX_EXPENSES 100
#define FILENAME "expenses.txt"

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense(const char *username) {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached.\n");
        return;
    }

    Expense e;
    strcpy(e.username, username);  // Set the logged-in username
    printf("Enter category: ");
    scanf("%s", e.category);
    printf("Enter amount: ");
    scanf("%f", &e.amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", e.date);

    expenses[expense_count++] = e;

    printf("Expense added successfully!\n");

    // Save expenses to the file after adding a new one
    save_expenses_to_file(FILENAME);
}

void view_expenses(const char *username) {
    if (expense_count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- Your Expenses ---\n");
    for (int i = 0; i < expense_count; i++) {
        if (strcmp(expenses[i].username, username) == 0) {  // Show only the user's expenses
            printf("Category: %s | Amount: ₹%.2f | Date: %s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
        }
    }
}


void save_expenses_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < expense_count; i++) {
        fprintf(file, "%s %s %.2f %s\n", expenses[i].username, expenses[i].category, expenses[i].amount, expenses[i].date);
    }

    fclose(file);
    printf("Expenses saved to file successfully.\n");
}

void load_expenses_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("No existing expenses found, starting fresh.\n");
        return;
    }

    while (fscanf(file, "%s %s %f %s", expenses[expense_count].username, expenses[expense_count].category, &expenses[expense_count].amount, expenses[expense_count].date) != EOF) {
        expense_count++;
    }

    fclose(file);
    printf("Expenses loaded from file successfully.\n");
}
