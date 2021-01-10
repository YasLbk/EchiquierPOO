/**
 * @author Yassine Lambarki El Allioui
 * @version 1.0
 * @date 25/05/2020
 * @file Piece.h
 * @title Piece
 * @brief
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>


#include "Square.h"
using namespace std;


enum Couleur { Blanc = 0, Noir};

/*!
 * @class Classe mère Pièce
 * @brief Une classe pour gérer les pièces
 */
class Piece {
 public:
  /*!
   * @brief Contructeur de pièce
   * @param couleur blanc ou noir , couleur de la pièce
   * @param nom nom/type de la pièce
   * @param coord coordonées de la case de la pièce au sein de l'échiquier
   */
  Piece(Couleur couleur, string nom, Square coord);
  /*!
   * @brief Destructeur de pièce
   */
  ~Piece();
  /*!
   * @brief getter de la couleur de la pièce
   */
  Couleur get_couleur() const;
  /*!
   * @brief getter de la nom de la pièce
   */
  string get_nom() const;
  /*!
   * @brief getter des coordonnées de la pièce
   */
  Square get_coord() const;
  /*!
   * @brief méthode virtuelle pour afficher les pièces
   */
  virtual void affiche() const = 0;
  /*!
   * @brief méthode virtuelle pour tester si un mouvement est légal
   * @param orig coordonnées de la case d'origine [x,y]
   * @param dest coordonnées de la case de destination [x,y]
   * @param echiquier l'échiquier courant
   */
  virtual bool est_mouvement_legal(vector<int> orig, vector<int> dest,
                                   Piece* echiquier[8][8]) const = 0;

 protected:
  Couleur couleur; /*!< La couleur de la pièce */
  string nom;      /*!< Le nom/type de la pièce */
  Square coord;    /*!< Les coordonnées de la case de la pièce */
}; 

/*!
 * @class Classe fils de type Tour
 * @brief Une classe pour gérer les Tours
 */
class Tour : public Piece {
 public:
  /*!
   * @brief Contructeur de pièce Tour
   * @param couleur blanc ou noir , couleur de la pièce
   * @param nom nom/type de la pièce
   * @param coord coordonées de la case de la pièce au sein de l'échiquier
   */
  Tour(Couleur couleur, string nom, Square coord);
  /*!
   * @brief Destructeur de pièce Tour
   */
  ~Tour();
  /*!
   * @brief méthode virtuelle pour afficher les pièces Tour 
   */
  virtual void affiche() const;
  /*!
   * @brief méthode virtuelle pour tester si un mouvement est légal
   * @param orig coordonnées de la case d'origine [x,y]
   * @param dest coordonnées de la case de destination [x,y]
   * @param echiquier l'échiquier courant
   */
  virtual bool est_mouvement_legal(vector<int> orig, vector<int> dest,
                                   Piece* echiquier[8][8]) const;
};
/*!
 * @class Classe fils de type Cavalier
 * @brief Une classe pour gérer les Cavaliers
 */
class Cavalier : public Piece {
 public:
  /*!
   * @brief Contructeur de pièce Cavalier
   * @param couleur blanc ou noir , couleur de la pièce
   * @param nom nom/type de la pièce
   * @param coord coordonées de la case de la pièce au sein de l'échiquier
   */
  Cavalier(Couleur couleur, string nom, Square coord);
  /*!
   * @brief Destructeur de pièce Cavalier
   */
  ~Cavalier();
  /*!
   * @brief méthode virtuelle pour afficher les pièces Cavalier
   */
  virtual void affiche() const;
  /*!
   * @brief méthode virtuelle pour tester si un mouvement est légal
   * @param orig coordonnées de la case d'origine [x,y]
   * @param dest coordonnées de la case de destination [x,y]
   * @param echiquier l'échiquier courant
   */
  virtual bool est_mouvement_legal(vector<int> orig, vector<int> dest,
                                   Piece* echiquier[8][8]) const;
};

/*!
 * @class Classe fils de type Fou 
 * @brief Une classe pour gérer les Foux
 */
