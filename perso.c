#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"perso.h"
#include"fonctions.h"

void initPerso(perso *p)
{
	int x,y=0,h=228,w;
	(*p).etat_droite.img=IMG_Load("image/stage1/perso/walking right.png");
	(*p).etat=0;
	(*p).dir=0;
	(*p).mouvment=0;
	(*p).movsaut=0;
	(*p).pos.w=105;
	(*p).pos.h=206;
	(*p).saut=0;
	(*p).haut=0;
	(*p).vie=3;
	(*p).h=1;
	(*p).d=1;
	(*p).b=1;
	(*p).g=1;
	for(int i=0;i<7;i++)
	{
		x=0;
		reanisyaliser(&w,i);
		for(int j=0;j<6;j++)
		{
			(*p).etat_droite.pos[i][j].x=x;
			(*p).etat_droite.pos[i][j].y=y;
			(*p).etat_droite.pos[i][j].h=h;
			(*p).etat_droite.pos[i][j].w=w;
			x=x+w;
			if(((i==4 || i==6) && j==1) || (i==0 && j==3) ||(i==5 && j==2)) break; 
		}
		y=y+h;
	}
	(*p).etat_gauche.img=IMG_Load("image/stage1/perso/walking left.png");
	y=0;
	for(int i=0;i<7;i++)
	{
		x=894;
		reanisyaliser(&w,i);
		for(int j=0;j<6;j++)
		{
			x=x-w;
			(*p).etat_gauche.pos[i][j].x=x;
			(*p).etat_gauche.pos[i][j].y=y;
			(*p).etat_gauche.pos[i][j].h=h;
			(*p).etat_gauche.pos[i][j].w=w;
			if(((i==4 || i==6) && j==1) || (i==0 && j==3) ||(i==5 && j==2)) break;
		}
		y=y+h;
	}
	(*p).pos.x=100;
	(*p).pos.y=560;
}
void reanisyaliser(int *w,int i)
{
	if(i==0) *w=105;
	else if(i==1) *w=136;
	else if(i==2) *w=149;
	else if(i==3) *w=145;
	else if(i==4) *w=109;
	else if(i==5) *w=145;
}
void afficherPerso(SDL_Surface * screen,perso p)
{
	if (p.dir==0 && p.saut==1)
	{
		SDL_BlitSurface(p.etat_droite.img,&p.etat_droite.pos[3][p.mouvment],screen,&p.pos);
	}
	else if (p.dir==1 && p.saut==1)
	{
		SDL_BlitSurface(p.etat_gauche.img,&p.etat_gauche.pos[3][p.mouvment],screen,&p.pos);
	}
	else if(p.dir==0)
	{
		SDL_BlitSurface(p.etat_droite.img,&p.etat_droite.pos[p.etat][p.mouvment],screen,&p.pos);
	}
	else
	{
		SDL_BlitSurface(p.etat_gauche.img,&p.etat_gauche.pos[p.etat][p.mouvment],screen,&p.pos);
	}
}
void animerPerso (perso* p)
{
	(*p).mouvment++;
	if((*p).mouvment==6)
	(*p).mouvment=0;
	else if(((p->etat==4 || p->etat==6) && p->mouvment==1) || (p->etat==0 && p->mouvment==4) ||(p->etat==5 && p->mouvment==3))
	{
		(*p).mouvment=0;
		if((*p).etat==5)(*p).etat=0;
	}
}
void movePerso (perso *p)
{
	if((*p).dir==0) 
	{
		if((*p).d!=0)
			(*p).pos.x=(*p).pos.x+p->vitesse;
		
	}		
	else if((*p).dir==1)
	{
			if((*p).g!=0)
				(*p).pos.x=(*p).pos.x-p->vitesse;
	}
}
void saut (perso* p)
{
	if ((*p).movsaut>1 && (*p).movsaut<(*p).maxsaut && (*p).haut==1) 
	{
		(*p).mouvment=1;
	}
	else if((*p).movsaut>(*p).maxsaut || (*p).haut==0)
	{
		(*p).haut=0;
		(*p).mouvment=3;
	}
	(*p).movsaut++;
	if((*p).haut==0 && (*p).b==0)
	{ 
		(*p).saut=0;
		(*p).movsaut=0;
	}
}
void mouv_saut (perso* p)
{
	
	if((*p).mouvment<3)
	{
		if((*p).h==1)
			
			(*p).pos.y=(*p).pos.y-22;
	}
	else if((*p).b==1)
	{
		(*p).pos.y=(*p).pos.y+22;
	}
}
void veriph_dir(obstacles o,perso *p,int c_obstacles[])
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
			else if((*p).dir==0 && (*p).pos.x<o.pos[c_obstacles[i]].x)
			{
				(*p).d=0;
			}
			else if((*p).dir==1 && (*p).pos.x>o.pos[c_obstacles[i]].x)
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
void deplacer_perso(perso *p,int dir,int v)
{
	if(dir==0) (*p).pos.x=(*p).pos.x+v;
	else if (dir==1)(*p).pos.x=(*p).pos.x-v;
	else if(dir==2) (*p).pos.y=(*p).pos.y+v;
	else if (dir==3)(*p).pos.y=(*p).pos.y-v;
	
}
void init_imageVies1(vie_player *v)
{
	char nom[50],num[4];
	for(int i=0;i<4;i++)
	{
		strcpy(nom,"image/backgrounds/vies/");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*v).img[i]=IMG_Load(nom);
	}
	(*v).pos.x=50;
	(*v).pos.y=50;
	(*v).nb_vie=3;
}
void init_imageVies2(vie_player *v)
{
	char nom[50],num[4];
	for(int i=0;i<4;i++)
	{
		strcpy(nom,"image/backgrounds/vies/");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*v).img[i]=IMG_Load(nom);
	}
	(*v).pos.x=50+700;
	(*v).pos.y=50;
	(*v).nb_vie=3;
}
void afficher_imageVies(SDL_Surface *screen,vie_player v)
{
	SDL_BlitSurface(v.img[v.nb_vie],NULL,screen,&v.pos);
}
void retoure_checkpointstage1(perso *p,background *back,checkpoint *ch,enmie e[],obstacles *o,collections *c,trap t[])
{
	int etat=(*ch).etat,dif;
	initPerso(p);
	initialiser_chekpointSTAGE1(ch);
	(*ch).etat=etat;
	annimer_checkpoint(ch);
	
	(*back).pos2.x=(*ch).pos1[etat].x;
	
	initenmieSTAGE1(e);
	for(int i=0;i<2;i++)
	{
		e[i].pos.x=e[i].pos.x-dif;
	}
	initialiser_obstaclesSTAGE1(o);
	for(int i=0;i<o->nbr;i++)
	{
		o->pos[i].x=o->pos[i].x-(*ch).pos1[etat].x;
	}
	(*o).pos_min[0]=(*o).pos_min[0]-(*ch).pos1[etat].x;
	(*o).pos_max[0]=(*o).pos_max[0]-(*ch).pos1[etat].x;
	initialiser_collectionsSTAGE1(c,o->pos);
	for(int i=0;i<5;i++)
	{
		c->pos[i].x=c->pos[i].x-(*ch).pos1[etat].x;
	}
	
	initialiser_trapSTAGE1(t);
	for(int i=0;i<2;i++)
	{
		t[i].pos1.x=t[i].pos1.x-(*ch).pos1[etat].x;
	}
	for(int i=0;i<3;i++)
	{
		
		(*ch).pos1[i].x=(*ch).pos1[i].x-(*ch).pos1[etat].x;
		
		
	}
	
}
void retoure_debut(perso *p,background *back,checkpoint *ch,enmie e[],obstacles *o,collections *c,trap t[])
{
	initPerso(p);
	initialiser_chekpointSTAGE1(ch);
	initialiser_obstaclesSTAGE1(o);
	initialiser_trapSTAGE1(t);
	initenmieSTAGE1(e);
	initialiser_collectionsSTAGE1(c,o->pos);
	(*back).pos2.x=0;
}
