#ifndef _XO_H_
#define _XO_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <time.h>
#include"minimap.h"
typedef struct
{
image table;
image bg;
image t[2];
int i[3][3];
SDL_Rect r[3][3];
int turn;
int choixx;
int choixy;
}xo;

int game(SDL_Surface *screen);


#endif
