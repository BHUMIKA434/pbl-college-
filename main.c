#include <stdio.h>
#include <string.h>
#include "auth/auth.h"
#include "string/string.h"
#include "record/record.h"
#include "calc/calc.h"

extern char current_user[MAX_LEN]; // Shared variable

int main() {
    int choice;

    load_expenses_from_file("expenses.txt");

    while (1) {
        printf("\n--- Expense Tracker Menu ---\n");

        if (!user_logged_in()) {
            printf("1. Register\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                register_user();
            } else if (choice == 2) {
                login_user();
            } else if (choice == 3) {
                printf("Goodbye!\n");
                break;
            } else {
                printf("Invalid choice.\n");
            }
        } else {
            // User is logged in
            printf("1. Add Expense\n");
            printf("2. View My Expenses\n");
            printf("3. Filter by Category\n");
            printf("4. Monthly Total\n");
            printf("5. Analyze Trends\n");
            printf("6. Logout & Save\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                add_expense(current_user);
            } else if (choice == 2) {
                view_expenses(current_user);
            } else if (choice == 3) {
                char category[30];
                printf("Enter category: ");
                scanf("%s", category);
                filter_expenses_by_category(current_user, category);
            } else if (choice == 4) {
                char month[10];
                printf("Enter month (YYYY-MM): ");
                scanf("%s", month);
                calculate_monthly_total(current_user, month);
            } else if (choice == 5) {
                analyze_spending_trend(current_user);
            } else if (choice == 6) {
                save_expenses_to_file("expenses.txt");
                printf("Logged out. Goodbye!\n");
                current_user[0] = '\0'; // logout
            } else {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}
