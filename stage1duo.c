#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include<time.h>
#include"background.h"
#include"ES.h"
#include"perso.h"
#include"fonctions.h"
#include"enigme.h"
#include "stage1duo.h"

int stage1duo(SDL_Surface *screen)
{
	/* *****decalration de variable***** */
	srand(time(NULL));
	int boocle=1,c_obstacles1[2],c_enmie1,c_lazer1,c_cristale1,c_checkpoint1,debut,x,x3,x2;
	int c_obstacles2[2],c_enmie2,c_lazer2,c_cristale2,c_checkpoint2;
	int debut_time;
	SDL_Event event;
	background back1,back2;
	perso p1,p2;
	enmie e1[],e2[];
	obstacles o1,o2;
	vie_player v1,v2;
	trap lazer1[2],lazer2[2];
	checkpoint ch1,ch2;
	// INITIALISATIONS DES VARIABLE
	/* *****initialisations des perso p,p2***** */
	initPerso1(&p1);
	initPerso2(&p2);
	/* *****initialisations des background back1,back2***** */
	initialiser_back1(&back1);
	initialiser_back2(&back2);
	/* *****initialisations des enmie e1,e2***** */
	initenmie1(&e1);
	initenmie2(&e2);
	/* *****initialisations des obstacles***** */
	initialiser_obstacles1(&o1);
	initialiser_obstacles2(&o2);
	/* *****initialisations traps***** */
	initialiser_trap1(lazer1);
	initialiser_trap2(lazer2);
	/* *****initialiser vie***** */
	init_imageVies1(&v1);
	init_imageVies2(&v2);
	/* *****initialiser checkpoint***** */
	initialiser_chekpoint1(&ch1);
	initialiser_chekpoint2(&ch2);
	//charger(&p1,&back1,"save_gamej1.txt");
	//charger(&p2,&back2,"save_gamej2.txt");
	while (boocle==1)
	{
		//AFFICHAGE
		//AFFICHAGE JOUEUR1
		afficher_back(screen,back1);
		afficher_obstacles(screen,o1);
		afficher_enmie(screen,e1);
		afficher_trap(screen,lazer1[0]);
		afficher_trap(screen,lazer1[1]);
		afficher_imageVies(screen,v1);
		afficher_chekpoint(screen,ch1);		
		afficherPerso(screen,p1);
		//AFFICHAGE JOUEUR2
		afficher_back(screen,back2);
		afficher_obstacles(screen,o2);
		afficher_enmie(screen,e2);
		afficher_imageVies(screen,v2);
		afficher_trap(screen,lazer2[0]);
		afficher_trap(screen,lazer2[1]);
		afficher_chekpoint(screen,ch2);
		afficherPerso(screen,p2);
		//COLISION
		/* *****collision avec l'enmie***** */
		c_enmie1=collision_enemie(p1,e1);
		if(c_enmie1!=-1)
		{
			if(ch1.etat!=-1)
				retoure_checkpoint(&p1,&back1,ch1);
			else
				retoure_debut(&p1,&back1,&e1,&ch1,&o1);
			v1.nb_vie--;
		}
		c_enmie2=collision_enemie(p2,e2);
		if(c_enmie2!=-1)
		{
			if(ch2.etat!=-1)
				retoure_checkpoint(&p2,&back2,ch2);
			else
				retoure_debut(&p2,&back2,&e2,&ch2,&o2);
			v2.nb_vie--;
		}
		/* *****collision avec les obstacles***** */
		collision_obstacles(o1,p1,c_obstacles1);
		collision_obstacles(o2,p2,c_obstacles2);
		/* *****collision avec les chekpoint***** */
		c_checkpoint1=collision_checkpoint(ch1,p1);
		if(c_checkpoint1>ch1.etat)
		{
			ch1.etat=c_checkpoint1;
			annimer_checkpoint(&ch1);
		}
		c_checkpoint2=collision_checkpoint(ch2,p2);
		if(c_checkpoint2>ch2.etat)
		{
			ch2.etat=c_checkpoint2;
			annimer_checkpoint(&ch2);
		}
		
		//BLOCKAGE DIRRECTIONS
		/* *****virifier directions perso***** */
		veriph_dir(o2,&p2,c_obstacles2);
		veriph_dir(o1,&p1,c_obstacles1);
		for(int i=0;i<2;i++)
		{
			if(e2.pos[i].x<back2.pos1.x)
			{
				e2.pos[i].h=0;
			}
			else
			{
				e2.pos[i].h=226;
			}
		}
		/* *****lire des evenment***** */		
		while(SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					boocle=0;
					
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{ 
						case SDLK_m:
						debut=SDL_GetTicks()/1000;
						 x3=game(screen,debut);
						break;
						/*case SDLK_k:
						
						 x=game3(screen);
						break;*/
						case SDLK_l:
						
						 x2=game2(screen);
						break;

						case SDLK_RIGHT:
							p1.etat=2;
							p1.dir=0;
							p1.vitesse=20;
							p1.d=1;
							break;
						case SDLK_LEFT:
							p1.etat=2;
							p1.dir=1;
							p1.vitesse=20;
							p1.g=1;
							break;
						case SDLK_UP:
							if(p1.saut!=1)
							{
								p1.saut=1;
								p1.mouvment=-1;
								p1.haut=1;
								p1.h=1;
							}
							break;
						case SDLK_DOWN:
							if(p1.saut!=1)
							{
								p1.etat=4;
								p1.mouvment=0;
							}
							break;
						case SDLK_d:
							p2.etat=2;
							p2.dir=0;
							p2.vitesse=20;
							p2.d=1;
							break;
						case SDLK_q:
							p2.etat=2;
							p2.dir=1;
							p2.vitesse=20;
							p2.g=1;
							break;
						case SDLK_z:
							if(p2.saut!=1)
							{
								p2.saut=1;
								p2.mouvment=-1;
								p2.haut=1;
								p2.h=1;
							}
							break;
						case SDLK_s:
							if(p2.saut!=1)
							{
								p2.etat=4;
								p2.mouvment=0;
							}
							break;
							
					}
					break;
				case SDL_KEYUP:
					switch(event.key.keysym.sym)
					{
						case SDLK_RIGHT:
							if(p1.dir==0)
							{
								p1.etat=0;
								p1.mouvment=0;
							}
							break;
						case SDLK_LEFT:
							if(p1.dir==1)
							{
								p1.etat=0;
								p1.mouvment=0;
							}
							break;
						case SDLK_UP:
							p1.haut=0;
							break;
						case SDLK_DOWN:
							if(p1.saut!=1)
							{
								p1.etat=0;
								p1.mouvment=0;
							}
							break;
						case SDLK_d:
							if(p2.dir==0)
							{
								p2.etat=0;
								p2.mouvment=0;
							}
							break;
						case SDLK_q:
							if(p2.dir==1)
							{
								p2.etat=0;
								p2.mouvment=0;
							}
							break;
						case SDLK_z:
							p2.haut=0;
							break;
						case SDLK_s:
							if(p2.saut!=1)
							{
								p2.etat=0;
								p2.mouvment=0;
							}
							break;
					}
					break;
			}
		}
		//DEPLACEMENT
		/* *****move perso1***** */
		if(p1.etat==1 ||p1.etat==2 )
		{
			if((p1.dir==0 && (p1.pos.x<=400 || (back1.pos2.x>=back1.pos1.w-back1.pos2.w && p1.pos.x<=back1.pos2.w-p1.pos.w-10))) 
			||  p1.dir==1 && (p1.pos.x>=100 || (back1.pos2.x<=10 && p1.pos.x>=10)))
				movePerso(&p1);
			else 
			{
				if((p1.dir==1 && p1.pos.x>back1.pos1.x) || (p1.dir==0 && p1.pos.x<back1.pos1.x+back1.pos2.w-p1.pos.w-10))
				{
					if((p1.dir==0 && p1.d!=0) || p1.dir==1 && p1.g!=0)
					{
						deplacer_ennemie(&e1[0],p1.dir,p1.vitesse);
						deplacer_ennemie(&e1[1],p1.dir,p1.vitesse);
						deplacer_obstacles1(&o1,p1.dir,p1.vitesse);
						deplacer_trap(&t1[0],p1.dir,p1.vitesse,back1);
						deplacer_trap(&t1[1],p1.dir,p1.vitesse,back1);
						deplacer_chekpoint(&ch1,p1.dir,p1.vitesse,back);
						deplacer_shot(&sh1,p1.dir,p1.vitesse);
						deplacer_collections(&c1,p1.dir,p1.vitesse);
					}
				}
			}
		}
		/* *****move perso2***** */
		if(p2.etat==1 ||p2.etat==2)
		{
			if((p2.dir==0 && (p2.pos.x<=1100 || (back2.pos2.x>=back2.pos1.w-back2.pos2.w && p2.pos.x<=back2.pos2.w-p2.pos.w-10))) 
			||  p2.dir==1 && (p2.pos.x>=750 || (back2.pos2.x<=10 && p2.pos.x>=700)))
				movePerso(&p2);
			else 
			{
				if((p2.dir==1 && back2.pos2.x>=0) || (p2.dir==0 && back2.pos2.x<=back2.pos1.w-back2.pos2.w-p2.pos.w))
				{
					if((p2.dir==0 && p2.d!=0) || p2.dir==1 && p2.g!=0)
					{
						scrolling(&back2,p2.dir,p2.vitesse);
						deplacer_ennemie(&e2,p2.dir,p2.vitesse);
						deplacer_obstacles(&o2,p2.dir,p2.vitesse);
						deplacer_trap(lazer2,p2.dir,p2.vitesse,back2);
						//deplacer_trap(lazer2,p2.dir,p2.vitesse,back2);
						deplacer_chekpoint(&ch2,p2.dir,p2.vitesse,back2);
					
					}
				}
			}
		}
		//DEPLACER
		/* *****deplacer perso 1 suite a la collision avec obstacle dynamique 
		/* *****move enmie e1 ***** */
		move_enmie(&e1);
		/* *****move enmie e2 ***** */
		move_enmie(&e2);
		/* *****move obstacele ***** */  //dans cette stage un seul obstacle dynamique
		movobstacle(&o1);
		movobstacle(&o2);
		//ANNILATIONS
		/* *****animer perso p1,p2***** */
		animerPerso(&p1);
		animerPerso(&p2);
		/* *****animer enmie e1,e2***** */
		animer_enmie(&e1);
		animer_enmie(&e2);
		//SAUT
		/* *****saut du perso p1***** */
		if(p1.saut==1)
		{
			saut(&p1);				
			mouv_saut(&p1);
		}
		if(p1.b==1 && p1.saut!=1) 
		{
			p1.saut=1;
			p1.movsaut=12;
		}
		/* *****saut du perso p2***** */
		if(p2.saut==1)
		{
			saut(&p2);		
			mouv_saut(&p2);
		}
		if(p2.b==1 && p2.saut!=1) 
		{
			p2.saut=1;
			p2.movsaut=12;
		}
		//DEPLACEMENT
		/* *****deplacer perso 1 lors d'une colision avec un obstacles dynamique***** */ //dans cette stage un seul obstacle dynamique
		if(c_obstacles1[0]==0 || c_obstacles1[1]==0)
		{
			if((o1.dir[0]==0 && p1.pos.x<=400) || (o1.dir[0]==1 && p1.pos.x>=100))
				deplacer_perso(&p1,o1.dir[0]);
			else
			{
				deplacer_ennemie(&e1[0],o1.dir[0],5);
				deplacer_ennemie(&e1[1],o1.dir[0],5);
				deplacer_obstacles1(&o1,o1.dir[0],5);
				deplacer_trap(&t1[0],o1.dir[0],5,back);
				deplacer_trap(&t1[1],o1.dir[0],5,back);
				deplacer_chekpoint(&ch1,o1.dir[0],5,back);
				deplacer_shot(&sh1,o1.dir[0],5);
				deplacer_collections(&c1,o1.dir[0],5);
			}
				
		}
		/* *****deplacer perso 1 lors d'une colision avec un obstacles dynamique***** */ //dans cette stage un seul obstacle dynamique
		if(c_obstacles2[0]==0 || c_obstacles2[1]==0)
		{
			if((o2.dir[0]==0 && p2.pos.x<=1100) || (o2.dir[0]==1 && p2.pos.x>=700))
				deplacer_perso(&p2,o2.dir[0]);
			else
			{
				deplacer_ennemie(&e2[0],o2.dir[0],5);
				deplacer_ennemie(&e2[1],o2.dir[0],5);
				deplacer_obstacles1(&o2,o2.dir[0],5);
				deplacer_trap(&t2[0],o2.dir[0],5,back);
				deplacer_trap(&t2[1],o2.dir[0],5,back);
				deplacer_chekpoint(&ch2,o2.dir[0],5,back);
				deplacer_shot(&sh2,o2.dir[0],5);
				deplacer_collections(&c2,o2.dir[0],5);
			}
				
		}
		SDL_Flip(screen);
		SDL_Delay(30);
	}
	sauvegarder(p1,back1,"save_gamej1.txt");
	sauvegarder(p2,back2,"save_gamej2.txt");
	SDL_FreeSurface(screen);
	SDL_FreeSurface(p1.etat_droite.img);
	SDL_FreeSurface(p1.etat_gauche.img);
	SDL_FreeSurface(p2.etat_droite.img);
	SDL_FreeSurface(p2.etat_gauche.img);
	SDL_FreeSurface(e1.etat_droite.img);
	SDL_FreeSurface(e1.etat_gauche.img);
	SDL_FreeSurface(e2.etat_droite.img);
	SDL_FreeSurface(e2.etat_gauche.img);
	for(int i=0;i<12;i++)
	{
		SDL_FreeSurface(back1.img[i]);
		SDL_FreeSurface(back2.img[i]);
	}
	}
}
