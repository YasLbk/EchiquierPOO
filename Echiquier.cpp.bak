/**
 * @author Yassine Lambarki El Allioui
 * @version 1.0
 * @date 25/05/2020
 * @file Echiquier.cpp
 * @title Echiquier
 * @brief
 */

#include "Echiquier.h"

#include <iostream>
#include <string>
#include <vector>

#include "Piece.h"
#include "Square.h"
using namespace std;
#define NBCOL 8
#define LGN 0
#define COL 1


// Compteurs de mouvement pour la tour et le roi 
int joueur = 0;
int compteurRblanc = 0 , compteurTblanche = 0;
int compteurRnoir = 0 , compteurTnoire = 0;



// constructeur

/************************ Utilitaires **********************************/

// enlève une pièce , en rendant nulle la case de sa position
// dans l'échiquier
void Echiquier::enlever_piece(Piece* p) {
  vector<int> a;
  a = (p->get_coord()).get_coord();
  echiquier[a[0]][a[1]] = nullptr;
}

// pose une pièce , dans une position précise dans l'échiquier
void Echiquier::pose_piece(Piece* p, Square case_coord) {
  vector<int> a;
  a = case_coord.get_coord();
  echiquier[a[0]][a[1]] = p;
}

// efface toutes les pièces de l'echiquier
void Echiquier::effacer_piece() {
  for (int i(0); i < 8; i++) {
    for (int j(0); j < 8; j++) {
      echiquier[i][j] = nullptr;
    }
  }
}
/**********************************************************************/
/************************ Fonctions à dev  **********************************/


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


