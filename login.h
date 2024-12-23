#ifndef LOGIN_H
#define LOGIN_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"
void initialiser_back_login(backs *back_login);
void initialiser_bt_done_log(boutton *done_log);
void initialiser_zone_usr(boutton *zone_usr);
void initialiser_zone_psw(boutton *zone_psw);
void initialiser_btn_sign(boutton *sign);
void initialiser_txt(text txt[]);
void afficher_txt(SDL_Surface *screen,text txt,char log[]);
player verifier_log(char mdp[],char log[],int *boocle);
player go_login(SDL_Surface *screen,int *boocle,int etat);
void initialiser_loki(background *loki);
void initialiser_backsigneup(backs *back_signeup);
void go_signup(SDL_Surface *screen,int *boocle);
int verifier_signup(char mdp[],char log[]);
void signe_up(char mdp[],char log[]);
void afficher_LOKIhide(SDL_Surface *screen,background loki);
void initialiser_lokiclose(backs *lokiclose);
void initialiser_eye(boutton *eye);
void afficher_eye(SDL_Surface *screen,boutton eye,int i);
void save_informationsPlayer(player p1);
#endif
