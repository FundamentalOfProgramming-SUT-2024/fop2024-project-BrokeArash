#include <ncurses.h>
#include <unistd.h>
#include <locale.h>
#include <wchar.h>



void fborder(int margin_top, int margin_left, int margin_bottom, int margin_right){

    int max_y, max_x; 
    getmaxyx(stdscr, max_y, max_x);

    for (int y = margin_top; y < max_y - margin_bottom; y++) {
        for (int x = margin_left; x < max_x - margin_right; x++) {
            if (y == margin_top || y == max_y - margin_bottom - 1) {
                mvprintw(y, x,"%s", "--");
            } else if (x == margin_left || x == max_x - margin_right - 1) {
                mvprintw(y, x,"%s", "|");  
            }
        }
    }
}




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

    fborder(2, 4, 2, 4);

    
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

    int loading_bar_width = max_x - margin_left - margin_right - 103;
    int loading_bar_pos_y = margin_top + 1 + 23+ max_y/5;

    int progress = 0;

    for (progress = 0; progress <= loading_bar_width; progress++) {
        mvprintw(loading_bar_pos_y, margin_left + 50,"%s", "[");
        for (int i = 0; i < progress; i++) {
            mvprintw(loading_bar_pos_y, margin_left + 51 + i,"%s", "#");
        }
        for (int i = progress; i < loading_bar_width; i++) {
            mvprintw(loading_bar_pos_y, margin_left + 51 + i,"%s", " ");
        }
        mvprintw(loading_bar_pos_y, margin_left + 51 + loading_bar_width,"%s", "]");

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

void fmenu(){


    clear();
    refresh();

    fborder(10, 40, 10, 40); // Draw the border
    int max_y, max_x; 
    getmaxyx(stdscr, max_y, max_x); // Get screen dimensions

    int margin_top = 10;
    int margin_left = 40;
    int margin_bottom = 10;
    int margin_right = 40;

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

    // Menu options
    const char *menu_options[] = {
        "1. NEW GAME",
        "2. LOAD GAME",
        "3. SETTINGS",
        "4. EXIT",
        NULL
    };

    int n_options = sizeof(menu_options) / sizeof(menu_options[0]) - 1; // Number of menu options
    int highlight = 0; // Start with the first option highlighted
    int choice = 0;
    int key;

    // Print the menu options
    for (int i = 0; i < n_options; i++) {
        if (i == highlight) {
            attron(A_REVERSE);  // Highlight the current option
            mvprintw(margin_top + 5 + i * 5, margin_left + 40, "%s", menu_options[i]);
            attroff(A_REVERSE);
        } else {
            mvprintw(margin_top + 5 + i * 5, margin_left + 40, "%s", menu_options[i]);
        }
    }

    // Main loop to handle menu navigation
    while (1) {
        for (int i = 0; logo1[i] != NULL; i++) {
            mvprintw(i + margin_bottom + 3, margin_left + + 5,"%s", logo1[i]);
        }


        for (int i = 0; logo2[i] != NULL; i++) {
            mvprintw(i + margin_bottom + 3, margin_left + + 57,"%s", logo2[i]);
        }
        key = getch();  // Get user input

        switch (key) {
            case KEY_UP:
                if (highlight == 0) {
                    highlight = n_options - 1;  // Wrap to the last option
                } else {
                    highlight--;  // Move up
                }
                break;
            case KEY_DOWN:
                if (highlight == n_options - 1) {
                    highlight = 0;  // Wrap to the first option
                } else {
                    highlight++;  // Move down
                }
                break;
            case 10:  // Enter key
                choice = highlight;
                break;
        }

        // Redraw the menu to reflect the updated selection
        usleep(300000);
        clear();
        fborder(10, 40, 10, 40);
        for (int i = 0; i < n_options; i++) {
            if (i == highlight) {
                attron(A_REVERSE);
                mvprintw(margin_top + 5 + i * 5, margin_left + 40, "%s", menu_options[i]);
                attroff(A_REVERSE);
            } else {
                mvprintw(margin_top + 5 + i * 5, margin_left + 40, "%s", menu_options[i]);
            }
        }

        if (choice != 0) {
            break;  // Exit the loop when the user selects an option
        }
    }

    // Handle the chosen option
    switch (choice) {
        case 0:
            mvprintw(margin_top + 30, margin_left + 40, "Starting NEW GAME...");
            usleep(500000);
            break;
        case 1:
            mvprintw(margin_top + 30, margin_left + 40, "Loading GAME...");
            usleep(500000);
            break;
        case 2:
            mvprintw(margin_top + 30, margin_left + 40, "Opening SETTINGS...");
            usleep(500000);
            break;
        case 3:
            mvprintw(margin_top + 30, margin_left + 40, "Exiting...");
            usleep(500000);
            break;
    }

    refresh();
    getch();  // Wait for the user to see the result before exiting
}



int main() {

    setlocale(LC_CTYPE, "");

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        bkgd(COLOR_BLACK);
    }

    drawlogo();
    fmenu();

    endwin();
    return 0;
}
