/**
 * @author Yassine Lambarki El Allioui
 * @version 1.0
 * @date 25/05/2020
 * @file Echiquier.h
 * @title Echiquier
 * @brief
 */

#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"
using namespace std;

/*!
 * @class Classe Echiquier
 * @brief Une classe pour gérer l'échiquier
 *
 */
class Echiquier {
 public:
  /*!
   * @brief constructeur de l'échiquier
   */
  Echiquier();
  /*!
   * @brief destructeur de l'échiquier
   */
  ~Echiquier();
  /*!
   * @brief alloue de la mémoire pour l'échiquier
   */
  void alloc_mem_echiquier();

  /*!
   * @brief pose une piece dans une certaine case
   * @param piece pièce 
   * @param case_coord les coordonnées de la case
   */
  void pose_piece(Piece* piece, Square case_coord);
  /*!
   * @brief enlever une pièce
   * @param piece 
   *
   */
  void enlever_piece(Piece* piece);

  /*!
   * @brief après le coup du joueur actuel est ce que le roi est en echec ?
   * 
   * D'abord cas des roques , échec si les pièces Roi ou Tour ont bougé 
   * ou si le roque n'est pas possible.
   * Testez si les cases destination origine sont bonnes .
   * Puis pour chaque joueur selon le type de la pièce :
   * Check si le mouvement est legal si oui remplacé la pièce 
   * mais check à la fin si le roi du joueur actuel est en echec apres son dernier mvmnt
   * si oui alors annuler le dernier mvmnt sinon continuer
   * et à la fin tester si le roi du joueur adverse est en echec .
   * 
   * @param case_origine 
   * @param case_destination
   * @return 0 si pas d'echec 1 sinon
   */
  int deplace(string orig, string dest);

  /*!
   * @brief check si petit roque possible ou pas 
   * @param joueur blanc si 0 , noir sinon
   * @return 1 si c'est possible 0 sinon
   */

  bool petitroque(bool joueur);
   /*!
   * @brief check si grand roque possible ou pas 
   * @param joueur blanc si 0 , noir sinon
   * @return 1 si c'est possible 0 sinon
   */
  bool grandroque(bool joueur);
  
  
  /*!
   * @brief après le coup du joueur actuel est ce que le roi est en echec ?
   * 
   * Supposons que le joueur actuel est noir , on check si le roi noir est en echec
   * Parcourir tout l'echiquier
   * Voir toutes les destinations légales possibles des pieces blanches existantes
   * Si parmi ces destinations légales possibles , il y le roi noir
   * alors ce roi est en echec 
   * 
   * @param joueur pour savoir la couleur du joueur
   * @param echiquier
   * @return 0 si pas d'echec 1 sinon
   */

  int adv_enechec(bool joueur, Piece* echiquier[8][8]);


  /*!
   * @brief Afficher l'échiquier
   */
  void affiche() const;

  /*!
   * @brief effacer toutes les pieces de l'echiquier
   */
  void effacer_piece();

 protected:
  
  vector<Piece*> piecesb;
  vector<Piece*> piecesn;
  vector<Piece*> pionsb;
  vector<Piece*> pionsn;
  Piece* echiquier[8][8];
};
