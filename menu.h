#ifndef MENU_H
#define MENU_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"
typedef struct
{
	SDL_Surface *img[2];
	SDL_Rect pos;
	int p;
}boutton;

void initialiser_backmenu(background *back);
void initialiser_back_chargement(animations *back);
/*void initialiser_bt_letsgo1(boutton *letsgo1);
void initialiser_bt_letsgo2(boutton *letsgo2);
void initialiser_bt_letsgo3(boutton *letsgo3);
void initialiser_bt_solo1(boutton *solo1);
void initialiser_bt_solo2(boutton *solo2);
void initialiser_bt_duo1(boutton *duo1);
void initialiser_bt_duo2(boutton *duo2);*/
void initialiser_play(boutton *play);
void initialiser_exit(boutton *exit);
void initialiser_setting(boutton *setting);
void initialiser_tops(boutton *tops);
//void animer_btns_selectlev(int *solo,int *duo,int solox,int duox);		
//void afficher_btn(SDL_Surface *screen,boutton btn);
void animer_btns(int *p,int *e,int *t,int *s,int px,int ex,int tx,int sx);
//void afficher(SDL_Surface *screen,backs imge);
//void go_select_level(SDL_Surface *screen,int *boocle,background back_chargement,input_joueur input);
#endif
