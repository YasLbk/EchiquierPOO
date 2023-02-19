/**
 * @author Yassine Lambarki El Allioui
 * @version 1.0
 * @date 25/05/2020
 * @file Piece.cpp
 * @title Piece
 * @brief
 */

#include "Piece.h"

#include <iostream>
#include <string>

#include "Historique.h"
#include "Square.h"

using namespace std;
#define NBCOL 8
#define LGN 0
#define COL 1
/*!
 * @brief Contructeur de pièce
 * @param couleur blanc ou noir , couleur de la pièce
 * @param nom nom/type de la pièce
 * @param coord coordonées de la case de la pièce au sein de l'échiquier
 */
Piece::Piece(Couleur couleur, string nom, Square coord)
    : couleur(couleur), nom(nom), coord(coord) {}
/*!
 * @brief Destructeur de pièce
 */
Piece::~Piece() {}
/*!
 * @brief getter de la couleur de la pièce
 */
Couleur Piece::get_couleur() const { return couleur; }
/*!
 * @brief getter de la nom de la pièce
 */
string Piece::get_nom() const { return nom; }
/*!
 * @brief getter des coordonnées de la pièce
 */
Square Piece::get_coord() const { return coord; }

/*!
 * @brief check si les coordonées sont valides ou pas
 */
bool coord_valides(vector<int> org, vector<int> dst) {
  if (org[LGN] < 0 || org[LGN] > 7 || org[COL] < 0 || org[COL] > 7) {
    cerr << "Les coordonnées d'origine ne sont pas valides" << endl;
    return false;
  }
  if (dst[LGN] < 0 || dst[LGN] > 7 || dst[COL] < 0 || dst[COL] > 7) {
    cerr << "Les coordonnées de destination ne sont pas valides" << endl;
    return false;
  }
  return true;
}
// *************************************************************************************

// Classe Tour
Tour::Tour(Couleur couleur, string nom, Square coord)
    : Piece(couleur, nom, coord) {}
Tour::~Tour() {}
void Tour::affiche() const { cout << get_nom(); }

bool Tour::est_mouvement_legal(vector<int> org, vector<int> dst,
                               Piece* echiquier[8][8]) const {
  coord_valides(org, dst);

  for (int i = 1; i < NBCOL; i++) {
    // Tour se déplace verticalement selont une colonne
    if (dst[LGN] == org[LGN] && dst[COL] == org[COL] + i) {
      // Check si le chemin est vide
      for (int j = 1; j < i; j++) {
        if (echiquier[dst[LGN]][org[COL] + j]) {
          return false;
        }
      }
      return true;
    }
    if (dst[LGN] == org[LGN] && dst[COL] == org[COL] - i) {
      for (int j = 1; j < i; j++) {
        if (echiquier[dst[LGN]][org[COL] - j]) {
          return false;
        }
      }
      return true;
    }

    // Tour se déplace horizontalement selont une ligne
    if (dst[LGN] == org[LGN] - i && dst[COL] == org[COL]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN] - j][dst[COL]]) {
          return false;
        }
      }
      return true;
    }

    if (dst[LGN] == org[LGN] + i && dst[COL] == org[COL]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN] + j][dst[COL]]) {
          return false;
        }
      }
      return true;
    }
  }
  return false;
}
// *********************************************************

// Classe Cavalier
Cavalier::Cavalier(Couleur couleur, string nom, Square coord)
    : Piece(couleur, nom, coord) {}
Cavalier::~Cavalier() {}
void Cavalier::affiche() const { cout << get_nom(); }

bool Cavalier::est_mouvement_legal(vector<int> org, vector<int> dst,
                                   Piece* echiquier[8][8]) const {
  coord_valides(org, dst);
  // Saut d'une case horizontalement et de deux verticalement
  // ou
  // Saut de deux cases horizontalement et une verticalement
  if (((dst[COL] == org[COL] + 1 || dst[COL] == org[COL] - 1) &&
       (dst[LGN] == org[LGN] + 2 || dst[LGN] == org[LGN] - 2)) ||
      ((dst[COL] == org[COL] + 2 || dst[COL] == org[COL] - 2) &&
       (dst[LGN] == org[LGN] + 1 || dst[LGN] == org[LGN] - 1))) {
    return true;
  } else {
    return false;
  }
}
// *********************************************************

// Classe Fou
Fou::Fou(Couleur couleur, string nom, Square coord)
    : Piece(couleur, nom, coord) {}
Fou::~Fou() {}
void Fou::affiche() const { cout << get_nom(); }

