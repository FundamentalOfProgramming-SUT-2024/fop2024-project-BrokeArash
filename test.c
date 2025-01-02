#include <ncurses.h>

void print_menu(WINDOW *menu_win, int highlight, char *choices[], int n_choices);

int main() {
    // Initialize ncurses
    initscr();
    cbreak();  // Disable line buffering
    noecho();  // Don't display input
    curs_set(0);  // Hide the cursor

    // Define the menu choices
    char *choices[] = {
        "Option 1",
        "Option 2",
        "Option 3",
        "Exit"
    };
    int n_choices = sizeof(choices) / sizeof(char *);
    int highlight = 0;  // Initially, the first option is highlighted
    int choice = 0;
    int key;

    // Create a window for the menu
    int startx = 0;
    int starty = 0;
    int height = 10;
    int width = 40;
    WINDOW *menu_win = newwin(height, width, starty, startx);
    keypad(menu_win, TRUE);  // Enable special keys like arrow keys

    // Main menu loop
    while (1) {
        print_menu(menu_win, highlight, choices, n_choices);  // Print the menu
        key = wgetch(menu_win);  // Get user input

        switch (key) {
            case KEY_UP:
                if (highlight == 0) {
                    highlight = n_choices - 1;  // Wrap around to the last option
                } else {
                    --highlight;  // Move up in the menu
                }
                break;
            case KEY_DOWN:
                if (highlight == n_choices - 1) {
                    highlight = 0;  // Wrap around to the first option
                } else {
                    ++highlight;  // Move down in the menu
                }
                break;
            case 10:  // Enter key
                choice = highlight;
                break;
        }

        // If Enter is pressed, break from the loop
        if (choice != -1) {
            break;
        }
    }

    // Execute the action based on the selected option
    switch (choice) {
        case 0:
            printw("You selected Option 1\n");
            break;
        case 1:
            printw("You selected Option 2\n");
            break;
        case 2:
            printw("You selected Option 3\n");
            break;
        case 3:
            printw("Exiting the menu\n");
            break;
    }

    // Refresh the screen to show the result
    refresh();
    getch();  // Wait for user to see the result before exiting

    // Clean up ncurses
    endwin();
    return 0;
}

// Function to print the menu
void print_menu(WINDOW *menu_win, int highlight, char *choices[], int n_choices) {
    int x = 2, y = 2;  // Starting position for the menu
    int i;

    // Clear the window
    werase(menu_win);

    // Print the title
    mvwprintw(menu_win, 0, 2, "Menu");
    for (i = 0; i < n_choices; ++i) {
        if (i == highlight) {  // Highlight the selected option
            wattron(menu_win, A_REVERSE);  // Reverse video mode for highlighting
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        } else {
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        }
        ++y;
    }

    // Refresh the window to show the menu
    wrefresh(menu_win);
}
