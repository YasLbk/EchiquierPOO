/**
  * @author Yassine Lambarki El Allioui
  * @version 1.0
  * @date 25/05/2020
  * @file Square.h
  * @title Square
  * @brief 
  */

#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*!
 * @class Classe Square 
 * @brief Une classe pour gérer les cases/carrés de l'échiquier
 */
class Square{

public:
  /*!
   * @brief transfome la case de la forme algébrique à la forme numérique
   * @param algebric_form case en forme algébrique
   */
  vector <int> alg_to_numcoord(string algebric_form); // convert "a1" to (0,0)
  /*!
   * @brief getter des coordonnées
   */
  vector <int> get_coord();                           // getter

  /*!
   * @brief Contructeur numérique de la case type: Square(0,0)
   * @param x ligne de la case
   * @param y colonne de la case
   */
  Square(int x, int y);      
    /*!
   * @brief Contructeur algébrique de la case type: Square("a1")
   * @param string case en forme algébrique
   */
  Square(string);            


private:
  vector <int> coord;          /*!< Les coordonnées de la case au format [0,0]
 */
};
