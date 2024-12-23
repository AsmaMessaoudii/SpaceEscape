#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ES.h"
#include"fonctions.h"
#include"background.h"
#include "perso.h"

void initialiser_backSTAGE4(background *b,SDL_Surface *screen)
{
	char nom[50],num[4];
	(*b).nbr=10;
	for(int i=0;i<(*b).nbr;i++)
	{
		strcpy(nom,"image/stage4/background/");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*b).img[i]=IMG_Load(nom);
	}
	(*b).pos1.x=0;
	(*b).pos1.y=0;
	(*b).pos2.x=0;
	(*b).pos1.h=1200;
	(*b).pos1.w=9100;
	(*b).pos2.y=200;
	(*b).pos2.h=1000;
	(*b).pos2.w=1400;
	(*b).photo=0;
}
void initPersosSTAGE4(persoSTAGE4 *p)
{
	char nom[50],num[4];
	for(int i=0;i<5;i++)
	{
		strcpy(nom,"image/stage4/perso/");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*p).img[i]=IMG_Load(nom);
	}
	(*p).etat=0;
	(*p).dir=0;
	(*p).mouvment=0;
	(*p).movsaut=0;
	(*p).pos.w=388;
	(*p).pos.h=171;
	(*p).saut=0;
	(*p).haut=0;
	(*p).vie=3;
	(*p).h=1;
	(*p).d=1;
	(*p).b=1;
	(*p).g=1;
	(*p).pos.x=100;
	(*p).pos.y=560;
}
void initenmieSTAGE4(enmieSTAGE4 *e)
{
	char nom[50],num[4];
	for(int i=0;i<5;i++)
	{
		strcpy(nom,"image/stage4/enmie/");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*e).img[i]=IMG_Load(nom);
	}
	(*e).pos[0].x=3485;
	(*e).pos[0].y=500;
	(*e).pos[0].w=406;
	(*e).pos[0].h=179;
		(*e).mouvment=0;
		(*e).pas=0;
		(*e).dir=2;
		(*e).etat=0;
	(*e).pos_max=1200;
	(*e).pos_min=0;
	/*(*e).pos[1].x=4969;
	(*e).pos[1].y=560;
	(*e).pos[1].w=100;
	(*e).pos[1].h=226;*/
}
void deplacer_persoSTAGE4(persoSTAGE4 *p,int dir,int v)
{
	if(dir==0)
	{
		(*p).pos.x=(*p).pos.x+v;
	}
	else if (dir==1)
	{
		(*p).pos.x=(*p).pos.x-v;
	}
	else if(dir==2) 
	{
		(*p).pos.y=(*p).pos.y+v;
	}
	else if (dir==3)
	{
		(*p).pos.y=(*p).pos.y-v;
	}
}
void init_obstaclesSTAGE4(obstacles *o)
{
	(*o).pos[0].x=753;
	(*o).pos[0].y=-200;
	(*o).pos[0].h=386;
	(*o).pos[0].w=477;
	//
	(*o).pos[1].x=1230;
	(*o).pos[1].y=654;
	(*o).pos[1].h=397;
	(*o).pos[1].w=805;
	//
	(*o).pos[2].x=4605;
	(*o).pos[2].y=0;
	(*o).pos[2].h=542;
	(*o).pos[2].w=542;
	//
	(*o).pos[3].x=8310;
	(*o).pos[3].y=203;
	(*o).pos[3].h=1000;
	(*o).pos[3].w=1000;
	//f1: w=211 / h=144 / x=777 / y=555
	(*o).pos[4].x=2464;
	(*o).pos[4].y=63;
	(*o).pos[4].h=377;
	(*o).pos[4].w=377;
	//f2: w=334 / h=161 / x=1185 / y=408
	(*o).pos[5].x=5920;
	(*o).pos[5].y=623;
	(*o).pos[5].h=304;
	(*o).pos[5].w=444;
	//f3 : w=226 / h=162 / x=1763 / y=519
	(*o).pos[6].x=6643;
	(*o).pos[6].y=160;
	(*o).pos[6].h=230;
	(*o).pos[6].w=328;
	
	(*o).nbr=7;
	(*o).nbr_h=0;
	(*o).nbr_v=0;
	(*o).nbr_a=0;
}
void veriph_dirSTAGE4(obstacles o,persoSTAGE4 *p,int c_obstacles[],int dir[])
{
	(*p).h=1;
	(*p).d=1;
	(*p).b=1;
	(*p).g=1;
	for(int i=0;i<2;i++)
	{
		
		if(c_obstacles[i]!=-1)
		{
			
			if (o.pos[c_obstacles[i]].y+o.pos[c_obstacles[i]].h-22<=(*p).pos.y)
			{
				(*p).h=0;
			}
			else if ((*p).pos.y+(*p).pos.h<=o.pos[c_obstacles[i]].y+27)
			{
				(*p).b=0;
			}
			else if(dir[0]==0 && (*p).pos.x<o.pos[c_obstacles[i]].x)
			{
				(*p).d=0;
			}
			else if(dir[1]==1 && (*p).pos.x>o.pos[c_obstacles[i]].x)
			{
				(*p).g=0;
			}
		}
	}
	if((*p).pos.y<=0)
	{
		(*p).h=0;
	}
}
void collision_obstaclesSTAGE4(obstacles o,persoSTAGE4 p,int c_obstacles[])
{
	int i=0,j=0;
	c_obstacles[0]=-1;
	c_obstacles[1]=-1;
	while(c_obstacles[1]==-1 && i<o.nbr)
	{
		if(collision(o.pos[i],p.pos)==1)
		{
			c_obstacles[j]=i;
			j++;
		}
		i++;
	}
}
void afficher_enmieSTAGE4( SDL_Surface * screen,enmieSTAGE4 e)
{
	
	SDL_BlitSurface(e.img[e.mouvment],NULL,screen,&e.pos[0]);
}

