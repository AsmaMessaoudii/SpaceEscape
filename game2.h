#ifndef GAME2_H
#define GAME2_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

void initialiser_backgame2(image back_game2[]);
void initialiser_etat(int etat[]);
void init_card_vide(image vide[]);
void initialise_tabcart(int tab_carte[],image tab_carteimage[]);
void afficher_cartes(SDL_Surface *screen,image tab_carteimage[]);
void afficher_unecarte(SDL_Surface *screen,image imge);
int verif_tab(int tab_carte[],int carte,int n);
void afficher_backgame2(SDL_Surface *screen,image back_game2[]);
void init_cartevide(image vide[]);
int game2(SDL_Surface *screen);
#endif
