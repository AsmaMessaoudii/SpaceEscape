#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "maze.h"
#include<time.h>
#include "minimap.h"
void initialiser_backmaze(image back_maze[])
{
	char nom[70],num[3];
	for(int i=1;i<11;i++)
	{
		strcpy(nom,"image/maze/");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		back_maze[i].img=IMG_Load(nom);
		back_maze[i].pos1.x=0;
		back_maze[i].pos1.y=0;
	}	
}
void afficher_maze(SDL_Surface *screen,image back_maze[],int nb_photo)
{
	
		SDL_BlitSurface(back_maze[nb_photo].img,NULL,screen,&back_maze[nb_photo].pos1);
		

}
/*int move_left(int timmy) {
    int map[84] = {0, 0, 3, 1, 4, 0, 8, 0, 10, 0, 11, 0, 0, 13, 14, 16, 18, 21, 22, 0, 25, 32, 28, 30, 0, 33, 0, 36, 0, 38, 42, 40, 0, 39, 46, 49, 0, 48, 54, 0, 55, 58, 60, 61, 0, 65, 66, 0, 68, 71, 0, 74, 76, 79, 77, 81, 83};

    if (timmy >= 1 && timmy <= 83) {
        return map[timmy];
    } else {
        return timmy;
    }
}*/
int  move_left(int timmy)
{
switch(timmy)
{
case 1:
timmy=0;break;
case 2:
timmy=3;break;
case 4:
timmy=1;break;
case 5:
timmy=4;break;
case 7:
timmy=8;break;
case 9:
timmy=10;break;
case 12:
timmy=11;break;
case 14:
timmy=13;break;
case 15:
timmy=14;break;
case 17:
timmy=16;break;
case 19:
timmy=18;break;
case 20:
timmy=21;break;
case 21:
timmy=22;break;
case 24:
timmy=25;break;
case 25:
timmy=32;break;
case 27:
timmy=28;break;
case 29:
timmy=30;break;
case 32:
timmy=33;break;
case 35:
timmy=36;break;
case 39:
timmy=38;break;
case 40:
timmy=42;break;
case 41:
timmy=40;break;
case 45:
timmy=39;break;
case 47:
timmy=46;break;
case 48:
timmy=49;break;
case 52:
timmy=48;break;
case 53:
timmy=54;break;
case 56:
timmy=55;break;
case 57:
timmy=58;break;
case 59:
timmy=60;break;
case 62:
timmy=61;break;
case 64:
timmy=65;break;
case 65:
timmy=66;break;
case 69:
timmy=68;break;
case 70:
timmy=71;break;
case 73:
timmy=74;break;
case 75:
timmy=76;break;
case 77:
timmy=79;break;
case 78:
timmy=77;break;
case 80:
timmy=81;break;
case 82:
timmy=83;break;
}
return timmy;
}

int  move_right(int timmy)
{
switch(timmy)
{
case 0:
timmy=1;break;
case 1:
timmy=4;break;
case 3:
timmy=2;break;
case 4:
timmy=5;break;
case 8:
timmy=7;break;
case 10:
timmy=9;break;
case 11:
timmy=12;break;
case 13:
timmy=14;break;
case 14:
timmy=15;break;
case 16:
timmy=17;break;
case 18:
timmy=19;break;
case 21:
timmy=20;break;
case 22:
timmy=21;break;
case 25:
timmy=24;break;
case 28:
timmy=27;break;
case 30:
timmy=29;break;
case 32:
timmy=25;break;
case 33:
timmy=32;break;
case 36:
timmy=35;break;
case 38:
timmy=39;break;
case 39:
timmy=45;break;
case 40:
timmy=41;break;
case 42:
timmy=40;break;
case 46:
timmy=47;break;
case 48:
timmy=52;break;
case 49:
timmy=48;break;
case 54:
timmy=53;break;
case 55:
timmy=56;break;
case 58:
timmy=57;break;
case 60:
timmy=59;break;
case 61:
timmy=62;break;
case 65:
timmy=64;break;
case 66:
timmy=65;break;
case 68:
timmy=69;break;
case 71:
timmy=70;break;
case 73:
timmy=84;break;
case 74:
timmy=73;break;
case 76:
timmy=75;break;
case 77:
timmy=78;break;
case 79:
timmy=77;break;
case 81:
timmy=80;break;
case 83:
timmy=82;break;
}
return timmy;
}

