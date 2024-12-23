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
void initialiser_backmenu(background *b)
{
	char nom[100],num[3];
	for(int i=0;i<10;i++)
	{
		strcpy(nom,"image/menu/an");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		b->img[i]=IMG_Load(nom);
	}
	b->pos1.x=0;
	b->pos1.y=0;
	b->pos2.x=0;
	b->pos2.y=0;
	b->pos2.h=1000;
	b->pos2.w=1400;
	b->photo=0;
	b->nbr=10;
}
void initialiser_back_chargement(animations *b)
{
	char nom[50],num[4];
	(*b).nbr=32;
	for(int i=0;i<(*b).nbr;i++)
	{
		strcpy(nom,"image/chargement/animeloading/");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*b).img[i]=IMG_Load(nom);
	}
	(*b).pos1.x=0;
	(*b).pos1.y=0;
	(*b).pos1.h=1200;
	(*b).pos1.w=14956;
	(*b).photo=0;
}
void initialiser_play(boutton *play)
{
	play->img[0]=IMG_Load("image/menu/play1.png");
	play->img[1]=IMG_Load("image/menu/play2.png");
	play->pos.x=538;
	play->pos.y=373;
	play->pos.h=105;
	play->pos.w=325;
	play->p=0;
}
void initialiser_exit(boutton *exit)
{
	exit->img[0]=IMG_Load("image/menu/exit1.png");
	exit->img[1]=IMG_Load("image/menu/exit2.png");
	exit->pos.x=538;
	exit->pos.y=788;
	exit->p=0;
}
void initialiser_setting(boutton *setting)
{
	setting->img[0]=IMG_Load("image/menu/setting1.png");
	setting->img[1]=IMG_Load("image/menu/setting2.png");
	setting->pos.x=538;
	setting->pos.y=512;
	setting->p=0;
}
void initialiser_tops(boutton *tops)
{
	tops->img[0]=IMG_Load("image/menu/topscore1.png");
	tops->img[1]=IMG_Load("image/menu/topscore2.png");
	tops->pos.x=538;
	tops->pos.y=650;
	tops->p=0;
}

