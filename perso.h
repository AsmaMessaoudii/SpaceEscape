#ifndef PERSO_H
#define PERSO_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
#include"ES.h"
#include"background.h"
void initPerso(perso *p);
void reanisyaliser(int *w,int i);
void afficherPerso(SDL_Surface * screen,perso p);
void animerPerso (perso* p);
void movePerso (perso *p);
void saut (perso* p);
void deplacer_perso(perso *p,int dir,int v);
void mouv_saut (perso* p);
void veriph_dir(obstacles o,perso *p,int c_obstacles[]);
void init_imageVies1(vie_player *v);
void init_imageVies2(vie_player *v);
void afficher_imageVies(SDL_Surface *screen,vie_player v);
void retoure_checkpointstage1(perso *p,background *back,checkpoint *ch,enmie e[],obstacles *o,collections *c,trap t[]);
void retoure_debut(perso *p,background *back,checkpoint *ch,enmie e[],obstacles *o,collections *c,trap t[]);
#endif