int Echiquier::adv_enechec(bool joueur, Piece* echiquier[8][8]) {
  
  // Initialisation des positions(cases) d'origine (0,0) et de destination (0,0)
  vector<int> org;
  org.push_back(0);
  org.push_back(0);
  vector<int> dst;
  dst.push_back(0);
  dst.push_back(0);

  // Joueur actuel noir , on check si le roi noir est en echec

  // parcourir toutes les pieces blanches // check leur mouvement possibles // si
  // parmieux case de destinaion = roi noir alors echec
  if (joueur != 0) {
    // si la case d'origine  est un roi

    // Parcourir tout l'echiquier
    for (int i = 0; i < NBCOL; i++) {
      for (int j = 0; j < NBCOL; j++) {
        org[0] = i;
        org[1] = j;
        // Voir toutes les destinations légales possibles des pieces noires
        // existantes
        for (int x = 0; x < NBCOL; x++) {
          for (int y = 0; y < NBCOL; y++) {
            dst[0] = x;
            dst[1] = y;
            if (echiquier[i][j] != 0 && echiquier[x][y] != 0) {
              //  pieces blanches existantes(mangeables) dans ses cases destinations
              // case d'origne blanche et case destination roi noir
              if (echiquier[i][j]->get_couleur() == Blanc &&
                  echiquier[x][y]->get_nom() == "\u265A") {
                if (echiquier[i][j]->est_mouvement_legal(org, dst,
                                                         echiquier)) {
                  cout << "Roi Noir mis en echec" << endl;
                  return 1;
                }
              }
            }
          }
        }
      }
    }
  }

  // cas des blanches (similaire au premier)
  else {
    // Parcourir tout l'echiquier
    for (int i = 0; i < NBCOL; i++) {
      for (int j = 0; j < NBCOL; j++) {
        org[0] = i;
        org[1] = j;
        // Voir toutes les destinations légales possibles des pieces noires
        // existantes
        for (int x = 0; x < NBCOL; x++) {
          for (int y = 0; y < NBCOL; y++) {
            dst[0] = x;
            dst[1] = y;
            if (echiquier[i][j] != 0 && echiquier[x][y] != 0) {
              if (echiquier[i][j]->get_couleur() == Noir &&
                  echiquier[x][y]->get_nom() == "\u2654") {
                if (echiquier[i][j]->est_mouvement_legal(org, dst,
                                                         echiquier)) {
                  
                  cout << "Roi Blanc mis en echec" << endl;
                  return 1;
                }
              }
            }
          }
        }
      }
    }
  }

  // cout << "pas d'echec pour le roi" <<endl;
  return 0;
}

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
int Echiquier::deplace(string case_origine, string case_destination) {


  ///- Cas où on demande le grand Roque:
  if (case_origine == "grand") {
    //Blanc
    if (!joueur) {
      if (compteurRblanc == 0 && compteurTblanche == 0) {
        if (grandroque(joueur)) {
          joueur = !joueur;
        } else {
          //cerr << "Failed : Grand roque impossible B " << endl;
          return 1;
        }

      } else {
        cerr << "Failed : Grand roque impossible car pièce(roi ou tour B) a été déja deplacée" << endl;
        return 1;
      }
    } else {
      if (compteurRnoir == 0 && compteurTnoire == 0) {
        if (grandroque(joueur)) {
          joueur = !joueur;
        } else {
          //cerr << "Failed : Grand roque impossible N " << endl;
          return 1;
        }
      } else {
        cerr << "Failed : Grand roque impossible car pièce(roi ou tour N) a été déja deplacée" << endl;
        return 1;
      }
    }
  }

  ///- Cas où on demande le petit Roque:
  else if (case_origine == "petit") {
    if (!joueur) {
      if (compteurRblanc == 0 && compteurTblanche == 0) {
        if (petitroque(joueur)) {
          joueur = !joueur;
        } else {
          //cerr << "Failed : Petit roque impossible B " << endl;
          return 1;
        }
      } else {
        cerr << "Failed : Petit roque impossible car pièce(roi ou tour B) a été déja deplacée" << endl;
        return 1;
      }
    } else {
      if (compteurRnoir == 0 && compteurTnoire == 0) {
        if (petitroque(joueur)) {
          joueur = !joueur;
        } else {
          //cerr << "Failed : Petit roque impossible N " << endl;
          return 1;
        }
      } else {
        cerr << "Failed : Petit roque impossible car pièce(roi ou tour N) a été déja deplacée" << endl;
        return 1;
      }
    }
  }
  
  ///- Cas d'un mouvement simple
  else {
    ///- Initialisation 
    
    // Cases
    Square org(case_origine), dst(case_destination);
    // Cordonnées de chaque case
    vector<int> org_coord = org.get_coord(), dst_coord = dst.get_coord();
    // Pièce
    Piece *p_org, *p_dst;
    ///- Get piece d'origine/destination de l'échiquier
    p_org = echiquier[org_coord[0]][org_coord[1]];
    p_dst = echiquier[dst_coord[0]][dst_coord[1]];

    ///- Cas où Case d'origine vide
    if (!p_org) {
      cerr << "Case d'origine vide. Réessayez" << endl;
      return 1;
    }

    ///- Sinon et Si le joueur est blanc
    if (!joueur) {
      ///- Si pièce d'origine noire
      if (p_org->get_couleur() == Noir) {
        cerr << "Veuillez déplacer une pièce de votre camp(BLANC) :" << endl;
        return 1;
      }
      
      ///- Effectuer les mouvements en verifiant toujours s'il ya echec du roi du joueur actuel 
      if (1) {
        // cout << "pas de menace pour le roi"<< endl;
        
        ///- Cas où Case de destination occupée par le meme joueur
        if (p_dst && p_dst->get_couleur() == Blanc) {
          cerr << "Case de destination occupée " << case_destination << endl;
          return 1;
        }



        ///- A partir d'ici comparaison selon type de pièce:

        ///- Tour
        else if (p_org->get_nom() == "\u2656") {
          ///- Check si le mouvement est legal
          if (p_org->est_mouvement_legal(org_coord, dst_coord, echiquier) == true) {
            ///- Si oui enlever la pièce d'origine
            enlever_piece(p_org);
            ///- Changer de joueur
            joueur = !joueur;
            compteurRblanc++;
            ///- Plaçer la tour dans la case de destination
            p_org = new Tour(Blanc, "\u2656", Square(dst_coord[0], dst_coord[1]));
            pose_piece(p_org, p_org->get_coord());
            ///- Check si maintenat le roi blanc est en danger
            if (adv_enechec(0, echiquier) == true) {
              cerr << "Ce mouvement est illégal car votre roi est en danger" << endl;
              ///- Si oui enlever la pièce de la case destination
              enlever_piece(p_org);
              ///- changer de joueur
              joueur = !joueur;
              compteurRblanc--;
              ///- Plaçer la tour dans la case d'origine'
              p_org = new Tour(Blanc, "\u2656", Square(org_coord[0], org_coord[1]));
              pose_piece(p_org, p_org->get_coord());
              return 1;
            }
          } else {
            cerr << "Ce mouvement est illegal" << endl;
            return 1;
          }
        }
        ///- Cavalier
        else if (p_org->get_nom() == "\u2658") {
          if (p_org->est_mouvement_legal(org_coord, dst_coord, echiquier) == true) {
            joueur = !joueur;
            enlever_piece(p_org);
            p_org = new Cavalier(Blanc, "\u2658", Square(dst_coord[0], dst_coord[1]));
            pose_piece(p_org, p_org->get_coord());
            if (adv_enechec(0, echiquier) == true) {
              cerr << "Ce mouvement est illégal car votre roi est en danger" << endl;
              joueur = !joueur;
              enlever_piece(p_org);
              p_org = new Cavalier(Blanc, "\u2658", Square(org_coord[0], org_coord[1]));
              pose_piece(p_org, p_org->get_coord());
              return 1;
            }
          } else {
            cerr << "Ce mouvement est illegal" << endl;
            return 1;
          }
        }
        ///- Fou
        else if (p_org->get_nom() == "\u2657") {
          if (p_org->est_mouvement_legal(org_coord, dst_coord, echiquier) == true) {
            joueur = !joueur;
            enlever_piece(p_org);
            p_org = new Fou(Blanc, "\u2657", Square(dst_coord[0], dst_coord[1]));
            pose_piece(p_org, p_org->get_coord());
            if (adv_enechec(0, echiquier) == true) {
              cerr << "Ce mouvement est illégal car votre roi est en danger" << endl;
              joueur = !joueur;
              enlever_piece(p_org);
              p_org = new Fou(Blanc, "\u2657", Square(org_coord[0], org_coord[1]));
              pose_piece(p_org, p_org->get_coord());
            }
          } else {
            cerr << "Ce mouvement est illegal" << endl;
            return 1;
          }
        }
        ///- Dame
        else if (p_org->get_nom() == "\u2655") {
          if (p_org->est_mouvement_legal(org_coord, dst_coord, echiquier) == true) {
            enlever_piece(p_org);
            joueur = !joueur;
            p_org = new Dame(Blanc, "\u2655", Square(dst_coord[0], dst_coord[1]));
            pose_piece(p_org, p_org->get_coord());
            if (adv_enechec(0, echiquier) == true) {
              cerr << "Ce mouvement est illégal car votre roi est en danger" << endl;
              enlever_piece(p_org);
              joueur = !joueur;
              p_org = new Dame(Blanc, "\u2655", Square(org_coord[0], org_coord[1]));
              pose_piece(p_org, p_org->get_coord());
              return 1;
            }
          } else {
            cerr << "Ce mouvement est illegal" << endl;
            return 1;
          }
        }
        ///- Roi
        else if (p_org->get_nom() == "\u2654") {
          if (p_org->est_mouvement_legal(org_coord, dst_coord, echiquier) == true) {
            enlever_piece(p_org);
            joueur = !joueur;
            compteurTblanche++;
            p_org = new Roi(Blanc, "\u2654", Square(dst_coord[0], dst_coord[1]));
            pose_piece(p_org, p_org->get_coord());
            if (adv_enechec(0, echiquier) == true) {
              cerr << "Ce mouvement est illégal car votre roi est en danger" << endl;
              enlever_piece(p_org);
              joueur = !joueur;
              compteurTblanche--;
              p_org = new Roi(Blanc, "\u2654", Square(org_coord[0], org_coord[1]));
              pose_piece(p_org, p_org->get_coord());
              return 1;
            }
          } else {
            cerr << "Ce mouvement est illegal" << endl;
            return 1;
          }
        }

        ///- Pion
        else if (p_org->get_nom() == "\u2659") {
          if (p_org->est_mouvement_legal(org_coord, dst_coord, echiquier) == true) {
            enlever_piece(p_org);
            joueur = !joueur;
            p_org = new Pion(Blanc, "\u2659", Square(dst_coord[0], dst_coord[1]));
            pose_piece(p_org, p_org->get_coord());
            if (adv_enechec(0, echiquier) == true) {
              cerr << "Ce mouvement est illégal car votre roi est en danger" << endl;
              enlever_piece(p_org);
              joueur = !joueur;
              p_org = new Pion(Blanc, "\u2659", Square(org_coord[0], org_coord[1]));
              pose_piece(p_org, p_org->get_coord());
              return 1;
            }
          } else {
            cerr << "Ce mouvement est illegal" << endl;
            return 1;
          }
        }
        // poser la nouvelle pièce
        pose_piece(p_org, p_org->get_coord());
        adv_enechec(1, echiquier);
      }

    }
    /// Si le joueur est noir ...
    else {
      if (p_org->get_couleur() == Blanc) {
        cerr << "Veuillez déplacer une pièce de votre camp(BLANC) :" << endl;
        return 1;
      }

      if (1) {
        //cout << "pas de menace pour le roi du joueur actuel" << endl;
        if (p_dst && p_dst->get_couleur() == Noir) {
          cerr << "Case de destination occupée par mm couleur" << endl;
          return 1;
        }

        else if (p_org->get_nom() == "\u265C") {
          // Check si le mouvement est legal
          if (p_org->est_mouvement_legal(org_coord, dst_coord, echiquier) == true) {
            // enlever la pièce d'origine
            enlever_piece(p_org);
            // changer de joueur
            joueur = !joueur;
            compteurRnoir++;
            // Plaçer la tour dans la case de destination
            p_org = new Tour(Noir, "\u265C", Square(dst_coord[0], dst_coord[1]));
            pose_piece(p_org, p_org->get_coord());
            if (adv_enechec(1, echiquier) == true) {
              cerr << "Ce mouvement est illégal car votre roi est en danger" << endl;
              // enlever la pièce d'origine
              enlever_piece(p_org);
              // changer de joueur
              joueur = !joueur;
              compteurRnoir--;
              // Plaçer la tour dans la case de destination
              p_org = new Tour(Noir, "\u265C", Square(org_coord[0], org_coord[1]));
              pose_piece(p_org, p_org->get_coord());
              return 1;
            }
          } else {
            cerr << "Ce mouvement est illegal" << endl;
            return 1;
          }
        }
        // Fou
        else if (p_org->get_nom() == "\u265D") {
          if (p_org->est_mouvement_legal(org_coord, dst_coord, echiquier) == true) {
            joueur = !joueur;
            enlever_piece(p_org);
            p_org = new Fou(Noir, "\u265D", Square(dst_coord[0], dst_coord[1]));
            pose_piece(p_org, p_org->get_coord());
            if (adv_enechec(1, echiquier) == true) {
              cerr << "Ce mouvement est illégal car votre roi est en danger" << endl;
              joueur = !joueur;
              enlever_piece(p_org);
              p_org = new Fou(Noir, "\u265D", Square(org_coord[0], org_coord[1]));
              pose_piece(p_org, p_org->get_coord());
            }
          } else {
            cerr << "Ce mouvement est illegal" << endl;
            return 1;
          }
        }
        // Cavalier
        else if (p_org->get_nom() == "\u265E") {
          if (p_org->est_mouvement_legal(org_coord, dst_coord, echiquier) == true) {
            joueur = !joueur;
            enlever_piece(p_org);
            p_org = new Cavalier(Noir, "\u265E", Square(dst_coord[0], dst_coord[1]));
            pose_piece(p_org, p_org->get_coord());
            if (adv_enechec(1, echiquier) == true) {
              cerr << "Ce mouvement est illégal car votre roi est en danger" << endl;
              joueur = !joueur;
              enlever_piece(p_org);
              p_org = new Cavalier(Noir, "\u265E", Square(org_coord[0], org_coord[1]));
              pose_piece(p_org, p_org->get_coord());
              return 1;
            }
          } else {
            cerr << "Ce mouvement est illegal" << endl;
            return 1;
          }
        } else if (p_org->get_nom() == "\u265A") {
          if (p_org->est_mouvement_legal(org_coord, dst_coord, echiquier) == true) {
            enlever_piece(p_org);
            joueur = !joueur;
            compteurTnoire++;
            p_org = new Roi(Noir, "\u265A", Square(dst_coord[0], dst_coord[1]));
            pose_piece(p_org, p_org->get_coord());
            if (adv_enechec(1, echiquier) == true) {
              cerr << "Ce mouvement est illégal car votre roi est en danger" << endl;
              enlever_piece(p_org);
              joueur = !joueur;
              compteurTnoire--;
              p_org = new Roi(Noir, "\u265A", Square(org_coord[0], org_coord[1]));
              pose_piece(p_org, p_org->get_coord());
              return 1;
            }
          } else {
            cerr << "Ce mouvement est illegal" << endl;
            return 1;
          }
        } else if (p_org->get_nom() == "\u265B") {
          if (p_org->est_mouvement_legal(org_coord, dst_coord, echiquier) == true) {
            enlever_piece(p_org);
            joueur = !joueur;
            p_org = new Dame(Noir, "\u265B", Square(dst_coord[0], dst_coord[1]));
            pose_piece(p_org, p_org->get_coord());
            if (adv_enechec(1, echiquier) == true) {
              cerr << "Ce mouvement est illégal car votre roi est en danger" << endl;
              enlever_piece(p_org);
              joueur = !joueur;
              p_org = new Dame(Noir, "\u265B", Square(org_coord[0], org_coord[1]));
              pose_piece(p_org, p_org->get_coord());
              return 1;
            }
          } else {
            cerr << "Ce mouvement est illegal" << endl;
            return 1;
          }
        }  //
        else if (p_org->get_nom() == "\u265F") {
          if (p_org->est_mouvement_legal(org_coord, dst_coord, echiquier) == true) {
            enlever_piece(p_org);
            joueur = !joueur;
            p_org = new Pion(Noir, "\u265F", Square(dst_coord[0], dst_coord[1]));
            pose_piece(p_org, p_org->get_coord());
            if (adv_enechec(1, echiquier) == true) {
              cerr << "Ce mouvement est illégal car votre roi est en danger" << endl;
              enlever_piece(p_org);
              joueur = !joueur;
              p_org = new Pion(Noir, "\u265F", Square(org_coord[0], org_coord[1]));
              pose_piece(p_org, p_org->get_coord());
              return 1;
            }
          } else {
            cerr << "Ce mouvement est illegal" << endl;
            return 1;
          }
        }
        pose_piece(p_org, p_org->get_coord());
        ///- Si tout se passe bien check si le roi adverse est en echec ou pas
        adv_enechec(0, echiquier);
      }
    }

  }
  ///- Nouveau joueur suivant
  if (joueur) {
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << "Tour des noirs" << endl;
  } else {
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << "Tour des blancs" << endl;
  }
  return 0;
}