void deplacer_enmieSRAGE4(enmieSTAGE4 *e,int dir,int v)
{
	for(int i=0;i<2;i++)
	{
		if(dir==0)
		{
			(*e).pos[i].x=(*e).pos[i].x-v;
		}
		else if(dir==1)
		{
			(*e).pos[i].x=(*e).pos[i].x+v;
		}
		else if(dir==3) 
		{
			(*e).pos[i].y=(*e).pos[i].y-v;
		}
		else
		{
			(*e).pos[i].y=(*e).pos[i].y+v;
		}
	}
}
void movobenmieSTAGE4(enmieSTAGE4 *e)
{
	if((*e).dir==2)
	{
		(*e).pos[0].y=(*e).pos[0].y+10;
	}
	else if ((*e).dir==3)
	{
		(*e).pos[0].y=(*e).pos[0].y-10;
	}
	if((*e).pos[0].y>=(*e).pos_max) (*e).dir=3;
	else if((*e).pos[0].y<=(*e).pos_min)(*e).dir=2;
}
int collision_enemieSTAGE4(persoSTAGE4 p,enmieSTAGE4 e)
{
	int pos=-1,i=0;
	while(pos==-1 && i<2)
	{
		if(collision(e.pos[i],p.pos)==1)
			pos=i;
		i++;
	}
	return pos;
	if(p.etat==5)p.pos.x=p.pos.x+100;
}
void retour_debutSTAGE4(background *back,enmieSTAGE4 *e,obstacles *o,persoSTAGE4 *p)
{
	init_obstaclesSTAGE4(o);
	initenmieSTAGE4(e);
	back->pos2.x=0;
	back->pos2.y=200;
	(*p).pos.x=100;
	(*p).pos.y=500;
}
int stage4(SDL_Surface *screen,input_joueur input,int select_perso,player p1)
{
	int boocle=1,c_obstacles[2],c_enmie,c_champ,c_traps,c_collections,c_checkpoint,time,nb_stage=1;
	SDL_Event event;
	enmieSTAGE4 e;
	background back,back_chargement;
	vie_player vie;
	obstacles o;
	score_info s;
	persoSTAGE4 p;
	int i=0,dir[4]={-1,-1,-1,-1};
	TTF_Init();
	initialiser_backSTAGE4(&back,screen);
	init_imageVies(&vie);
	init_scoreTexte(&s);
	initenmieSTAGE4(&e);
	initPersosSTAGE4(&p);
	init_obstaclesSTAGE4(&o);
	p.maxsaut=17;
	s.score=0;
	init_imageVies(&vie);
	while (boocle==1)
	{
		afficher_back(screen,back);
		afficher_enmieSTAGE4(screen,e);
		afficher_imageVies(screen,vie);
		SDL_BlitSurface(p.img[i],NULL,screen,&p.pos);
		e.mouvment++;
		i++;
		if(i==5)
		{
			i=0;
			e.mouvment=0;
		}
		if(vie.nb_vie==0)
		{		
			boocle=0;
			
		}
		printf("%d\n",e.pos[0].y);
		collision_obstaclesSTAGE4(o,p,c_obstacles);
		c_enmie=collision_enemieSTAGE4(p,e);
		veriph_dirSTAGE4(o,&p,c_obstacles,dir);
		movobenmieSTAGE4(&e);
		if(p.pos.y>=860) p.b=0;
		//else p.b=1;
		if((dir[0]==0 && (p.pos.x<=700 || (back.pos2.x>=back.pos1.w-back.pos2.w && p.pos.x<=back.pos2.w-p.pos.w-10))))
		{
			if(p.d==1)
			deplacer_persoSTAGE4(&p,dir[0],p.vitesse);
		}
		else
		{
			if((dir[0]==0 && p.pos.x<back.pos1.x+back.pos2.w-p.pos.w-10))
			{
					if((dir[0]==0 && p.d!=0))
					{
						scrolling(&back,dir[0],p.vitesse);
						deplacer_obstacles(&o,dir[0],p.vitesse);
						deplacer_enmieSRAGE4(&e,dir[0],p.vitesse);
					}
			}
		}
		if(  dir[1]==1 && (p.pos.x>=100 || (back.pos2.x<=10 && p.pos.x>=10)))
		{
			if(p.g==1)
			deplacer_persoSTAGE4(&p,dir[1],p.vitesse);
		}
		else
		{
				
			if(dir[1]==1 && p.pos.x>back.pos1.x)
			{
					if(dir[1]==1 && p.g!=0)
					{
						scrolling(&back,dir[1],p.vitesse);
						deplacer_obstacles(&o,dir[1],p.vitesse);
						deplacer_enmieSRAGE4(&e,dir[1],p.vitesse);
					}
			}
		}
		if((dir[2]==2 && p.pos.y<=550) || (dir[2]==2 && back.pos2.y>=200))
		{	
			if(p.b==1)
			deplacer_persoSTAGE4(&p,dir[2],p.vitesse);
		}
		else if(dir[2]==2 && p.b==1)
		{
			scrolling(&back,3,p.vitesse);
			deplacer_obstacles(&o,3,p.vitesse);
			deplacer_enmieSRAGE4(&e,3,p.vitesse);
		}

		if((dir[3]==3 && p.pos.y>=200) ||  (dir[3]==3 && back.pos2.y<=22))
		{
			if(p.h==1)
			deplacer_persoSTAGE4(&p,dir[3],p.vitesse);
		}
		else if( dir[3]==3 && p.h==1)
		{
			
			scrolling(&back,2,p.vitesse);
			deplacer_obstacles(&o,2,p.vitesse);
			deplacer_enmieSRAGE4(&e,2,p.vitesse);
		}
		if(c_enmie!=-1)
		{
			retour_debutSTAGE4(&back,&e,&o,&p);
			dir[0]=-1;
			dir[1]=-1;
			dir[2]=-1;
			dir[3]=-1;
			vie.nb_vie--;
		}
		while(SDL_PollEvent(&event))
		{
		switch(event.type)
		{
			case SDL_QUIT:
				boocle=0;
				break;
			case SDL_KEYDOWN:
	
				if(event.key.keysym.sym==input.right)
				{
					dir[0]=0;
					p.vitesse=30;
				}
				else if(event.key.keysym.sym==input.down)
				{
					dir[2]=2;
					p.vitesse=30;
				}
				else if(event.key.keysym.sym==input.up)
				{
					dir[3]=3;
					p.vitesse=30;
				}
				if(event.key.keysym.sym==input.left)
				{
					dir[1]=1;
					p.vitesse=30;
				}
				else if(event.key.keysym.sym==SDLK_r)
				{
					boocle=0;
				}
				else if(event.key.keysym.sym==SDLK_ESCAPE)
						SDL_WM_ToggleFullScreen(screen);
				break;
			case SDL_KEYUP:
					if(event.key.keysym.sym==input.right )
					{
						dir[0]=-1;
					}
					else if(event.key.keysym.sym==input.down )
					{
						dir[2]=-1;
					}
					else if(event.key.keysym.sym==input.left)
					{
						dir[1]=-1;
					}
					else if(event.key.keysym.sym==input.up)
					{
						dir[3]=-1;
					}
				break;
		}
		}
	SDL_Delay(40);
	animerBack(&back);
	SDL_Flip(screen);
	}
	SDL_FreeSurface(screen);
	for(int i=0;i<back.nbr;i++)
	{
		SDL_FreeSurface(back.img[i]);
	}
	for(int i=0;i<5;i++)
	{
		SDL_FreeSurface(p.img[i]);
	}
}