bool Fou::est_mouvement_legal(vector<int> org, vector<int> dst,
                              Piece* echiquier[8][8]) const {
  coord_valides(org, dst);

  for (int i = 0; i < NBCOL; i++) {
    // Mouvement diagonal haut droit
    if (org[COL] + i == dst[COL] && org[LGN] + i == dst[LGN]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN] + j][org[COL] + j]) {
          return false;
        }
      }
      return true;
    }
    // Mouvement diagonal haut gauche
    if (org[COL] - i == dst[COL] && org[LGN] + i == dst[LGN]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN] + j][org[COL] - j]) {
          return false;
        }
      }
      return true;
    }

    // Mouvement diagonal bas droit
    if (org[COL] + i == dst[COL] && org[LGN] - i == dst[LGN]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN] - j][org[COL] + j]) {
          return false;
        }
      }
      return true;
    }

    // Mouvement diagonal bas gauche
    if (org[COL] - i == dst[COL] && org[LGN] - i == dst[LGN]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN] - j][org[COL] - j]) {
          return false;
        }
      }
      return true;
    }
  }
  return false;
}
// *********************************************************

// Classe Dame

Dame::Dame(Couleur couleur, string nom, Square coord)
    : Piece(couleur, nom, coord) {}
Dame::~Dame() {}
void Dame::affiche() const { cout << get_nom(); }

bool Dame::est_mouvement_legal(vector<int> org, vector<int> dst,
                               Piece* echiquier[8][8]) const {
  coord_valides(org, dst);

  for (int i = 0; i < NBCOL; i++) {
    // Mouvements de la tour
    if (org[LGN] == dst[LGN] && org[COL] + i == dst[COL]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN]][org[COL] + j]) {
          return false;
        }
      }
      return true;
    }

    if (org[LGN] == dst[LGN] && org[COL] - i == dst[COL]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN]][org[COL] - j]) {
          return false;
        }
      }
      return true;
    }

    if (org[LGN] - i == dst[LGN] && org[COL] == dst[COL]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN] - j][org[COL]]) {
          return false;
        }
      }
      return true;
    }

    if (org[LGN] + i == dst[LGN] && org[COL] == dst[COL]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN] + j][org[COL]]) {
          return false;
        }
      }
      return true;
    }
    // Mouvements du fou

    if (org[LGN] + i == dst[LGN] && org[COL] + i == dst[COL]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN] + j][org[COL] + j]) {
          return false;
        }
      }
      return true;
    }

    if (org[LGN] + i == dst[LGN] && org[COL] - i == dst[COL]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN] + j][org[COL] - j]) {
          return false;
        }
      }
      return true;
    }

    if (org[LGN] - i == dst[LGN] && org[COL] - i == dst[COL]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN] - j][org[COL] - j]) {
          return false;
        }
      }
      return true;
    }

    if (org[LGN] - i == dst[LGN] && org[COL] + i == dst[COL]) {
      for (int j = 1; j < i; j++) {
        if (echiquier[org[LGN] - j][org[COL] + j]) {
          return false;
        }
      }
      return true;
    }
  }
  return false;
}
// *********************************************************

// Classe Roi

Roi::Roi(Couleur couleur, string nom, Square coord)
    : Piece(couleur, nom, coord) {}
Roi::~Roi() {}
void Roi::affiche() const { cout << get_nom(); }
bool Roi::est_mouvement_legal(vector<int> org, vector<int> dst,
                              Piece* echiquier[8][8]) const {
  coord_valides(org, dst);

  // Avance verticalement et bouge librement sur la ligne
  if (dst[LGN] == org[LGN] + 1) {
    if (dst[COL] == org[COL] - 1 || dst[COL] == org[COL] ||
        dst[COL] == org[COL] + 1) {
      return true;
    }
  }
  // Recule verticalement et bouge librement sur la ligne
  if (dst[LGN] == org[LGN] - 1) {
    if (dst[COL] == org[COL] + 1 || dst[COL] == org[COL] - 1 ||
        dst[COL] == org[COL]) {
      return true;
    }
  }
  // bouge librement sur la ligne
  if (dst[LGN] == org[LGN]) {
    if (dst[COL] == org[COL] + 1 || dst[COL] == org[COL] - 1) {
      return true;
    }
  }
  return false;
}

// *********************************************************

// Classe Pion

Pion::Pion(Couleur couleur, string nom, Square coord)
    : Piece(couleur, nom, coord) {}
Pion::~Pion() {}
void Pion::affiche() const { cout << get_nom(); }

