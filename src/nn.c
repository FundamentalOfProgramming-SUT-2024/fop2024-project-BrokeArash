#include "rogue.h"
#include "mainMenu.h"
#include "game.h"
#include "utils.h"

char username[50], password[50], email[50];

void drawlogo() {
    const char *logo[] = {
        "8 888888888o.      ,o888888o.     8 8888      88     ,o888888o.    8 888888888888  ",
        "8 8888    `88.  . 8888     `88.   8 8888      88    8888     `88.  8 8888          ",
        "8 8888     `88 ,8 8888       `8b  8 8888      88 ,8 8888       `8. 8 8888          ",
        "8 8888     ,88 88 8888        `8b 8 8888      88 88 8888           8 8888          ",
        "8 8888.   ,88' 88 8888         88 8 8888      88 88 8888           8 888888888888  ",
        "8 888888888P'  88 8888         88 8 8888      88 88 8888           8 8888          ",
        "8 8888`8b      88 8888        ,8P 8 8888      88 88 8888   8888888 8 8888          ",
        "8 8888 `8b.    `8 8888       ,8P  ` 8888     ,8P `8 8888       .8' 8 8888          ",
        "8 8888   `8b.   ` 8888     ,88'     8888   ,d8P     8888     ,88'  8 8888          ",
        "8 8888     `88.    `8888888P'        `Y88888P'       `8888888P'    8 888888888888  ", 
        "                                                                                   ",
        "                                                                                   ",
        "                                                                                   ",
        "         888  8  88      888 888 888 8 8     88  88   8   88 888  88 888           ", 
        "         8   8 8 8 8       8 8 8   8 8 8     8 8 8 8 8 8   8 8   8    8            ", 
        "         88  8 8 88      888 8 8 888 888     88  88  8 8   8 88  8    8            ",  
        "         8   8 8 8       8   8 8 8     8     8   8 8 8 8 8 8 8   8    8            ",
        "         8    8  8       888 888 888   8     8   8 8  8   8  888  88  8            ",
        NULL
    };

    const char *name1[] = {
    "    d8b                        d8b                ",
    "    ?88                        ?88                ",
    "    88b                        88b               ",
    "    888888b   88bd88b d8888b   888  d88' d8888b  ",
    "    88P `?8b  88P'  `d8P' ?88  888bd8P' d8b_,dP  ",
    "    d88,  d88 d88     88b  d88 d88888b   88b      ",
    "    d88'`?88P'd88'     `?8888P'd88' `?88b,`?888P'  ",
    "                                                ",
    NULL
    };




    const char *name2[] = {
    "                                          d8b      ",
    "                                          ?88      ",
    "                                           88b     ",
    "    d888b8b    88bd88b d888b8b   .d888b,   888888b ",
    "    d8P' ?88    88P'  `d8P' ?88   ?8b,     88P `?8b ",
    "    88b  ,88b  d88     88b  ,88b    `?8b   d88   88P ",
    "    `?88P'`88bd88'     `?88P'`88b`?888P'   d88'   88b ",                               
    NULL
    };

    

    
    int max_y, max_x; 
    getmaxyx(stdscr, max_y, max_x);

    int margin_top = 2;
    int margin_left = 4;
    int margin_bottom = 2;
    int margin_right = 4;

    for (int i = 0; logo[i] != NULL; i++) {
        mvprintw(i + max_y/4 + 4, margin_left + max_x/4.2,"%s", logo[i]);
    }
    
    for (int i = 0; name1[i] != NULL; i++) {
        mvprintw(i + margin_top + 1, margin_left + 1,"%s", name1[i]);
    }
    
    for (int i = 0; name2[i] != NULL; i++) {
        mvprintw(i + margin_top + 1, margin_left + 105,"%s", name2[i]);
    }

    int loading_bar_width = max_x - margin_left - margin_right - 127;
    int loading_bar_pos_y = margin_top + 1 + 23+ max_y/5;

    int progress = 0;

    for (progress = 0; progress <= loading_bar_width; progress++) {
        mvprintw(loading_bar_pos_y, margin_left + 57,"%s", "[");
        for (int i = 0; i < progress; i++) {
            mvprintw(loading_bar_pos_y, margin_left + 58 + i,"%s", "#");
        }
        for (int i = progress; i < loading_bar_width; i++) {
            mvprintw(loading_bar_pos_y, margin_left + 58 + i,"%s", " ");
        }
        mvprintw(loading_bar_pos_y, margin_left + 58 + loading_bar_width,"%s", "]");

        refresh();

        usleep(50000);
    }
    int message_y = loading_bar_pos_y + 3;
    nodelay(stdscr, TRUE);
    int blink_count = 0;
    while (getch() != 10) {
        if (blink_count % 2 == 0) {
            mvprintw(message_y, margin_left + 69,"%s", "Press Enter to continue...");
        } else {
            mvprintw(message_y, margin_left + 69,"%s", "                               ");
        }

        refresh();
        usleep(500000);
        blink_count ++;
    }

    clear();
}