bool Echiquier::petitroque(bool joueur) {
  // Tour des pièces Blanches
  if (!joueur) {
    if (!(echiquier[0][5] == nullptr && echiquier[0][6] == nullptr)) {
      cerr << "Des pièces sont présentes entre le roi et la tour:" << endl;
      cerr << "Mouvement petit roque impossible (B)" << endl;
      return false;
    } else {
      echiquier[0][6] = new Roi(Blanc, "\u2654", Square(0, 6));
      enlever_piece(echiquier[0][4]);
      echiquier[0][5] = new Tour(Blanc, "\u2656", Square(0, 5));
      enlever_piece(echiquier[0][7]);
      return true;
    }
  }
  // Tour des pièces Noires
  else {
    if (!(echiquier[7][5] == nullptr && echiquier[7][6] == nullptr)) {
      cerr << "Des pièces sont présentes entre le roi et la tour:" << endl;
      cerr << "Mouvement petit roque impossible (N)" << endl;
      return false;
    } else {
      echiquier[7][6] = new Roi(Noir, "\u265A", Square(7, 6));
      enlever_piece(echiquier[7][4]);
      echiquier[7][5] = new Tour(Noir, "\u265C", Square(7, 5));
      enlever_piece(echiquier[7][7]);
      return true;
    }
  }
}

