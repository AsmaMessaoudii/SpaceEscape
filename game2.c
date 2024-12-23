#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "minimap.h"
#include"game2.h"

void initialiser_etat(int etat[])
{
	for(int i=0;i<8;i++)
	{
		etat[i]=0;
	}
}
void initialise_tabcart(int tab_carte[],image tab_carteimage[])
{
	char nom[40],num[2];
	for(int i=0;i<8;i++)
	{
		
		do
		{
			
			tab_carte[i]=rand()%(4);
		}while(verif_tab(tab_carte,tab_carte[i],i)!=1);
	
	}
	for(int i=0;i<8;i++)
	{
		strcpy(nom,"image/game2/carte/");
		sprintf(num,"%d",tab_carte[i]);
		strcat(nom,num);
		strcat(nom,".png");
		tab_carteimage[i].img=IMG_Load(nom);
		if(i<=3) 
		{
			tab_carteimage[i].pos1.y=129;
			tab_carteimage[i].pos1.x=79+(324*i);
		}
		else
		{
			tab_carteimage[i].pos1.y=634;
			tab_carteimage[i].pos1.x=79+(324*(i-4));
		}
		
		
	}
}
void afficher_cartes(SDL_Surface *screen,image tab_carteimage[])
{
	for(int i=0;i<8;i++)
	{
		SDL_BlitSurface(tab_carteimage[i].img,NULL,screen,&tab_carteimage[i].pos1);
	}
}
int verif_tab(int tab_carte[],int carte,int n)
{
	int test=1,i=0,s=0;
	
	while(test==1 && i<n)
	{
		if(tab_carte[i]==carte)
		{
			s++;
			if(s==2)
			{
				test=0;
			}
		}
		i++;
	}
	return test;
}

void init_cartevide(image vide[])
{	char nom[40],num[2];
for(int i=0;i<8;i++)
	{
		strcpy(nom,"image/game2/vide/vide");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		vide[i].img=IMG_Load(nom);
		if(i<=3) 
		{
			vide[i].pos1.y=129;
			vide[i].pos1.x=79+(324*i);
		}
		else
		{
			vide[i].pos1.y=634;
			vide[i].pos1.x=79+(324*(i-4));
		}
		
	}

}



void initialiser_backgame2(image back_game2[])
{
	char nom[30],num[4];
	for(int i=0;i<2;i++)
	{
		strcpy(nom,"image/game2/back_enigme/bg");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		back_game2[i].img=IMG_Load(nom);
		back_game2[i].pos1.x=0;
		back_game2[i].pos1.y=0;
		
	}	
}

void afficher_backgame2(SDL_Surface *screen,image back_game2[])
{
	for(int i=0;i<2;i++)
	{
		SDL_BlitSurface(back_game2[i].img,NULL,screen,&back_game2[i].pos1);
	}
}
void afficher_unecarte(SDL_Surface *screen,image imge)
{
SDL_BlitSurface(imge.img,NULL,screen,&imge.pos1);
}

int game2(SDL_Surface *screen)

{
	srand(time(NULL));
	int etat[8],tab_carteint[8],boocle=1,s,x,selected[2] = {-1, -1},mistake=0,same=0;
	image tab_carteimage[8],back_game2[3],vide[8];
	SDL_Event event;
	initialiser_etat(etat);
	initialise_tabcart(tab_carteint,tab_carteimage);
	SDL_WM_SetCaption("you need in this game to find 2 same cards\t GOOD LUCK :)",NULL);
	initialiser_backgame2(back_game2);
	init_cartevide(vide);
	afficher_backgame2(screen,back_game2);
	afficher_cartes(screen,vide);
	
	while (boocle==1)
	{	
	if (mistake==5)
		return 0;
	if(same==4)
	return 1;
if (s == 2) 
	{
    int card1 = tab_carteint[selected[0]];
    int card2 = tab_carteint[selected[1]];
    if (card1 == card2) 
    {
        etat[selected[0]] = 2; 
        etat[selected[1]] = 2; 
        s = 0;
	same++; 
    }
    else 
    {
        SDL_Delay(1000); 
        afficher_unecarte(screen, vide[selected[0]]); 
        afficher_unecarte(screen, vide[selected[1]]); 
        etat[selected[0]] = 0; 
        etat[selected[1]] = 0; 
        s = 0; 
	mistake++;
    }
}
		s=0;	
		
		for(int i=0;i<8;i++)
		{
		if(etat[i]==1)
		s++;}
		
		while(SDL_PollEvent(&event))
		{  
		 switch(event.type)
		 {
			case SDL_QUIT:
				boocle=0;
				break;
		 case SDL_MOUSEBUTTONUP:
		 { 		if( s<2)
{ 				if(event.motion.y >= 129 && event.motion.y <= 410)
		   {
			if(event.motion.x >=79 && event.motion.x <= 295)
			{  	
			 if (etat[0] == 0)
                            {
                                afficher_unecarte(screen, tab_carteimage[0]);
                                etat[0] = 1;
                                selected[s] = 0;
                                s++;
                            }												
			}
			if(event.motion.x >=403 && event.motion.x <= 619)
			{
			   if (etat[1] == 0)
                            {
                                afficher_unecarte(screen, tab_carteimage[1]);
                                etat[1] = 1;
                                selected[s] = 1;
                                s++;
                            }	
			}
			if(event.motion.x >=727 && event.motion.x <= 943)
			{
			    if (etat[2] == 0)
                            {
                                afficher_unecarte(screen, tab_carteimage[2]);
                                etat[2] = 1;
                                selected[s] = 2;
                                s++;
                            }	
			}
			if(event.motion.x >=1051 && event.motion.x <= 1269)
			{
			   if (etat[3] == 0)
                            {
                                afficher_unecarte(screen, tab_carteimage[3]);
                                etat[3] = 1;
                                selected[s] = 3;
                                s++;
                            }	
			}
		   }//partie 2
			 if(event.motion.y >= 634 && event.motion.y <= 915)
		   {
			if(event.motion.x >=79 && event.motion.x <= 295)
			{
			  if (etat[4] == 0)
                            {
                                afficher_unecarte(screen, tab_carteimage[4]);
                                etat[4] = 1;
                                selected[s] = 4;
                                s++;
                            }	
			}
			if(event.motion.x >=403 && event.motion.x <= 619)
			{
			   if (etat[5] == 0)
                            {
                                afficher_unecarte(screen, tab_carteimage[5]);
                                etat[5] = 1;
                                selected[s] = 5;
                                s++;
                            }	
			}
			if(event.motion.x >=727 && event.motion.x <= 943)
			{
			  if (etat[6] == 0)
                            {
                                afficher_unecarte(screen, tab_carteimage[6]);
                                etat[6] = 1;
                                selected[s] = 6;
                                s++;
                            }	
			}
			if(event.motion.x >=1051 && event.motion.x <= 1269)
			{
			  if (etat[7] == 0)
                            {
                                afficher_unecarte(screen, tab_carteimage[7]);
                                etat[7] = 1;
                                selected[s] = 7;
                                s++;
                            }	
			}
		   }
			
		  }}  break;
		 }
		}


		SDL_Flip(screen);
	}
}