class Fou : public Piece {
 public:
  /*!
   * @brief Contructeur de pièce Fou
   * @param couleur blanc ou noir , couleur de la pièce
   * @param nom nom/type de la pièce
   * @param coord coordonées de la case de la pièce au sein de l'échiquier
   */
  Fou(Couleur couleur, string nom, Square coord);
  /*!
   * @brief Destructeur de pièce Fou
   */
  ~Fou();
  /*!
   * @brief méthode virtuelle pour afficher les pièces Fou
   */
  virtual void affiche() const;
  /*!
   * @brief méthode virtuelle pour tester si un mouvement est légal
   * @param orig coordonnées de la case d'origine [x,y]
   * @param dest coordonnées de la case de destination [x,y]
   * @param echiquier l'échiquier courant
   */
  virtual bool est_mouvement_legal(vector<int> orig, vector<int> dest,
                                   Piece* echiquier[8][8]) const;
};

/*!
 * @class Classe fils de type Dame
 * @brief Une classe pour gérer les Dames
 */
class Dame : public Piece {
 public:
  /*!
   * @brief Contructeur de pièce Dame
   * @param couleur blanc ou noir , couleur de la pièce
   * @param nom nom/type de la pièce
   * @param coord coordonées de la case de la pièce au sein de l'échiquier
   */
  Dame(Couleur couleur, string nom, Square coord);
  /*!
   * @brief Destructeur de pièce Dame
   */
  ~Dame();
  /*!
   * @brief méthode virtuelle pour afficher les pièces Dame
   */
  virtual void affiche() const;
  /*!
   * @brief méthode virtuelle pour tester si un mouvement est légal
   * @param orig coordonnées de la case d'origine [x,y]
   * @param dest coordonnées de la case de destination [x,y]
   * @param echiquier l'échiquier courant
   */
  virtual bool est_mouvement_legal(vector<int> orig, vector<int> dest,
                                   Piece* echiquier[8][8]) const;
};

/*!
 * @class Classe fils de type Roi
 * @brief Une classe pour gérer les Rois
 */
class Roi : public Piece {
 public:
  /*!
   * @brief Contructeur de pièce Roi
   * @param couleur blanc ou noir , couleur de la pièce
   * @param nom nom/type de la pièce
   * @param coord coordonées de la case de la pièce au sein de l'échiquier
   */
  Roi(Couleur couleur, string nom, Square coord);
  /*!
   * @brief Destructeur de pièce Roi
   */
  ~Roi();
  /*!
   * @brief méthode virtuelle pour afficher les pièces Roi
   */
  virtual void affiche() const;
  /*!
   * @brief méthode virtuelle pour tester si un mouvement est légal
   * @param orig coordonnées de la case d'origine [x,y]
   * @param dest coordonnées de la case de destination [x,y]
   * @param echiquier l'échiquier courant
   */
  virtual bool est_mouvement_legal(vector<int> orig, vector<int> dest,
                                   Piece* echiquier[8][8]) const;
};

/*!
 * @class Classe fils de type Pion
 * @brief Une classe pour gérer les Pions
 */
class Pion : public Piece {
 public:
  /*!
   * @brief Contructeur de pièce Pion
   * @param couleur blanc ou noir , couleur de la pièce
   * @param nom nom/type de la pièce
   * @param coord coordonées de la case de la pièce au sein de l'échiquier
   */
  Pion(Couleur couleur, string nom, Square coord);
  /*!
   * @brief Destructeur de pièce Pion
   */
  ~Pion();
  /*!
   * @brief méthode virtuelle pour afficher les pièces Pion
   */
  virtual void affiche() const;
  /*!
   * @brief méthode virtuelle pour tester si un mouvement est légal
   * @param orig coordonnées de la case d'origine [x,y]
   * @param dest coordonnées de la case de destination [x,y]
   * @param echiquier l'échiquier courant
   */
  virtual bool est_mouvement_legal(vector<int> orig, vector<int> dest,
                                   Piece* echiquier[8][8]) const;
};
