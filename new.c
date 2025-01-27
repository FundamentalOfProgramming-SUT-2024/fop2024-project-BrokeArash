#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


typedef struct {
    int x, y, width, height;
    int character_x, character_y;
} Room;

int room_overlap(Room room1, Room room2) {
    return !(room1.x + room1.width <= room2.x || room1.x >= room2.x + room2.width ||
             room1.y + room1.height <= room2.y || room1.y >= room2.y + room2.height);
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



void menu(){


    noecho();
    int max_y, max_x; 
    getmaxyx(stdscr, max_y, max_x);
    WINDOW* win = newwin(max_y-10, max_x-40, 5, 25);
    
    wrefresh(win);

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
        "1. NEW USER",
        "2. LOGIN",
        "3. EXIT",
        NULL
    };

    int margin_top = 7;
    int margin_left = 40;
    int margin_bottom = 7;
    int margin_right = 40;

    int n_options = sizeof(menu_options) / sizeof(menu_options[0]) - 1;

    while(1){
        box(win, 0, 0);
        usleep(100000);
        wrefresh(win);
        char a = getch();
        for (int i = 0; i < n_options; i++) {
                mvwprintw(win, margin_top + i * 5 + 4, margin_left + 20, "%s", menu_options[i]);
            }
        
            for (int i = 0; logo1[i] != NULL; i++) {
                mvwprintw(win, i + margin_bottom, margin_left -25,"%s", logo1[i]);
            }


            for (int i = 0; logo2[i] != NULL; i++) {
                mvwprintw(win, i + margin_bottom, margin_left + 45,"%s", logo2[i]);
            }

        


        // Handle the chosen option
        wrefresh(win);
        if(a == '1'){
            game_menu();
            break;
        }
        else if(a == '2'){
            return;
        }
        else if(a == '3')
            return;
         // Wait for the user to see the result before exiting
    }
    
}

void generate_random_map(WINDOW* win, int height, int width, unsigned int seed, Room room_details[6], int i) {
    srand(seed);
    int room_x = rand() % (width / 3);   // Room position
    int room_y = rand() % (height / 3);  // Room position
    int room_width = rand() % 10 + 6;    // Room dimensions
    int room_height = rand() % 6 + 4;

    // Ensure room fits within window
    room_width = (room_x + room_width > width) ? (width - room_x - 1) : room_width;
    room_height = (room_y + room_height > height) ? (height - room_y - 1) : room_height;

    // Draw the room
    for (int y = room_y; y < room_y + room_height; y++) {
        for (int x = room_x; x < room_x + room_width; x++) {
            if (y == room_y || y == room_y + room_height - 1) {
                mvwaddch(win, y, x, '-');  // Top/Bottom walls
            } else if (x == room_x || x == room_x + room_width - 1) {
                mvwaddch(win, y, x, '|');  // Side walls
            } else {
                mvwaddch(win, y, x, '.');  // Empty floor
            }
        }
    }


    // Add doors
    mvwaddch(win, room_y, room_x + room_width / 2, '+');                 // Top door
    mvwaddch(win, room_y + room_height - 1, room_x + room_width / 2, '+'); // Bottom door

    wrefresh(win);
}


void main_game(){
    noecho();
    srand(time(NULL));
    int max_y, max_x; 
    getmaxyx(stdscr, max_y, max_x);
    WINDOW* win1 = newwin(max_y/2, max_x/3, 0, 0);
    WINDOW* win2 = newwin(max_y/2, max_x/3, 0, max_x/3);
    WINDOW* win3 = newwin(max_y/2, max_x/3, 0, 2*max_x/3);
    WINDOW* win4 = newwin(max_y/2, max_x/3, max_y/2, 0);
    WINDOW* win5 = newwin(max_y/2, max_x/3, max_y/2, max_x/3);
    WINDOW* win6 = newwin(max_y/2, max_x/3, max_y/2, 2*max_x/3);

    WINDOW* rooms[6] = {win1, win2, win3, win4, win5, win6};
    Room room_details[6];
    for(int i = 0; i < 6; i++){
        int room_width = max_x / 3;
        int room_height = max_y / 2;
        room_details[i].x = i % 3 * room_width;
        room_details[i].y = i / 3 * room_height;
        room_details[i].width = room_width;
        room_details[i].height = room_height;
        generate_random_map(rooms[i], room_height, room_width, (unsigned int)time(NULL) + i + 1, room_details, i);   
    }

    int room_index = rand() % 6;
    Room chosen = room_details[room_index];
    chosen.character_x = chosen.x + 2 + rand() % (chosen.width - 4); 
    chosen.character_y = chosen.y + 2 + rand() % (chosen.height - 4);

    mvwaddch(rooms[room_index], chosen.character_y - chosen.y, chosen.character_x - chosen.x, 'H');
    wrefresh(win1); wrefresh(win2); wrefresh(win3); wrefresh(win4); wrefresh(win5); wrefresh(win6);

    while(1){
        usleep(500000);  // Sleep for a while
        
        if(getch() == 10){  // If Enter key is pressed, exit
            break;
        }
    }
}

