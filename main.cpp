#include "element.h"
#include "skipList.h"
#include <cstdio>
#include <iostream>


int main()
{
  skipList sl ;

  for(int i = 20; i >= 0; --i) {
    sl.inserer(i) ;
  };
  sl.supprimer(2);
  sl.afficher() ;

}