int  move_up(int timmy)
{
switch(timmy)
{
case 2:
timmy=1;break;
case 4:
timmy=7;break;
case 5:
timmy=6;break;
case 8:
timmy=9;break;
case 11:
timmy=10;break;
case 13:
timmy=4;break;
case 14:
timmy=16;break;
case 16:
timmy=20;break;
case 17:
timmy=18;break;
case 21:
timmy=24;break;
case 22:
timmy=23;break;
case 25:
timmy=26;break;
case 27:
timmy=25;break;
case 29:
timmy=28;break;
case 30:
timmy=31;break;
case 32:
timmy=38;break;
case 33:
timmy=35;break;
case 34:
timmy=33;break;
case 36:
timmy=37;break;
case 39:
timmy=40;break;
case 42:
timmy=44;break;
case 43:
timmy=42;break;
case 46:
timmy=45;break;
case 48:
timmy=47;break;
case 49:
timmy=50;break;
case 51:
timmy=49;break;
case 53:
timmy=52;break;
case 55:
timmy=54;break;
case 56:
timmy=61;break;
case 57:
timmy=56;break;
case 58:
timmy=59;break;
case 61:
timmy=64;break;
case 63:
timmy=62;break;
case 65:
timmy=68;break;
case 66:
timmy=67;break;
case 68:
timmy=73;break;
case 70:
timmy=69;break;
case 72:
timmy=70;break;
case 74:
timmy=77;break;
case 75:
timmy=74;break;
case 80:
timmy=79;break;
case 81:
timmy=82;break;
}
return timmy;
}

int  move_down(int timmy)
{
switch(timmy)
{
case 1:
timmy=2;break;
case 4:
timmy=13;break;
case 6:
timmy=5;break;
case 7:
timmy=4;break;
case 9:
timmy=8;break;
case 10:
timmy=11;break;
case 16:
timmy=14;break;
case 18:
timmy=17;break;
case 20:
timmy=16;break;
case 23:
timmy=22;break;
case 24:
timmy=21;break;
case 25:
timmy=27;break;
case 26:
timmy=25;break;
case 28:
timmy=29;break;
case 31:
timmy=30;break;
case 33:
timmy=34;break;
case 35:
timmy=33;break;
case 37:
timmy=36;break;
case 38:
timmy=32;break;
case 40:
timmy=39;break;
case 42:
timmy=43;break;
case 44:
timmy=42;break;
case 45:
timmy=46;break;
case 47:
timmy=48;break;
case 49:
timmy=51;break;
case 50:
timmy=49;break;
case 52:
timmy=53;break;
case 54:
timmy=55;break;
case 56:
timmy=57;break;
case 59:
timmy=58;break;
case 61:
timmy=56;break;
case 62:
timmy=63;break;
case 64:
timmy=61;break;
case 67:
timmy=66;break;
case 68:
timmy=65;break;
case 69:
timmy=70;break;
case 70:
timmy=72;break;
case 73:
timmy=68;break;
case 74:
timmy=75;break;
case 77:
timmy=74;break;
case 79:
timmy=80;break;
case 82:
timmy=81;break;
}
return timmy;
}
void move(int *timmy,int etat)
{
switch(etat)
{
case 1:
*timmy=move_left(*timmy);	
break;
case 2:

*timmy=move_right(*timmy);

break;
case 3:
*timmy=move_up(*timmy);
break;
case 4:
*timmy=move_down(*timmy);
break;


}//fin switch

}
void init_maze(image *joueur,image *maze)
{



maze->img=IMG_Load("image/maze/maze.png");
if(  maze->img==NULL)
printf("e2\t");
maze->pos1.x=292;
maze->pos1.y=174;


 joueur->img=IMG_Load("image/maze/timmy.png");
if(  joueur->img==NULL)
printf("e2\t");
 joueur->pos1.x=980;
joueur->pos1.y=390;


}


