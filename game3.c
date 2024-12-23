#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"game3.h"
#include<time.h>
#include"minimap.h"

void initialiser_message(message *m)
{

m->police=TTF_OpenFont("police/Ubuntu-Bold.ttf",50);
if(m->police==NULL)
	{
	printf("Unable to load image %s \n",SDL_GetError());
	return ;
	}
m->color.r=255;
m->color.g=255;
m->color.b=255;
m->pos.x=900;//1270
m->pos.y=50;//923
strcpy(m->nom,"go to the Exit !!!");
}
void afficher_message(SDL_Surface *screen,message m)
{ 
	m.txt=TTF_RenderText_Blended(m.police,m.nom,m.color);
	SDL_BlitSurface(m.txt,NULL,screen,&m.pos);
}

void init_G3(image images[])
{ char nom[40] ,nom_image[60],num[4];
	strcpy(nom,"image/game3/");
	for(int i=0;i<11;i++)
	{
		strcpy(nom_image,nom);
		sprintf(num,"%d",i);
		strcat(nom_image,num);
		strcat(nom_image,".png");
		 images[i].img=IMG_Load(nom_image);
				
		images[10].pos1.x=150;
		images[10].pos1.y=40;		
		images[i].pos1.x=0;
		images[i].pos1.y=0;
		
	}


	for(int i=0;i<10;i++)
	{
	strcpy(nom,"image/game3/bg/");
	sprintf(num,"%d",i+1);
	strcat(nom,num);
	strcat(nom,".png");
	images[i+11].img=IMG_Load(nom);
	printf("e%d",i+1);
 	images[i+10].pos1.x=0;
  	images[i+10].pos1.y=0;	
	}
}

void afficher_imge(SDL_Surface *screen,image imge)
{
	SDL_BlitSurface(imge.img,NULL,screen,&imge.pos1);
}
void afficher_exite(SDL_Surface *screen, image imge,SDL_Rect posbouton[])
	{ int i;
for(i=0;i<3;i++)
	{ SDL_BlitSurface(imge.img,NULL,screen,&posbouton[i]);}
}
void afficher_timmy(SDL_Surface *screen, image imge,SDL_Rect pos_timali[],int pos_timmy)
{
 SDL_BlitSurface(imge.img,NULL,screen,&pos_timali[pos_timmy]);
}

void init(SDL_Rect posbouton[],SDL_Rect pos_timali[])
{
//init pos bouton
posbouton[0].x=150;
posbouton[0].y=40;
posbouton[1].x=150;
posbouton[1].y=461;
posbouton[2].x=150;
posbouton[2].y=835;
posbouton[3].x=457;//partie2
posbouton[3].y=165;
posbouton[4].x=457;
posbouton[4].y=460;
posbouton[5].x=457;
posbouton[5].y=732;
posbouton[6].x=755;//partie3
posbouton[6].y=289;
posbouton[7].x=755;
posbouton[7].y=461;
posbouton[8].x=755;
posbouton[8].y=617;
posbouton[9].x=1103;//partie4
posbouton[9].y=460;
//init pos timmy/alien
pos_timali[0].x=170;
pos_timali[0].y=10;
pos_timali[1].x=170;
pos_timali[1].y=410;
pos_timali[2].x=170;
pos_timali[2].y=800;
pos_timali[3].x=475;
pos_timali[3].y=135;
pos_timali[4].x=475;
pos_timali[4].y=430;
pos_timali[5].x=475;
pos_timali[5].y=680;
pos_timali[6].x=775;
pos_timali[6].y=260;
pos_timali[7].x=775;
pos_timali[7].y=430;
pos_timali[8].x=775;
pos_timali[8].y=590;
pos_timali[9].x=1130;
pos_timali[9].y=420;
}

int test(int pos[],int x)
{int t=0;
for(int i=0;i<3;i++)
	{if (pos[i]==x) t=1;}
return t;
}
void afficher_bleu(SDL_Surface *screen,image images[],int pos_timmy,alien e,SDL_Rect posbouton[])
{
switch (pos_timmy)
{
case 9:
{
if(test(e.pos_r,6)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[6]);
if(test(e.pos_r,7)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[7]);
if(test(e.pos_r,8)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[8]);
}break;
case 8:
{if(test(e.pos_r,4)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[4]);
if(test(e.pos_r,5)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[5]);
if(test(e.pos_r,7)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[7]);
if(test(e.pos_r,9)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[9]);
}break;
 case 7:
	{ if(test(e.pos_r,6)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[6]);
	if(test(e.pos_r,8)==0)
		SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[8]);	
	if(test(e.pos_r,4)==0)
		SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[4]);
	if(test(e.pos_r,9)==0)
		SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[9]);
	}break;
 case 6:
	{if(test(e.pos_r,3)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[3]);
	if(test(e.pos_r,4)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[4]);
	if(test(e.pos_r,7)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[7]);
	if(test(e.pos_r,9)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[9]);
	}break;
