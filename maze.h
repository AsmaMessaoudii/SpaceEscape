#ifndef MAZE_H
#define MAZE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"

typedef struct 
{
char nom[30];
SDL_Color color;
SDL_Rect pos;
SDL_Surface *txt;
TTF_Font *police;

}message;
void afficher_maze(SDL_Surface *screen,image back_maze[],int nb_photo);
void initialiser_backmaze(image back_maze[]);
void init_maze(image *joueur,image *maze);
void init_mazepoints(SDL_Rect points[]);
void afficher_joueur(SDL_Surface *screen,image joueur,SDL_Rect points[],int timmy);
void move(int *timmy,int etat);
int  move_left(int timmy);
int  move_right(int timmy);
int  move_up(int timmy);
int  move_down(int timmy);
int maze(SDL_Surface *screen);
#endif
