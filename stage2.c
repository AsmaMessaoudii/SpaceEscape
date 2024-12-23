#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ES.h"
#include "perso.h"
#include "enigme.h"
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
#include <stdio.h>   
#include <unistd.h>  
#include <fcntl.h>  
#include <errno.h>   
#include <termios.h>  
#include <string.h>  
#include <sys/ioctl.h>
#include <stdint.h> 
#include "serie.h"
void initenmieSTAGE2(enmie e[])
{
	int x,w=271,h=242,y=0;
	e[0].etat_droite.img=IMG_Load("image/stage2/ES/photo_enmie/walk right.png");
	e[1].etat_droite.img=IMG_Load("image/stage2/ES/photo_enmie/walk right.png");
	for(int k=0;k<3;k++)
	{
		y=0;
		for(int i=0;i<3;i++)
		{
			x=0;
			for(int j=0;j<7;j++)
			{
				e[k].etat_droite.pos[i][j].x=x;
				e[k].etat_droite.pos[i][j].y=y;
				e[k].etat_droite.pos[i][j].h=h;
				e[k].etat_droite.pos[i][j].w=w;
				x=x+w;
				if((i==1 && j==1) || (i==2 && j==2)) break;
			}
			y=y+h;
		}
	}
	e[0].etat_gauche.img=IMG_Load("image/stage2/ES/photo_enmie/walk gauche.png");
	e[1].etat_gauche.img=IMG_Load("image/stage2/ES/photo_enmie/walk gauche.png");
	for(int k=0;k<3;k++)
	{
		
		y=0;
		for(int i=0;i<3;i++)
		{
			x=1832;
			for(int j=0;j<7;j++)
			{
				x=x-w;
				e[k].etat_gauche.pos[i][j].x=x;
				e[k].etat_gauche.pos[i][j].y=y;
				e[k].etat_gauche.pos[i][j].h=h;
				e[k].etat_gauche.pos[i][j].w=w;
				
				if((i==1 && j==1) || (i==2 && j==2)) break;
			}
			y=y+h;
		}
	}
	e[0].pos.x=7550;
	e[0].pos.y=634-230+60;
	e[0].pos.w=w;
	e[0].pos.h=h;
	e[0].etat=0;
	e[1].pos.x=4768+1452-250;
	e[1].pos.y=10+30;
	e[1].pos.w=w;
	e[1].pos.h=h;
	for(int i=0;i<2;i++)
	{
		e[i].mouvment=0;
		e[i].pas=0;
		e[i].dir=0;
	}
	e[0].champs_visuelle.x=e[0].pos.x-500;
	e[0].champs_visuelle.y=e[0].pos.y-100;
	e[0].champs_visuelle.w=1000+e[0].pos.w;
	e[0].champs_visuelle.h=e[0].pos.h+1000;
}
void initialiser_obstaclesSTAGE2(obstacles* o)
{
	//INITIALISATIONS DES IMAGE
	(*o).img_obS[0]=IMG_Load("image/stage2/ES/obstacledynamique/f5.png");
	(*o).img_obS[1]=IMG_Load("image/stage2/ES/obstacledynamique/f5.png");
	(*o).img_obS[2]=IMG_Load("image/stage2/ES/obstacledynamique/obstacle dynamique verticale.png");
	(*o).img_obA[0]=IMG_Load("image/stage2/ES/obstacledynamique/1.png");
	(*o).img_obA[1]=IMG_Load("image/stage2/ES/obstacledynamique/2.png");
	(*o).img_obA[2]=IMG_Load("image/stage2/ES/obstacledynamique/3.png");
	(*o).img_obA[3]=IMG_Load("image/stage2/ES/obstacledynamique/up.png");
	(*o).img_obA[4]=IMG_Load("image/stage2/ES/obstacledynamique/down.png");
	//INITIALISATIONS DES POSITIONS
	/* *****les obstacles dynamique avec deplacement horizontal***** */ // dans ce stage il ya deux obstacles de ce type
	(*o).pos[0].x=12407;
	(*o).pos[0].y=760;
	(*o).pos[0].h=110;
	(*o).pos[0].w=281;
	
	(*o).pos[1].x=13243;
	(*o).pos[1].y=760;
	(*o).pos[1].h=110;
	(*o).pos[1].w=281;
	/* *****les obstacles dynamique avec deplacement verticales***** */ // dans ce stage il ya un seul obstacles de ce type
	(*o).pos[2].x=4473;
	(*o).pos[2].y=719;
	(*o).pos[2].h=143;
	(*o).pos[2].w=295;
	/* *****les obstacles dynamique avec animations***** */ // dans ce stage il ya 4 obstacles de ce type
	(*o).pos[3].x=2048;
	(*o).pos[3].y=760;
	(*o).pos[3].h=138;
	(*o).pos[3].w=407;
	
	(*o).pos[4].x=1441;
	(*o).pos[4].y=760;
	(*o).pos[4].h=138;
	(*o).pos[4].w=407;
	
	(*o).pos[5].x=2629;
	(*o).pos[5].y=760;
	(*o).pos[5].h=138;
	(*o).pos[5].w=407;
	
	(*o).pos[6].x=8550;
	(*o).pos[6].y=450;
	(*o).pos[6].h=110;
	(*o).pos[6].w=158;
	
	/* *****les obstacles statique ***** */ // 
	(*o).pos[7].x=0;
	(*o).pos[7].y=760;
	(*o).pos[7].h=240;
	(*o).pos[7].w=1270;
	
	(*o).pos[8].x=3209;
	(*o).pos[8].y=760;
	(*o).pos[8].h=240;
	(*o).pos[8].w=1559;
	
	(*o).pos[9].x=4768;
	(*o).pos[9].y=209;
	(*o).pos[9].h=791;
	(*o).pos[9].w=1452;
	
	(*o).pos[10].x=6469;
	(*o).pos[10].y=371;
	(*o).pos[10].h=163;
	(*o).pos[10].w=294;
	
	(*o).pos[11].x=6959;
	(*o).pos[11].y=489;
	(*o).pos[11].h=110;
	(*o).pos[11].w=300;
	
	(*o).pos[12].x=7491;
	(*o).pos[12].y=634;
	(*o).pos[12].h=366;
	(*o).pos[12].w=921;
	
	(*o).pos[13].x=8382;
	(*o).pos[13].y=864;
	(*o).pos[13].h=136;
	(*o).pos[13].w=1369;
	
	(*o).pos[14].x=9719;
	(*o).pos[14].y=634;
	(*o).pos[14].h=366;
	(*o).pos[14].w=2688;
	
	(*o).pos[15].x=14116;
	(*o).pos[15].y=760;
	(*o).pos[15].h=240;
	(*o).pos[15].w=1281;
	
	//NOMBRE DES OBSTACLES
	(*o).nbr=16;  // nombre d'obstacles totales
	(*o).nbr_h=2; // nombre d'obstacles dynamique avec deplacement horizontal
	(*o).nbr_v=1; // nombre d'obstacles dynamique avec deplacement verticale
	(*o).nbr_a=3; // nombre d'obstacles dynamique avec animations
	(*o).nbr_pA=3;
	
	
	// L'ETAT DES OBSTACLES DYNAMIQUE 
	/*etat=1:obstacles en mouvment etat=1:obstacles n'est pas en mouvment*/

	(*o).etat[0]=0; 
	(*o).etat[1]=0; 
	(*o).etat[2]=1; 
	(*o).etat[3]=0;	
	(*o).etat[4]=0;
	(*o).etat[5]=0;
	(*o).etat[6]=0;
	//initialisation du variables tomber
	for(int i=0;i<3;i++)
	{
		(*o).tomber[i]=0;
	}
	//initialisations du variable dir
	for(int i=0;i<7;i++)
	{
		(*o).dir[i]=0;
	}
	for(int i=0;i<5;i++)
	{
		(*o).p[i]=0;
		(*o).r[i]=0;
	}
	//initialisations du variable pos_max et pos min
	(*o).pos_min[0]=12407;
	(*o).pos_min[1]=13243;
	(*o).pos_min[2]=219;
	(*o).pos_max[0]=12938;	
	(*o).pos_max[1]=13831;
	(*o).pos_max[2]=719;
	
	
}
void initialiser_trapSTAGE2(trap t[])
{
	t[0].img=IMG_Load("image/stage2/ES/lazer/laser.png");
	t[0].etat=1;
	t[0].r=0;
	t[1].img=IMG_Load("image/stage2/ES/lazer/iron.png");
	t[1].time=4;
	t[1].etat=1;
	t[0].r=0;
	
	
	t[0].pos1.x=8396;
	t[0].pos1.y=686;
	t[0].pos1.w=1337;
	t[0].pos1.h=225;
	t[0].pos2.x=0;
	t[0].pos2.y=0;
	t[0].pos2.w=1337;
	t[0].pos2.h=225;
	//
	t[1].pos1.x=10550;
	t[1].pos1.y=582;
	t[1].pos1.w=899;
	t[1].pos1.h=87;
	t[1].pos2.x=0;
	t[1].pos2.y=0;
	t[1].pos2.w=899;
	t[1].pos2.h=87;
}
void initialiser_chekpointSTAGE2(checkpoint *ch)
{
	


	(*ch).img[1]=IMG_Load("image/stage2/checkpoint/allumee.png");
	(*ch).img[0]=IMG_Load("image/stage2/checkpoint/eteinte.png");
	(*ch).pos1[0].w=107;
	(*ch).pos1[0].h=141;
	(*ch).pos1[0].x=3656;
	(*ch).pos1[0].y=703-50;
	(*ch).pos2[0].w=107;
	(*ch).pos2[0].h=141;
	(*ch).pos2[0].x=0;
	(*ch).pos2[0].y=0;
	//
	(*ch).pos1[1].w=107;
	(*ch).pos1[1].h=141;
	(*ch).pos1[1].x=6959;
	(*ch).pos1[1].y=400;
	(*ch).pos2[1].w=107;
	(*ch).pos2[1].h=141;
	(*ch).pos2[1].x=0;
	(*ch).pos2[1].y=0;
	//
	(*ch).pos1[2].w=107;
	(*ch).pos1[2].h=141;
	(*ch).pos1[2].x=12282;
	(*ch).pos1[2].y=582-50;
	(*ch).pos2[2].w=107;
	(*ch).pos2[2].h=141;
	(*ch).pos2[2].x=0;
	(*ch).pos2[2].y=0;
	(*ch).etat=-1;
	
	for(int i=0;i<3;i++)
	{
		(*ch).p[i]=0;
	}
	
	
}
void initialiser_shotSTAGE2(shot *sh,enmie e)
{
	(*sh).img=IMG_Load("image/stage2/ES/photo_enmie/shoot.png");
	for(int i=0;i<3;i++)
	{
		(*sh).pos[i].y=e.pos.y+61;
		(*sh).pos[i].x=e.pos.x;
		(*sh).pos[i].h=1;
		(*sh).pos[i].w=0;
		(*sh).nbr=0;
		(*sh).r=0;
	}
}
void initialiser_collectionsSTAGE2(collections *c,SDL_Rect pos[])
{
	int tab[6];
	char nom[50],num[2];
	for(int i=0;i<4;i++)
	{
		strcpy(nom,"image/stage2/ES/cristale/c");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*c).img[i]=IMG_Load(nom);
	}
	for(int i=0;i<5;i++)
	{
		do
		{
			tab [i]=rand()%(17);
		}
		while(verif_collections(tab,tab[i],i)!=0);
		(*c).pos[i].w=212;
		(*c).pos[i].x=((2*pos[tab[i]].x+pos[tab[i]].w)/2)-(*c).pos[i].w/2;
		(*c).pos[i].y=pos[tab[i]].y-225;
		(*c).pos[i].h=225;
		
	}
	(*c).p=0;
	(*c).img_mini=IMG_Load("image/stage2/ES/cristale/c1.png");
	(*c).police=TTF_OpenFont("police/Ubuntu-Bold.ttf", 30);
	(*c).color[0].r = 225;
	(*c).color[0].g = 0;
	(*c).color[0].b = 0;
	//pour la couleur rouge
	(*c).color[1].r = 225;
	(*c).color[1].g = 225;
	(*c).color[1].b = 225;
	//pour la couleur blanc
	(*c).pos_mini[0].x=10;
	(*c).pos_mini[0].y=1600;
	(*c).pos_mini[1].x=1105;
	(*c).pos_mini[1].y=30;
	(*c).nbr=0;
	(*c).txt= TTF_RenderText_Blended((*c).police,"x0/3", (*c).color[0]);
}
void initialiser_backSTAGE2(background *b)
{
	char nom[50],num[4];
	(*b).nbr=6;
	for(int i=0;i<(*b).nbr;i++)
	{
		strcpy(nom,"image/stage2/background/animation_background/");
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
	(*b).pos1.w=15334;
	(*b).pos2.y=200;
	(*b).pos2.h=1000;
	(*b).pos2.w=1400;
	(*b).photo=0;
}
void retoure_checkpointstage2(perso *p,background *back,checkpoint *ch,enmie e[],obstacles *o,collections *c,trap t[],shot *sh,shot *sh2)
{
	int etat=(*ch).etat,dif;
	initPerso(p,1);
	initialiser_chekpointSTAGE2(ch);
	(*ch).etat=etat;
	annimer_checkpoint(ch);
	
	(*back).pos2.x=(*ch).pos1[etat].x;
	(*back).pos2.y=200;
	initenmieSTAGE2(e);
	for(int i=0;i<2;i++)
	{
		e[i].pos.x=e[i].pos.x-(*ch).pos1[etat].x;
	}
	initialiser_shotSTAGE2(sh,e[0]);
	initialiser_shotSTAGE2(sh2,e[1]);
	initialiser_obstaclesSTAGE2(o);
	for(int i=0;i<o->nbr;i++)
	{
		o->pos[i].x=o->pos[i].x-(*ch).pos1[etat].x;
	}
	(*o).pos_min[0]=(*o).pos_min[0]-(*ch).pos1[etat].x;
	(*o).pos_max[0]=(*o).pos_max[0]-(*ch).pos1[etat].x;
	initialiser_collectionsSTAGE2(c,o->pos);
	initialiser_trapSTAGE2(t);
	for(int i=0;i<2;i++)
	{
		t[i].pos1.x=t[i].pos1.x-(*ch).pos1[etat].x;
	}
	for(int i=0;i<etat;i++)
	{
		
		(*ch).pos1[i].x=(*ch).pos1[i].x-(*ch).pos1[etat].x;
		
	}
	for(int i=etat+1;i<3;i++)
	{
		
		(*ch).pos1[i].x=(*ch).pos1[i].x-(*ch).pos1[etat].x;		
	}
	(*ch).pos1[etat].x=0;
	p->pos.y=(*ch).pos1[etat].y-100;
	
	
}
void retoure_debutstage2(perso *p,background *back,checkpoint *ch,enmie e[],obstacles *o,collections *c,trap t[])
{
	initPerso(p,1);
	initialiser_chekpointSTAGE2(ch);
	initialiser_obstaclesSTAGE2(o);
	initialiser_trapSTAGE2(t);
	initenmieSTAGE2(e);
	initialiser_collectionsSTAGE2(c,o->pos);
	(*back).pos2.x=0;
	(*back).pos2.y=200;
	
}
player stage2(SDL_Surface *screen,input_joueur input,int select_perso,player p1)
{
	char buffer[100];                   // un buffer
    int i;
    uint8_t val1='1';
    uint8_t val2='2';
    // ouverture du port à 9600 bauds
    int fd = serialport_init("/dev/ttyACM0", 9600);
	//declarations des variable
	srand(time(NULL));
	int boocle=1,c_obstacles[2],c_enmie,c_champ,c_traps,c_shot1,c_shot2,c_collections,nb_stage=2,cc=0,c_checkpoint;
	SDL_Event event;
	trap t[2];
	enmie e[4];
	background back,back_hardluck,back_goodluck;
	obstacles o;
	vie_player vie;
	checkpoint ch;
	perso p;
	collections c;
	shot sh,sh2;
	score_info s;
	minimap m;
	texte temp;
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	//initialisations des variables
	TTF_Init();
	initmap(&m,2);
	initialiser_back_hardluck(&back_hardluck);
	initialiser_back_goodluck(&back_goodluck);
	initialiser_texte(&temp);
	initialiser_backSTAGE2(&back);
	init_imageVies(&vie);
	initenmieSTAGE2(e);
	initialiser_obstaclesSTAGE2(&o);
	initialiser_trapSTAGE2(t);
	initialiser_chekpointSTAGE2(&ch);
	initialiser_shotSTAGE2(&sh,e[0]);
	initialiser_shotSTAGE2(&sh2,e[1]);
	init_scoreTexte(&s);
	initPerso(&p,select_perso);
	initialiser_collectionsSTAGE2(&c,o.pos);
	p.maxsaut=10;
	s.score=0;
	while(boocle==1)
	{
	
		//  lecture d'une ligne
        serialport_read_until(fd, buffer, '\r', 9, 10);

        // suppression de la fin de ligne
        for (i=0 ; buffer[i]!='\r' && i<100 ; i++);
        buffer[i] = 0;
         if(strstr(buffer,"right"))
         {
        // écriture du résultat
        printf("right \n");
        serialport_writebyte(fd,val1);
	p.etat=2;
					p.dir=0;
					p.vitesse=20;
			init_scoreTexte(&s);		p.b=1;
	buffer[0]='\0';
         }
         if(strstr(buffer,"left"))
	
         {
        // écriture du résultat
        printf("left \n");if(c_checkpoint>ch.etat)
		{
			ch.etat=c_checkpoint;
			annimer_checkpoint(&ch);
		}
	p.etat=2;
					p.dir=1;
					p.vitesse=20;
        serialport_writebyte(fd,val2);
	buffer[0]='\0';
         }
	if(strstr(buffer,"up"))
	
         {
        // écriture du résultat
        if(p.saut!=1)
					{
						p.saut=1;
						p.mouvment=-1;
						p.haut=1;
						p.h=1;
					}
        serialport_writebyte(fd,val2);
	buffer[0]='\0';
         }
	else if(buffer[0]='\0' && cc==0)
	{
		p.etat=0;
	}	
		//affichage des variable
		temp.nom[0]='\0';
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
			if(p1.nbr_stage==2)
			{
				p1.nbr_stage=3;
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
		ajout(&temp);
		afficher_back(screen,back);
		afficher_enmie(screen,e[0]);
		afficher_enmie(screen,e[1]);
		afficher_imageVies(screen,vie);
		afficher_trap(screen,t[0]);
		afficher_trap(screen,t[1]);
		afficher_chekpoint(screen,ch);
		afficher_obstacles(screen,o);
		afficher_collections(screen,c);
		MAJMinimap(p,&m,o,e,back,2);
		afficherminimap(screen,m,temp,2,t,e,o);
		afficher_minicris(screen,&c);
		//	afficher_scoreTexte(screen,s);
		if(o.pos[6].x>=0)
		{
			if(o.etat[6]==0)
				SDL_BlitSurface(o.img_obA[3],NULL,screen,&o.pos[6]);
			else
				SDL_BlitSurface(o.img_obA[4],NULL,screen,&o.pos[6]);
		}
		afficherPerso(screen,p);
		//colision
		collision_obstacles(o,p,c_obstacles);
		c_enmie=collision_enemie(p,e);
		collision_checkpoint(ch,p);
		c_shot1=collision_shot(sh,p);
		c_collections=collision_collections(p,c);
		c_checkpoint=collision_checkpoint(ch,p);
		c_shot2=collision_shot(sh2,p);
		//blockage des directions
		c_traps=collision_traps(p,t);
		veriph_dir(o,&p,c_obstacles);
		//lire les evenment
		while(SDL_PollEvent(&event))
		{
		switch(event.type)
		{
			
			case SDL_QUIT:
				
				boocle=0;
				break;
			case SDL_KEYDOWN:
				cc=1;
				if(event.key.keysym.sym==input.right)
				{
					
					p.etat=2;
					p.dir=0;
					p.vitesse=20;
					p.b=1;
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
						p.h=1;
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
						p.pos.w=200;
					}
					
				}
				else if(event.key.keysym.sym==SDLK_c)
				{
					p.etat=1;
					p.vitesse=10;
				}
				else if(event.key.keysym.sym==SDLK_r)
				{
					boocle=0;
				}
				else if(event.key.keysym.sym==SDLK_ESCAPE)
						SDL_WM_ToggleFullScreen(screen);
				break;
			case SDL_KEYUP:
				p.pos.w=80;
					if(event.key.keysym.sym==input.right && p.dir==0)
					{
						cc=0;
						p.mouvment=0;
						p.etat=0;
					}
					else if(event.key.keysym.sym==input.down && p.etat==4)
					{
						cc=0;
						p.mouvment=0;
						p.etat=0;
					}
					else if(event.key.keysym.sym==input.left && p.dir==1)
					{
						cc=0;
						p.mouvment=0;
						p.etat=0;
					}
					else if(event.key.keysym.sym==input.up)
					{
						cc=0;
						p.haut=0;
					}
				break;
			
		}
		}
		//mouvment
		//movperso
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
						deplacer_shot(&sh2,p.dir,p.vitesse);
						deplacer_collections(&c,p.dir,p.vitesse);
					}
				}
			}
		}
		//movobstacles
		movobstacle(&o);
		//mov_enmie
		for(int i=0;i<1;i++)
		{
			if(e[i].etat==0)
			{
				move_enmie(&e[i]);
			}
		}
		/*if(e[0].etat==0);
			//movshot(&sh,e[0].dir);
		else*/ 
			avancer_shot(&sh,e[0]);
		afficher_shot(screen,sh);
		//animations
		for(int i=0;i<4;i++)
		{
			animer_enmie(&e[i]);
		}
		animer_lazer(&t[1]);
		animerPerso(&p);
		animerBack(&back);
		annimer_obstacles(&o);
		annimer_collections(&c);
		if(e[0].etat==1 && e[0].pos.h!=0)
		{
			elien_shot(&sh,e[0]);
			
		}
		//saut
		if(p.saut==1)
		{
			saut(&p);
			if(((p.movsaut<17 && p.haut==1) && p.pos.y>=200) || ((p.movsaut>17 || p.haut==0) && p.pos.y<=550) || ((p.movsaut>17 || p.haut==0) && back.pos2.y>=200) || ((p.movsaut<17 && p.haut==1) && back.pos2.y<=22))				
					mouv_saut(&p);
			else if((p.movsaut<17 && p.haut==1) && p.h==1)
			{
				scrolling(&back,2,22);
				deplacer_ennemie(&e[0],2,22);
				deplacer_ennemie(&e[1],2,22);
				deplacer_obstacles(&o,2,22);
				deplacer_trap(&t[0],2,22,back);
				deplacer_trap(&t[1],2,22,back);
				deplacer_chekpoint(&ch,2,22,back);
				deplacer_shot(&sh,2,22);
				deplacer_shot(&sh2,2,22);
				deplacer_collections(&c,2,22);
			}
			else if((p.movsaut>17 || p.haut==0) && p.b==1)
			{
				scrolling(&back,3,22);
				deplacer_ennemie(&e[0],3,22);
				deplacer_ennemie(&e[1],3,22);
				deplacer_obstacles(&o,3,22);
				deplacer_trap(&t[0],3,22,back);
				deplacer_trap(&t[1],3,22,back);
				deplacer_chekpoint(&ch,3,22,back);
				deplacer_shot(&sh,3,22);
				deplacer_shot(&sh2,3,22);
				deplacer_collections(&c,3,22);
			} 
		}
		printf("%d\n",p.b);
		if(p.b==1 && p.saut!=1) 
		{
			p.saut=1;
			p.movsaut=17;
		}
		//dans le cas des collision
		if(c_obstacles[0]==3 || c_obstacles[0]==4 || c_obstacles[0]==5)
		{
			o.etat[c_obstacles[0]]=1;
			if(o.tomber[c_obstacles[0]-o.nbr_h-o.nbr_v]==1)
			{
				deplacer_perso(&p,2,5);
			}
		}
		else if(c_obstacles[0]==0||c_obstacles[0]==1)
		{
			o.etat[c_obstacles[0]]=1;
			if((p.dir==0 && (p.pos.x<=700 || (back.pos2.x>=back.pos1.w-back.pos2.w && p.pos.x<=back.pos2.w-p.pos.w-10))) 
				||  p.dir==1 && (p.pos.x>=100 || (back.pos2.x<=10 && p.pos.x>=10)))
					deplacer_perso(&p,o.dir[c_obstacles[0]],5);
				else 
				{
					if((p.dir==1 && p.pos.x>back.pos1.x) || (p.dir==0 && p.pos.x<back.pos1.x+back.pos2.w-p.pos.w-10))
					{
						if((p.dir==0 && p.d!=0) || p.dir==1 && p.g!=0)
						{
							scrolling(&back,o.dir[c_obstacles[0]],5);
							deplacer_ennemie(&e[0],o.dir[c_obstacles[0]],5);
							deplacer_ennemie(&e[1],o.dir[c_obstacles[0]],5);
							deplacer_obstacles(&o,o.dir[c_obstacles[0]],5);
							deplacer_trap(&t[0],o.dir[c_obstacles[0]],5,back);
							deplacer_trap(&t[1],o.dir[c_obstacles[0]],5,back);
							deplacer_chekpoint(&ch,o.dir[c_obstacles[0]],5,back);
							deplacer_shot(&sh,o.dir[c_obstacles[0]],5);
							deplacer_shot(&sh2,o.dir[c_obstacles[0]],5);
							deplacer_collections(&c,o.dir[c_obstacles[0]],5);
						}
					}
				}
		}
		else if(c_obstacles[0]==2)
		{
			deplacer_perso(&p,o.dir[c_obstacles[0]],5);
		}
		else if(c_obstacles[0]==6 && p.b==0 && c_obstacles[1]!=7)
		{
			o.etat[6]=1;
			t[0].etat=0;
		}
		if(collision(p.pos,e[0].champs_visuelle)==1 && ((p.pos.x<=e[0].pos.x && e[0].dir==1) || (p.pos.x>=e[0].pos.x && e[0].dir==0)))
		{
			e[0].etat=1;	
		}
		else
		{
			e[0].etat=0;
		}
		e[1].etat=1;
		e[1].dir=1;
		if(e[1].pos.h!=0)
		{
			elien_shot(&sh2,e[1]);
		}
		avancer_shot(&sh2,e[1]);
		afficher_shot(screen,sh2);
		if(c_enmie!=-1 && p.etat==5)
		{
			e[c_enmie].pos.h=0;
			s.score=s.score+10;
		}
		if((c_enmie!=-1 && p.etat!=5 && e[c_enmie].pos.h!=0) || (c_traps!=-1 && t[c_traps].etat==1) ||(p.pos.y>=1200) || c_shot1!=-1 && sh.pos[c_shot1].h!=0 || c_shot2!=-1 && sh2.pos[c_shot2].h!=0)
		{
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
				retoure_checkpointstage2(&p,&back,&ch,e,&o,&c,t,&sh,&sh2);
			else
				retoure_debutstage2(&p,&back,&ch,e,&o,&c,t);
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
		SDL_Delay(50);
		SDL_Flip(screen);
	}
	
/* ** liberations**** */
	free_minimap(m,2);
	TTF_CloseFont(temp.police);
	TTF_Quit();
	//alien
	SDL_FreeSurface(e[0].etat_droite.img);
	SDL_FreeSurface(e[1].etat_droite.img);
	SDL_FreeSurface(e[0].etat_gauche.img);
	SDL_FreeSurface(e[1].etat_gauche.img);
	//obstacle
	SDL_FreeSurface(o.img_obS[0]);
	SDL_FreeSurface(o.img_obS[1]);
	SDL_FreeSurface(o.img_obS[2]);
	for(int i=0;i<5;i++)
	{
	SDL_FreeSurface(o.img_obA[i]);
	}
	
	SDL_FreeSurface(t[0].img);
	SDL_FreeSurface(t[1].img);
	SDL_FreeSurface(ch.img[1]);
	SDL_FreeSurface(ch.img[0]);
	for(int i=0;i<4;i++)
	{
	SDL_FreeSurface(c.img[i]);
	}	
	SDL_FreeSurface(c.img_mini);
	for(int i=0;i<6;i++)
	{
	SDL_FreeSurface(back.img[i]);
	}
	return p1;
}
