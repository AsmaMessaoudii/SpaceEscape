#ifndef GAME3_H
#define GAME3_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
#include "maze.h"
typedef struct
{
	SDL_Surface *img;
	int t[10];
	SDL_Rect pos[10];
	int pos_r[3];
}alien;
//init
void init_G3(image images[]);
void afficher_imge(SDL_Surface *screen,image imge);
void afficher_exite(SDL_Surface *screen, image imge,SDL_Rect posbouton[]);
void afficher_timmy(SDL_Surface *screen, image imge,SDL_Rect pos_timali[],int pos_timmy);
void init(SDL_Rect posbouton[],SDL_Rect pos_timali[]);
void afficher_alien(SDL_Surface *screen, image imge,alien e);
int test(int pos_alien[],int x);
void afficher_bleu(SDL_Surface *screen,image images[],int pos_timmy,alien e,SDL_Rect posbouton[]);
//void afficher_bleu(SDL_Surface *screen, image images[], int pos_timmy, alien e)
void movetimmy(int x,int y,int *pos_timmy,int c);
//void 	Update_alien(int pos_alien[]);
int existe(int t[],int x);
void intialiser_alien(alien *e,SDL_Rect pos_timali[]);
void move_alien(alien *e);
void remplir_tab(int t[],int tab[]);
void verif_movalien(int t[], int r);
void afficher_message(SDL_Surface *screen,message m);
void initialiser_message(message *m);

int game3(SDL_Surface *screen);
#endif