bool Echiquier::grandroque(bool joueur) {
  // Tour des pièces blanches
  if (!joueur) {
    if (!(echiquier[0][1] == nullptr && echiquier[0][2] == nullptr &&
          echiquier[0][3] == nullptr)) {
      cerr << "Des pieces sont présentes entre le roi et la tour:" << endl;
      cerr << "Grand roque impossible" << endl;
      return false;
    } else {
      echiquier[0][2] = new Roi(Blanc, "\u2654", Square(0, 2));
      enlever_piece(echiquier[0][0]);
      echiquier[0][3] = new Tour(Blanc, "\u2656", Square(0, 3));
      enlever_piece(echiquier[0][4]);
      return true;
    }
  }
  // Tour des pièces noirs
  else {
    if (!(echiquier[7][1] == nullptr && echiquier[7][2] == nullptr &&
          echiquier[7][3] == nullptr)) {
      cerr << "Des pieces sont présentes entre le roi et la tour:" << endl;
      cerr << "Grand roque impossible" << endl;
      return false;
    } else {
      echiquier[7][2] = new Roi(Noir, "\u265A", Square(7, 6));
      enlever_piece(echiquier[7][0]);
      echiquier[7][3] = new Tour(Noir, "\u265C", Square(7, 5));
      enlever_piece(echiquier[7][4]);
      return true;
    }
  }
}

