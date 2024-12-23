#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
#include"background.h"

void initialiser_backSTAGE1(background *b)
{
	char nom[50],num[4];
	(*b).nbr=12;
	for(int i=0;i<(*b).nbr;i++)
	{
		strcpy(nom,"image/stage1/backgrounds/animation_background/bg");
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
	(*b).pos1.w=14956;
	(*b).pos2.y=200;
	(*b).pos2.h=1000;
	(*b).pos2.w=1400;
	(*b).photo=0;
}
void scrolling(background *b, int direction,int v)
{
	switch(direction)
	{
	case 0:
		b->pos2.x=b->pos2.x+v;
		break;
	case 1:
		b->pos2.x=b->pos2.x-v;
		break;
	case 2:
		b->pos2.y=b->pos2.y-v;
		break;
	case 3:
		b->pos2.y=b->pos2.y+v;
		break;	
	}
}
void afficher_back(SDL_Surface *screen,background b)
{
	SDL_BlitSurface(b.img[b.photo],&b.pos2,screen,&b.pos1);
}


void animerBack(background *b)
{
	(*b).photo++;
	if ((*b).photo==(*b).nbr) (*b).photo=0;
}

void afficher_minicris(SDL_Surface *screen,collections c)
{
	char ch[20],num[2];
	strcpy(ch,"x");
	sprintf(num,"%d",c.nbr);
	
	strcat(ch,num);
	strcat(ch,"/3");
	if(c.nbr<3)
		c.txt= TTF_RenderText_Blended(c.police,ch, c.color[0]);
	else 
		c.txt= TTF_RenderText_Blended(c.police,ch, c.color[1]);
        SDL_BlitSurface(c.txt, NULL, screen, &c.pos_mini[1]);
	SDL_BlitSurface(c.img_mini, NULL, screen, &c.pos_mini[0]);
}
void initialiser_back(background *b)
{
	char nom[50],num[4];
	for(int i=0;i<12;i++)
	{
		strcpy(nom,"image/backgrounds/animation_background/bg");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*b).img[i]=IMG_Load(nom);
	}
	(*b).pos1.x=0;
	(*b).pos1.y=0;
	(*b).pos2.x=0;
	(*b).pos2.y=200;
	(*b).pos2.h=1000;
	(*b).pos2.w=700;
	(*b).photo=0;
}
void init_scoreTexte(score_info *s)
{
	
	(*s).police=TTF_OpenFont("police/Ubuntu-Bold.ttf", 30);
	(*s).color.r = 225;
	(*s).color.g = 225;
	(*s).color.b = 225;
	(*s).pos.x=50;
	(*s).pos.y=100;
}
void afficher_scoreTexte(SDL_Surface *screen,score_info s)
{
	char ch1[20];
	strcpy(ch1,"SCORE : ");
	sprintf(s.ch,"%d",s.score);
	strcat(ch1,s.ch);
	s.txt= TTF_RenderText_Blended(s.police,ch1, s.color);
        SDL_BlitSurface(s.txt, NULL, screen, &s.pos);
}
/*void best_score(score_info t[],char *fileName)
{
	score_info aux;
	score_info s;
	int tmp;
	int nb=0;
	FILE *f=fopen(fileName,"r");
	if (f!=NULL)
	{
		while(fscanf(f,"%d%s",&s.score,s.temps)!=EOF)
		{
			nb++;
		}
		for(int i=0;i<nb;i++)
		{
			fscanf(f,"%d%s",&t[i].score,t[i].temps);
		}
		fclose(f);
	}
	do
	{
		tmp=0;
		for(int i=0;i<nb-1;i++)
		{
			if(t[i].score < t[i+1].score)
			{
				aux=t[i];
				t[i]=t[i+1];
				t[i+1]=aux;
				tmp=1;
			}
			else if(t[i].top_score = t[i+1].top_score)
			{
				if(t[i].temps < t[i+1].temps)
			{
			aux=t[i];
			t[i]=t[i+1];
			t[i+1]=aux;
			tmp=1;
		}
		}
		}
	}while(tmp==1);
}
void afficherBest(score_info t[],char *fileName)
{
	FILE *f1,*f=fopen(fileName,"r");
	if(f!=NULL)
	{
		while(fscanf(f,"%d%s",&s.score,s.temps)!=EOF)
		{
			
		}
	}
}*/





