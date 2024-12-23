#include"xo.h"

/*void initialiser_backenigme(background *b)
{
	char nom[50],num[4];
	for(int i=0;i<8;i++)
	{
		strcpy(nom,"xo/back xo/");
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
}
void annimer_backenigme(background *b)
{
	(*b).photo++;
	if ((*b).photo==8) (*b).photo=0;
}*/
void quitgame(int * q, xo c) {
  Uint8 * keystate = SDL_GetKeyState(NULL);
  if (keystate[SDLK_ESCAPE])( * q) = 1;
  int count = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (c.i[i][j] != -1) count++;
  if (count == 9)( * q) = 1;
}
void init_xo(xo * c) {

  c -> t[0].img = IMG_Load("image/xo/o.png");
 c -> t[0] .pos1.x=0;
c -> t[0] .pos1.y=0;
  c -> t[1].img = IMG_Load("image/xo/x.png");
 c -> t[1] .pos1.x=0;
c -> t[1] .pos1.y=0;
  c -> bg.img = IMG_Load("image/xo/1.png");
c -> table.pos1.x=0;
c -> table.pos1.y=0;
  c -> table.img = IMG_Load("x o.png");
	c -> table.pos1.x=252;
	c -> table.pos1.y=50;
  if (c -> t[1].img == NULL) printf("aa\n");
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      c -> i[i][j] = -1;
      c -> r[i][j].x = 250*i +402;
      c -> r[i][j].y = 250 * j + 223;
      c -> turn = rand() % 2;
      c -> choixx = 0;
      c -> choixy = 0;
    }
}
void show(xo c, SDL_Surface * screen) {
  SDL_BlitSurface(c.bg.img, NULL, screen,NULL);
//printf("%d\t",c.table.pos.x);
//printf("%d\n",c.table.pos.y);
 // SDL_BlitSurface(c.table.img, NULL, screen,&c.table.pos);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (c.i[i][j] != -1) {
        SDL_BlitSurface(c.t[c.i[i][j]].img, NULL, screen, & c.r[i][j]);
      }
      if ((c.choixx == i) && (c.choixy == j)) {
        SDL_BlitSurface(c.t[c.turn].img, NULL, screen, & c.r[i][j]);
      }
    }
  }
  SDL_Flip(screen);
}

void turn_played(xo * c) {
  c -> turn++;
  if (c -> turn == 2) c -> turn = 0;
}
void change(xo * c) {
  SDL_Delay(100);
  Uint8 * keystate = SDL_GetKeyState(NULL);
  if (keystate[SDLK_RIGHT])
    if (c -> choixx < 2) c -> choixx++;
  if (keystate[SDLK_LEFT])
    if (c -> choixx > 0) c -> choixx--;
  if (keystate[SDLK_DOWN])
    if (c -> choixy < 2) c -> choixy++;
  if (keystate[SDLK_UP])
    if (c -> choixy > 0) c -> choixy--;

  if (keystate[SDLK_RETURN])
    if (c -> i[c -> choixx][c -> choixy] == -1) {
      c -> i[c -> choixx][c -> choixy] = c -> turn;
      turn_played( & ( * c));
    }
}
int winner_is(xo c) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      if ((c.i[j][0] == i) && (c.i[j][1] == i) && (c.i[j][2] == i)) return i;
      if ((c.i[0][j] == i) && (c.i[1][j] == i) && (c.i[2][j] == i)) return i;
    }
    if ((c.i[0][0] == i) && (c.i[1][1] == i) && (c.i[2][2] == i)) return i;
    if ((c.i[0][2] == i) && (c.i[1][1] == i) && (c.i[2][0] == i)) return i;
  }
  return -1;
}
void ia2(xo * c) {
  int count = 0;
  if (c -> turn == 1) {
    SDL_Delay(500);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        count = 0;
        for (int k = 0; k < 3; k++)
          if (c -> i[j][k] == i) count++;
        if (count == 2)
          for (int k = 0; k < 3; k++)
            if (c -> i[j][k] == -1) {
              c -> i[j][k] = 1;
              turn_played( & ( * c));
              return;
            }
        count = 0;
        for (int k = 0; k < 3; k++)
          if (c -> i[k][j] == i) count++;
        if (count == 2)
          for (int k = 0; k < 3; k++)
            if (c -> i[k][j] == -1) {
              c -> i[k][j] = 1;
              turn_played( & ( * c));
              return;
            }
        count = 0;
      }
      for (int k = 0; k < 3; k++)
        if (c -> i[k][k] == i) count++;
      if (count == 2)
        for (int k = 0; k < 3; k++)
          if (c -> i[k][k] == -1) {
            c -> i[k][k] = 1;
            turn_played( & ( * c));
            return;
          }
      count = 0;
      if (c -> i[0][2] == i) count++;
      if (c -> i[1][1] == i) count++;
      if (c -> i[2][0] == i) count++;
      if (count == 2) {
        if (c -> i[0][2] == -1) {
          c -> i[0][2] = 1;
          turn_played( & ( * c));
          return;
        }
        if (c -> i[2][0] == -1) {
          c -> i[2][0] = 1;
          turn_played( & ( * c));
          return;
        }
        if (c -> i[1][1] == -1) {
          c -> i[1][1] = 1;
          turn_played( & ( * c));
          return;
        }
      }
    }
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (c -> i[i][j] == -1) {
          c -> i[i][j] = 1;
          turn_played( & ( * c));
          return;
        }
  }
}

int game(SDL_Surface * screen) {
  int q = 0;
  xo c;
SDL_Event event;
  init_xo( & c);
  screen = SDL_SetVideoMode(1400, 1000, 32, SDL_SWSURFACE);
  while (q == 0) {
    SDL_PumpEvents();
if (event.type==SDL_QUIT)
q=0;
    quitgame( & q, c);
    if (c.turn == 0) change( & c);
    ia2( & c);
    show(c, screen);
    if (winner_is(c) != -1) {
      if (winner_is(c) == 1) SDL_Flip(screen);
      SDL_Delay(1000);
      return winner_is(c);
    }
  }
  SDL_Delay(1000);
  return -1;
}
