#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ES.h"
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
#include "perso.h"
#include "enigme.h"
player stage1(SDL_Surface *screen,animations back_chargement,input_joueur input,int select_perso,player p1)
{
	//declarations des variable
	srand(time(NULL));
	int boocle=1,c_obstacles[2],c_enmie,c_champ,c_traps,c_collections,c_checkpoint,time,nb_stage=1,resume;
	SDL_Event event;
	trap t[2];
	enmie e[4];
	background back,back_hardluck,back_goodluck;
	vie_player vie;
	obstacles o;
	score_info s;
	checkpoint ch;
	perso p;
	collections c;
	shot sh;
	minimap m;
	texte temp;
	image masque;
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	//initialisations des variables
	TTF_Init();
	initmap(&m,1);
	
	initialiser_backSTAGE1(&back,back_chargement,screen);
	
	init_imageVies(&vie);
	init_scoreTexte(&s);
	initenmieSTAGE1(e);
	initialiser_texte(&temp);
	initialiser_obstaclesSTAGE1(&o);
	initialiser_trapSTAGE1(t);
	initialiser_chekpointSTAGE1(&ch);
	initialiser_collectionsSTAGE1(&c,o.pos);
	initialiser_back_hardluck(&back_hardluck);
	initialiser_back_goodluck(&back_goodluck);
	initPerso(&p,select_perso);
	afficher_back(screen,back);
	resume=go_ResumReplay(&p,&back,1,screen,p1);
	if(resume==2)
	{
		for(int i=0;i<2;i++)
		{
			e[i].pos.x=e[i].pos.x-back.pos2.x;
			e[i].pos.y=e[i].pos.y+200-back.pos2.y;
		}
		for(int i=0;i<o.nbr;i++)
		{
			o.pos[i].x=o.pos[i].x-back.pos2.x;
			o.pos[i].y=o.pos[i].y+200-back.pos2.y;
		}
		o.pos_max[0]=o.pos_max[0]-back.pos2.x;
		o.pos_min[0]=o.pos_min[0]-back.pos2.x;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<back.pos2.x;j=j+20)
			{
				if(t[i].pos1.x>=back.pos1.x)
				{
					
					t[i].pos1.x=t[i].pos1.x-20;
				}
				else
				{
					
					t[i].pos2.x=t[i].pos2.x+20;
				}
			}
			t[i].pos1.y=t[i].pos1.y+200-back.pos2.y;
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<back.pos2.x;j=j+20)
			{
				if(ch.pos1[i].x>=back.pos1.x)
				{
					ch.pos1[i].x=ch.pos1[i].x-20;
				}
				else
				{
					ch.pos2[i].x=ch.pos2[i].x+20;
				}
				ch.pos1[i].y=ch.pos1[i].y+200-back.pos2.y;
			}
		}
		
	}
	p.maxsaut=17;
	s.score=0;
	while(boocle==1)
	{ 	temp.nom[0]='\0';
		if(p.pos.x>=1100)
		{
			for(int i=0;i<10;i++)
				{

				afficher_back(screen,back_goodluck);
				animerBack(&back_goodluck);
				SDL_Flip(screen);
				SDL_Delay(100);
				}
			boocle=0;
			if(p1.top_score<s.score)
			{
				p1.top_score=s.score;
			}
			if(p1.nbr_stage==1)
			{
				p1.nbr_stage=2;
			}
			if(p1.nbr_perso<3)
			{
				p1.nbr_perso++;
			}
		}
		if(vie.nb_vie==0)
		{	
			for(int i=0;i<10;i++)
				{

				afficher_back(screen,back_hardluck);
				animerBack(&back_hardluck);
				SDL_Flip(screen);
				SDL_Delay(100);
				}	
			boocle=0;
			
		}
		afficher_back(screen,back);
		afficher_enmie(screen,e[0]);
		
		afficher_trap(screen,t[0]);
		afficher_trap(screen,t[1]);
		afficher_chekpoint(screen,ch);
		afficher_obstacles(screen,o);
		afficher_collections(screen,c);
		
		afficher_imageVies(screen,vie);
		afficher_enmie(screen,e[1]);
		afficherPerso(screen,p);
		//time 
		ajout(&temp);
		MAJMinimap(p,&m,o,e,back,1);
		afficherminimap(screen,m,temp,1,t,e,o);
		//afficher_scoreTexte(screen,s);
		afficher_minicris(screen,&c);
		//colision
		collision_obstacles(o,p,c_obstacles);
		c_enmie=collision_enemie(p,e);
		c_traps=collision_traps(p,t);
		c_collections=collision_collections(p,c);
		c_checkpoint=collision_checkpoint(ch,p);
		//blockage des directions
		veriph_dir(o,&p,c_obstacles);
		//lire les evenment
		while(SDL_PollEvent(&event))
		{
		switch(event.type)
		{
			case SDL_QUIT:
				p.vie=vie.nb_vie;
				p.score=s.score;
				go_exit(back,p,screen,p1,1);
				boocle=0;
				break;
			case SDL_KEYDOWN:
	
				if(event.key.keysym.sym==input.right)
				{
					
					p.etat=2;
					p.dir=0;
					p.vitesse=20;
				}
				else if(event.key.keysym.sym==input.down)
				{
					if(p.saut!=1)
					{
						p.etat=4;
						p.mouvment=0;
					}
				}
				else if(event.key.keysym.sym==input.up)
				{
					if(p.saut!=1)
					{
						p.saut=1;
						p.mouvment=-1;
						p.haut=1;
						//p.h=1;
					}
				}
				if(event.key.keysym.sym==input.left)
				{
					p.etat=2;
					p.dir=1;
					p.vitesse=20;
				}
				else if(event.key.keysym.sym==input.attack)
				{
					if(p.saut!=1)
					{
						p.etat=5;
						p.mouvment=0;
						//p.pos.w=200;
					}
					
				}
				else if(event.key.keysym.sym==SDLK_c)
				{
					p.etat=1;
					p.vitesse=10;
				}
				else if(event.key.keysym.sym==SDLK_r)
				{
					go_exit(back,p,screen,p1,1);
					boocle=0;
				}
				else if(event.key.keysym.sym==SDLK_ESCAPE)
						SDL_WM_ToggleFullScreen(screen);
				break;
			case SDL_KEYUP:
					p.pos.w=80;
				
					if(event.key.keysym.sym==input.right && p.dir==0)
					{
						p.mouvment=0;
						p.etat=0;
					}
					else if(event.key.keysym.sym==input.down && p.etat==4)
					{
						p.mouvment=0;
						p.etat=0;
					}
					else if(event.key.keysym.sym==input.left && p.dir==1)
					{
						p.mouvment=0;
						p.etat=0;
					}
					else if(event.key.keysym.sym==input.up)
					{
						p.haut=0;
					}
				break;
			
		}
		}
		if(p.etat==1 ||p.etat==2 )
		{
			if((p.dir==0 && (p.pos.x<=700 || (back.pos2.x>=back.pos1.w-back.pos2.w && p.pos.x<=back.pos2.w-p.pos.w-10))) 
			||  p.dir==1 && (p.pos.x>=100 || (back.pos2.x<=10 && p.pos.x>=10)))
				movePerso(&p);
			else 
			{
				if((p.dir==1 && p.pos.x>back.pos1.x) || (p.dir==0 && p.pos.x<back.pos1.x+back.pos2.w-p.pos.w-10))
				{
					if((p.dir==0 && p.d!=0) || p.dir==1 && p.g!=0)
					{
						scrolling(&back,p.dir,p.vitesse);
						deplacer_ennemie(&e[0],p.dir,p.vitesse);
						deplacer_ennemie(&e[1],p.dir,p.vitesse);
						deplacer_obstacles(&o,p.dir,p.vitesse);
						deplacer_trap(&t[0],p.dir,p.vitesse,back);
						deplacer_trap(&t[1],p.dir,p.vitesse,back);
						deplacer_chekpoint(&ch,p.dir,p.vitesse,back);
						deplacer_shot(&sh,p.dir,p.vitesse);
						deplacer_collections(&c,p.dir,p.vitesse);
					}
				}
			}
		}
		animerPerso(&p);
		animerBack(&back);
		animer_enmie(&e[0]);
		animer_enmie(&e[1]);
		animer_lazer(&t[0]);
		animer_lazer(&t[1]);
		annimer_collections(&c);
		movobstacle(&o);
		move_enmie(&e[0]);
		move_enmie(&e[1]);
		if(p.saut==1)
		{
			saut(&p);
			if(((p.movsaut<19 && p.haut==1) && p.pos.y>=200) || ((p.movsaut>19 || p.haut==0) && p.pos.y<=550) || ((p.movsaut>19 || p.haut==0) && back.pos2.y>=200) || ((p.movsaut<19 && p.haut==1) && back.pos2.y<=22))				
					mouv_saut(&p);
			else if((p.movsaut<19 && p.haut==1) && p.h==1)
			{
				scrolling(&back,2,22);
				deplacer_ennemie(&e[0],2,22);
				deplacer_ennemie(&e[1],2,22);
				deplacer_obstacles(&o,2,22);
				deplacer_trap(&t[0],2,22,back);
				deplacer_trap(&t[1],2,22,back);
				deplacer_chekpoint(&ch,2,22,back);
				deplacer_shot(&sh,2,22);
				deplacer_collections(&c,2,22);
				
			}
			else if((p.movsaut>19 || p.haut==0) && p.b==1)
			{
				scrolling(&back,3,22);
				deplacer_ennemie(&e[0],3,22);
				deplacer_ennemie(&e[1],3,22);
				deplacer_obstacles(&o,3,22);
				deplacer_trap(&t[0],3,22,back);
				deplacer_trap(&t[1],3,22,back);
				deplacer_chekpoint(&ch,3,22,back);
				deplacer_shot(&sh,3,22);
				deplacer_collections(&c,3,22);
			}
		}
		printf("%d\n",p.b);
		if(p.b==1 && p.saut!=1) 
		{
			p.saut=1;
			p.movsaut=17;
		}
		if(c_obstacles[0]==0 || c_obstacles[1]==0)
		{
			if((o.dir[0]==0 && (p.pos.x<=700 || (back.pos2.x>=back.pos1.w-back.pos2.w && p.pos.x<=back.pos2.w-p.pos.w-10))) 
			||  o.dir[0]==1 && (p.pos.x>=100 || (back.pos2.x<=10 && p.pos.x>=10)))
				deplacer_perso(&p,o.dir[0],5);
			else 
			{
				if((o.dir[0]==1 && p.pos.x>back.pos1.x) || (o.dir[0]==0 && p.pos.x<back.pos1.x+back.pos2.w-p.pos.w-10))
				{
					if((p.dir==0 && p.d!=0) || p.dir==1 && p.g!=0)
					{
						scrolling(&back,o.dir[0],5);
						deplacer_ennemie(&e[0],o.dir[0],5);
						deplacer_ennemie(&e[1],o.dir[0],5);
						deplacer_obstacles(&o,o.dir[0],5);
						deplacer_trap(&t[0],o.dir[0],5,back);
						deplacer_trap(&t[1],o.dir[0],5,back);
						deplacer_chekpoint(&ch,o.dir[0],5,back);
						deplacer_shot(&sh,o.dir[0],5);
						deplacer_collections(&c,o.dir[0],5);
					}
				}
			}
		}
		if((c_enmie!=-1 && p.etat!=5 && e[c_enmie].pos.h!=0) || (c_traps!=-1 && t[c_traps].etat==1) ||(p.pos.y>=1200))
		{
			time=SDL_GetTicks()/1000;
			if(go_enigme(screen,&boocle)==0)
			{
				for(int i=0;i<10;i++)
				{

				afficher_back(screen,back_hardluck);
				animerBack(&back_hardluck);
				SDL_Flip(screen);
				SDL_Delay(100);
				}
				vie.nb_vie--;
			}
			else
			{
				for(int i=0;i<10;i++)
				{

				afficher_back(screen,back_goodluck);
				animerBack(&back_goodluck);
				SDL_Flip(screen);
				SDL_Delay(100);
				}
			}
			if(ch.etat!=-1)
				{
				retoure_checkpointstage1(&p,&back,&ch,e,&o,&c,t,select_perso);
				}
			else
				{
				retoure_debut(&p,&back,&ch,e,&o,&c,t,select_perso);
				}

		}
		if(c_enmie!=-1 && p.etat==5)
		{
			e[c_enmie].pos.h=0;
			s.score=s.score+10;
		}
		if(c_collections!=-1 && c.pos[c_collections].h!=0)
		{
			c.nbr++;
			c.pos[c_collections].h=0;
			s.score=s.score+10;
			
		}
		if(c_checkpoint>ch.etat)
		{
			ch.etat=c_checkpoint;
			annimer_checkpoint(&ch);
		}
		SDL_Flip(screen);
		SDL_Delay(50);
	}
	
	/* ** liberations**** */
	free_minimap(m,1);
	TTF_CloseFont(temp.police);
	//background
	for(int i=0;i<12;i++)
		SDL_FreeSurface(back.img[i]);

	//alien
	SDL_FreeSurface(e[0].etat_droite.img);
	SDL_FreeSurface(e[1].etat_droite.img);
	SDL_FreeSurface(e[0].etat_gauche.img);
	SDL_FreeSurface(e[1].etat_gauche.img);
	//obstacle
	SDL_FreeSurface(o.img_obS[0]);
	SDL_FreeSurface(t[1].img);
	SDL_FreeSurface(t[0].img);
	SDL_FreeSurface(ch.img[1]);
	SDL_FreeSurface(ch.img[0]);
	SDL_FreeSurface(c.img_mini);
	for(int i=0;i<4;i++)
		SDL_FreeSurface(c.img[i]);
	for(int i=0;i<4;i++)
		SDL_FreeSurface(vie.img[i]);
		
		TTF_Quit();
		
	
	return p1;
}
				
