#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"minimap.h"
#include"fonctions.h"
#include"ES.h"
void initialiser_Masque(image *masque)
{
	masque->img=SDL_LoadBMP("image/minimap/timmy.png");
	masque->pos1.x=0;
	masque->pos1.y=0;
	
}

void initialiser_texte(texte *temp)
{

temp->police=TTF_OpenFont("police/Ubuntu-Bold.ttf",40);
if(temp->police==NULL)
	{
	printf("Unable to load image %s \n",SDL_GetError());
	return ;
}
	temp->color_txt.r=255;
	temp->color_txt.g=255;
	temp->color_txt.b=255;
	temp->pos_txt.x=500;
	temp->pos_txt.y=100;
	temp->s=0;
	temp->m=0;
	temp->h=0;
}

void ajout(texte *temp)
{ 	Uint32 x;
	x=(SDL_GetTicks()-2000)/1000;	
	temp->h=x/3600;
	temp->m=(x/60)%60;
	temp->s=x%60;
	  sprintf(temp->nom,"%02d:%02d",temp->m,temp->s);
}


void initmap(minimap *m,int nb_stage)
{
m->image_bonhomme=IMG_Load("image/minimap/timmy.png");
	m->position_bonhomme.x=600;
	m->position_bonhomme.y=50;
	m->position_bonhomme.h=487;  
	m->position_bonhomme.w=596; 
//alien
m->image_alien=IMG_Load("image/minimap/MINI ALIEN.png");
 if(nb_stage==1)
{	
for(int i=0;i<3;i++)
{
	m->position_alien[i].x=0;
	m->position_alien[i].y=0;
}

 //minimap
	m->image_minimap=IMG_Load("image/minimap/miniback.png");
	m->position_minimap.x=700;
	m->position_minimap.y=0;
	//obstacle
	m->image_obstacle=IMG_Load("image/minimap/obstacle.png");
	m->position_obstacle[0].x=300;
	m->position_obstacle[0].y=50;
//lazer
	m->image_lazer=IMG_Load("image/minimap/lazer.png");
	m->position_lazer[0].x=839;
	m->position_lazer[0].y=78;
	m->position_lazer[1].x=1163;
	m->position_lazer[1].y=78;

}
//stage 2
if(nb_stage==2)
{
m->image_lazer=IMG_Load("image/minimap2/laser(1).png");
	m->position_lazer[0].x=1038;
	m->position_lazer[0].y=149;

m->image_spike=IMG_Load("image/minimap2/iron.png");

	m->position_spike.x=1150;
	m->position_spike.y=139;
m->image_minimap=IMG_Load("image/minimap2/minimap2.png");

	m->position_minimap.x=600;
	m->position_minimap.y=0;
for(int i=0;i<4;i++)
{
	m->position_alien[i].x=0;
	m->position_alien[i].y=0;
}

m-> image_buttom1=IMG_Load("image/minimap2/down.png");

	m->position_buttom1.x=1046;
	m->position_buttom1.y=110;

m-> image_buttom2=IMG_Load("image/minimap2/up.png");

	m->position_buttom2.x=1046;
	m->position_buttom2.y=110;

m->image_dynamique=IMG_Load("image/minimap2/obstacle-dynamique-verticale2.png");

	m->position_dynamique.x=0;
	m->position_dynamique.y=0;

m-> image_obstacle=IMG_Load("image/minimap2/3.png");

	for(int j=0;j<5;j++)
{

m->position_obstacle[j].x=0;
	m->position_obstacle[j].y=0;
}
}
}//fin
void animerMinimap( SDL_Surface * screen,minimap m,trap t[],enmie e[],obstacles o,int nb_stage)
{
if(nb_stage==1)
{SDL_BlitSurface(m.image_obstacle,NULL,screen,&m.position_obstacle[0]); 
//printf("%d %d %d ",e[0].pos.w,e[0].pos.w,e.[0]pos.w);

SDL_BlitSurface(m.image_alien,NULL,screen,&m.position_alien[0]);
	SDL_BlitSurface(m.image_alien,NULL,screen,&m.position_alien[1]);
printf("%d\n",t[0].etat);
if(t[0].etat!=0 )
	{
	SDL_BlitSurface(m.image_lazer,NULL,screen,&m.position_lazer[0]);
	SDL_BlitSurface(m.image_lazer,NULL,screen,&m.position_lazer[1]);
	}
}
if(nb_stage==2)
{
for(int j=0;j<5;j++)
{
SDL_BlitSurface(m.image_obstacle,NULL,screen,&m.position_obstacle[j]);

}

if(o.etat[6]==0)
SDL_BlitSurface(m.image_buttom2,NULL,screen,&m.position_buttom2);
else
SDL_BlitSurface(m.image_buttom1,NULL,screen,&m.position_buttom1);
SDL_BlitSurface(m.image_dynamique,NULL,screen,&m.position_dynamique);
if(t[0].etat==1)
SDL_BlitSurface(m.image_lazer,NULL,screen,&m.position_lazer[0]);
if(t[1].etat==1)
SDL_BlitSurface(m.image_spike,NULL,screen,&m.position_spike);
SDL_BlitSurface(m.image_alien,NULL,screen,&m.position_alien[0]);
SDL_BlitSurface(m.image_alien,NULL,screen,&m.position_alien[1]);

}

}