/********************************************************************************************/
/************************ Contraintes  **********************************/
Echiquier::Echiquier() {
  alloc_mem_echiquier();  // --> alloue un tableau équivalent à un Piece *[8][8]
                          //     en initialisant les cases à nullptr
                          //     et alloue des vecteurs piecesb, piecesn, pionsb
  // Constructeur (Couleur,nom_affiché,id,case)
  piecesb[0] = new Tour(Blanc, "\u2656", Square(0, 0));
  piecesb[1] = new Cavalier(Blanc, "\u2658", Square(0, 1));
  piecesb[2] = new Fou(Blanc, "\u2657", Square(0, 2));
  piecesb[3] = new Dame(Blanc, "\u2655", Square(0, 3));
  piecesb[4] = new Roi(Blanc, "\u2654", Square(0, 4));
  piecesb[5] = new Fou(Blanc, "\u2657", Square(0, 5));
  piecesb[6] = new Cavalier(Blanc, "\u2658", Square(0, 6));
  piecesb[7] = new Tour(Blanc, "\u2656", Square(0, 7));
  piecesn[0] = new Tour(Noir, "\u265C", Square(7, 0));
  piecesn[1] = new Cavalier(Noir, "\u265E", Square(7, 1));
  piecesn[2] = new Fou(Noir, "\u265D", Square(7, 2));
  piecesn[3] = new Dame(Noir, "\u265B", Square(7, 3));
  piecesn[4] = new Roi(Noir, "\u265A", Square(7, 4));
  piecesn[5] = new Fou(Noir, "\u265D", Square(7, 5));
  piecesn[6] = new Cavalier(Noir, "\u265E", Square(7, 6));
  piecesn[7] = new Tour(Noir, "\u265C", Square(7, 7));

  // allocation des pions
  for (unsigned char i(0); i < NBCOL; i++) {
    pionsb[i] = new Pion(Blanc, "\u2659", Square(1, i));
    pionsn[i] = new Pion(Noir, "\u265F", Square(6, i));
  }

  for (unsigned char i(0); i < NBCOL; i++) {
    pose_piece(piecesb[i], piecesb[i]->get_coord());
    pose_piece(piecesn[i], piecesn[i]->get_coord());
    pose_piece(pionsb[i], pionsb[i]->get_coord());
    pose_piece(pionsn[i], pionsn[i]->get_coord());
  }
}

