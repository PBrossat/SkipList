#include "skipList.h"
#include <iostream>



skipList::skipList() {
  m_sentinelle = new Cellule ;
  m_sentinelle->nbNiveau=9;
  for (int i=0; i<m_sentinelle->nbNiveau; i++)
  {
    m_sentinelle->suivant[i]=nullptr;
  }
  taille=0;
}




skipList::~skipList() 
{
  delete m_sentinelle ;
}



Cellule::Cellule()
{
  nbNiveau=0;
}




void skipList::inserer(Elem v) 
{
  Cellule *current= new Cellule;
  Cellule *newC= new Cellule;
  newC->info=v;
  int nvMax = m_sentinelle-> nbNiveau;
  int nvCurrent= nvMax;
  Cellule *tabPrecedent [nvMax+1];
  current=m_sentinelle;
  while (nvCurrent>=0) //on cherche où placer la nouvelle cellule
  {
    while ((current->suivant[nvCurrent]!=nullptr)&&(current->suivant[nvCurrent]->info <v))
    {
      current=current->suivant[nvCurrent];
    }
    tabPrecedent [nvCurrent]=current;
    nvCurrent--; 
  }
  //on place la nouvelle cellule au bon endroit
  nvCurrent=0; 
  // newC->suivant[0]=tabPrecedent[0]->suivant[0];
  // tabPrecedent[0]->suivant[0]=newC;
  
  while (nvCurrent<nvMax) //on définit le niveau de la nouvelle cellule
  {
    if (pile_ou_face()||nvCurrent==0)
    {
      newC->suivant[nvCurrent]=tabPrecedent[nvCurrent]->suivant[nvCurrent];
      tabPrecedent[nvCurrent]->suivant[nvCurrent]=newC;
      nvCurrent=nvCurrent+1;
    }else
    {
      break; //on sort de la boucle  
    }
  }
}







Cellule* skipList::chercher(int v) 
{
  Cellule *current= m_sentinelle;
  int nvMax = m_sentinelle-> nbNiveau;
  int nvCurrent= nvMax;
  while (nvCurrent>=0) //on cherche la cellule contenant v
  {
    while ((current->suivant[nvCurrent]!=nullptr)&&(current->suivant[nvCurrent]->info <=v))
    {
      current=current->suivant[nvCurrent];
    }
    if (current->info==v)
    {
      return current;
    }
    nvCurrent--; 
  }
    return nullptr;
}




void skipList::supprimer(int v)
{

  Cellule* deleteCellule=chercher(v);
  if (deleteCellule==nullptr)
  {
    std::cout<<v<<"  introuvable"<<std::endl;
    return;
  }
  else
  {
    int nvMaxCellule=deleteCellule->nbNiveau;
    int nvCurrentCellule=nvMaxCellule;
    Cellule *current= m_sentinelle;
    int nvMax = m_sentinelle-> nbNiveau;
    int nvCurrent= nvMax;
    Cellule *tabPrecedent [nvMaxCellule+1];
    while (nvCurrent>=0) 
    { 
      std::cout<<"hey"<<std::endl;
      while ((current->suivant[nvCurrent]!=nullptr)&&(current->suivant[nvCurrent]->info <=v))
      {
        std::cout<<"hoy"<<std::endl;
        current=current->suivant[nvCurrent];
      }
      tabPrecedent [nvCurrent]=current;
      nvCurrent--; 
    }
    while (nvCurrentCellule>=0)
    {
      std::cout<<"hiy"<<std::endl;
      current->suivant[nvCurrentCellule]=tabPrecedent[nvCurrentCellule]->suivant[nvCurrentCellule];
      tabPrecedent[nvCurrentCellule]->suivant[nvCurrent]=deleteCellule->suivant[nvCurrentCellule];
      nvCurrentCellule=nvCurrentCellule-1;
    }
  }
}





  // Cellule *current=m_sentinelle;
  // int nvMax = m_sentinelle-> nbNiveau;
  // int nvCurrent= nvMax;
  // Cellule *tabPrecedent [nvMax+1];
  // while (nvCurrent>=0) //on cherche la cellule contenant v
  // {
  //   while ((current->suivant[nvCurrent]!=nullptr)&&(current->suivant[nvCurrent]->info <=v))
  //   {
  //     current=current->suivant[nvCurrent];
  //   }
  //   tabPrecedent [nvCurrent]=current;
  //   nvCurrent--; 
  // }
  // nvCurrent=0;
  // Cellule *temp= current;
  // while (nvCurrent<nvMax)
  // {
  //   temp->suivant[nvCurrent]=tabPrecedent[nvCurrent]->suivant[nvCurrent];
  //   tabPrecedent[nvCurrent]->suivant[nvCurrent]=temp->suivant[nvCurrent];
  //   nvCurrent++;
  // }
  // delete current;





bool skipList::test_tri() {
  //initialisation du curseur
  Cellule* courante = m_sentinelle->suivant[0] ;
  while(courante && courante->suivant[0]) {
    //on a deux cellules de suite qui existent
    if(courante->info > courante->suivant[0]->info) {
      //la premiere a une valeur plus grande que la seconde, ce n'est pas trie
      return false ;
    }
    courante = courante->suivant[0] ;
  }
  return true ;
}



void skipList::afficher()
{
  std::cout<<m_sentinelle->nbNiveau<<std::endl;
  for (int i=0; i<m_sentinelle->nbNiveau; i++)
  {
  Cellule *current=m_sentinelle; // Cellule *temp=m_sentinelle;
  std::cout<<"Niveau : "<<i<<std::endl;
  while(current->suivant[i]!=nullptr)
  {
    
    affichageElement(current->suivant[i]->info);
    current=current->suivant[i];
  }
  std::putchar('\n');
  }
}



bool skipList::pile_ou_face() 
{
  int pile_face=rand() % 2;
  return pile_face==0;
}

