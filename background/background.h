#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
	SDL_Rect pos1;
	SDL_Rect pos2;
	SDL_Surface *img[6];
	int photo;
}background;
typedef struct
{
	SDL_Rect pos;
	TTF_Font *police;
	SDL_Surface *txt;
	SDL_Color color;
	int score;
	int temps;
	char ch[20];
	char player_name[20];
}score_info;
typedef struct
{
	SDL_Rect pos;
	SDL_Surface *img[4];
	int nb_vie;
}vie_player;
typedef struct
{
	char player_name[20];
	char mdp[20];
	int top_score;
	int time;
}play;
void initialiser_back(background *b);
void afficher(SDL_Surface *screen,background imge);
void scrolling(background *b,int direction,score_info *s);
void animerBack(background ba[]);
void init_scoreTexte(score_info *s);
void afficher_scoreTexte(SDL_Surface *screen,score_info s);
void init_imageVies(vie_player *v);
void afficher_imageVies(SDL_Surface *screen,vie_player v);
void save_score(score_info s,char *fileName);
void best_score(score_info t[],char *fileName);
void animerVies(vie_player *v);
void afficherBest(score_info t[],char *fileName);
#endif