void afficher_joueur(SDL_Surface *screen,image joueur,SDL_Rect points[],int timmy)
{

	SDL_BlitSurface(joueur.img,NULL,screen,&points[timmy]);
}
void init_mazepoints(SDL_Rect points[])
{
points[0].x=290 ;
points[0].y= 792;
points[1].x=440 ;
points[1].y= 792;
points[2].x= 440;
points[2].y=862 ;
points[3].x=290 ;
points[3].y=862;
points[4].x=510 ;
points[4].y= 792;
points[5].x=577 ;
points[5].y= 792;
points[6].x= 577;
points[6].y= 725;
points[7].x=510 ;
points[7].y= 725;
points[8].x=440 ;
points[8].y=725;
points[9].x= 440;
points[9].y= 655;
points[10].x= 290;
points[10].y=655 ;
points[11].x=290 ;
points[11].y= 725;
points[12].x=372 ;
points[12].y= 725;
points[13].x= 510;
points[13].y= 860;
points[14].x= 640;
points[14].y= 860;
points[15].x= 775;
points[15].y= 860;
points[16].x= 643;
points[16].y= 792;
points[17].x= 710;
points[17].y= 792;
points[18].x= 710;
points[18].y= 590;
points[19].x=780 ;
points[19].y= 590;
points[20].x= 643;
points[20].y= 655;
points[21].x= 577;
points[21].y= 655;
points[22].x= 510;
points[22].y= 655;
points[23].x= 510;
points[23].y= 590;
points[24].x= 577;
points[24].y= 460;
points[25].x= 510;
points[25].y= 460;
points[26].x= 510;
points[26].y= 390;
points[27].x= 510;
points[27].y= 520;
points[28].x= 440;
points[28].y= 520;
points[29].x= 440;
points[29].y= 590;
points[30].x= 310;
points[30].y= 590;
points[31].x= 310;
points[31].y= 460;
points[32].x= 440;
points[32].y= 457;
points[33].x= 375;
points[33].y= 457;
points[34].x= 375;
points[34].y= 520;
points[35].x= 375;
points[35].y= 390;
points[36].x= 310;
points[36].y= 390;
points[37].x= 310;
points[37].y= 190;
points[38].x= 440;
points[38].y= 320;
points[39].x= 510;
points[39].y= 320;
points[40].x= 510;
points[40].y= 250;
points[41].x= 577;
points[41].y= 250;
points[42].x= 373;
points[42].y= 250;
points[43].x= 373;
points[43].y= 320;
points[44].x= 373 ;
points[44].y=190  ;
points[45].x= 577 ;
points[45].y= 320 ;
points[46].x= 577 ;
points[46].y= 390 ;
points[47].x= 710 ;
points[47].y=  390;
points[48].x= 710 ;
points[48].y= 520 ;
points[49].x= 640 ;
points[49].y= 520 ;
points[50].x= 640 ;
points[50].y=  460;
points[51].x= 640 ;
points[51].y= 590 ;
points[52].x= 845 ;
points[52].y= 520 ;
points[53].x=  845;
points[53].y= 655 ;
points[54].x= 780 ;
points[54].y= 655 ;
points[55].x= 780 ;
points[55].y= 725 ;
points[56].x=910  ;
points[56].y= 725 ;
points[57].x= 910 ;
points[57].y= 860 ;
points[58].x= 845 ;
points[58].y= 860 ;
points[59].x= 845 ;
points[59].y= 792 ;
points[60].x= 780 ;
points[60].y=  792;
points[61].x= 910 ;
points[61].y= 590 ;
points[62].x= 980 ;
points[62].y= 590 ;
points[63].x=980  ;
points[63].y= 860 ;
points[64].x= 910 ;
points[64].y= 460 ;
points[65].x= 845 ;
points[65].y= 460 ;
points[66].x=780  ;
points[66].y= 460 ;
points[67].x=  780;
points[67].y= 390 ;
points[68].x= 845 ;
points[68].y= 320 ;
points[69].x=980  ;
points[69].y=320  ;
points[70].x=980  ;
points[70].y= 390 ;
points[71].x= 910 ;
points[71].y= 390 ;
points[72].x=980  ;
points[72].y= 520 ;
points[73].x= 845 ;
points[73].y= 250 ;
points[74].x=780  ;
points[74].y= 250 ;
points[75].x= 780 ;
points[75].y= 320 ;
points[76].x= 640 ;
points[76].y=  320;
points[77].x= 780 ;
points[77].y= 190 ;
points[78].x= 980 ;
points[78].y= 190 ;
points[79].x= 710 ;
points[79].y= 190 ;
points[80].x= 710 ;
points[80].y= 250 ;
points[81].x= 640 ;
points[81].y= 250 ;
points[82].x= 640 ;
points[82].y= 190 ;
points[83].x= 440 ;
points[83].y= 190 ;
points[84].x=980  ;
points[84].y= 250 ;

}
int maze(SDL_Surface *screen)
{
	int boocle=1,timmy=0;
	float x=0;
	int nb_photo=0.75;
	SDL_Event event;
	image back_maze[11],joueur,maze;
	SDL_Rect points[85];
	initialiser_backmaze(back_maze);
	init_maze(&joueur,&maze);
	init_mazepoints(points);
	//SDL_EnableKeyRepeat(100,10);
	while (boocle==1)
		{
		if(timmy==84)
		return 0;	
		x=x+0.25;
		if(x==1){nb_photo++;x--;}
		afficher_maze(screen,back_maze,nb_photo);
		//afficher_imge(screen,back_maze);
	  	afficher_imge(screen,maze);
		afficher_joueur(screen,joueur,points,timmy);
		
		if(nb_photo==10) nb_photo=0;
		
		while(SDL_PollEvent(&event))
		{
		switch(event.type)
		{
			case SDL_QUIT:
				boocle=0;
				break;
		


		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
                case SDLK_LEFT:
                       
                    move(&timmy,1);
		
                break;
                case SDLK_RIGHT:
                 
                     move(&timmy,2); 
			//printf("%d\t",timmy);
                break;
                case SDLK_UP:
                  move(&timmy,3); 
                break;  
                case SDLK_DOWN:
           move(&timmy,4); 
                break; 

           	 }break;


		
		}}//while and switch
	SDL_Flip(screen);
	

	



	}

	SDL_FreeSurface(screen);
	SDL_FreeSurface(maze.img);
	for(int i=1;i<11;i++)
{
	SDL_FreeSurface(back_maze[i].img);
}
	SDL_FreeSurface(joueur.img);

}

