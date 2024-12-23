#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"menu.h"
#include"fonctions.h"
#include"background.h"
#include"stage1.h"
#include"minimap.h"
#include"game3.h"
#include "game2.h"
#include "xo.h"
#include "quit.h"
#include "setting.h"
#include "topscore.h"
#include "login.h"
#include"selectniv.h"
void afficher_eye(SDL_Surface *screen,boutton eye,int i)
{
SDL_BlitSurface(eye.img[i],NULL,screen,&eye.pos);
}
void initialiser_back_login(backs *back_login)
{
	back_login->img=IMG_Load("image/login/back.png");
	if(back_login->img==NULL) printf("%s",SDL_GetError());
	back_login->pos.x=0;
	back_login->pos.y=0;
}
void initialiser_bt_done_log(boutton *done_log)
{
	done_log->img[0]=IMG_Load("image/login/DONE_.png");
	done_log->img[1]=IMG_Load("image/login/DONE selectionnee.png");
	done_log->pos.x=537;
	done_log->pos.y=849;
	done_log->pos.w=316;
	done_log->pos.h=102;
	done_log->p=0;
}
void initialiser_zone_usr(boutton *zone_usr)
{
	zone_usr->img[0]=IMG_Load("image/login/rectangle selectionnee.png");
	zone_usr->img[1]=IMG_Load("image/login/rectangle_.png");
	zone_usr->pos.x=593;
	zone_usr->pos.y=464;
	zone_usr->pos.w=478;
	zone_usr->pos.h=82;
	zone_usr->p=0;
}
void initialiser_zone_psw(boutton *zone_psw)
{
	zone_psw->img[0]=IMG_Load("image/login/rectangle_.png");
	zone_psw->img[1]=IMG_Load("image/login/rectangle selectionnee.png");
	zone_psw->pos.x=593;
	zone_psw->pos.y=593;
	zone_psw->pos.w=478;
	zone_psw->pos.h=82;
	zone_psw->p=0;
}
void initialiser_btn_sign(boutton *sign)
{
	sign->img[0]=IMG_Load("image/login/Sign Up.png");
	sign->img[1]=IMG_Load("image/login/Sign Up selectionnee.png");
	sign->pos.x=620;
	sign->pos.y=723;
	sign->pos.w=138;
	sign->pos.h=34;
	sign->p=0;
}
void initialiser_loki(background *loki)
{
	char nom[100],num[3];
	for(int i=0;i<5;i++)
	{
		strcpy(nom,"image/login/animation/l");
		sprintf(num,"%d",i+1);
		strcat(nom,num);
		strcat(nom,".png");
		printf("%s\n",nom);
		loki->img[i]=IMG_Load(nom);
	}
	loki->pos1.x=625;
	loki->pos1.y=85;
	loki->pos2.x=0;
	loki->pos2.y=0;
	loki->pos2.h=1000;
	loki->pos2.w=1400;
	loki->photo=0;
	loki->nbr=5;
}
void initialiser_lokiclose(backs *lokiclose)
{
	lokiclose->img=IMG_Load("image/login/animation/l6.png");
	if(lokiclose->img==NULL) printf("%s",SDL_GetError());
	lokiclose->pos.x=625;
	lokiclose->pos.y=85;
}
void initialiser_eye(boutton *eye)
{
	eye->img[0]=IMG_Load("image/login/eye off.png");
	eye->img[1]=IMG_Load("image/login/eye on.png");
	eye->pos.x=1009;
	eye->pos.y=623;
	eye->pos.w=51;
	eye->pos.h=37;
	eye->p=0;
}
void initialiser_txt(text txt[])
{
	for(int i=0;i<2;i++)
	{
		txt[i].color.r = 0;
		txt[i].color.g = 0;
		txt[i].color.b = 0;
		txt[i].police = TTF_OpenFont("police/Ubuntu-Bold.ttf", 30);
	}
	txt[0].pos.x=603;
	txt[0].pos.y=484;
	txt[1].pos.x=603;
	txt[1].pos.y=613;
}
void afficher_txt(SDL_Surface *screen,text txt,char log[])
{
	txt.txt= TTF_RenderText_Blended(txt.police, log, txt.color);
        SDL_BlitSurface(txt.txt, NULL, screen, &txt.pos);
}
player verifier_log(char mdp[],char log[],int *boocle)
{
	FILE *f;
	int test=2;
	player p;
	f=fopen("player.txt","r");
	if(f!=NULL)
	{
		while (test==2 && fscanf(f,"%s\t\t%s\t\t%d\t\t%d\t\t%d\n",p.player_name,p.mdp,&p.top_score,&p.nbr_stage,&p.nbr_perso)!=EOF )
		{
			if(strcmp(p.player_name,log)==0 && strcmp(p.mdp,mdp)==0)
				test=1;
		}
	}
	fclose(f);
	*boocle=test;
	return p;
}
void initialiser_wrong(backs *wrong)
{
	wrong->img=IMG_Load("image/login/wrong.png");
	if(wrong->img==NULL) printf("%s",SDL_GetError());
	wrong->pos.x=357;
	wrong->pos.y=417;
}
player go_login(SDL_Surface *screen,int *boocle,int etat)
{
	player p;
	int blogin=1,llog=0,lmdp=0,select=1,test=3,test1=0,ey=0;
	backs back_login,lokiclose,wrong;
	background loki;
	boutton done_log,zone_usr,zone_psw,sign,eye;
	text txt[2];
	char mdp[20],log[20],secret[20];
	mdp[0]='\0';
	log[0]='\0';
	secret[0]='\0';
	TTF_Init();
	initialiser_wrong(&wrong);
	initialiser_loki(&loki);
	initialiser_lokiclose(&lokiclose);
	initialiser_back_login(&back_login);
	initialiser_txt(txt);
	initialiser_btn_sign(&sign);
	initialiser_zone_usr(&zone_usr);
	initialiser_zone_psw(&zone_psw);
	initialiser_bt_done_log(&done_log);
	initialiser_eye(&eye);
	SDL_Event event;
	
	while (blogin==1)
	{
		
		afficher(screen,back_login);
		if (etat==1)
		{
			afficher(screen,wrong);
		}
		if(select==1)
		afficher_back(screen,loki);
		else 
		if(select==2 && test==0)
			{afficher_LOKIhide(screen,loki);}
		else afficher(screen,lokiclose);
		afficher_btn(screen,done_log);
		afficher_btn(screen,zone_usr);
		afficher_btn(screen,zone_psw);
		afficher_btn(screen,sign);
		if(test!=3)
		{afficher_txt(screen,txt[1],mdp);
		afficher_txt(screen,txt[0],log);
		afficher_eye(screen,eye,1);}
		else
		{
		afficher_txt(screen,txt[1],secret);
		afficher_txt(screen,txt[0],log);
		afficher_eye(screen,eye,0);
		}
		
	while (SDL_PollEvent(&event))
	{
		
		switch(event.type)
		{
		case SDL_QUIT:
			    
			blogin=0;
			*boocle=0;
		        break;
		case SDL_MOUSEMOTION:
				if((event.motion.x>=done_log.pos.x && event.motion.x<=done_log.pos.x+done_log.pos.w) && 
				   (event.motion.y>=done_log.pos.y && event.motion.y<=done_log.pos.y+done_log.pos.h))
					{
					animer_btns_quit(&done_log.p,&sign.p,1,0);	
					}
				else if ((event.motion.x>=sign.pos.x && event.motion.x<=sign.pos.x+sign.pos.w) && 
				   (event.motion.y>=sign.pos.y && event.motion.y<=sign.pos.y+sign.pos.h))
					{
					animer_btns_quit(&done_log.p,&sign.p,0,1);
					}
				else animer_btns_quit(&done_log.p,&sign.p,0,0);
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
					animerBack(&loki);
				}
				else if(select==2)
				{
					mdp[lmdp]=event.key.keysym.sym;
					secret[lmdp]='*';
					lmdp++;
					mdp[lmdp]='\0';
					secret[lmdp]='\0';
					afficher(screen,lokiclose);
				}
				}
				else if(event.key.keysym.sym==SDLK_BACKSPACE)
				{
					if(select==1){
					if(llog>0)
					{
						llog--;
						log[llog]='\0';
						animerBack(&loki);
					}}
					else if(select==2)
					{
						lmdp--;
						mdp[lmdp]='\0';
						secret[lmdp]='\0';
						//afficher_LOKIhide(screen,loki);
					}
					afficher(screen,back_login);
					//afficher_back(screen,loki);
					afficher_btn(screen,done_log);
					afficher_btn(screen,zone_usr);
					afficher_btn(screen,zone_psw);
					afficher_btn(screen,sign);
					afficher_txt(screen,txt[0],log);
					if(test!=3)
					afficher_txt(screen,txt[1],mdp);
					else
					afficher_txt(screen,txt[1],secret);
					}
				else if(event.key.keysym.sym==SDLK_RETURN)
				{
					p=verifier_log(mdp,log,boocle);
					blogin=0;
				}
				else if(event.key.keysym.sym==SDLK_TAB)
					if(select==1)
					{
						animer_btns_quit(&zone_usr.p,&zone_psw.p,1,1);
						select=2;
					}
					else if(select==2)
					{
						animer_btns_quit(&zone_usr.p,&zone_psw.p,0,0);
						select=1;
					}
				break;
			case SDL_MOUSEBUTTONUP:
				if(event.motion.x>=593 && event.motion.x<=1071)
				{
				if(event.motion.y>=464 && event.motion.y<=546)
				{
					animer_btns_quit(&zone_usr.p,&zone_psw.p,0,0);
					select=1;
				}
				else if(event.motion.y>=593
					&& event.motion.y<=675)
				{
					animer_btns_quit(&zone_usr.p,&zone_psw.p,1,1);
					select=2;
				}
				}
				//hide password
				if((event.motion.x>=eye.pos.x && event.motion.x<=eye.pos.x+eye.pos.w) && 
					(event.motion.y>=eye.pos.y&& event.motion.y<=eye.pos.y+eye.pos.h))
				{
				
				if(test!=3)test=3;
				else test=0;
				animer_btn_set_op(&eye.p,1); 
				}
				if((event.motion.x>=done_log.pos.x && event.motion.x<=done_log.pos.x+done_log.pos.w) && 
				   (event.motion.y>=done_log.pos.y && event.motion.y<=done_log.pos.y+done_log.pos.h))
				{
					p=verifier_log(mdp,log,boocle);
					blogin=0;
				}
				if((event.motion.x>=sign.pos.x && event.motion.x<=sign.pos.x+sign.pos.w) && 
				   (event.motion.y>=sign.pos.y && event.motion.y<=sign.pos.y+sign.pos.h))
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
	SDL_FreeSurface(back_login.img);
	return p;
}
void initialiser_backsigneup(backs *back_signeup)
{
	back_signeup->img=IMG_Load("image/signe up/backsn.png");
	if(back_signeup->img==NULL) printf("%s",SDL_GetError());
	back_signeup->pos.x=0;
	back_signeup->pos.y=0;
}
void go_signup(SDL_Surface *screen,int *boocle)
{
	int bsignup=1,llog=0,lmdp=0,select=1,test=3,test1=0;
	backs back_signeup,lokiclose;
	background loki;
	boutton done_log,zone_usr,zone_psw,sign;
	text txt[2];
	char mdp[20],log[20],secret[20];
	mdp[0]='\0';
	log[0]='\0';
	secret[0]='\0';
	TTF_Init();
	initialiser_loki(&loki);
	initialiser_lokiclose(&lokiclose);
	initialiser_backsigneup(&back_signeup);
	initialiser_txt(txt);
	initialiser_btn_sign(&sign);
	initialiser_zone_usr(&zone_usr);
	initialiser_zone_psw(&zone_psw);
	initialiser_bt_done_log(&done_log);
	SDL_Event event;
	
	while (bsignup==1)
	{
		
		afficher(screen,back_signeup);
		if(select==1)
		afficher_back(screen,loki);
		else 
		if(select==2 && test==0)
			{afficher_LOKIhide(screen,loki);}
		else afficher(screen,lokiclose);
		afficher_btn(screen,done_log);
		afficher_btn(screen,zone_usr);
		afficher_btn(screen,zone_psw);
		//afficher_btn(screen,sign);
		if(test!=3)
		afficher_txt(screen,txt[1],mdp);
		else
		afficher_txt(screen,txt[1],secret);
		afficher_txt(screen,txt[0],log);
		
	while (SDL_PollEvent(&event))
	{
		
		switch(event.type)
		{
		case SDL_QUIT:
			    
			bsignup=0;
			*boocle=0;
		        break;
		case SDL_MOUSEMOTION:
				if((event.motion.x>=done_log.pos.x && event.motion.x<=done_log.pos.x+done_log.pos.w) && 
				   (event.motion.y>=done_log.pos.y && event.motion.y<=done_log.pos.y+done_log.pos.h))
					{
					animer_btn_set_op(&done_log.p,1);	
					}
				else animer_btn_set_op(&done_log.p,0);
				
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
					animerBack(&loki);
				}
				else if(select==2)
				{
					mdp[lmdp]=event.key.keysym.sym;
					secret[lmdp]='*';
					lmdp++;
					mdp[lmdp]='\0';
					secret[lmdp]='\0';
					afficher(screen,lokiclose);
				}
				}
				else if(event.key.keysym.sym==SDLK_BACKSPACE)
				{
					if(select==1)
					{
						if(llog>0)
						{
							llog--;
							log[llog]='\0';
							animerBack(&loki);
						}
					}
					else if(select==2)
					{
						lmdp--;
						mdp[lmdp]='\0';
						secret[lmdp]='\0';
						//afficher_LOKIhide(screen,loki);
					}
					afficher(screen,back_signeup);
					//afficher_back(screen,loki);
					afficher_btn(screen,done_log);
					afficher_btn(screen,zone_usr);
					afficher_btn(screen,zone_psw);
					//afficher_btn(screen,sign);
					afficher_txt(screen,txt[0],log);
					if(test!=3)
					afficher_txt(screen,txt[1],mdp);
					else
					afficher_txt(screen,txt[1],secret);
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
						secret[0]='\0';
						log[0]='\0';
						select=1;
						llog=0;
						lmdp=0;
						afficher(screen,back_signeup);
					}
				}
				else if(event.key.keysym.sym==SDLK_TAB)
					if(select==1)
					{
						animer_btns_quit(&zone_usr.p,&zone_psw.p,1,1);
						select=2;
					}
					else if(select==2)
					{
						animer_btns_quit(&zone_usr.p,&zone_psw.p,0,0);
						select=1;
					}
				break;
			case SDL_MOUSEBUTTONUP:
				if(event.motion.x>=593 && event.motion.x<=1071)
				{
				if(event.motion.y>=464 && event.motion.y<=546)
				{
					animer_btns_quit(&zone_usr.p,&zone_psw.p,0,0);
					select=1;
				}
				else if(event.motion.y>=593
					&& event.motion.y<=675)
				{
					animer_btns_quit(&zone_usr.p,&zone_psw.p,1,1);
					select=2;
				}
				}
				//hide password
				if((event.motion.x>=0 && event.motion.x<=50) && (event.motion.y>=0&& event.motion.y<=50))
				{if(test!=3)test=3;
				else test=0; 
				}
				if((event.motion.x>=done_log.pos.x && event.motion.x<=done_log.pos.x+done_log.pos.w) && 
				   (event.motion.y>=done_log.pos.y && event.motion.y<=done_log.pos.y+done_log.pos.h))
				{
					if(verifier_signup(mdp,log)==1)
					{
						signe_up(mdp,log);
						bsignup=0;
					}
					else
					{
						mdp[0]='\0';
						secret[0]='\0';
						log[0]='\0';
						select=1;
						llog=0;
						lmdp=0;
						afficher(screen,back_signeup);
					}
				}
				
				break;
		}
		}
	SDL_Flip(screen);
	}
	
}
int verifier_signup(char mdp[],char log[])
{
	int test=1;
	if (strlen(mdp)<2) test=0;
	player p;
	FILE *f;
	f=fopen("player.txt","r");
	if(f!=NULL)
	{
		while (fscanf(f,"%s\t%s\t%d\n",p.player_name,p.mdp,&p.top_score)!=EOF && test==1)
		{
		if(strcmp(p.player_name,log)==0)
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
		fprintf(f,"%s\t\t%s\t\t%d\t\t%d\t\t%d\n",log,mdp,0,1,1);
	}
	fclose(f);
}
void afficher_LOKIhide(SDL_Surface *screen,background loki)
{
	SDL_BlitSurface(loki.img[0],&loki.pos2,screen,&loki.pos1);
}
void save_informationsPlayer(player p1)
{
	player p2;
	FILE *f1,*f2;
	f1=fopen("player.txt","r");
	f2=fopen("player_nouv.txt","w");
	if(f1!=NULL && f2!=NULL)
	{
		while(fscanf(f1,"%s\t\t%s\t\t%d\t\t%d\t\t%d\n",p2.player_name,p2.mdp,&p2.top_score,&p2.nbr_stage,&p2.nbr_perso)!=EOF)
		{
			if(strcmp(p1.player_name,p2.player_name)==0)
			{
				fprintf(f2,"%s\t\t%s\t\t%d\t\t%d\t\t%d\n",p1.player_name,p1.mdp,p1.top_score,p1.nbr_stage,p1.nbr_perso);
			}
			else
			{
				fprintf(f2,"%s\t\t%s\t\t%d\t\t%d\t\t%d\n",p2.player_name,p2.mdp,p2.top_score,p2.nbr_stage,p2.nbr_perso);
			}
		}
		remove("player.txt");
		rename("player_nouv.txt","player.txt");
	}
	else
	{
		printf("probleme d'ouverture");
	}
	fclose(f2);
	fclose(f1);
	
}

/*void initialiser_btnYES(boutton *yes)
{
	yes->img[0]=IMG_Load("image/exit/yes1.png");
	yes->img[1]=IMG_Load("image/exit/yes2.png");
	yes->pos.x=414;
	yes->pos.y=602;
	yes->pos.h=83;
	yes->pos.w=255;
	yes->p=0;
}
void initialiser_btnNO(boutton *no)
{
	no->img[0]=IMG_Load("image/exit/no1.png");
	no->img[1]=IMG_Load("image/exit/no2.png");
	no->pos.x=780;
	no->pos.y=602;
	no->pos.h=83;
	no->pos.w=255;
	no->p=0;
}
void initialiser_back_exit(background *b)
{
	char nom[50],num[4];
	(*b).nbr=1;
	(*b).img[0]=IMG_Load("image/exit/exiit.png");
	(*b).pos1.x=345;
	(*b).pos1.y=238;
	(*b).pos1.h=582;
	(*b).pos1.w=757;


	(*b).pos2.x=0;
	(*b).pos2.y=0;
	(*b).pos2.h=582;
	(*b).pos2.w=757;
	(*b).photo=0;
}



/*void go_exit(background b,perso p,SDL_Surface *screen,player p1,int nb_stage)
{
	int bexit=1,select=1,selct_input;
	SDL_Event event;
	background back_exit;
	boutton yes,no;
	char nom_fiche[50],num[2];
	strcpy(nom_fiche,"stage");
	sprintf(num,"%d",nb_stage);
	strcat(nom_fiche,num);
	strcat(nom_fiche,".txt");
	initialiser_btnNO(&no);
	initialiser_btnYES(&yes);
	initialiser_back_exit(&back_exit);
	while (bexit==1)
	{
		
		afficher_back(screen,back_exit);
		afficher_btn(screen,yes);
		afficher_btn(screen,no);
		while(SDL_PollEvent(&event))
		{
		switch(event.type)
		{
			
			case SDL_QUIT:
				
				bexit=0;
				break;
			case SDL_MOUSEMOTION:
				if((event.motion.x>=no.pos.x && event.motion.x<=no.pos.x+no.pos.w) && 
				   (event.motion.y>=no.pos.y && event.motion.y<=no.pos.y+no.pos.h))
				{
					no.p=1;
				}
				else if((event.motion.x>=yes.pos.x && event.motion.x<=yes.pos.x+yes.pos.w) && 
				   (event.motion.y>=yes.pos.y && event.motion.y<=yes.pos.y+yes.pos.h))
				{
					yes.p=1;
				}
				else
				{
					yes.p=0;
					no.p=0;
				}
			case SDL_MOUSEBUTTONUP:
				if((event.motion.x>=yes.pos.x && event.motion.x<=yes.pos.x+yes.pos.w) && 
				   (event.motion.y>=yes.pos.y && event.motion.y<=yes.pos.y+yes.pos.h))
				{
					sauvegarder(p,b,nom_fiche,p1);
					bexit=0;
				}
				else if((event.motion.x>=no.pos.x && event.motion.x<=no.pos.x+no.pos.w) && 
				   (event.motion.y>=no.pos.y && event.motion.y<=no.pos.y+no.pos.h))
				{
					bexit=0;
				}
		}
		}
	SDL_Flip(screen);
	}
}*/















































