#ifndef RECORD_H
#define RECORD_H

typedef struct {
    char username[50];  // Added to associate each expense with a user
    char category[30];
    float amount;
    char date[20];
} Expense;

void add_expense(const char *username);
void view_expenses(const char *username);
void save_expenses_to_file(const char *filename);
void load_expenses_from_file(const char *filename);

#endif