case 5:
{
 if(test(e.pos_r,2)==0)
			SDL_BlitSurface( images[5].img,NULL,screen,&posbouton[2]);
 if(test(e.pos_r,4)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[4]);
 if(test(e.pos_r,8)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[8]);
}break;
case 4:
{
 if(test(e.pos_r,0)==0)
			SDL_BlitSurface( images[5].img,NULL,screen,&posbouton[0]);
 if(test(e.pos_r,1)==0)
			SDL_BlitSurface( images[5].img,NULL,screen,&posbouton[1]);
 if(test(e.pos_r,2)==0)
			SDL_BlitSurface( images[5].img,NULL,screen,&posbouton[2]);
 if(test(e.pos_r,3)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[3]);
 if(test(e.pos_r,5)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[5]);
 if(test(e.pos_r,6)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[6]);
 if(test(e.pos_r,7)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[7]);
 if(test(e.pos_r,8)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[8]);
}break;
case 3:
{ 
 if(test(e.pos_r,0)==0)
			SDL_BlitSurface( images[5].img,NULL,screen,&posbouton[0]);
 if(test(e.pos_r,4)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[4]);
 if(test(e.pos_r,6)==0)
			SDL_BlitSurface( images[4].img,NULL,screen,&posbouton[6]);
}break;
}
}
/*void afficher_bleu(SDL_Surface *screen, image images[], int pos_timmy, alien e) {
    SDL_Rect posbouton[NUM_BUTTONS] = {  button positions  };
    SDL_Surface blue_button = images[4].img; / blue button image 

    int button_indexes[NUM_BUTTONS][MAX_BUTTONS_PER_INDEX] = {
        {0, 1, 2, 3, 5, 6, 7, 8}, // pos_timmy = 4 
        {0, 4, 6}, // pos_timmy = 3 
        {2, 4, 8}, //  pos_timmy = 5 
        {0, 4, 6, 9}, // pos_timmy = 6 
        {2, 4, 8}, // pos_timmy = 7 
        {1, 2, 3, 5, 6, 7, 8}, // pos_timmy = 8 
        {4, 6, 8} // pos_timmy = 9 
    };

    int index = pos_timmy - MIN_TIMMY_POSITION;
    for (int i = 0; i < MAX_BUTTONS_PER_INDEX; i++) {
        int button_index = button_indexes[index][i];
        if (test(e.pos_r, button_index) == 0) {
            SDL_BlitSurface(blue_button, NULL, screen, &posbouton[button_index]);
        }
    }
}*/
void movetimmy(int x,int y,int *pos,int c)
{
	if((x >=151 && x <= 291 )&&(y >=40 && y <= 180)  && (c==3 || c==4  ) )*pos=0;	
			if(x >=149 && x <= 289 && y >=461 && y <= 601 &&c==4  )*pos=1;
			if((x >=149 && x<= 289 && y >=835 && y <= 975 ) && (c==4 ||c==5))*pos=2;
			if(x >=457 && x <= 597)
			{if	((y>=165 && y<= 305)  && (c==4 ||c==6))	*pos=3;	
			if ((y >=460 && y<= 600&& (c==3 ||c==5 ||c==6 || c==7||c==8))) *pos=4;	
			if ((y >=732 && y <= 872) && (c==4||c==8))*pos=5;	}
			if(x >=755 && x <= 895)
			{if	((y >=289 && y <= 429) &&(c==3 ||c==4 ||c==7 ||c==9))	*pos=6;
			if	((y >=461 && y <= 601)&& (c==4 ||c==6||c==8 ||c==9))	*pos=7;
			if	((y >=617 && y <= 757) &&( c==4||c==5 ||c==7||c==9))	*pos=8;
			}
		if((x >=1100 && x <= 1240 )&&(y >=460 && y <= 600) && ( c==6||c==7 ||c==8))*pos=9;	 
}
void intialiser_alien(alien *e,SDL_Rect pos_timali[])
{
	for(int i=0;i<10;i++)
	{ 
		e->pos[i]=pos_timali[i];		
	}
	e->pos_r[0]=0;
	e->pos_r[1]=1;
	e->pos_r[2]=9;
	for(int i=0;i<10;i++)
	{ 
		e->t[i]=0;		
	}
}
void remplir_tab(int t[],int tab[])
{
	for(int i=0;i<10;i++)
	{
		t[i]=tab[i];
	}
}
void verif_movalien(int t[], int r)
{
		switch(r)
		{
			case 0:	 
				remplir_tab(t,(int []){0,1,0,1,1,0,0,0,0,0}); 
				break;
			case 1:
				remplir_tab(t,(int []){1,0,1,0,1,0,0,0,0,0});
				break;
			case 2:
				remplir_tab(t,(int []){0,1,0,0,1,1,0,0,0,0});
				break;		
			case 3:
				remplir_tab(t,(int []){1,0,0,0,1,0,1,0,0,0});
				break;	
			case 4:
				remplir_tab(t,(int []){1,1,1,1,0,1,1,1,1,0});
				break;	
			case 5:
				remplir_tab(t,(int []){0,0,1,0,1,0,0,0,1,0});
				break;	
			case 6:
				remplir_tab(t,(int []){0,0,0,1,1,0,0,1,0,1});
				break;	
			case 7:
				remplir_tab(t,(int []){0,0,0,0,1,0,1,0,1,1});
				break;	
			case 8:
				remplir_tab(t,(int []){0,0,0,0,1,1,0,1,0,1});
				break;	
			case 9:
				remplir_tab(t,(int []){0,0,0,0,0,0,1,1,1,0});
				break;	
		}
}
int existe(int t[],int x)
{int y=0;
for(int i=0;i<3;i++)
{if(t[i]==x)
y=1;
}
return y;
}
void move_alien(alien *e)
{
	int aleas_alien,aleas_move;
	aleas_alien=rand()%3;
	verif_movalien(e->t,aleas_alien);
	do
	{
		aleas_move=rand()%10;
	}
	while((e->t[aleas_move]==0) || (existe(e->pos_r,aleas_move)!=0));//|| (e->pos_r[0]!=aleas_move || e->pos_r[1]!=aleas_move || e->pos_r[2]!=aleas_move)|| existe(e->pos_r,aleas_move)!=0
	e->pos_r[aleas_alien]=aleas_move;

}
void afficher_alien(SDL_Surface *screen, image imge,alien e)
{
	for(int i=0;i<3;i++)
	{
		SDL_BlitSurface(imge.img,NULL,screen,&e.pos[e.pos_r[i]]);
	}
}

