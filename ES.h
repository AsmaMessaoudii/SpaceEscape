#ifndef ES_H
#define ES_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
//COLISION
int collision(SDL_Rect pos1,SDL_Rect pos2);
int collision_enemie(perso p,enmie e[]);
void collision_obstacles(obstacles o,perso p,int c_obstacles[]);
int collision_checkpoint(checkpoint ch,perso p);
int collision_traps(perso p,trap t[]);
int collision_collections(perso p,collections c);
int collision_shot(shot sh,perso p);
//INITIALISATIONS
void initenmieSTAGE1(enmie e[]);
void initialiser_obstaclesSTAGE1(obstacles* o);
void initialiser_trapSTAGE1(trap lazer[]);
void initialiser_chekpointSTAGE1(checkpoint *ch);
void initialiser_shotSTAGE1(shot *sh,enmie e);
void initialiser_collectionsSTAGE1(collections *c,SDL_Rect pos[]);
int verif_collections(int tab[],int x,int n);
//ANNIMATIONS
void animer_enmie (enmie* e);
void animer_lazer(trap *t);
void annimer_checkpoint(checkpoint *ch);
void annimer_obstacles(obstacles *o);
void annimer_collections(collections *c);
//mouvment
void move_enmie (enmie *e);
void movobstacle(obstacles *o);
void movshot(shot *ch,int dir);
//affichage
void afficher_enmie( SDL_Surface * screen,enmie e);
void afficher_obstacles(SDL_Surface *screen,obstacles o);
void afficher_trap(SDL_Surface *screen,trap t);
void afficher_chekpoint(SDL_Surface *screen,checkpoint ch);
void afficher_shot(SDL_Surface *screen,shot sh);
void afficher_collections(SDL_Surface *screen,collections c);
//scrolling
void deplacer_ennemie(enmie *e,int dir,int v);
void deplacer_obstacles(obstacles *o,int dir,int v);
void deplacer_trap(trap lazer[],int dir,int v,background back);
void deplacer_chekpoint(checkpoint *ch,int dir,int v,background back);
void deplacer_shot(shot *sh,int dir,int v);
void deplacer_collections(collections *sh,int dir,int v);
//elienshot
void elien_shot(shot *sh,enmie e);
void avancer_shot(shot *sh,enmie e);
#endif
