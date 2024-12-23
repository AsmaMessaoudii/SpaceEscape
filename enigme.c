#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include<time.h>
#include"enigme.h"
#include"fonctions.h"
#include"background.h"


void afficher_planet(SDL_Surface *screen,planet p[])
{
	for(int i=0;i<3;i++)
	{
		SDL_BlitSurface(p[i].img[p[i].photo],NULL,screen,&p[i].pos);
		p[i].photo++;
		if(p[i].photo==10) p[i].photo=0;
	}
}
void initialiser_enigme(enigme *e)
{
	(*e).police=TTF_OpenFont("police/Ubuntu-Bold.ttf", 30);
	(*e).color[0].r = 255;
	(*e).color[0].g = 255;
	(*e).color[0].b = 255;
	//white non selectioner et questions
	(*e).color[1].r = 255;
	(*e).color[1].g = 0;
	(*e).color[1].b = 255;
	//mauve question
	(*e).color[2].r = 128;
	(*e).color[2].g = 0;
	(*e).color[2].b = 128;
	//bleu ciel selectioner
	(*e).color[3].r = 255;
	(*e).color[3].g = 0;
	(*e).color[3].b = 0;
	//rouge reponse faux
	(*e).color[4].r = 0;
	(*e).color[4].g = 255;
	(*e).color[4].b = 0;
	//vert reponse vrai
	(*e).pos[0].x=300;
	(*e).pos[0].y=190;
	(*e).pos[1].x=300;
	(*e).pos[1].y=220;
	(*e).pos[2].x=225;
	(*e).pos[2].y=686;
	(*e).pos[3].x=658;
	(*e).pos[3].y=686;
	(*e).pos[4].x=1069;
	(*e).pos[4].y=686;
	(*e).r1=0;
	(*e).r2=0;
	(*e).r3=0;
}
void genererEnigme(enigme *e, char nomfichier[])
{
	int alea_enigme,l=0;
	FILE *f;
	do
	alea_enigme=rand()%((3-0)+1);
	while (alea_enigme==0);
	f=fopen(nomfichier,"r");
	while(l!=alea_enigme)
	{
		fflush(stdin);
		fgets((*e).questions1,57,f);
		fgets((*e).questions2,55,f);
		fgets((*e).reponse1,10,f);
		fgets((*e).reponse2,10,f);
		fgets((*e).reponse3,10,f);
		fscanf(f,"%d\n",&(*e).reponse);
		l++;
	}
	fclose(f);
	initialiser_enigme(e);
}
void afficher_enigme(SDL_Surface *screen,enigme e)
{
	SDL_Surface *txt[5];
	txt[0]= TTF_RenderText_Blended(e.police,e.questions1,e.color[0]);
	txt[1]= TTF_RenderText_Blended(e.police,e.questions2,e.color[0]);
	txt[2]= TTF_RenderText_Blended(e.police,e.reponse1,e.color[e.r1]);
	txt[3]= TTF_RenderText_Blended(e.police,e.reponse2,e.color[e.r2]);
	txt[4]= TTF_RenderText_Blended(e.police,e.reponse3,e.color[e.r3]);
	for(int i=0;i<5;i++)
	{
		SDL_BlitSurface(txt[i], NULL, screen, &e.pos[i]);
	}
}
void initialiser_planets(enigme e,planet p[])
{
	char nom[50],nom_planet[50],num[3];
	strcpy(nom,"image/enigme/");
	strcat(nom,e.reponse1);
	strcat(nom,"/");
	for(int i=0;i<10;i++)
	{
		strcpy(nom_planet,nom);
		sprintf(num,"%d",i+1);
		strcat(nom_planet,num);
		strcat(nom_planet,".png");
		p[0].img[i]=IMG_Load(nom_planet);
		
	}
	strcpy(nom,"image/enigme/");
	strcat(nom,e.reponse2);
	strcat(nom,"/");
	
	for(int i=0;i<10;i++)
	{
		strcpy(nom_planet,nom);
		sprintf(num,"%d",i+1);
		strcat(nom_planet,num);
		strcat(nom_planet,".png");
		p[1].img[i]=IMG_Load(nom_planet);
		
	}
	strcpy(nom,"image/enigme/");
	strcat(nom,e.reponse3);
	strcat(nom,"/");
	
	for(int i=0;i<10;i++)
	{
		strcpy(nom_planet,nom);
		
		sprintf(num,"%d",i+1);
		strcat(nom_planet,num);
		strcat(nom_planet,".png");
		p[2].img[i]=IMG_Load(nom_planet);
	}
	p[0].pos.x=170;
	p[0].pos.y=400;
	if(strcmp(e.reponse2,"Comet   m")==0)
	{
		p[1].pos.x=500;
		p[1].pos.y=300;
	}
	else
	{
		p[1].pos.x=594;
		p[1].pos.y=400;
	}
	p[2].pos.x=1017;
	p[2].pos.y=400;
	p[0].photo=0;
	p[1].photo=0;
	p[2].photo=0;
	
	
}
void initialiser_backenigme(background *b)
{
	char nom[50],num[4];
	for(int i=0;i<8;i++)
	{
		strcpy(nom,"image/enigme/back_enigme/");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		(*b).img[i]=IMG_Load(nom);
	}
	(*b).pos1.x=0;
	(*b).pos1.y=0;
	(*b).pos2.x=0;
	(*b).pos2.y=0;
	(*b).pos2.h=1000;
	(*b).pos2.w=1400;
	(*b).photo=0;
	(*b).nbr=8;
}
void annimer_backenigme(background *b)
{
	(*b).photo++;
	if ((*b).photo==6) (*b).photo=0;
}
int go_enigme(SDL_Surface *screen,int *boocle)
{
	srand(time(NULL));
	int b_enigme=1,i=0,reponse_joueur;
	planet p[3];
	char nom[11];
	SDL_Event event;
	background back;
	enigme e;
	Mix_Music *musique;
	Mix_Chunk *song_bref;
	TTF_Init();
	initialiser_backenigme(&back);
	genererEnigme(&e,"riddles.txt");
	initialiser_planets(e,p);
	e.reponse1[strlen(e.reponse1)-2]='\0';
	strcpy(nom,e.reponse1);
	strcpy(e.reponse1,"a.");
	strcat(e.reponse1,nom);
	e.reponse2[strlen(e.reponse2)-2]='\0';
	strcpy(nom,e.reponse2);
	strcpy(e.reponse2,"b.");
	strcat(e.reponse2,nom);
	e.reponse3[strlen(e.reponse3)-1]='\0';
	strcpy(nom,e.reponse3);
	strcpy(e.reponse3,"c.");
	strcat(e.reponse3,nom);
	while (b_enigme==1)
	{
		
		afficher_back(screen,back);
		afficher_enigme(screen,e);
		afficher_planet(screen,p);
		animerBack(&back);
		while(SDL_PollEvent(&event))
		{
		switch(event.type)
		{
			case SDL_QUIT:
				b_enigme=0;
				break;
			case SDL_KEYDOWN:
				if(event.key.keysym.sym==SDLK_a)
				{
					e.r1=2;
					e.r2=0;
					e.r3=0;
					reponse_joueur=1;
				}
				else if(event.key.keysym.sym==SDLK_b)
				{
					e.r1=0;
					e.r2=2;
					e.r3=0;
					reponse_joueur=2;
				}
				else if(event.key.keysym.sym==SDLK_c)
				{
					e.r1=0;
					e.r2=0;
					e.r3=2;
					reponse_joueur=3;
				}
				else if(event.key.keysym.sym==SDLK_RETURN)
				{
					if(reponse_joueur==e.reponse)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
				break;	
		}
		}
	SDL_Flip(screen);
	SDL_Delay(125);
	}
	//SDL_FreeSurface(screen);
	TTF_CloseFont (e.police);
	for (int i=0;i<5;i++)
	{ 
  		SDL_FreeSurface(e.txt[i]);
	}
  	//TTF_Quit();
}

void sauvegarder (perso p, background b, char  nomfichier[]) 
{
	FILE *f;
	f=fopen(nomfichier,"w");
	fprintf(f,"%d\t%d\t%d\t%d\t%d\t%d\n",b.pos1.x,b.pos1.y,b.pos2.x,b.pos2.y,p.pos.x,p.pos.y);
	fclose(f);
}
void charger ( perso * p, background *b , char  nomfichier[])
{
	FILE *f;
	f=fopen(nomfichier,"r");
	//fscanf(f,"%d\t%d\t%d\t%d\t%d\t%d\n",&b->pos1.x,&b->pos1.y,&b->pos2.x,&b->pos2.y,&p->pos.x,&p->pos.y);

	fclose(f);
}
//void charger ( personne * p, background *b , char * nomfichier)
