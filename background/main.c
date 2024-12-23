#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"


int main()
{
	// declaration des variables
	int boocle=1;
	SDL_Event e;
	SDL_Surface *screen;
	vie_player v;
	score_info s;
	
	background b,ba[10];
	int i,direction=0;
	Mix_Music *musique;
	screen=SDL_SetVideoMode(1400,1000,32,SDL_HWSURFACE|SDL_SRCALPHA);
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	TTF_Init();
	initialiser_back(&b);
	init_imageVies(&v);
	s.score=100;
	
	init_scoreTexte(&s);
	musique=Mix_LoadMUS("/home/aziz/Documents/background/son/stage1_audio.mp3");
	Mix_PlayMusic(musique,-1);
	while (boocle==1)
	{ 	
		afficher(screen,b);
		animerBack(&b);
		afficher_imageVies(screen,v);
		
		afficher_scoreTexte(screen,s);
		
		while(SDL_PollEvent(&e))
		{
		switch(e.type)
		{
			case SDL_QUIT:
				boocle=0;
				break;
			case SDL_KEYDOWN:
				if(e.key.keysym.sym==SDLK_RIGHT){direction=1;}
				else if(e.key.keysym.sym==SDLK_LEFT){direction=2;}
				else if(e.key.keysym.sym==SDLK_DOWN){direction=3;}
				else if(e.key.keysym.sym==SDLK_UP){direction=4;}
				else if (e.key.keysym.sym==SDLK_ESCAPE)
					SDL_WM_ToggleFullScreen(screen);
				break;
			case SDL_KEYUP:
				if(e.key.keysym.sym==SDLK_RIGHT || e.key.keysym.sym==SDLK_LEFT || e.key.keysym.sym==SDLK_DOWN || e.key.keysym.sym==SDLK_UP){direction=0;}
			break;
			
		}
			
		}
		
		scrolling(&b,direction,&s);
		SDL_Flip(screen);
		SDL_Delay(50);
	}
	for(int i=0;i<12;i++)
	{
		SDL_FreeSurface(b.img[i]);
	}
	SDL_FreeSurface(screen);
	Mix_FreeMusic(musique);
	TTF_CloseFont(s.police);

	TTF_Quit();
}
