#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"menu.h"
#include"fonctions.h"
#include"background.h"
#include "quit.h"
#include "setting.h"
#include "topscore.h"
void initialiser_backtopp(backs *backtop)
{
	backtop->img=IMG_Load("image/topscore/top score without.png");
	if(backtop->img==NULL) printf("%s",SDL_GetError());
	backtop->pos.x=0;
	backtop->pos.y=0;
}
void initialiser_bt_exit_top(boutton *exit_top)
{
	exit_top->img[0]=IMG_Load("image/topscore/EXIT non selectionnee.png");
	exit_top->img[1]=IMG_Load("image/topscore/exit selectionne.png");
	exit_top->pos.x=590;
	exit_top->pos.y=874;
	exit_top->pos.w=294;
	exit_top->pos.h=95;
	exit_top->p=0;
}
void go_topscore(SDL_Surface *screen,int *boocle)
{
	int btop=1;
	backs backtop;
	boutton exit_top;
	SDL_Event event;
	initialiser_backtopp(&backtop);
	initialiser_bt_exit_top(&exit_top);
	while (btop==1)
	{
		afficher(screen,backtop);
		afficher_btn(screen,exit_top);
	while (SDL_PollEvent(&event))
	{
		    
		switch(event.type)
		{
		case SDL_QUIT:
			    
			btop=0;
			*boocle=0;
		        break;
		case SDL_MOUSEMOTION:
			if((event.motion.x>=exit_top.pos.x && event.motion.x<=exit_top.pos.x+exit_top.pos.w) && 
			   (event.motion.y>=exit_top.pos.y && event.motion.y<=exit_top.pos.y+exit_top.pos.h))
			{
				animer_btn_set_op(&exit_top.p,1);
				}
				else
				{
				animer_btn_set_op(&exit_top.p,0);
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if((event.motion.x>=exit_top.pos.x && event.motion.x<=exit_top.pos.x+exit_top.pos.w) && 
			   (event.motion.y>=exit_top.pos.y && event.motion.y<=exit_top.pos.y+exit_top.pos.h))
			{
				btop=0;
			}
			break;
		

		}
	}
		SDL_Flip(screen);
	}
}
