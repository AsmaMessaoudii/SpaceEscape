#ifndef MINIMAP_H
#define MINIMAP_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
#include "ES.h"
#include "background.h"
#include "perso.h"
#include "stage1.h"
typedef struct
{
	SDL_Rect pos1;
	SDL_Rect pos2;
	SDL_Surface *img;
}image;

typedef struct
{
SDL_Surface * image_minimap;
SDL_Rect position_minimap;
SDL_Surface * image_bonhomme;
SDL_Rect position_bonhomme;
SDL_Surface * image_obstacle;
SDL_Rect position_obstacle[5];
SDL_Surface * image_lazer;
SDL_Rect position_lazer[2];
SDL_Surface *image_spike;
SDL_Rect position_spike;
SDL_Surface * image_alien;
SDL_Rect position_alien[4];
SDL_Surface * image_buttom1;
SDL_Rect position_buttom1;
SDL_Surface * image_buttom2;
SDL_Rect position_buttom2;
SDL_Surface *image_dynamique;
SDL_Rect position_dynamique;

}minimap;


//init
void initialiser_texte(texte *temp);
void initmap(minimap *m,int nb_stage);
void initialiser_Masque(image *masque);
//afficher
void afficher_imge(SDL_Surface *screen,image imge);
void afficherminimap ( SDL_Surface * screen,minimap m,texte temp,int nb_stage,trap t[],enmie e[],obstacles o);
void afficher_texte(SDL_Surface *screen,texte message);
//MAJ
void ajout(texte *time);
void animerMinimap(SDL_Surface * screen,minimap m,trap t[],enmie e[],obstacles o,int nb_stage); 
void MAJMinimap(perso p,minimap *m,obstacles o,enmie e[],background back,int nb_stage);
int collisionPP(perso p, image *Masque);
SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
//liberer
void free_minimap(minimap m,int nb_stage);
#endif
