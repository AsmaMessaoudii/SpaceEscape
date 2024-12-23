#ifndef STAGE1_H
#define STAGE1_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
player stage1(SDL_Surface *screen,animations back_chargement,input_joueur input,int select_perso,player p);
void initenmieSTAGE1(enmie e[]);
void initialiser_obstaclesSTAGE1(obstacles* o);
void initialiser_trapSTAGE1(trap lazer[]);
void initialiser_chekpointSTAGE1(checkpoint *ch);
void initialiser_shotSTAGE1(shot *sh,enmie e);
void initialiser_collectionsSTAGE1(collections *c,SDL_Rect pos[]);
void initialiser_backSTAGE1(background *b,animations back_chargement,SDL_Surface *screen);
#endif
