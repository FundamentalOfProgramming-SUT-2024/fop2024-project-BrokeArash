#ifndef MAIN_MENU_H
#define MAIN_MENU_H

enum Main {START_GAME, QUIT_GAME};
enum Start {SIGNUP, LOGIN, EXIT};
enum SignUp {USERNAME, PASSWORD, EMAIL, SAVE };
enum SignIn {USER, PASS, SUBMIT, BACK };

int mainMenu(int numberItems, char* choices[]);

#endif