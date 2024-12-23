#ifndef ENIGME_H
#define ENIGME_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
typedef struct
{
	SDL_Rect pos;
	SDL_Surface *img[29];
	int photo;
}planet;
typedef struct
{
	char questions1[60];
	char questions2[60];
	char reponse1[20];
	char reponse2[10];
	char reponse3[12];
	int reponse;
	int r1;
	int r2;
	int r3;
	SDL_Color color[5];
	TTF_Font *police;
	SDL_Surface *txt[5];
	SDL_Rect pos[5];
}enigme;
void afficher_planet(SDL_Surface *screen,planet p[]);
void initialiser_enigme(enigme *e);
void afficher_enigme(SDL_Surface *screen,enigme e);
void genererEnigme(enigme *p, char nomfichier[]);
void initialiser_backenigme(background *back);
void initialiser_planets(enigme e,planet p[]);
int go_enigme(SDL_Surface *screen,int *boocle);
void ajout_enigme(texte *time1,int debut_time,texte time);
void initialiser_texte1(texte *time1);
#endif
