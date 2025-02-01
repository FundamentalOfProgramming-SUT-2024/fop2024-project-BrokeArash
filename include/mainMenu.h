#ifndef MAIN_MENU_H
#define MAIN_MENU_H

enum Main {START_GAME, RESUME_GAME, SETTING, SCOREBOARD, QUIT_GAME};
enum Start {SIGNUP, LOGIN, EXIT};
enum SignUp {USERNAME, PASSWORD, EMAIL, SAVE };
enum LogIn {USER, PASS, SUBMIT, GUEST, BACK };
enum Settings {DIFFICULTY, MUSIC, COLOR, BACK1 };
enum Color {RED, BLUE, GREEN, BACK2 };
enum Diff {EASY, NORMAL, HARD, BACK3 };
enum Music {MUSIC_1, MUSIC_2, MUSIC_3, BACK4 };

int mainMenu(int numberItems, char* choices[]);

#endif