#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"

void initialiser_back(background *b)
{
	char nom[100],num[4];
	for(int i=0;i<12;i++)
	{
		strcpy(nom,"/home/aziz/Documents/background/backgrounds/animation_background/bg");
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
	(*b).pos2.w=1400;
	(*b).photo=0;
}
void scrolling(background *b, int direction,score_info *s)
{
	switch(direction)
	{
	case 1:
		if(b->pos2.x!=10000)
		b->pos2.x=b->pos2.x+30;
		(*s).score+=5;
		break;
	case 2:
		if(b->pos2.x!=0)
		b->pos2.x=b->pos2.x-30;
		break;
	case 3:
		if(b->pos2.y!=210)
		b->pos2.y=b->pos2.y+10;
		break;
	case 4:
		if(b->pos2.y!=0)
		b->pos2.y=b->pos2.y-10;
		break;	
	}
}

void afficher(SDL_Surface *screen,background b)
{
	SDL_BlitSurface(b.img[b.photo],&b.pos2,screen,&b.pos1);
}


void animerBack(background *b)
{
	(*b).photo++;
	if ((*b).photo==6) (*b).photo=0;
}
void init_scoreTexte(score_info *s)
{
	(*s).police=TTF_OpenFont("/home/aziz/Documents/background/police/Ubuntu-Bold.ttf", 30);
	if(s->police == NULL)
	{
		printf("erreur %s \n",SDL_GetError());
		return ;
	}
	(*s).color.r = 225;
	(*s).color.g = 225;
	(*s).color.b = 225;
	(*s).pos.x=50;
	(*s).pos.y=150;
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
void init_imageVies(vie_player *v)
{
	char nom[150],num[4];
	for(int i=0;i<4;i++)
	{
		strcpy(nom,"/home/aziz/Documents/background/backgrounds/vies_/vies_");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*v).img[i]=IMG_Load(nom);
	}
	(*v).pos.x=50;
	(*v).pos.y=50;
	(*v).nb_vie=0;
}
void animerVies(vie_player *v)
{
	(*v).nb_vie++;
	if ((*v).nb_vie==4) (*v).nb_vie=0;
}
void afficher_imageVies(SDL_Surface *screen,vie_player v)
{
	SDL_BlitSurface(v.img[v.nb_vie],NULL,screen,&v.pos);
}
/*void save_score(score_info s,char fileName[])
{
	FILE *f;
	f=fopen(fileName,"a");
	if(f==NULL)
		printf("probleme d'overture");
	else
	{
		fprintf(f,"%d\t%s\n",s.score,s.temps);
	}
	fclose(f);
}
void best_score(score_info t[],char *fileName)
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




