#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"perso.h"
#include"ES.h"
#include"fonctions.h"
//colision
int collision(SDL_Rect pos1,SDL_Rect pos2)
{
    if(pos1.x + pos1.w > pos2.x && pos1.x < pos2.x + pos2.w && pos1.y + pos1.h 		> pos2.y && pos1.y < pos2.y + pos2.h) 
	{
		return 1;
	}
    return 0;
}
int collision_enemie(perso p,enmie e[])
{
	int pos=-1,i=0;
	if(p.etat==5)p.pos.x=p.pos.x-100;
	while(pos==-1 && i<2)
	{
		if(collision(e[i].pos,p.pos)==1)
			pos=i;
		i++;
	}
	return pos;
	if(p.etat==5)p.pos.x=p.pos.x+100;
}
int collision_traps(perso p,trap t[])
{
	int pos=-1,i=0;
	SDL_Rect pos1;
	while(pos==-1 && i<2)
	{
		pos1.x=t[i].pos1.x-t[i].pos2.x;
		pos1.y=t[i].pos1.y;
		pos1.w=t[i].pos1.w;
		pos1.h=t[i].pos1.h;
		if(collision(pos1,p.pos)==1)
			pos=i;
		i++;
	}
	return pos;
}
void collision_obstacles(obstacles o,perso p,int c_obstacles[])
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
int collision_checkpoint(checkpoint ch,perso p)
{
	int pos=-1,i=0;
	while(pos==-1 && i<2)
	{
		if(collision(ch.pos1[i],p.pos)==1)
			pos=i;
		i++;
	}
	return pos;
}
int collision_collections(perso p,collections c)
{
	int pos=-1,i=0;
	while(pos==-1 && i<5)
	{
		if(collision(c.pos[i],p.pos)==1)
			pos=i;
		i++;
	}
	return pos;
}
int collision_shot(shot sh,perso p)
{
	int pos=-1,i=0;
	while(pos==-1 && i<2)
	{
		if(collision(sh.pos[i],p.pos)==1)
			pos=i;
		i++;
	}
	return pos;
}
//initialisations
void initenmieSTAGE1(enmie e[])
{
	int x,w=126,h=226,y=0;
	e[0].etat_droite.img=IMG_Load("image/stage1/ES/photo_enmie/alien walk droite(1).png");
	e[1].etat_droite.img=IMG_Load("image/stage1/ES/photo_enmie/alien walk droite(1).png");
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
	e[0].etat_gauche.img=IMG_Load("image/stage1/ES/photo_enmie/alien walk gauche(1).png");
	e[1].etat_gauche.img=IMG_Load("image/stage1/ES/photo_enmie/alien walk gauche(1).png");
	for(int k=0;k<3;k++)
	{
		
		y=0;
		for(int i=0;i<3;i++)
		{
			x=856;
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
	e[0].pos.x=4969;
	e[0].pos.y=560;
	e[0].pos.w=100;
	e[0].pos.h=226;
	e[1].pos.x=1185;
	e[1].pos.y=560;
	e[1].pos.w=80;
	e[1].pos.h=226;
	for(int i=0;i<2;i++)
	{
		e[i].mouvment=0;
		e[i].pas=0;
		e[i].dir=0;
		e[i].etat=0;
	}
	e[0].champs_visuelle.x=e[0].pos.x-500;
	e[0].champs_visuelle.y=e[0].pos.y;
	e[0].champs_visuelle.w=1000+e[0].pos.w;
	e[0].champs_visuelle.h=e[0].pos.h+1000;
}
void initialiser_obstaclesSTAGE1(obstacles* o)
{
	(*o).img_obS[0]=IMG_Load("image/stage1/ES/obstacledynamique/16.png");
	(*o).pos[16].x=0;
	(*o).pos[16].y=760;
	(*o).pos[16].h=240;
	(*o).pos[16].w=3915;
	//
	(*o).pos[1].x=4969;
	(*o).pos[1].y=760;
	(*o).pos[1].h=240;
	(*o).pos[1].w=1337;
	//
	(*o).pos[2].x=7727;
	(*o).pos[2].y=760;
	(*o).pos[2].h=240;
	(*o).pos[2].w=1821;
	//
	(*o).pos[3].x=11749;
	(*o).pos[3].y=760;
	(*o).pos[3].h=240;
	(*o).pos[3].w=3207;
	//f1: w=211 / h=144 / x=777 / y=555
	(*o).pos[4].x=777;
	(*o).pos[4].y=350;
	(*o).pos[4].h=144;
	(*o).pos[4].w=211;
	//f2: w=334 / h=161 / x=1185 / y=408
	(*o).pos[5].x=1185;
	(*o).pos[5].y=200;
	(*o).pos[5].h=161;
	(*o).pos[5].w=334;
	//f3 : w=226 / h=162 / x=1763 / y=519
	(*o).pos[6].x=1763;
	(*o).pos[6].y=300;
	(*o).pos[6].h=162;
	(*o).pos[6].w=226;
	//f4: w=310 / h=75 / x=2623 / y=451
	(*o).pos[7].x=2623;
	(*o).pos[7].y=250;
	(*o).pos[7].h=75;
	(*o).pos[7].w=310;
	//f5: w=217 / h=151 / x=3103 / y=569
	(*o).pos[8].x=3103;
	(*o).pos[8].y=369;
	(*o).pos[8].h=151;
	(*o).pos[8].w=217;
	//f6: w=211 / h=144 / x=6449 / y=681
	(*o).pos[9].x=6449;
	(*o).pos[9].y=470;
	(*o).pos[9].h=144;
	(*o).pos[9].w=211;
	//f7: w=334 / h=161 / x=6847 / y=439
	(*o).pos[10].x=6847;
	(*o).pos[10].y=218;
	(*o).pos[10].h=161;
	(*o).pos[10].w=334;
	//f8: w=226 / h=162 / x=7318 / y=708
	(*o).pos[11].x=7318;
	(*o).pos[11].y=508-11;
	(*o).pos[11].h=162;
	(*o).pos[11].w=226;
	//f10: w=310 / h=75 / x=8657 / y=439
	(*o).pos[12].x=8657;
	(*o).pos[12].y=239;
	(*o).pos[12].h=75;
	(*o).pos[12].w=310;
	//f11: w=448 / h=359 / x=9728 / y=841
	(*o).pos[13].x=9728;
	(*o).pos[13].y=641;
	(*o).pos[13].h=359;
	(*o).pos[13].w=448;
	//f12: w=435 / h=591 / x=10392 / y=609
	(*o).pos[14].x=10392;
	(*o).pos[14].y=409;
	(*o).pos[14].h=591;
	(*o).pos[14].w=435;
	//f13: w=435 / h=120 / x=11044 / y=1080
	(*o).pos[15].x=11044;
	(*o).pos[15].y=880;
	(*o).pos[15].h=120;
	(*o).pos[15].w=435;
	//x=3915 hatta tosal x=4684   f9: w=285 / h=90 /y=960 / x=(3915 -> 4684)
	(*o).pos[0].x=3915;
	(*o).pos[0].y=760;
	(*o).pos[0].h=90;
	(*o).pos[0].w=285;
	//
	(*o).pos[17].x=12350;
	(*o).pos[17].y=581;
	(*o).pos[17].h=178;
	(*o).pos[17].w=150;
	(*o).pos[18].x=12950;
	(*o).pos[18].y=557;
	(*o).pos[18].h=211;
	(*o).pos[18].w=141;
	(*o).pos_min[0]=3915;
	(*o).pos_max[0]=4684;
	(*o).nbr=19;
	(*o).nbr_h=1;
	(*o).nbr_v=0;
	(*o).nbr_a=0;
	(*o).dir[0]=0;
	(*o).etat[0]=1;
	
}
void initialiser_trapSTAGE1(trap t[])
{
	
	t[0].img=IMG_Load("image/stage1/ES/traps/laser.png");
	t[0].etat=0;
	t[0].time=3;
	t[0].r=0;
	t[1].img=IMG_Load("image/stage1/ES/traps/laser.png");
	t[1].time=3;
	t[1].etat=0;
	t[0].r=0;
	
	
	t[0].pos1.x=8677;
	t[0].pos1.y=293;
	t[0].pos1.w=300;
	t[0].pos1.h=899;
	t[0].pos2.x=0;
	t[0].pos2.y=0;
	t[0].pos2.w=266;
	t[0].pos2.h=557;
	//
	t[1].pos1.x=2642;
	t[1].pos1.y=304;
	t[1].pos1.w=300;
	t[1].pos1.h=899;
	t[1].pos2.x=0;
	t[1].pos2.y=0;
	t[1].pos2.w=266;
	t[1].pos2.h=495;
}
void initialiser_chekpointSTAGE1(checkpoint *ch)
{
	(*ch).img[1]=IMG_Load("image/stage1/checkpoint/allumee.png");
	(*ch).img[0]=IMG_Load("image/stage1/checkpoint/eteinte.png");
	(*ch).pos1[0].w=107;
	(*ch).pos1[0].h=141;
	(*ch).pos1[0].x=2284;
	(*ch).pos1[0].y=620;
	(*ch).pos2[0].w=107;
	(*ch).pos2[0].h=141;
	(*ch).pos2[0].x=0;
	(*ch).pos2[0].y=0;
	//
	(*ch).pos1[1].w=107;
	(*ch).pos1[1].h=141;
	(*ch).pos1[1].x=5667;
	(*ch).pos1[1].y=620;
	(*ch).pos2[1].w=107;
	(*ch).pos2[1].h=141;
	(*ch).pos2[1].x=0;
	(*ch).pos2[1].y=0;
	//
	(*ch).pos1[2].w=107;
	(*ch).pos1[2].h=141;
	(*ch).pos1[2].x=9357;
	(*ch).pos1[2].y=620;
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
void initialiser_shotSTAGE1(shot *sh,enmie e)
{
	(*sh).img=IMG_Load("image/stage2/ES/photo_enmie/shoot.png");
	for(int i=0;i<3;i++)
	{
		(*sh).pos[i].y=e.pos.y+61;
		(*sh).pos[i].x=e.pos.x;
		(*sh).pos[i].h=50;
		(*sh).pos[i].w=50;
		(*sh).nbr=0;
		(*sh).r=0;
	}
}
void initialiser_collectionsSTAGE1(collections *c,SDL_Rect pos[])
{
	int tab[6];
	char nom[50],num[2];
	for(int i=0;i<4;i++)
	{
		strcpy(nom,"image/stage1/ES/cristale/c");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		(*c).img[i]=IMG_Load(nom);
		if((*c).img[i]==NULL) printf("%s\n",SDL_GetError());
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
		printf("%d\n",tab[i]);	
	}
	(*c).p=0;
	(*c).img_mini=IMG_Load("image/backgrounds/minicristale/mini_cristale.png");
	(*c).police=TTF_OpenFont("police/Ubuntu-Bold.ttf", 30);
	(*c).color[0].r = 225;
	(*c).color[0].g = 0;
	(*c).color[0].b = 0;
	//pour la couleur rouge
	(*c).color[1].r = 225;
	(*c).color[1].g = 225;
	(*c).color[1].b = 225;
	//pour la couleur blanc
	(*c).pos_mini[0].x=25;
	(*c).pos_mini[0].y=125;
	(*c).pos_mini[1].x=100;
	(*c).pos_mini[1].y=175;
	(*c).nbr=0;
	
}
int verif_collections(int tab[],int x,int n)
{
	int test=0,i=0;
	while(test==0 && i<n)
	{
		if(tab[i]==x)
			test=1;
		i++;
	}
	return test;
}
//animations
void animer_enmie (enmie* e)
{
	(*e).mouvment++;
	if((*e).etat==1)
		(*e).mouvment=0;
	else if((*e).mouvment==7)
	{
		(*e).mouvment=0;
		(*e).pas++;
		if((*e).pas==10)
		{
			(*e).pas=0;
			if((*e).dir==0)(*e).dir=1;
			else (*e).dir=0;
		}
	}
}
void animer_lazer(trap *t)
{
	int time;
	time=SDL_GetTicks()/1000;
	if(time%(*t).time==0)
	{
		if((*t).r==0)
		{
			if((*t).etat==0)(*t).etat=1;
			else (*t).etat=0;
			(*t).r=1;
		}
	}
	else
	{
		(*t).r=0;
	}
}
void annimer_checkpoint(checkpoint *ch)
{
	switch((*ch).etat)
	{
		case 0:
			(*ch).p[0]=1;
			break;
		case 1:
			(*ch).p[1]=1;
			break;
		case 2:
			(*ch).p[2]=1;
			break;
	}
}
void annimer_obstacles(obstacles *o)
{
	for(int i=(*o).nbr_h+(*o).nbr_v;i<(*o).nbr_h+(*o).nbr_v+(*o).nbr_a;i++)
	{
		if((*o).etat[i]==1 && (*o).tomber[i-(*o).nbr_h-(*o).nbr_v]==0)
		{
			
			(*o).p[i-(*o).nbr_h-(*o).nbr_v]++;
			if((*o).p[i-(*o).nbr_h-(*o).nbr_v]==(*o).nbr_pA)
			{ 
				(*o).p[i-(*o).nbr_h-(*o).nbr_v]=0;
				(*o).r[i-(*o).nbr_h-(*o).nbr_v]++;
				if((*o).r[i-(*o).nbr_h-(*o).nbr_v]==3)
				{
					(*o).etat[i]=0;
					(*o).tomber[i-(*o).nbr_h-(*o).nbr_v]=1;
				}
				
			}
			
		}
		else if((*o).tomber[i-(*o).nbr_h-(*o).nbr_v]==1)
		{
			(*o).pos[i].y=(*o).pos[i].y+5;

			if((*o).pos[i].y>=1200)
			{
				(*o).pos[i].h=0;
				(*o).tomber[i-(*o).nbr_h-(*o).nbr_v]=0;
			}
		}
	}
}
void annimer_collections(collections *c)
{
	(*c).p++;
	if((*c).p==4) (*c).p=0;
}

//movement
void move_enmie (enmie *e)
{
	if((*e).dir==0)
	{
		(*e).pos.x=(*e).pos.x+10;
		(*e).champs_visuelle.x=(*e).champs_visuelle.x+10;
		
	}
	else 
	{
		(*e).pos.x=(*e).pos.x-10;
		(*e).champs_visuelle.x=(*e).champs_visuelle.x-10;
	}
}
void movobstacle(obstacles *o)
{
	for(int i=0;i<(*o).nbr_h;i++)
	{
		if((*o).etat[i]==1)
		{
			if((*o).dir[i]==0)
			{
				(*o).pos[i].x=(*o).pos[i].x+5;
			}
			else
			{
				(*o).pos[i].x=(*o).pos[i].x-5;
			}
			
			if((*o).pos[i].x>=(*o).pos_max[i]) (*o).dir[i]=1;
			else if((*o).pos[i].x<=(*o).pos_min[i])(*o).dir[i]=0;
		}
	}
	for(int i=(*o).nbr_h;i<(*o).nbr_h+(*o).nbr_v;i++)
	{
		if((*o).etat[i]==1)
		{
			if((*o).dir[i]==2)
			{
				(*o).pos[i].y=(*o).pos[i].y+5;
			}
			else
			{
				(*o).pos[i].y=(*o).pos[i].y-5;
			}
			
			if((*o).pos[i].y>=(*o).pos_max[i]) (*o).dir[i]=3;
			else if((*o).pos[i].y<=(*o).pos_min[i])(*o).dir[i]=2;
		}
	}
}
void movshot(shot *ch,int dir)
{
	for(int i=0;i<3;i++)
	{
		if(dir==0)
		{
			(*ch).pos[i].x=	(*ch).pos[i].x+10;
		}
		else if(dir==1)
		{
			(*ch).pos[i].x=	(*ch).pos[i].x-10;
		}
	}
}
//affichage
void afficher_enmie( SDL_Surface * screen,enmie e)
{
	if(e.pos.w!=0 && e.pos.h!=0)
	{
		if(e.dir==0)
			SDL_BlitSurface(e.etat_droite.img,&e.etat_droite.pos[e.etat][e.mouvment],screen,&e.pos);
		else 
			SDL_BlitSurface(e.etat_gauche.img,&e.etat_gauche.pos[e.etat][e.mouvment],screen,&e.pos);
	}
}
void afficher_obstacles(SDL_Surface *screen,obstacles o)
{
	for(int i=0;i<o.nbr_h+o.nbr_v;i++)
	{
		SDL_BlitSurface(o.img_obS[i],NULL,screen,&o.pos[i]);
	}
	for(int i=o.nbr_h+o.nbr_v;i<o.nbr_h+o.nbr_v+o.nbr_a;i++)
	{
		SDL_BlitSurface(o.img_obA[o.p[i-o.nbr_h-o.nbr_v]],NULL,screen,&o.pos[i]);
	}
}
void afficher_trap(SDL_Surface *screen,trap t)
{
	if(t.etat==1)
		SDL_BlitSurface(t.img,&t.pos2,screen,&t.pos1);
}
void afficher_chekpoint(SDL_Surface *screen,checkpoint ch)
{
	for(int i=0;i<3;i++)
	{
		SDL_BlitSurface(ch.img[ch.p[i]],&ch.pos2[i],screen,&ch.pos1[i]);
	}
}
void afficher_shot(SDL_Surface *screen,shot sh)
{
	for(int i=0;i<sh.nbr;i++)
	{
		SDL_BlitSurface(sh.img,NULL,screen,&sh.pos[i]);
	}
}
void afficher_collections(SDL_Surface *screen,collections c)
{
	for(int i=0;i<5;i++)
	{
		if(c.pos[i].h!=0)
			SDL_BlitSurface(c.img[c.p],NULL,screen,&c.pos[i]);
	}
}
//scrolling
void deplacer_ennemie(enmie *e,int dir,int v)
{
	if(dir==0)
	{
		(*e).pos.x=(*e).pos.x-v;
		(*e).champs_visuelle.x=(*e).champs_visuelle.x-v;
	}
	else if(dir==1)
	{
		(*e).pos.x=(*e).pos.x+v;
		(*e).champs_visuelle.x=(*e).champs_visuelle.x+v;
	}
	else if(dir==3) 
	{
		(*e).pos.y=(*e).pos.y-v;
		(*e).champs_visuelle.y=(*e).champs_visuelle.y-v;
	}
	else
	{
		(*e).pos.y=(*e).pos.y+v;
		(*e).champs_visuelle.y=(*e).champs_visuelle.y+v;
	}
}
void deplacer_obstacles(obstacles *o,int dir,int v)
{
	for(int i=0;i<(*o).nbr;i++)
	{
		if(dir==0) 
			(*o).pos[i].x=(*o).pos[i].x-v;
		else if(dir==1)
			(*o).pos[i].x=(*o).pos[i].x+v;
		else if(dir==3)
			(*o).pos[i].y=(*o).pos[i].y-v;
		else
			(*o).pos[i].y=(*o).pos[i].y+v;
	}
	for(int i=0;i<(*o).nbr_h;i++)
	{
		if(dir==0)
		{
			(*o).pos_max[i]=(*o).pos_max[i]-v;
			(*o).pos_min[i]=(*o).pos_min[i]-v;
		}
		else if(dir==1)
		{
			(*o).pos_max[i]=(*o).pos_max[i]+v;
			(*o).pos_min[i]=(*o).pos_min[i]+v;
		}
	}
	for(int i=(*o).nbr_h;i<(*o).nbr_h+(*o).nbr_v;i++)
	{
		if(dir==2)
		{
			(*o).pos_max[i]=(*o).pos_max[i]+v;
			(*o).pos_min[i]=(*o).pos_min[i]+v;
		}
		else if(dir==3)
		{
			(*o).pos_max[i]=(*o).pos_max[i]-v;
			(*o).pos_min[i]=(*o).pos_min[i]-v;
		}
	}
}
void deplacer_trap(trap *t,int dir,int v,background back)
{
	
	if(dir==0)
	{
		if((*t).pos1.x>=back.pos1.x)
		{
			
			(*t).pos1.x=(*t).pos1.x-v;
		}
		else
		{
			
			(*t).pos2.x=(*t).pos2.x+v;
		}
	}
	else if(dir==1)
	{
		if((*t).pos2.x>=0)
		{
			
			(*t).pos2.x=(*t).pos2.x-v;
		}
		else
		{
			
			(*t).pos1.x=(*t).pos1.x+v;
		}
	}
	else if(dir==2)
	{
		(*t).pos1.y=(*t).pos1.y+v;
	}
	else if(dir==3)
	{
		(*t).pos1.y=(*t).pos1.y-v;
	}
}
void deplacer_chekpoint(checkpoint *ch,int dir,int v,background back)
{
	for(int i=0;i<2;i++)
	{
		if(dir==0)
		{
			if((*ch).pos1[i].x>=back.pos1.x)
			{
				(*ch).pos1[i].x=(*ch).pos1[i].x-v;
			}
			else
			{
				(*ch).pos2[i].x=(*ch).pos2[i].x+v;
			}
		}
		else if(dir==1)
		{
			if((*ch).pos2[i].x>=0)
			{
				(*ch).pos2[i].x=(*ch).pos2[i].x-v;
			}
			else
			{
				(*ch).pos1[i].x=(*ch).pos1[i].x+v;
			}
		}
		else if(dir==2)
		{
			(*ch).pos1[i].y=(*ch).pos1[i].y+v;
		}
		else if(dir==3)
		{
			(*ch).pos1[i].y=(*ch).pos1[i].y-v;
		}
	}
}
void deplacer_shot(shot *sh,int dir,int v)
{
	for(int i=0;i<3;i++)
	{
		if(dir==0)
		{
			(*sh).pos[i].x=(*sh).pos[i].x-v;
		}
		else if(dir==1)
		{
			(*sh).pos[i].x=(*sh).pos[i].x+v;
		}
		else if(dir==2)
		{
			(*sh).pos[i].y=(*sh).pos[i].y+v;
		}
		else if(dir==3)
		{
			(*sh).pos[i].y=(*sh).pos[i].y-v;
		}
	}
}
void deplacer_collections(collections *sh,int dir,int v)
{
	for(int i=0;i<5;i++)
	{
		if(dir==0)
		{
			(*sh).pos[i].x=(*sh).pos[i].x-v;
		}
		else if(dir==1)
		{
			(*sh).pos[i].x=(*sh).pos[i].x+v;
		}
		else if(dir==2)
		{
			(*sh).pos[i].y=(*sh).pos[i].y+v;
		}
		else if(dir==3)
		{
			(*sh).pos[i].y=(*sh).pos[i].y-v;
		}
	}
}
//elien_shot
void elien_shot(shot *sh,enmie e)
{
	int time;
	time=SDL_GetTicks()/1000;
	if(time%5==0)
	{
		if ((*sh).r==0)
		{
			if ((*sh).nbr!=3)
			{
				(*sh).nbr++;
				if(e.dir==0)
				{
					(*sh).pos[(*sh).nbr-1].x=e.pos.x+e.pos.w;
				}
			}
		}
		(*sh).r++;
	}
	else
		(*sh).r=0;
}
void avancer_shot(shot *sh,enmie e)
{
	for(int i=0;i<(*sh).nbr;i++)
	{
		if(e.dir==0)
		{
			(*sh).pos[i].x=(*sh).pos[i].x+5;
		}
		else
		{
			(*sh).pos[i].x=(*sh).pos[i].x-5;
		}
		if(    e.dir==1  &&   (*sh).pos[i].x<= e.pos.x-1205    )
		{
			(*sh).pos[i].x=e.pos.x;
			
		}
		else if (e.dir==0  &&   (*sh).pos[i].x>= e.pos.x+1205)
		{
			(*sh).pos[i].x=e.pos.x+e.pos.w;
		}
	}
}
