/**
  * @author Yassine Lambarki El Allioui
  * @version 1.0
  * @date 25/05/2020
  * @file Jeu.cpp
  * @title Jeu
  * @brief 
  */

#include <string>
#include <iostream>
#include <regex>
#include "Echiquier.h"
#include "Jeu.h"
using namespace std;

// constructeur du Jeu
Jeu::Jeu(){
  cout << "START GAME" << endl;
  cout << "Tour des blancs" << endl;
}
// destructeur du Jeu
Jeu::~Jeu(){
  cout << "" << endl;
}
// affiche le jeu et donc affiche l'échiquier
void Jeu::affiche(){
  cout << "Affichage de l'échiquier:" << endl;
  echiquier.affiche();
}
// effectue le déplacement de la pièce de case origine
// à destination 
int Jeu::deplace(string orig, string dest){
  cout << "Déplacement de la pièce case " << orig << " à " << dest << endl;
  return echiquier.deplace(orig, dest);
}
// efface le jeu/ échiquier
void Jeu::efface(){
  cout << "END GAME" << endl;
  echiquier.effacer_piece();
}




bool Jeu::saisie_correcte(string const & cmd) {
regex mouvmtpattern("[a-h][1-8][a-h][1-8]");
    return regex_match(cmd,mouvmtpattern);

}

bool Jeu::saisie_correcte_proque(string const & cmd) {
regex mouvmtpattern("(O|o|0)-(O|o|0)");
    return regex_match(cmd,mouvmtpattern);
}

bool Jeu::saisie_correcte_groque(string const & cmd) {
regex mouvmtpattern("(O|o|0)-(O|o|0)-(O|o|0)");
    return regex_match(cmd,mouvmtpattern);
}