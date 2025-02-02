#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <pthread.h>

int play_music(const char *file_path);
extern int MAX_HEIGHT;
extern int MAX_WIDTH;




#endif