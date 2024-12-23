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
#include"stage2.h"
#include"minimap.h"
#include"game3.h"
#include "game2.h"
#include "xo.h"
#include "quit.h"
#include "setting.h"
#include "topscore.h"
#include "login.h"
#include"selectniv.h"
void initialiser_animationslogo(animations *logo)
{
	char nom[50],num[4];
	(*logo).nbr=166;
	for(int i=0;i<(*logo).nbr;i++)
	{
		strcpy(nom,"image/logo/");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*logo).img[i]=IMG_Load(nom);
	}
	(*logo).pos1.x=0;
	(*logo).pos1.y=0;
	(*logo).pos1.h=1200;
	(*logo).pos1.w=14956;
	(*logo).photo=0;
}

int main()
{
	player p;
	input_joueur input;
	animations logo,back_chargement;
	int boocle=2,select=1,repetition=0,volum=10,selct_input,selct_level,full=0,etat=0;
	SDL_Surface *screen;
	SDL_Event event;
	background back_menu;
	boutton play,exit,setting,tops;
	Mix_Music *musique;
	Mix_Chunk *song_bref;
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	screen=SDL_SetVideoMode(1400,1000,32,SDL_HWSURFACE|SDL_SRCALPHA);
	SDL_WM_ToggleFullScreen(screen);
	initialiser_animationslogo(&logo);
	for(int i=0;i<logo.nbr;i++)
	{
		afficher_animations(screen,logo);
		animer_animations(&logo);
		SDL_Flip(screen);
		SDL_FreeSurface(logo.img[i]);
		SDL_Delay(40);
	}
	while(boocle==2)
	{
		p=go_login(screen,&boocle,etat);
		if(boocle==2) etat=1;
	}
	initialiser_backmenu(&back_menu);
	initialiser_back_chargement(&back_chargement);
	initialiser_play(&play);
	initialiser_exit(&exit);
	initialiser_setting(&setting);
	initialiser_tops(&tops);
	initialiser_input(&input);
	musique=Mix_LoadMUS("son/music audio.mp3");
	song_bref=Mix_LoadWAV("son/pop-window-click-menu-info-35.wav");
	Mix_PlayMusic(musique,-1);
	while (boocle==1)
	{
		afficher_back(screen,back_menu);
		afficher_btn(screen,play);
		afficher_btn(screen,exit);
		afficher_btn(screen,setting);
		afficher_btn(screen,tops);
		animerBack(&back_menu);
		while(SDL_PollEvent(&event))
		{
		switch(event.type)
		{
			case SDL_QUIT:
				boocle=0;
				break;
			case SDL_MOUSEMOTION:
				if(event.motion.x>=play.pos.x && event.motion.x<=play.pos.x+play.pos.w)
				{
					if(event.motion.y>=play.pos.y && event.motion.y<=play.pos.y+play.pos.h)
					{
						animer_btns(&play.p,&exit.p,&setting.p,&tops.p,1,0,0,0);
						select=1;
						if(repetition==0){
						Mix_PlayChannel( -1,song_bref,0);
						repetition++;}
					}
					else if(event.motion.y>=exit.pos.y && event.motion.y<=exit.pos.y+play.pos.h)
					{
						animer_btns(&play.p,&exit.p,&setting.p,&tops.p,0,1,0,0);
						select=4;
						if(repetition==0){
						Mix_PlayChannel( -1,song_bref,0);	
						repetition=1;}
					}
					else if(event.motion.y>=setting.pos.y && event.motion.y<=setting.pos.y+play.pos.h)
					{
						animer_btns(&play.p,&exit.p,&setting.p,&tops.p,0,0,1,0);
						if(repetition==0){
						select=2;
						Mix_PlayChannel( -1,song_bref,0);
						repetition=1;}
					}
					else if(event.motion.y>=tops.pos.y && event.motion.y<=tops.pos.y+play.pos.h)
					{
						animer_btns(&play.p,&exit.p,&setting.p,&tops.p,0,0,0,1);
						select=3;
						if(repetition==0){
						Mix_PlayChannel( -1,song_bref,0);
						repetition=1;}
					}
				}
					else {
						animer_btns(&play.p,&exit.p,&setting.p,&tops.p,0,0,0,0);
						repetition=0;
						}
				break;
			case SDL_MOUSEBUTTONUP:
				if(event.motion.x>=play.pos.x && event.motion.x<=play.pos.x+play.pos.w)
				{
					if(event.motion.y>=exit.pos.y && event.motion.y<=exit.pos.y+play.pos.h)
					{
						go_quit(screen,&boocle);
					}
					else if(event.motion.y>=setting.pos.y && event.motion.y<=setting.pos.y+play.pos.h)
					{
						go_setting(screen,&boocle,&volum,&input,&full);
					}
					else if (event.motion.y>=tops.pos.y && event.motion.y<=tops.pos.y+play.pos.h)
					{
						go_topscore(screen,&boocle);
					}
					else if (event.motion.y>=play.pos.y && event.motion.y<=play.pos.y+play.pos.h)
					{
						go_select_level(screen,&boocle,back_chargement,input,p);
					}
				}	
				break;
				case SDL_KEYDOWN:
				
				if(event.key.keysym.sym==SDLK_DOWN)
				{
					select++;
					if(select>4) select=1;
				}
				else if(event.key.keysym.sym==SDLK_UP)
				{
					select--;
					if(select<1) select=4;
				}
				else if (event.key.keysym.sym==SDLK_RETURN)
				{
					if(select==4) go_quit(screen,&boocle);
					else if(select==1)
					{ 
					go_select_level(screen,&boocle,back_chargement,input,p);
					}
				}
				else if (event.key.keysym.sym==SDLK_ESCAPE)
				{
					SDL_WM_ToggleFullScreen(screen);
					if(full==1)full=0;
					else full=1;
				}
				else if(event.key.keysym.sym==SDLK_p) select=1;
				else if(event.key.keysym.sym==SDLK_s) select=2;
				else if(event.key.keysym.sym==SDLK_t) select=3;
				else if(event.key.keysym.sym==SDLK_q) select=4;
				switch(select)
				{
					case 1:
						animer_btns(&play.p,&exit.p,&setting.p,&tops.p,1,0,0,0);
						break;
					case 2:
						animer_btns(&play.p,&exit.p,&setting.p,&tops.p,0,0,1,0);
						break;
					case 3:
						animer_btns(&play.p,&exit.p,&setting.p,&tops.p,0,0,0,1);
						break;
					case 4:
						animer_btns(&play.p,&exit.p,&setting.p,&tops.p,0,1,0,0);
						break;
				}
				break;
		}

		}
	SDL_Flip(screen);
	SDL_Delay(70);
	}
	Mix_FreeMusic(musique);
	Mix_FreeChunk(song_bref);

}