int game3(SDL_Surface *screen)
{srand(time(NULL));
	int boocle=1, y,x,test,i1=0;
	alien e;
	float x1=0.995;
	message m;
	SDL_Event event;
	
	image images[25];
	SDL_Rect posbouton[10];
	SDL_Rect pos_timali[10];
	int pos_timmy=7;
TTF_Init();
	init(posbouton,pos_timali);
	intialiser_alien(&e,pos_timali);
	initialiser_message(&m);
	//screen=SDL_SetVideoMode(1400,1000,32,SDL_HWSURFACE|SDL_SRCALPHA);
	
	init_G3(images);
images[10].pos1.x=150;
		images[10].pos1.y=40;
	while (boocle==1)
	{

y=SDL_GetTicks()/1000; 
		x1=x1+0.005;
//if(x1==1)
//{i1++;x1=x1-1;}
i1++;
if(i1==10)
i1=0;
	afficher_imge(screen,images[11+i1]);
	afficher_imge(screen,images[10]);
	afficher_exite(screen,images[9],posbouton);
	afficher_timmy(screen,images[8],posbouton,pos_timmy);
	afficher_timmy(screen,images[0],pos_timali,pos_timmy);
	//afficher_bleu(screen,images,pos_timmy,e)
	afficher_bleu(screen,images,pos_timmy,e,posbouton);
	afficher_alien(screen,images[3],e);
	//afficher_message(screen,m);
	if(pos_timmy==e.pos_r[0] || pos_timmy==e.pos_r[1] || pos_timmy==e.pos_r[2] )
		{
	afficher_alien(screen,images[3],e);
	SDL_Delay(1000);
		return 0;
		}		
	if(pos_timmy==0 || pos_timmy==1 || pos_timmy==2 )
		{afficher_alien(screen,images[3],e);
		SDL_Delay(1000);
		return 1;}
		while(SDL_PollEvent(&event))
		{
		switch(event.type)
		{
			case SDL_QUIT:
				boocle=0;
				break;
		 case SDL_MOUSEBUTTONUP:
			 { 	int x = event.motion.x;
   		        int y = event.motion.y;
			int c=pos_timmy;
			movetimmy(x,y,&pos_timmy,c);
			if(c!=pos_timmy ) move_alien(&e);
			}
			break;
		
		
		}}
	
	SDL_Flip(screen);
	SDL_Delay(50);
	}
	TTF_CloseFont (m.police);
	SDL_FreeSurface(screen);
	TTF_Quit();

}