void free_minimap(minimap m,int nb_stage)
{
SDL_FreeSurface(m.image_bonhomme);
SDL_FreeSurface(m.image_alien);
if(nb_stage==1)
{SDL_FreeSurface(m.image_minimap);
	SDL_FreeSurface(m.image_obstacle);
SDL_FreeSurface(m.image_lazer);}
if(nb_stage==2)
{
SDL_FreeSurface(m.image_lazer);
SDL_FreeSurface(m.image_obstacle);
SDL_FreeSurface(m.image_minimap);
SDL_FreeSurface(m.image_spike);
SDL_FreeSurface(m. image_buttom1);
SDL_FreeSurface(m. image_buttom2);
SDL_FreeSurface(m.image_dynamique);
}


}
void afficher_texte(SDL_Surface *screen,texte message)
{ 
	message.txt=TTF_RenderText_Blended(message.police,message.nom,message.color_txt);
	SDL_BlitSurface(message.txt,NULL,screen,&message.pos_txt);
}

void afficherminimap ( SDL_Surface * screen,minimap m,texte temp,int nb_stage,trap t[],enmie e[],obstacles o)
{ 
	temp.txt=TTF_RenderText_Blended(temp.police,temp.nom,temp.color_txt);
	SDL_BlitSurface(temp.txt,NULL,screen,&temp.pos_txt);

	SDL_BlitSurface(m.image_minimap,NULL,screen,&m.position_minimap);
	SDL_BlitSurface(m.image_bonhomme,NULL,screen,&m.position_bonhomme);
if(nb_stage==1)

	animerMinimap(screen,m,t,e,o,1);

if(nb_stage==2)
	animerMinimap(screen,m,t,e,o,2);
}

void MAJMinimap(perso p,minimap *m,obstacles o,enmie e[],background back,int nb_stage)
{int j;
if(nb_stage==2)
{ 
for( j=0;j<3;j++)
{
m->position_obstacle[j].x=(o.pos[j+3].x+back.pos2.x)/19.14 +593 ;//3 4 5
m->position_obstacle[j].y=(o.pos[j+3].y+back.pos2.y)/6 +10;
}
for( j=3;j<5;j++)
{
m->position_obstacle[j].x=(o.pos[j-3].x+back.pos2.x)/19.14 +593 ;//0 1
m->position_obstacle[j].y=(o.pos[j-3].y+back.pos2.y)/6 ;
}
for( j=0;j<3;j++)
{
if(m->position_obstacle[j].y>200)
m->position_obstacle[j].y=1500;
}
m->position_dynamique.x=(o.pos[2].x+back.pos2.x)/19.14 +590 ;
m->position_dynamique.y=(o.pos[2].y+back.pos2.y)/6 +15;


m->position_bonhomme.x=(p.pos.x+back.pos2.x )/19.14 +590;
m->position_bonhomme.y=(p.pos.y+back.pos2.y)/6 +20;
if(m->position_bonhomme.y>200)
m->position_bonhomme.y=1500;
m->position_alien[0].y=(e[0].pos.y+back.pos2.y)/6 +20 ;
m->position_alien[0].x=(e[0].pos.x+back.pos2.x)/19.14+590;
m->position_alien[1].x=900;
m->position_alien[1].y=50;

}
if(nb_stage==1)
{ 
m->position_bonhomme.x=(p.pos.x+back.pos2.x )/18.67 +690;
	m->position_bonhomme.y=(p.pos.y+back.pos2.y)/6 +10;
	m->position_obstacle[0].x=(o.pos[0].x+back.pos2.x)/20 +715 ;
	m->position_obstacle[0].y=(o.pos[0].y+back.pos2.y)/5.625 -10;
	m->position_alien[0].x=(e[0].pos.x+back.pos2.x)/18.67+690;
m->position_alien[0].y=(e[0].pos.y+back.pos2.y)/6 +20 ;
m->position_alien[1].x=(e[1].pos.x+back.pos2.x)/18.67+690;
m->position_alien[1].y=(e[1].pos.y+back.pos2.y)/6 +20;
		}
}





SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{

    SDL_Color color;
    Uint32 col = 0;
    //Determine position
    char *pixelPosition = (char *)Background->pixels;
    //Offset by Y
    pixelPosition += (Background->pitch * y);
    //Offset by X
    pixelPosition += (Background->format->BytesPerPixel * x);
    //Copy pixel data
    memcpy(&col, pixelPosition, Background->format->BytesPerPixel);
    //Convert to color
    SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

    return (color);
}


int collisionPP(perso p, image *Masque)
{
    SDL_Color test, couleurnoir = {0, 0, 0};
   int collision = 0, x, y,i;

    SDL_Rect pos[8];
    pos[0].x = p.pos.x;
    pos[0].y = p.pos.y;
    pos[1].x = p.pos.x + p.pos.w / 2;
    pos[1].y = p.pos.y;
    pos[2].x = p.pos.x + p.pos.w;
    pos[2].y = p.pos.y;
    pos[3].x = p.pos.x;
    pos[3].y = p.pos.y + p.pos.h / 2;
    pos[4].x = p.pos.x;
    pos[4].y = p.pos.y + p.pos.h;
    pos[5].x = p.pos.x + p.pos.w / 2;
    pos[5].y = p.pos.y + p.pos.h;
    pos[6].x = p.pos.x + p.pos.w;
    pos[6].y = p.pos.y + p.pos.h;
    pos[7].x = p.pos.x + p.pos.w;
    pos[7].y = p.pos.y + p.pos.h / 2;
 

    for (i=0; i<8 && collision==0;i++)
    {
        x = pos[i].x;
        y = pos[i].y;
        test = GetPixel(Masque->img, x, y);
        if (test.r == 0 && test.g == 0 && test.b == 0)
            collision = 1;
    }
    return collision;
}


