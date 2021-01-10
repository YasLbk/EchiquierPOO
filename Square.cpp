/**
 * @author Yassine Lambarki El Allioui
 * @version 1.0
 * @date 25/05/2020
 * @file Square.cpp
 * @title Square
 * @brief
 */

#include "Square.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

  /*!
   * @brief Contructeur numérique de la case type: Square(0,0)
   * @param x ligne de la case
   * @param y colonne de la case
   */
Square::Square(int x, int y) {
  coord.push_back(x);
  coord.push_back(y);
}
    /*!
   * @brief Contructeur algébrique de la case type: Square("a1")
   * @param string case en forme algébrique
   */
Square::Square(string algebric_form) { coord = alg_to_numcoord(algebric_form); }

  /*!
   * @brief getter des coordonnées
   */
vector<int> Square::get_coord() { return coord; }
  
  /*!
   * @brief transfome la case de la forme algébrique à la forme numérique
   * 
   * rq: a1-> (0,0)  , 1 est devenu 0 par respect au normes ,
   * a est devenu 0 , en castant le charcatère a en int donc a=97
   * et en soustracant 97
   * 
   * @param algebric_form case en forme algébrique
   */
vector<int> Square::alg_to_numcoord(string algebric_form) {
  for (int i = 0; i < 2; i++) {
    coord.push_back(0);
  }
  int s = atoi(&algebric_form[1]);
  if (0 < s && s < 9) coord[0] = s - 1;
  char c = algebric_form[0];
  if (96 < c && c < 96 + 9) coord[1] = c - 97;
  return coord;
}
