/**
 * @author Yassine Lambarki El Allioui
 * @version 1.0
 * @date 25/05/2020
 * @file Jeu.h
 * @title Jeu
 * @brief
 */

#pragma once
#include <iostream>
#include <string>

#include "Echiquier.h"
using namespace std;

/*!
 * @class Classe Jeu
 * @brief Une classe pour gérer le déroulement du jeu
 */
class Jeu {
 public:
  /*!
   * @brief Contructeur de jeu
   */
  Jeu();
  /*!
   * @brief Destructeur de jeu
   */
  ~Jeu();
  /*!
   * @brief Méthode qui affiche le jeu
   */
  void affiche();
  /*!
   * @brief efface le jeu
   */
  void efface();
  /*!
   * @param orig case origine en string
   * @param dest case destination en string
   * @brief Une classe pour gérer l'échiquier
   * @return 0 si pas d'erreur 1 sinon
   */
  int deplace(string orig, string dest);

  /*!
   * @param cmd mouvement
   * @brief teste si le format du string mouvement adéquat avec un mvmnt normal
   * @return 1 si c'est vrai 0 sinon
   */
  bool saisie_correcte(string const& cmd);
  /*!
   * @param cmd mouvement
   * @brief teste si le format du string mouvement est celui du petit roque
   * @return 1 si c'est vrai 0 sinon
   */
  bool saisie_correcte_proque(string const& cmd);
  /*!
   * @param cmd mouvement
   * @brief teste si le format du string mouvement est celui du grand roque
   * @return 1 si c'est vrai 0 sinon
   */
  bool saisie_correcte_groque(string const& cmd);

 private:
  Echiquier echiquier; /*!< L'échiquier */
};