const char* logo1[] = {
    "      _,.",
    "    ,` -.)",
    "   ( _/-\\\\-._",
    "  /,|`--._,-^|            ,",
    "  \\_| |`-._/||          ,'|",
    "    |  `-, / |         /  /",
    "    |     || |        /  /",
    "     `r-._||/   __   /  /",
    " __,-<_     )`-/  `./  /",
    "'  \\   `---'   \\   /  /",
    "    |           |./  /",
    "    /           //  /",
    "\\_/' \\         |/  /",
    " |    |   _,^-'/  /",
    " |    , ``  (\\/  /_",
    "  \\,.->._    \\X-=/^",
    "  (  /   `-._//^`",
    "   `Y-.____(__}",
    "    |     {__)",
    "          ()",
    NULL
    };


const char* logo2[] = {

    "                  _,-'|",
    "               ,-'._  |",
    "     .||,      |####\\ |",
    "    \\.`',/     \\####| |",
    "    = ,. =      |###| |",
    "    / || \\    ,-'\\#/,'`.",
    "      ||     ,'   `,,. `.",
    "      ,|____,' , ,;' \\| |",
    "     (3|\\    _/|/'   _| |",
    "  ||/,-''  | >-'' _,\\\\",
    "      ||'      ==\\ ,-'  ,'",
    "      ||       |  V \\ ,|",
    "      ||       |    |` |",
    "      ||       |    |   \\",
    "      ||       |    \\    \\",
    "      ||       |     |    \\",
    "      ||       |      \\_,-'",
    "      ||       |___,,--'')_\\",
    "      ||         |_|   ccc/",
    "      ||        ccc/",
    "      ||                hjm",
        NULL
    };


void createUser() {
    int choice;
    char* choices[] = {"UserName", "Password", "Email", "Save"};
    char username[100];  // Buffer to store username
    char password[100];  // Buffer to store password
    char email[100];     // Buffer to store email

    while (1) {
        choice = mainMenu(4, choices);  // Main menu with 4 options

        switch (choice) {
            case 0:  // USERNAME
                echo();  // Enable echoing (if needed)
                mvscanw(0, 10, "%99s", username);  // Read username (limit to 99 characters)
                FILE* output1 = fopen("user.txt", "a");
                fprintf(output1, username);
                fclose(output1);

                break;

            case 1:  // PASSWORD
                echo();  // Enable echoing (if needed)
                mvscanw(1, 10, "%99s", password);  // Read username (limit to 99 characters)
                FILE* output2 = fopen("user.txt", "a");
                fprintf(output2, password);
                fclose(output2);  // Read password (limit to 99 characters)
                break;

            case 2:  // EMAIL
                echo();  // Enable echoing (if needed)
                mvscanw(2, 10, "%99s", email);  // Read username (limit to 99 characters)
                FILE* output3 = fopen("user.txt", "a");
                fprintf(output3, email);
                fclose(output3);
                break;

            case 3:  // SAVE
                // Save logic, if needed
                return;  // Exit the loop, saving the data
        }
    }
}


void login(){
    int choice;
    char* choices[] = {"UserName", "Password", "Submit", "Back"};


    while (1) {
        choice = mainMenu(4, choices);

        switch (choice) {
            case USER:
                echo();
                mvscanw(0, 10, "%99s", username);
                break;

            case PASS:
                echo();
                mvscanw(0, 10, "%99s", password);
                
                break;

            case SUBMIT:
                menuLoop();
                break;
            case BACK:
                return;
        }
    }
}



void startLoop(){
    int choice;
    char* choices[] = {"SignUp", "LogIn", "Exit"};

    for (int i = 0; logo1[i] != NULL; i++) {
        mvprintw(i + 4, 20, "%s", logo1[i]);
    }

    while (1) {
        choice = mainMenu(3, choices);

        switch (choice) {
            case SIGNUP:
                createUser();
                break;

            case LOGIN:
                login();
                break;

            case EXIT:
                return;
        }
    }
}



void menuLoop(){

    int choice;
    char* choices[] = {"New Game", "Exit"};

    Game game;
    game.currentLevel = 0;

     for (int i = 0; logo2[i] != NULL; i++) {
        mvprintw(i + 4, 20,"%s", logo2[i]);
    }

    while(1){

        clear();
        refresh();
        
        choice = mainMenu(2, choices);

        switch(choice){

                case START_GAME:
                    gameLoop(&game);
                    clear();
                    break;
                case QUIT_GAME:
                    return;

        }
    }
}

int main() {

    screenSetUp();
    drawlogo();
    startLoop();
    endwin();

    return 0;
}





