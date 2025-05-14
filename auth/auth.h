#ifndef AUTH_H
#define AUTH_H

#define MAX_LEN 50
extern char current_user[MAX_LEN];  // Declare it for all modules

int user_logged_in();
void register_user();
void login_user();
int user_exists(const char *username);

#endif
