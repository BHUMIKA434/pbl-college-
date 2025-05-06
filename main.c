// main.c
#include <stdio.h>
#include "auth.h"

int main() {
    int choice;

    while (1) {
        printf("\n--- User Authentication Menu ---\n");
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
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
