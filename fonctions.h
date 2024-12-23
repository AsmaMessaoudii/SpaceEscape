#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
typedef struct
{
	SDL_Surface *img;
	SDL_Rect pos[7][6];
	
}image_perso;
typedef struct
{
	image_perso etat_droite;
	image_perso etat_gauche;
	SDL_Rect pos;
	int dir;
	int etat;
	int haut;
	int mouvment;
	int movsaut;
	int saut;
	int vitesse;
	int maxsaut;
	int vie;
	int h;
	int b;
	int d;
	int g;
}perso;
typedef struct
{
	SDL_Surface *img;    
	SDL_Rect pos[3][8];
	
}image_enmie;
typedef struct
{
	image_enmie etat_droite;
	image_enmie etat_gauche;
	SDL_Rect pos;
	SDL_Rect champs_visuelle;
	int dir;
	int etat;
	int mouvment;
	int pas;
}enmie;
typedef struct
{
	SDL_Rect pos1;
	SDL_Rect pos2;
	SDL_Surface *img[12];
	int photo;
	int nbr;
}background;
typedef struct
{
	SDL_Surface *img_obS[5];
	SDL_Surface *img_obA[5];
	SDL_Rect pos[20];
	SDL_Rect pos2[10];
	int pos_max[10];
	int pos_min[10];
	int dir[10];
	int etat[10];
	int p[5];
	int tomber[5];
	int nbr_h;
	int nbr_v;
	int nbr_a;
	int nbr;
	int nbr_pA;
	int r[5];
	
}obstacles;
typedef struct
{
	SDL_Surface *img;
	SDL_Rect pos1;
	SDL_Rect pos2;
	int time;
	int etat;
	int r;
	
}trap;
typedef struct
{
	SDL_Surface *img[2];
	SDL_Rect pos1[3];
	SDL_Rect pos2[3];
	int etat;
	int p[3];
}checkpoint;
typedef struct
{
	SDL_Rect pos;
	SDL_Surface *img[4];
	int nb_vie;
}vie_player;
typedef struct
{
	SDL_Surface *img[4];
	SDL_Rect pos[5];
	int p;
	int nbr;
	SDL_Surface *img_mini;
	SDL_Rect pos_mini[2];
	TTF_Font *police;
	SDL_Surface *txt;
	SDL_Color color[2];
}collections;
typedef struct
{
	SDL_Surface *img;
	SDL_Rect pos[3];
	int dir[3];
	int nbr;
	int r;
}shot;
typedef struct
{
	int up;
	int down;
	int left;
	int right;
	int attack;
	int choix;
}input_joueur;
typedef struct
{
	SDL_Rect pos;
	SDL_Surface *img;
}backs;
typedef struct
{
	SDL_Surface *txt;
	SDL_Rect pos_txt;
	SDL_Colour color_txt;
	TTF_Font *police;
	int s,m,h;
	char nom[10];
}texte;
typedef struct
{
	SDL_Surface *img;
	SDL_Rect pos[2];
	SDL_Rect pos2[2];
	int etat;
	int r;
}lazer;
typedef struct
{
	SDL_Rect pos;
	TTF_Font *police;
	SDL_Surface *txt;
	SDL_Color color;
	int score;
	char temps[20];
	char ch[20];
	char player_name[20];
}score_info;
#endif
