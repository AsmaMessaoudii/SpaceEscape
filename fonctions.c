#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"fonctions.h"
void initialiser_back(image *back)
{
	(*back).img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/menu/back.png");
	(*back).pos.x=0;
	(*back).pos.y=0;
}
void initialiser_play(image play[])
{
	play[0].img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/menu/play1.png");
	play[1].img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/menu/play2.png");
	for(int i=0;i<2;i++)
	{
		play[i].pos.x=34;
		play[i].pos.y=159;
	}
}
void initialiser_exit(image exit[])
{
	exit[0].img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/menu/exit1.png");
	exit[1].img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/menu/exit2.png");
	for(int i=0;i<2;i++)
	{
		exit[i].pos.x=34;
		exit[i].pos.y=390;
	}
}
void initialiser_setting(image setting[])
{
	setting[0].img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/menu/setting1.png");
	setting[1].img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/menu/setting2.png");
	for(int i=0;i<2;i++)
	{
		setting[i].pos.x=34;
		setting[i].pos.y=234;
	}
}
void initialiser_tops(image tops[])
{
	tops[0].img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/menu/tops1.png");
	tops[1].img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/menu/tops2.png");
	for(int i=0;i<2;i++)
	{
		tops[i].pos.x=34;
		tops[i].pos.y=313;
	}
}
void initialiser_sp(image sp[])
{
	char nom[70],num[3];
	for(int i=1;i<11;i++)
	{
		strcpy(nom,"/home/aziz/Documents/menu_mansa(1)/menu/image/sp/s");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		sp[i].img=IMG_Load(nom);
		sp[i].pos.x=30;
		sp[i].pos.y=30;
	}	
}
void afficher(SDL_Surface *screen,image imge)
{
	SDL_BlitSurface(imge.img,NULL,screen,&imge.pos);
}
void afficher_btns(int *p,int *e,int *t,int *s,int px,int ex,int tx,int sx)
{
	*p=px;
	*e=ex;
	*t=tx;
	*s=sx;
}
void initialiser_backseting(image *back_setting)
{
	(*back_setting).img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/setting/back_setting.png");
	if((*back_setting).img==NULL) printf("%s",SDL_GetError());
	(*back_setting).pos.x=0;
	(*back_setting).pos.y=0;
}
void initialiser_backtopscore(image *back_tops)
{
	(*back_tops).img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/setting/TOP SCORE.png");
	if((*back_tops).img==NULL) printf("%s",SDL_GetError());
	(*back_tops).pos.x=0;
	(*back_tops).pos.y=0;
}
void initialiser_retour(image retour[])
{
	retour[0].img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/setting/retour1.png");
	retour[1].img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/setting/retour2.png");
	for(int i=0;i<2;i++)
	{
		retour[i].pos.x=445;
		retour[i].pos.y=30;
	}
}
void initialiser_barre(image barre[])
{
	char nom[70],num[3];
	for(int i=0;i<13;i++)
	{
		strcpy(nom,"/home/aziz/Documents/menu_mansa(1)/menu/image/setting/barre/");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		barre[i].img=IMG_Load(nom);
		barre[i].pos.x=212;
		barre[i].pos.y=223;
	}
}
void go_setting(SDL_Surface *screen,int *boocle,int *volum)
{
	int bsetting=1,full=128;
   	image back_setting,retour[2],barre[13],on_of[2];
    	SDL_Event event;
    	initialiser_backseting(&back_setting);
	initialiser_retour(retour);
	initialiser_on_of(on_of);
	afficher(screen,back_setting);
	afficher(screen,retour[0]);
	afficher(screen,on_of[1]);
	initialiser_barre(barre);
	afficher(screen,barre[(*volum)]);
	while (bsetting==1)
	{
	while (SDL_PollEvent(&event))
	{
		    
		switch(event.type)
		{
		case SDL_QUIT:
			    
			bsetting=0;
			*boocle=0;
		        break;
		case SDL_MOUSEMOTION:
			if((event.motion.x>=445 && event.motion.x<=485) && 
			   (event.motion.y>=30 && event.motion.y<=70))
			{
				afficher(screen,retour[1]);
			}
			else
			{
				afficher(screen,retour[0]);
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if((event.motion.x>=445 && event.motion.x<=485) && 
			   (event.motion.y>=30 && event.motion.y<=70))
				bsetting=0;
			else if((event.motion.x>=315 && event.motion.x<=364) && 
			   (event.motion.y>=190 && event.motion.y<=217))
			{
				if(*volum!=0)
				{
					*volum=0;
					afficher(screen,on_of[0]);
					afficher(screen,barre[(*volum)]);
					Mix_VolumeMusic((full*(*volum)*12)/100);
				}
				else
				{
					*volum=1;
					afficher(screen,on_of[1]);
					afficher(screen,barre[(*volum)]);
					Mix_VolumeMusic((full*(*volum)*12)/100);
				}
			}
			break;
		case SDL_KEYDOWN:
			if(event.key.keysym.sym==SDLK_ESCAPE)
				SDL_WM_ToggleFullScreen(screen);
			else if(event.key.keysym.sym==SDLK_r) bsetting=0;
			else if (event.key.keysym.sym==SDLK_MINUS &&(*volum)>=1)
			{
				(*volum)--;
				Mix_VolumeMusic((full*(*volum)*12)/100);
				afficher(screen,barre[(*volum)]);
				if ((*volum)==0) afficher(screen,on_of[0]);
			}
			else if(event.key.keysym.sym==SDLK_a && (*volum)<12)
			{
				(*volum)++;
				Mix_VolumeMusic((full*(*volum)*12)/100);
				afficher(screen,barre[(*volum)]);
				if(*volum==1) afficher(screen,on_of[1]);
			}
			
		}
	}
		SDL_Flip(screen);
	}
	SDL_FreeSurface(back_setting.img);
	SDL_FreeSurface(retour[0].img);
	SDL_FreeSurface(retour[1].img);
}
void initialiser_back_login(image back_login[])
{
	char nom[70],num[3];
	for(int i=1;i<95;i++)
	{
		strcpy(nom,"/home/aziz/Documents/menu_mansa(1)/menu/image/login/animation/");
		sprintf(num,"%d",i);
		strcat(nom,num);
		strcat(nom,".png");
		back_login[i].img=IMG_Load(nom);
		if(back_login==NULL) printf("%s",SDL_GetError());
		back_login[i].pos.x=0;
		back_login[i].pos.y=0;
	}
}
void initialiser_txt(text txt[])
{
	for(int i=0;i<2;i++)
	{
		txt[i].color.r = 225;
		txt[i].color.g = 225;
		txt[i].color.b = 225;
		txt[i].police = TTF_OpenFont("/home/aziz/Documents/menu_mansa(1)/menu/police/Ubuntu-Bold.ttf", 15);
	}
	txt[0].pos.x=225;
	txt[0].pos.y=190;
	txt[1].pos.x=225;
	txt[1].pos.y=250;
}
void afficher_txt(SDL_Surface *screen,text txt,char log[])
{
	txt.txt= TTF_RenderText_Blended(txt.police, log, txt.color);
        SDL_BlitSurface(txt.txt, NULL, screen, &txt.pos);
}
int verifier_log(char mdp[],char log[])
{
	FILE *f;
	int test=0;
	player p;
	f=fopen("player.txt","r");
	if(f!=NULL)
	{
		while (fscanf(f,"%s\t%s\t%d\n",p.log,p.mdp,&p.score)!=EOF && test==0){
		if(strcmp(p.log,log)==0 && strcmp(p.mdp,mdp)==0)
			test=1;}
	}
	fclose(f);
	return test;
}
void go_login(SDL_Surface *screen,int *boocle)
{
	int blogin=1,llog=0,lmdp=0,select=1;
	image back_login[95];
	text txt[2];
	char mdp[20],log[20];
	mdp[0]='\0';
	log[0]='\0';
	TTF_Init();
	initialiser_back_login(back_login);
	initialiser_txt(txt);
	SDL_Event event;
	for(int i=1;i<95;i++)
	{
		afficher(screen,back_login[i]);
		SDL_Flip(screen);
		SDL_Delay(25);
	}
	while (blogin==1)
	{
	while (SDL_PollEvent(&event))
	{
		afficher(screen,back_login[94]);
		afficher_txt(screen,txt[1],mdp);
		afficher_txt(screen,txt[0],log);
		switch(event.type)
		{
		case SDL_QUIT:
			    
			blogin=0;
			*boocle=0;
		        break;
		case SDL_KEYDOWN:
				if(event.key.keysym.sym==SDLK_ESCAPE)
				SDL_WM_ToggleFullScreen(screen);
				
				else if((event.key.keysym.sym >= SDLK_a 
					&& event.key.keysym.sym <= SDLK_z)
					||((event.key.keysym.sym >= SDLK_1 
					&&event.key.keysym.sym <= SDLK_9)))
				{
				if(select==1)
				{
				    log[llog]=event.key.keysym.sym;
				    llog++;
				    log[llog]='\0';
				}
				else if(select==2)
				{
					mdp[lmdp]=event.key.keysym.sym;
					lmdp++;
					mdp[lmdp]='\0';
				}
				}
				else if(event.key.keysym.sym==SDLK_BACKSPACE)
				{
					if(select==1){
					if(llog>0)
					{
						llog--;
						log[llog]='\0';
					}}
					else if(select==2)
					{
						lmdp--;
						mdp[lmdp]='\0';
						
						
					}
					afficher(screen,back_login[94]);
					afficher_txt(screen,txt[0],log);
					afficher_txt(screen,txt[1],mdp);
				}
				else if(event.key.keysym.sym==SDLK_RETURN)
				{
					*boocle=verifier_log(mdp,log);
					blogin=0;
				}
				else if(event.key.keysym.sym==SDLK_TAB)
					select=2;
				break;
			case SDL_MOUSEBUTTONUP:
				if(event.motion.x>=218 && event.motion.x<=375)
				{
				if(event.motion.y>=183 && event.motion.y<=216)
				{
					select=1;
				}
				else if(event.motion.y>=254
					&& event.motion.y<=287)
				{
					select=2;
				}
				}
				if((event.motion.x>=161 
					&& event.motion.x<=405)
					&& (event.motion.y>=388
					&& event.motion.y<=424))
				{
					*boocle=verifier_log(mdp,log);
					blogin=0;
				}
				if((event.motion.x>=272 
					&& event.motion.x<=371)
					&& (event.motion.y>=316
					&& event.motion.y<=328))
				{
					go_signup(screen,&(*boocle));
					printf("%d",(*boocle));
					if(*boocle==0) blogin=0;
				}
				break;
		}
	
	}
	SDL_Flip(screen);
	}
	for(int i=1;i<95;i++)
	{
		SDL_FreeSurface(back_login[i].img);
	}
}
void initialiser_backsigneup(image *back_signeup)
{
	(*back_signeup).img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/signe up/sign up.png");
	(*back_signeup).pos.x=0;
	(*back_signeup).pos.y=0;
}
void initialiser_on_of(image on_of[])
{
	on_of[0].img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/setting/off.png");
	on_of[1].img=IMG_Load("/home/aziz/Documents/menu_mansa(1)/menu/image/setting/on.png");
	for(int i=0;i<2;i++)
	{
		on_of[i].pos.x=315;
		on_of[i].pos.y=190;
	}
}
void go_signup(SDL_Surface *screen,int *boocle)
{
	int bsignup=1,llog=0,lmdp=0,select=1;
	SDL_Event event;
	text txt[2];
	image back_signeup;
	char mdp[20],log[20];
	mdp[0]='\0';
	log[0]='\0';
	TTF_Init();
	initialiser_txt(txt);
	initialiser_backsigneup(&back_signeup);
	afficher(screen,back_signeup);
	while(bsignup==1)
	{
		while (SDL_PollEvent(&event))
		{   
		switch(event.type)
		{
		case SDL_QUIT:
			    
			bsignup=0;
			*boocle=0;
		        break;
		case SDL_KEYDOWN:
				if(event.key.keysym.sym==SDLK_ESCAPE)
				SDL_WM_ToggleFullScreen(screen);
				
				else if((event.key.keysym.sym >= SDLK_a 
					&& event.key.keysym.sym <= SDLK_z)
					||((event.key.keysym.sym >= SDLK_1 
					&&event.key.keysym.sym <= SDLK_9)))
				{
				if(select==1)
				{
				    log[llog]=event.key.keysym.sym;
				    llog++;
				    log[llog]='\0';
				    afficher_txt(screen,txt[0],log);
				}
				else if(select==2)
				{
					mdp[lmdp]=event.key.keysym.sym;
					lmdp++;
					mdp[lmdp]='\0';
					afficher_txt(screen,txt[1],mdp);
				}
				}
				else if(event.key.keysym.sym==SDLK_BACKSPACE)
				{
					if(select==1){
					if(llog>0)
					{
						llog--;
						log[llog]='\0';
					}
				}
					else if(select==2)
					{
						lmdp--;
						mdp[lmdp]='\0';
					}
					afficher(screen,back_signeup);
					afficher_txt(screen,txt[0],log);
					afficher_txt(screen,txt[1],mdp);
				}
				else if(event.key.keysym.sym==SDLK_RETURN)
				{
					if(verifier_signup(mdp,log)==1)
					{
						signe_up(mdp,log);
						bsignup=0;
					}
					else
					{
						mdp[0]='\0';
						log[0]='\0';
						select=1;
						llog=0;
						lmdp=0;
						afficher(screen,back_signeup);
					}
				}
				else if(event.key.keysym.sym==SDLK_TAB)
					select=2;
				break;
		}
		}
	SDL_Flip(screen);
	}
	
}
int verifier_signup(char mdp[],char log[])
{
	int test=1;
	if (strlen(mdp)<8) test=0;
	player p;
	FILE *f;
	f=fopen("player.txt","r");
	if(f!=NULL)
	{
		while (fscanf(f,"%s\t%s\t%d\n",p.log,p.mdp,&p.score)!=EOF && 									test==1)
		{
		if(strcmp(p.log,log)==0)
			test=0;
		}
	}
	printf("%d",test);
	fclose(f);
	return test;
}
void signe_up(char mdp[],char log[])
{
	FILE *f;
	f=fopen("player.txt","a");
	if(f!=NULL)
	{
		fprintf(f,"%s\t%s\t%d\n",log,mdp,0);
	}
	fclose(f);
}
