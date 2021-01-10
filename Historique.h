
/**
 * @author Yassine Lambarki El Allioui
 * @version 1.0
 * @date 25/05/2020
 * @file Historique.h
 * @title Historique
 * @brief
 */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*!
 * @brief ajoute un mot au fichier hist
 * 
 */
void add_to_hist(string name);

/*!
 * @brief search a word in historique file
 * 
 * @param word le mot à chercher
 * @return 1 si mot est trouvé 0 sinon
 */
int search_in_hist(string word);

/*!
 * @brief crée un fichier historique.txt
 * pour sauvegarder les coups valides executés
 *
 */
void historique_file();
