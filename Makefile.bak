CC=g++
CFLAGS=--std=c++11 -Wall -g
DFLAGS=DEBUG

target : echecs

echecs : Main.cpp Jeu.o Echiquier.o Piece.o Square.o Historique.o
	$(CC) $(CFLAGS) Main.cpp Jeu.o Echiquier.o Piece.o Square.o Historique.o -o $@

Echiquier.o : Echiquier.h Echiquier.cpp Piece.h 
	$(CC) $(CFLAGS) -c Echiquier.cpp

Piece.o : Piece.h Piece.cpp Historique.h
	$(CC) $(CFLAGS) -c Piece.cpp 

Square.o : Square.h Square.cpp 
	$(CC) $(CFLAGS) -D$(DFLAGS) -c Square.cpp

Jeu.o : Jeu.h Jeu.cpp  Echiquier.h
	$(CC) $(CFLAGS) -c Jeu.cpp

Historique.o : Historique.h Historique.cpp  
	$(CC) $(CFLAGS) -c Historique.cpp

clean:
	rm -rf *.dSYM *.o echec
