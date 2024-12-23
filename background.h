#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
void afficher_back(SDL_Surface *screen,background b);
void initialiser_backSTAGE1(background *b);
void scrolling(background *b, int direction,int v);
void animerBack(background ba[]);
void liberer_image(background *imge);
void afficher_minicris(SDL_Surface *screen,collections c);
void afficher_scoreTexte(SDL_Surface *screen,score_info s);
void init_scoreTexte(score_info *s);
#endif
