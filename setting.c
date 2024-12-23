#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"menu.h"
#include"fonctions.h"
#include"background.h"
#include"stage1.h"
#include "quit.h"
#include "setting.h"
#include "topscore.h"
void initialiser_backsett(backs *backsett)
{
	backsett->img=IMG_Load("image/setting/new_sett/bg_SETTING.png");
	if(backsett->img==NULL) printf("%s",SDL_GetError());
	backsett->pos.x=0;
	backsett->pos.y=0;
}
void initialiser_back_op_sett(backs *backop)
{
	backop->img=IMG_Load("image/setting/opption/bg_option.png");
	if(backop->img==NULL) printf("%s",SDL_GetError());
	backop->pos.x=0;
	backop->pos.y=0;
}
void initialiser_bt_done_set(boutton *done_set)
{
	done_set->img[0]=IMG_Load("image/setting/new_sett/DONE1.png");
	done_set->img[1]=IMG_Load("image/setting/new_sett/DONE2.png");
	done_set->pos.x=574;
	done_set->pos.y=768;
	done_set->pos.w=325;
	done_set->pos.h=105;
	done_set->p=0;
}
void initialiser_bt_full_on(boutton *full_on)
{
	full_on->img[0]=IMG_Load("image/setting/new_sett/full_off.png");
	full_on->img[1]=IMG_Load("image/setting/new_sett/full_on.png");
	full_on->pos.x=833;
	full_on->pos.y=600;
	full_on->pos.w=66;
	full_on->pos.h=60;
	full_on->p=0;
}
void initialiser_bt_plus_set(boutton *plus_set)
{
	plus_set->img[0]=IMG_Load("image/setting/new_sett/plus1.png");
	plus_set->img[1]=IMG_Load("image/setting/new_sett/plus2.png");
	plus_set->pos.x=810;
	plus_set->pos.y=430;
	plus_set->pos.w=61;
	plus_set->pos.h=71;
	plus_set->p=0;
}
void initialiser_bt_moin_set(boutton *moin_set)
{
	moin_set->img[0]=IMG_Load("image/setting/new_sett/moin1.png");
	moin_set->img[1]=IMG_Load("image/setting/new_sett/moin2.png");
	moin_set->pos.x=580;
	moin_set->pos.y=430;
	moin_set->pos.w=61;
	moin_set->pos.h=71;
	moin_set->p=0;
}
void initialiser_bt_return_set(boutton *return_set)
{
	return_set->img[0]=IMG_Load("image/setting/new_sett/return_set1.png");
	return_set->img[1]=IMG_Load("image/setting/new_sett/return_set2.png");
	return_set->pos.x=944;
	return_set->pos.y=323;
	return_set->pos.w=73;
	return_set->pos.h=71;
	return_set->p=0;
}
void initialiser_bt_option_set(boutton *option_set)
{
	option_set->img[0]=IMG_Load("image/setting/new_sett/option1.png");
	option_set->img[1]=IMG_Load("image/setting/new_sett/option2.png");
	option_set->pos.x=430;
	option_set->pos.y=323;
	option_set->pos.w=73;
	option_set->pos.h=71;
	option_set->p=0;
}
void initialiser_bt_son_set(boutton *son_set)
{
	son_set->img[0]=IMG_Load("image/setting/new_sett/son_icone.png");
	son_set->img[1]=IMG_Load("image/setting/new_sett/mute_icone.png");
	son_set->pos.x=688;
	son_set->pos.y=430;
	son_set->pos.w=73;
	son_set->pos.h=71;
	son_set->p=0;
}
void initialiser_bt_on_opset(backs *on_opset1)
{
	on_opset1->img=IMG_Load("image/setting/opption/on_op.png");
	if(on_opset1->img==NULL) printf("%s",SDL_GetError());
	on_opset1->pos.x=997;
	on_opset1->pos.y=50;
}
void initialiser_bt_off_opset(backs *on_opset2)
{
	on_opset2->img=IMG_Load("image/setting/opption/on_op.png");
	if(on_opset2->img==NULL) printf("%s",SDL_GetError());
	on_opset2->pos.x=331;
	on_opset2->pos.y=50;
}
void initialiser_bt_return_opset(boutton *return_opset)
{
	return_opset->img[0]=IMG_Load("image/setting/opption/return_opset1.png");
	return_opset->img[1]=IMG_Load("image/setting/opption/return_opset2.png");
	return_opset->pos.x=1305;
	return_opset->pos.y=15;
	return_opset->pos.w=73;
	return_opset->pos.h=71;
	return_opset->p=0;
}

