#ifndef SETTING_H
#define SETTING_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"
void initialiser_backsett(backs *backsett);
void initialiser_back_op_sett(backs *backop);
void initialiser_bt_done_set(boutton *done_set);
void initialiser_bt_full_on(boutton *full_on);
void initialiser_bt_plus_set(boutton *plus_set);
void initialiser_bt_moin_set(boutton *moin_set);
void initialiser_bt_return_set(boutton *return_set);
void initialiser_bt_option_set(boutton *option_set);
void initialiser_bt_son_set(boutton *son_set);
void initialiser_bt_on_opset(backs *on_opset1);
void initialiser_bt_off_opset(backs *on_opset2);
void animer_btns_setting(int *done_s,int *full_s,int *plus_s,int *moin_s,int *return_s,int *option_s,int *son_s,int done_sx,int full_sx,int plus_sx,int moin_sx,int return_sx,int option_sx,int son_sx);
void animer_btn_set_op(int *return_op,int return_opx);
void go_setting(SDL_Surface *screen,int *boocle,int *volum,input_joueur *input,int *pfull);
void go_option_set(SDL_Surface *screen,int *boocle,input_joueur *input);
void initialiser_input(input_joueur *input);














#endif
