#ifndef LIFAP6_SKIP_LISTE_HPP
#define LIFAP6_SKIP_LISTE_HPP
#include "element.h"
#include <random>
    

class Cellule
{
    friend class skipList;

    public :

      Cellule();
    

    private :
        Elem info;
        Cellule* suivant[10];
        int nbNiveau;
};


class skipList {
  public :

    /* construction, destruction */
    skipList() ;
    ~skipList() ;

    /* suppression de la copie pour le moment */
    //skipList(const skipList&) = delete ;
    //skipList& operator=(const skipList&) = delete ;

    /* insertion triee */
    void inserer(Elem v) ;

    /* recherche */
    Cellule* chercher(int v) ;

    /* affichage */
    void afficher() ;

    void supprimer(int v);

    /* tests */
    bool test_tri() ;

  private :

    /* la sentinelle servira a stocker les tetes de chaque niveau */
    Cellule* m_sentinelle ;

    /* generateur de nombres aleatoires pour les pile ou face */
    std::default_random_engine m_random ;
    std::bernoulli_distribution m_piece ;
    bool pile_ou_face() ;
    int taille;
   
} ;

#endif

