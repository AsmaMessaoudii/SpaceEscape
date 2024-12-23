prog:background.o main.o perso.o ES.o enigme.o minimap.o stage1.o menu.o game3.o game2.o xo.o setting.o topscore.o quit.o login.o selectniv.o stage2.o duo_perso.o maze.o serie.o stage4.o
	gcc background.o perso.o ES.o enigme.o minimap.o stage1.o menu.o  game3.o game2.o xo.o setting.o topscore.o quit.o login.o selectniv.o stage2.o duo_perso.o maze.o main.o serie.o stage4.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c
background.o:background.c
	gcc -c background.c
ES.o:ES.c
	gcc -c ES.c
perso.o:perso.c
	gcc -c perso.c
enigme.o:enigme.c
	gcc -c enigme.c
minimap.o:minimap.c 
	gcc -c minimap.c -g
stage1.o:stage1.c 
	gcc -c stage1.c -g
menu.o:menu.c
	gcc -c menu.c
game3.o:game3.c 
	gcc -c game3.c -g
game2.o:game2.c 
	gcc -c game2.c -g
xo.o:xo.c 
	gcc -c xo.c -g
setting.o:setting.c
	gcc -c setting.c -g
topscore.o:topscore.c
	gcc -c topscore.c -g
quit.o:quit.c
	gcc -c quit.c -g
login.o:login.c
	gcc -c login.c -g
selectniv.o:selectniv.c
	gcc -c selectniv.c -g
stage2.o:stage2.c 
	gcc -c stage2.c -g
duo_perso.o:duo_perso.c
	gcc -c duo_perso.c -g
maze.o:maze.c
	gcc -c maze.c -g
serie.o:serie.c
	gcc -c serie.c -g
stage4.o:stage4.c 
	gcc -c stage4.c -g
