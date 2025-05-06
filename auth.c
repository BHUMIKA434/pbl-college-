// auth.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"

#define MAX_LEN 50

void register_user() {
    char username[MAX_LEN];
    char password[MAX_LEN];

    printf("Enter a username: ");
    scanf("%s", username);

    printf("Enter a password: ");
    scanf("%s", password);

    FILE *fp = fopen("users.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);

    printf("Registration successful!\n");
}

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
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found) {
        printf("Login successful! Welcome, %s.\n", username);
    } else {
        printf("Login failed. Invalid username or password.\n");
    }
}