Echiquier::~Echiquier() {}

// afficher l'échiquier
void Echiquier::affiche() const {
  string space5 = string(5, ' ');
  cout << endl;
  cout << "     a     b     c     d     e     f     g     h    " << endl;
  cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
  for (int i(NBCOL - 1); i >= 0; i--) {
    cout << i + 1 << " ";  // numérotation ligne dans affichage
    for (int j(0); j < NBCOL; j++) {
      cout << "|";
      if (echiquier[i][j]) {
        cout << "\u0020\u0020";  // U+0020 est un esapce utf-8 taille police
        echiquier[i][j]->affiche();
        cout << "\u0020"
             << " ";
      } else
        cout << space5;  // 2 ascii spaces
    }
    cout << "|\n  +-----+-----+-----+-----+-----+-----+-----+-----+";
    cout << endl;
  }
}

/// initialisation(nulle) des pièces noires/blanches
/// des pions  noires/blanches  et de l'échiquier
void Echiquier::alloc_mem_echiquier() {
  for (unsigned char i(0); i < NBCOL; i++) {
    for (size_t j = 0; j < NBCOL; j++) {
      echiquier[i][j] = nullptr;
    }
    piecesb.push_back(nullptr);
    piecesn.push_back(nullptr);
    pionsb.push_back(nullptr);
    pionsn.push_back(nullptr);
  }
}

/********************************************************************/