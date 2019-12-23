exe : graphique.o jeu.o serpent.o main.o
	gcc -o exe graphique.o jeu.o serpent.o main.o -lgraph

graphique.o : graphique.c graphique.h jeu.h serpent.h 
	gcc -c  graphique.c graphique.h jeu.h serpent.h 

jeu.o : jeu.c jeu.h 
	gcc -c  jeu.c jeu.h

serpent.o : serpent.c serpent.h jeu.h
	gcc -c serpent.c serpent.h jeu.h

main.o : main.c graphique.h
	gcc -c  main.c graphique.h

clean :
	rm -f  graphique.o jeu.o serpent.o main.o
