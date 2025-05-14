#include <string.h>
#include <stdio.h>
#include "auth.h"
#include "../string/string.h" 


char current_user[MAX_LEN] = "";  // Define the global variable here

void login_user() {
    char username[MAX_LEN];
    char password[MAX_LEN];
    char file_username[MAX_LEN];
    char file_password[MAX_LEN];
    int found = 0;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(fp, "%s %s", file_username, file_password) != EOF) {
        if (str_compare(username, file_username) == 0 && str_compare(password, file_password) == 0) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found) {
        printf("Login successful! Welcome, %s.\n", username);
        str_copy(current_user, username);  // ✅ THIS IS IMPORTANT!
    } else {
        printf("Login failed. Invalid username or password.\n");
    }
}