bool Pion::est_mouvement_legal(vector<int> org, vector<int> dst,
                               Piece* echiquier[8][8]) const {
  coord_valides(org, dst);

  // Pion blanc
  if (echiquier[org[LGN]][org[COL]]->get_couleur() == Blanc) {
    // Première ligne +2 possible
    if (org[LGN] == 1) {
      // Avancer une case
      if (org[COL] == dst[COL] && dst[LGN] == org[LGN] + 1) {
        if (echiquier[dst[LGN]][dst[COL]])
          return false;
        else
          return true;
      }
      // Avancer 2 cases
      if (org[COL] == dst[COL] && dst[LGN] == org[LGN] + 2) {
        if (echiquier[dst[LGN]][dst[COL]] || echiquier[dst[LGN] - 1][dst[COL]])
          return false;
        else
          return true;
      }
    }
    // Avancer de deux cases n'est plus possible
    if (org[COL] == dst[COL] && dst[LGN] == org[LGN] + 1) {
      if (echiquier[dst[LGN]][dst[COL]])
        return false;
      else
        return true;
    }
    // manger en diagonale
    if (org[COL] + 1 == dst[COL] && echiquier[dst[LGN]][dst[COL]] &&
        org[LGN] + 1 == dst[LGN])
      return true;

    if (org[COL] - 1 == dst[COL] && echiquier[dst[LGN]][dst[COL]] &&
        org[LGN] + 1 == dst[LGN])
      return true;

    // prise en passant
    if (org[LGN] == 4 && org[COL] + 1 == dst[COL] &&
        echiquier[dst[LGN] - 1][dst[COL]] && org[LGN] + 1 == dst[LGN]) {
      char column = (char)(dst[COL] + 97);
      string mvmnt;
      mvmnt.push_back(column);
      mvmnt.push_back('7');
      mvmnt.push_back(column);
      mvmnt.push_back('5');
      if (search_in_hist(mvmnt) == 1) {
        echiquier[dst[LGN] - 1][dst[COL]] = nullptr;
        return true;
      }
    }

    if (org[LGN] == 4 && org[COL] - 1 == dst[COL] &&
        echiquier[dst[LGN] - 1][dst[COL]] && org[LGN] + 1 == dst[LGN]) {
      char column = (char)(dst[COL] + 97);
      string mvmnt;
      mvmnt.push_back(column);
      mvmnt.push_back('7');
      mvmnt.push_back(column);
      mvmnt.push_back('5');
      if (search_in_hist(mvmnt) == 1) {
        echiquier[dst[LGN] - 1][dst[COL]] = nullptr;
        return true;
      }
    }
  }

  else {  ///- Première ligne +2 possible
    if (org[LGN] == 6) {
      // Avancer une case
      if (org[COL] == dst[COL] && dst[LGN] == org[LGN] - 1) {
        if (echiquier[dst[LGN]][dst[COL]])
          return false;
        else
          return true;
      }
      // Avancer 2 cases
      if (org[COL] == dst[COL] && dst[LGN] == org[LGN] - 2) {
        if (echiquier[dst[LGN]][dst[COL]] || echiquier[dst[LGN] + 1][dst[COL]])
          return false;
        else
          return true;
      }
    }

    if (org[COL] == dst[COL] && dst[LGN] == org[LGN] - 1) {
      if (echiquier[dst[LGN]][dst[COL]])
        return false;
      else
        return true;
    }
    ///- manger en diagonale
    if (org[COL] + 1 == dst[COL] && echiquier[dst[LGN]][dst[COL]] &&
        org[LGN] - 1 == dst[LGN])
      return true;

    if (org[COL] - 1 == dst[COL] && echiquier[dst[LGN]][dst[COL]] &&
        org[LGN] - 1 == dst[LGN])
      return true;
    ///- prise en passant
    if (org[LGN] == 3 && org[COL] + 1 == dst[COL] && echiquier[dst[LGN] + 1][dst[COL]] &&
        org[LGN] - 1 == dst[LGN]) {
      char column = (char)(dst[COL] + 97);
      string mvmnt;
      mvmnt.push_back(column);
      mvmnt.push_back('2');
      mvmnt.push_back(column);
      mvmnt.push_back('4');
      if (search_in_hist(mvmnt) == 1) {
        echiquier[dst[LGN] + 1][dst[COL]] = nullptr;
        return true;
      }
    }

    if ( org[LGN] == 3 && org[COL] - 1 == dst[COL] && echiquier[dst[LGN] + 1][dst[COL]] &&
        org[LGN] - 1 == dst[LGN]) {
      char column = (char)(dst[COL] + 97);
      string mvmnt;
      mvmnt.push_back(column);
      mvmnt.push_back('2');
      mvmnt.push_back(column);
      mvmnt.push_back('4');
      if (search_in_hist(mvmnt) == 1) {
        echiquier[dst[LGN] + 1][dst[COL]] = nullptr;
        return true;
      }
    }
  }

  return false;
}

// *********************************************************