/*void initialiser_backselct_lev(backs *backlvl)
{
	backlvl->img=IMG_Load("image/play_/play_selct/bg_playselct2.png");
	if(backlvl->img==NULL) printf("%s",SDL_GetError());
	backlvl->pos.x=0;
	backlvl->pos.y=0;
}

void initialiser_bt_letsgo1(boutton *letsgo1)
{
	letsgo1->img[0]=IMG_Load("image/play_/play_selct/letsgoo1.png");
	letsgo1->img[1]=IMG_Load("image/play_/play_selct/letsgoo2.png");
	letsgo1->pos.x=85;
	letsgo1->pos.y=754;
	letsgo1->pos.w=325;
	letsgo1->pos.h=105;
	letsgo1->p=0;
}
void initialiser_bt_letsgo2(boutton *letsgo2)
{
	letsgo2->img[0]=IMG_Load("image/play_/play_selct/letsgoo1.png");
	letsgo2->img[1]=IMG_Load("image/play_/play_selct/letsgoo2.png");
	letsgo2->pos.x=532;
	letsgo2->pos.y=754;
	letsgo2->pos.w=325;
	letsgo2->pos.h=105;
	letsgo2->p=0;
}
void initialiser_bt_letsgo3(boutton *letsgo3)
{
	letsgo3->img[0]=IMG_Load("image/play_/play_selct/letsgoo1.png");
	letsgo3->img[1]=IMG_Load("image/play_/play_selct/letsgoo2.png");
	letsgo3->pos.x=979;
	letsgo3->pos.y=754;
	letsgo3->pos.w=325;
	letsgo3->pos.h=105;
	letsgo3->p=0;
}

void initialiser_bt_solo1(boutton *solo1)
{
	solo1->img[0]=IMG_Load("image/play_/play_selct/solo1.png");
	solo1->img[1]=IMG_Load("image/play_/play_selct/solo2.png");
	solo1->pos.x=85;
	solo1->pos.y=754;
	solo1->pos.w=162;
	solo1->pos.h=105;
	solo1->p=0;
}
void initialiser_bt_solo2(boutton *solo2)
{
	solo2->img[0]=IMG_Load("image/play_/play_selct/solo1.png");
	solo2->img[1]=IMG_Load("image/play_/play_selct/solo2.png");
	solo2->pos.x=532;
	solo2->pos.y=754;
	solo2->pos.w=162;
	solo2->pos.h=105;
	solo2->p=0;
}
void initialiser_bt_duo1(boutton *duo1)
{
	duo1->img[0]=IMG_Load("image/play_/play_selct/duo1.png");
	duo1->img[1]=IMG_Load("image/play_/play_selct/duo2.png");
	duo1->pos.x=249;
	duo1->pos.y=754;
	duo1->pos.w=162;
	duo1->pos.h=105; 
	duo1->p=0;
}
void initialiser_bt_duo2(boutton *duo2)
{
	duo2->img[0]=IMG_Load("image/play_/play_selct/duo1.png");
	duo2->img[1]=IMG_Load("image/play_/play_selct/duo2.png");
	duo2->pos.x=694;
	duo2->pos.y=754;
	duo2->pos.w=162;
	duo2->pos.h=105;
	duo2->p=0;
}
void go_select_level(SDL_Surface *screen,int *boocle,background back_chargement,input_joueur input)
{
	int blevel=1,select=0,etat=2,lv1=0,lv2=0;
	backs backlvl;
	boutton letsgo1,letsgo2,letsgo3,solo1,solo2,duo1,duo2;
	SDL_Event event;
	initialiser_backselct_lev(&backlvl);
	initialiser_bt_letsgo1(&letsgo1);
	initialiser_bt_letsgo2(&letsgo2);
	initialiser_bt_letsgo3(&letsgo3);
	initialiser_bt_solo1(&solo1);
	initialiser_bt_solo2(&solo2);
	initialiser_bt_duo1(&duo1);
	initialiser_bt_duo2(&duo2);
	while (blevel==1)
	{
		afficher(screen,backlvl);
		if(lv1==0)afficher_btn(screen,letsgo1);
		if(lv2==0)afficher_btn(screen,letsgo2);
		//afficher_btn(screen,letsgo3);
		//afficher_btn(screen,letsgo4);
		if (etat==0)
		{
			afficher_btn(screen,solo1);
			afficher_btn(screen,duo1);
		}
		else if (etat==1)
		{
			afficher_btn(screen,solo2);
			afficher_btn(screen,duo2);
		}
	while (SDL_PollEvent(&event))
	{
		    
		switch(event.type)
		{
		case SDL_QUIT:
			    
			blevel=0;
			*boocle=0;
		        break;
		case SDL_MOUSEMOTION:
			if((event.motion.x>=letsgo1.pos.x && event.motion.x<=letsgo1.pos.x+letsgo1.pos.w) && 
			   (event.motion.y>=letsgo1.pos.y && event.motion.y<=letsgo1.pos.y+letsgo1.pos.h))
			{
				
				etat=0;
				if((event.motion.x>=solo1.pos.x && event.motion.x<=solo1.pos.x+solo1.pos.w) && 
			   	   (event.motion.y>=solo1.pos.y && event.motion.y<=solo1.pos.y+solo1.pos.h))
				{
					lv1=1;
					animer_btns_selectlev(&solo1.p,&duo1.p,1,0);
				}
				else if((event.motion.x>=duo1.pos.x && event.motion.x<=duo1.pos.x+duo1.pos.w) && 
			   		(event.motion.y>=duo1.pos.y && event.motion.y<=duo1.pos.y+duo1.pos.h))
				{
					lv1=1;
					animer_btns_selectlev(&solo1.p,&duo1.p,0,1);
				}
				
			}
			
			else if((event.motion.x>=letsgo2.pos.x && event.motion.x<=letsgo2.pos.x+letsgo2.pos.w) && 
			   	(event.motion.y>=letsgo2.pos.y && event.motion.y<=letsgo2.pos.y+letsgo2.pos.h))
			{
				
				etat=1;
				if((event.motion.x>=solo2.pos.x && event.motion.x<=solo2.pos.x+solo2.pos.w) && 
			   	   (event.motion.y>=solo2.pos.y && event.motion.y<=solo2.pos.y+solo2.pos.h))
				{
					lv2=1;
					animer_btns_selectlev(&solo2.p,&duo2.p,1,0);
				}
				else if((event.motion.x>=duo2.pos.x && event.motion.x<=duo2.pos.x+duo2.pos.w) && 
			   		(event.motion.y>=duo2.pos.y && event.motion.y<=duo2.pos.y+duo2.pos.h))
				{
					lv2=1;
					animer_btns_selectlev(&solo2.p,&duo2.p,0,1);
				}
				
			}
			else 
				{
				animer_btns_selectlev(&solo1.p,&duo1.p,0,0);
				lv1=0;
				lv2=0;
				etat=2;
				}
			break;
		case SDL_MOUSEBUTTONUP:
			if((event.motion.x>=solo1.pos.x && event.motion.x<=solo1.pos.x+solo1.pos.w) && 
			  (event.motion.y>=solo1.pos.y && event.motion.y<=solo1.pos.y+solo1.pos.h))
			{
				afficher_back(screen,back_chargement);
				SDL_Flip(screen);
				stage1(screen,back_chargement,input);
			}
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym==SDLK_ESCAPE)
					SDL_WM_ToggleFullScreen(screen);
			else if (event.key.keysym.sym==SDLK_r)
				blevel=0;
			break;

		}
	}
		SDL_Flip(screen);
	}
	
}



void animer_btns_selectlev(int *solo,int *duo,int solox,int duox)
{
	*solo=solox;
	*duo=duox;
}























void afficher_btn(SDL_Surface *screen,boutton btn)
{
	SDL_BlitSurface(btn.img[btn.p],NULL,screen,&btn.pos);
}
void afficher(SDL_Surface *screen,backs imge)
{
	SDL_BlitSurface(imge.img,NULL,screen,&imge.pos);
}*/

void animer_btns(int *p,int *e,int *t,int *s,int px,int ex,int tx,int sx)
{
	*p=px;
	*e=ex;
	*t=tx;
	*s=sx;
}

