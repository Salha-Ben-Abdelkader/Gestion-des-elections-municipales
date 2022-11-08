prog:observateurs.o main.o
	gcc observateurs.o main.o -o prog -g
main.o:main.c
	gcc -c main.c -g
fonctions.o:observateurs.c
	gcc -c observateurs.c-g
