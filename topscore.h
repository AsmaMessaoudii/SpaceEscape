#ifndef TOPSCORE_H
#define TOPSCORE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"
void initialiser_backtopp(backs *backtop);
void initialiser_bt_exit_top(boutton *exit_top);
void go_topscore(SDL_Surface *screen,int *boocle);


#endif