void go_setting(SDL_Surface *screen,int *boocle,int *volum,input_joueur *input,int *pfull)
{
	int bsetting=1 ,full=128;
	backs backsett;
	boutton done_set,full_on,plus_set,moin_set,return_set,option_set,son_set;
	SDL_Event event;
	initialiser_backsett(&backsett);
	initialiser_bt_done_set(&done_set);
	initialiser_bt_full_on(&full_on);
	initialiser_bt_plus_set(&plus_set);
	initialiser_bt_moin_set(&moin_set);
	initialiser_bt_return_set(&return_set);
	initialiser_bt_option_set(&option_set);
	initialiser_bt_son_set(&son_set);
	while(bsetting)
	{
		afficher(screen,backsett);
		afficher_btn(screen,done_set);
		afficher_btn(screen,full_on);
		afficher_btn(screen,plus_set);
		afficher_btn(screen,moin_set);
		afficher_btn(screen,return_set);
		afficher_btn(screen,option_set);
		afficher_btn(screen,son_set);
		full_on.p=*pfull;
		while(SDL_PollEvent(&event))
		{
		switch(event.type)
			{
			case SDL_QUIT:
			bsetting=0;
			*boocle=0;
		        break;
			case SDL_MOUSEMOTION:
				if((event.motion.x>=done_set.pos.x && event.motion.x<=done_set.pos.x+done_set.pos.w) && 
				   (event.motion.y>=done_set.pos.y && event.motion.y<=done_set.pos.y+done_set.pos.h))
				{
					animer_btns_setting(&done_set.p,&full_on.p,&plus_set.p,&moin_set.p,&return_set.p,&option_set.p,&son_set.p,1,full_on.p,0,0,0,0,son_set.p);
				}
				else if((event.motion.x>=plus_set.pos.x && event.motion.x<=plus_set.pos.x+plus_set.pos.w) && 
				   (event.motion.y>=plus_set.pos.y && event.motion.y<=plus_set.pos.y+plus_set.pos.h))
				{
					animer_btns_setting(&done_set.p,&full_on.p,&plus_set.p,&moin_set.p,&return_set.p,&option_set.p,&son_set.p,0,full_on.p,1,0,0,0,son_set.p);
				}
				else if((event.motion.x>=moin_set.pos.x && event.motion.x<=moin_set.pos.x+moin_set.pos.w) && 
				   (event.motion.y>=moin_set.pos.y && event.motion.y<=moin_set.pos.y+moin_set.pos.h))
				{
					animer_btns_setting(&done_set.p,&full_on.p,&plus_set.p,&moin_set.p,&return_set.p,&option_set.p,&son_set.p,0,full_on.p,0,1,0,0,son_set.p);
				}
				else if((event.motion.x>=return_set.pos.x && event.motion.x<=return_set.pos.x+return_set.pos.w) && 
				   (event.motion.y>=return_set.pos.y && event.motion.y<=return_set.pos.y+return_set.pos.h))
				{
					animer_btns_setting(&done_set.p,&full_on.p,&plus_set.p,&moin_set.p,&return_set.p,&option_set.p,&son_set.p,0,full_on.p,0,0,1,0,son_set.p);
				}
				else if((event.motion.x>=option_set.pos.x && event.motion.x<=option_set.pos.x+option_set.pos.w) && 
				   (event.motion.y>=option_set.pos.y && event.motion.y<=option_set.pos.y+option_set.pos.h))
				{
					animer_btns_setting(&done_set.p,&full_on.p,&plus_set.p,&moin_set.p,&return_set.p,&option_set.p,&son_set.p,0,full_on.p,0,0,0,1,son_set.p);
				}
				else 
				{
				animer_btns_setting(&done_set.p,&full_on.p,&plus_set.p,&moin_set.p,&return_set.p,&option_set.p,&son_set.p,0,full_on.p,0,0,0,0,son_set.p);
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if((event.motion.x>=return_set.pos.x && event.motion.x<=return_set.pos.x+return_set.pos.w) && 
				   (event.motion.y>=return_set.pos.y && event.motion.y<=return_set.pos.y+return_set.pos.h))
					bsetting=0;
				else if ((event.motion.x>=done_set.pos.x && event.motion.x<=done_set.pos.x+done_set.pos.w) && 
				   (event.motion.y>=done_set.pos.y && event.motion.y<=done_set.pos.y+done_set.pos.h))
					bsetting=0;
				else if((event.motion.x>=plus_set.pos.x && event.motion.x<=plus_set.pos.x+plus_set.pos.w) && 
				   (event.motion.y>=plus_set.pos.y && event.motion.y<=plus_set.pos.y+plus_set.pos.h) && (*volum)<10)
					{
					(*volum)++;
					if(*volum==1) son_set.p=0;
					Mix_VolumeMusic((full*(*volum)*10)/100);
					}
				else if((event.motion.x>=moin_set.pos.x && event.motion.x<=moin_set.pos.x+moin_set.pos.w) && 
				   (event.motion.y>=moin_set.pos.y && event.motion.y<=moin_set.pos.y+moin_set.pos.h))
					{
						(*volum)--;
						if ((*volum)==0) son_set.p=1;			
						Mix_VolumeMusic((full*(*volum)*10)/100);
					}
				else if((event.motion.x>=full_on.pos.x && event.motion.x<=full_on.pos.x+full_on.pos.w) && 
				   (event.motion.y>=full_on.pos.y && event.motion.y<=full_on.pos.y+full_on.pos.h))
					{
						SDL_WM_ToggleFullScreen(screen);
						if (*pfull==0) *pfull=1;
						else *pfull=0;
						
					}
				else if((event.motion.x>=son_set.pos.x && event.motion.x<=son_set.pos.x+son_set.pos.w) && 
				   (event.motion.y>=son_set.pos.y && event.motion.y<=son_set.pos.y+son_set.pos.h))
					{
						if(*volum!=0)
						{
							*volum=0;
							son_set.p=1;
							Mix_VolumeMusic((full*(*volum)*10)/100);
						}
						else
						{
							*volum=1;
							son_set.p=0;
							Mix_VolumeMusic((full*(*volum)*10)/100);
						}
					}
				else if((event.motion.x>=option_set.pos.x && event.motion.x<=option_set.pos.x+option_set.pos.w) && 
				   (event.motion.y>=option_set.pos.y && event.motion.y<=option_set.pos.y+option_set.pos.h))
					{
						go_option_set(screen,&(*boocle),input);
					}
				break;
			/*case SDL_KEYDOWN:
				break;*/
			}
		}
	SDL_Flip(screen);
	}
}
void go_option_set(SDL_Surface *screen,int *boocle,input_joueur *input)
{
	int boption=1,selection=0,etat=0;
	backs backop ,on_opset1,on_opset2 ;
	boutton return_opset;
	SDL_Event event;
	initialiser_back_op_sett(&backop);
	initialiser_bt_on_opset(&on_opset1);
	initialiser_bt_off_opset(&on_opset2);
	initialiser_bt_return_opset(&return_opset);
	while(boption)
	{
		afficher(screen,backop);
		afficher_btn(screen,return_opset);
		if((*input).choix==1)
		{
			afficher(screen,on_opset2);
		}
		else
		{
			afficher(screen,on_opset1);
		}
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
				boption=0;
				*boocle=0;
				break;
				case SDL_MOUSEMOTION:
					if((event.motion.x>=return_opset.pos.x && event.motion.x<=return_opset.pos.x+return_opset.pos.w) && 
				   (event.motion.y>=return_opset.pos.y && event.motion.y<=return_opset.pos.y+return_opset.pos.h))
					{
						animer_btn_set_op(&return_opset.p,1);
					}
					else
					{
						animer_btn_set_op(&return_opset.p,0);
					}
				break;
				case SDL_MOUSEBUTTONUP:
					if((event.motion.x>=return_opset.pos.x && event.motion.x<=return_opset.pos.x+return_opset.pos.w) && 
				   (event.motion.y>=return_opset.pos.y && event.motion.y<=return_opset.pos.y+return_opset.pos.h))
					{
						boption=0;
					}
					else if((event.motion.x>=151 && event.motion.x<=583) && 
				   (event.motion.y>=234 && event.motion.y<=516))
					{
						afficher(screen,on_opset2);
						selection=1;
						(*input).choix=1;
						(*input).up=SDLK_z;
						(*input).down=SDLK_s;
						(*input).left=SDLK_q;
						(*input).right=SDLK_d;
						(*input).attack=SDLK_SPACE;
						etat=0;
						
		printf("r=%c\n",(*input).left);
					}
					else if((event.motion.x>=817 && event.motion.x<=1249) && 
				   (event.motion.y>=218 && event.motion.y<=500))
					{
						afficher(screen,on_opset1);
						selection=0;
						(*input).choix=0;
						(*input).up=SDLK_UP;
						(*input).down=SDLK_DOWN;
						(*input).left=SDLK_LEFT;
						(*input).right=SDLK_RIGHT;
						(*input).attack=SDLK_l;
						etat=1;
						
		printf("r=%c\n",(*input).left);
					}
					
				break;
			}
		}
		SDL_Flip(screen);
	}

}
void animer_btn_set_op(int *return_op,int return_opx)
{
	*return_op=return_opx;
}
void animer_btns_setting(int *done_s,int *full_s,int *plus_s,int *moin_s,int *return_s,int *option_s,int *son_s,int done_sx,int full_sx,int plus_sx,int moin_sx,int return_sx,int option_sx,int son_sx)
{
	*done_s=done_sx;
	*full_s=full_sx;
	*plus_s=plus_sx;
	*moin_s=moin_sx;
	*return_s=return_sx;
	*option_s=option_sx;
	*son_s=son_sx;
}
void initialiser_input(input_joueur *input)
{
	(*input).up=SDLK_UP;
	(*input).down=SDLK_DOWN;
	(*input).left=SDLK_LEFT;
	(*input).right=SDLK_RIGHT;
	(*input).attack=SDLK_l;
}
















