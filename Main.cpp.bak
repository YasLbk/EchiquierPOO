/**
 * @author Yassine Lambarki El Allioui
 * @version 1.0
 * @date 25/05/2020
 * @file Main.cpp
 * @title Main
 * @brief
 */

using namespace std;
#include <iostream>
#include <string>

#include "Echiquier.h"
#include "Jeu.h"
#include "Historique.h"


int main() {
  Jeu monjeu;        // initialise le jeu
  string mouvement;  // initialise le mvmnt
  bool stop(false);
  int coup = 0, erreur = 0;  // nombre de coups effectués
  monjeu.affiche();      // affiche le jeu
  historique_file();
  do {
    cout << "Coup (eg. a1a8) ? \n";
    cin >> mouvement;
    if (mouvement != "/quit") {
      if (monjeu.saisie_correcte_proque(mouvement)) {
        erreur = monjeu.deplace("petit", "roque");

      } else if (monjeu.saisie_correcte_groque(mouvement)) {
        erreur = monjeu.deplace("grand", "roque");

      } else if (monjeu.saisie_correcte(
                     mouvement)) {  // découper case origine et destination
                    
        string orig = mouvement.substr(0, 2);
        string dest = mouvement.substr(2, 2);
        erreur = monjeu.deplace(orig, dest);

      } else {
        cerr << "saisie incorrecte" << endl;
        erreur = 1;
        
      }
      if (erreur == 0) {
        add_to_hist(mouvement); 
        coup++;  // incrémente le nombre de coups
        monjeu.affiche();
      }
    } else
      stop = true;
    cout << "Nombre de coups valides joués: " << coup << endl << endl;
  } while (!stop);
  monjeu.efface();
}