void game_menu(){

    noecho();
    int max_y, max_x; 
    getmaxyx(stdscr, max_y, max_x);
    WINDOW* win = newwin(max_y-10, max_x-40, 5, 25);
    
    wrefresh(win);

    const char *menu_options[] = {
        "1. NEW GAME",
        "2. LOAD GAME",
        "3. SCORE BOARD",
        "4. SETTINGS",
        "5. BACK",
        NULL
    };


    int margin_top = 7;
    int margin_left = 40;
    int margin_bottom = 7;
    int margin_right = 40;

    int n_options = sizeof(menu_options) / sizeof(menu_options[0]) - 1;

    while(1){
        box(win, 0, 0);
        usleep(100000);
        wrefresh(win);
        char a = getch();
        for (int i = 0; i < n_options; i++) {
                mvwprintw(win, margin_top + i * 5, margin_left + 20, "%s", menu_options[i]);
            }
    
        if(a == '1'){
            main_game();
        
            break;
        }
        else if(a == '2'){
            const char* gol[] = {
            "             ,         ",
            "         /\\^/`\\      ",
            "        | \\/   |      ",
            "        | |    |       ",
            "        \\ \\    /     ",
            "         '\\\\//'      ",
            "           ||          ",
            "           ||          ",
            "           ||          ",
            "           ||  ,       ",
            "       |\\  ||  |\\    ",
            "       | | ||  | |     ",
            "       | | || / /      ",
            "        \\ \\||/ /     ",
            "     jgs  `\\\\//`     ",
            "        ^^^^^^^^       ",
                NULL
            };

            while(1){
                clear();
                for (int i = 0; gol[i] != NULL; i++) {
                mvprintw(i + max_y/4 + 4, margin_left + max_x/4.2, "%s", gol[i]);
                usleep(100000);
                }

                if(getch() == 10)
                    break;
            }
        }
        else if(a == '3'){
            clear();  // Clear the screen
            while(1) {

                // Calculate the size and position of the window
                int height = max_y - 10;   // Adjust the height as needed
                int width = max_x - 40;    // Adjust the width as needed
                int start_y = (max_y - height) / 2;  // Center the window vertically
                int start_x = (max_x - width) / 2;   // Center the window horizontally

                // Create the window
                WINDOW* scorewin = newwin(height, width, start_y, start_x);
                

                // Open the scoreboard file
                FILE *score = fopen("scoreboard.txt", "r");
                if (score == NULL) {
                    wprintw(scorewin, "Error opening the file.\n");
                    wrefresh(scorewin);
                    fclose(score);  // Close the file if it failed to open
                    break;  // Exit the loop
                }

                // Print the contents of the file to the window
                char ch;
                while ((ch = fgetc(score)) != EOF) {
                    move(5, 5);
                    wprintw(scorewin, "%c", ch);  // Print each character in the window
                }

                fclose(score);  // Close the file
                wrefresh(scorewin);  // Update the window to show the content

                // Wait for user input (Enter key to exit)
                usleep(100000);
                if (getch() == 10) {
                    clear();
                    break;  // Exit the loop when Enter is pressed
                }
            }
        }
        else if(a == '4'){
                            // Calculate the size and position of the window
            clear();  // Clear the screen
            int height = max_y - 10;   // Adjust the height as needed
            int width = max_x - 40;    // Adjust the width as needed
            int start_y = (max_y - height) / 2;  // Center the window vertically
            int start_x = (max_x - width) / 2;   // Center the window horizontally

            WINDOW* settingwin = newwin(height, width, start_y, start_x);
            const char *setting_options[] = {
            "1. DIFICULTY",
            "2. CHANGE COLOR",
            "3. CHANGE MUSIC",
            "4. BACK",
            NULL
            };
            while(1) {
                usleep(100000);

                int margin_top = 7;
                int margin_left = 40;
                int margin_bottom = 7;
                int margin_right = 40;

                int n_options = sizeof(setting_options) / sizeof(setting_options[0]) - 1;

                while(1){
                    box(settingwin, 0, 0);
                    wrefresh(settingwin);
                    char a = getch();
                    for (int i = 0; i < n_options; i++) {
                        mvwprintw(settingwin, margin_top + i * 5, margin_left + 20, "%s", setting_options[i]);
                    }
                    usleep(100000);
                
                    if(a == '1'){ //dificulty
                    
                        break;
                    }
                    else if(a == '2'){ //color

                    }

                    else if(a == '3'){ //music

                    }
                    else if(a == '4'){
                        clear();
                        game_menu();
                        break;
                    }
                    break;
                }
            }
        }    
            
        else if(a == '5'){ //back to main menu
            return;
            break;
        }
        
    }
}

int main(){

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
    menu();


    endwin();
    return 0;
}