/**
 * \file ListePortes.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe ListePortes
 * \author �tudiant 1, �tudiant 2
 * \version 0.1
 * \date juin 2014
 *
 */

#include "ListePortes.h"

namespace TP1
{

//constructeur par d�faut
ListePortes::ListePortes() :
      acces(0), fin(0), nbPorte(0)
{

}

//destructeur
ListePortes::~ListePortes()
{
   _detruire();
}

//Constructeur de copie
ListePortes::ListePortes(const ListePortes& source)
{
   nbPorte = source.nbPorte;

   if (source.nbPorte == 0) // la liste originale est vide
   {
      acces = 0;
      fin = 0;
   }
   else
      _copier(source.acces);
}

//Surcharge de l'op�rateur =
const ListePortes& ListePortes::operator =(const ListePortes& source)
{
   if (this != &source)
   {
      // On d�truit la liste de portes originale
      if (acces != 0)
      {
         _detruire();
      }

      // On copie la liste source
      nbPorte = source.nbPorte;

      if (source.nbPorte == 0) // la liste de portes originale est vide
      {
         acces = 0;
         fin = 0;
      }
      else
      {
         _copier(source.acces);
      }
   }

   return *this;
}

//Cette fonction doit ajouter la porte p � la liste donn�e.
//Dans une liste de portes, plusieurs portes de couleurs diff�rentes peuvent
//donner acc�s � la m�me autre pi�ce. Par contre, deux portes de m�me couleur
//ne peuvent pas relier deux m�mes pi�ces. Si une tentative d'ajouter une porte
//menant � la m�me pi�ce et ayant la m�me couleur qu'une porte d�j� pr�sente
//dans la liste est effectu�e, il faut lancer une exception logic_error (doublon).
void ListePortes::ajoutePorte(Porte& p)
{
   // on v�rifie que la porte n'est pas d�j� pr�sente
   NoeudListePortes* courant = acces;
   while (courant != 0)
   {
      if (courant->porte.getCouleur() == p.getCouleur()
            && courant->porte.getDestination() == p.getDestination())
      {
         throw std::logic_error("ajoutePorte: Porte d�j� pr�sente (doublon)");
      }

      courant = courant->suivant;
   }

   // on cr�e le nouveau noeud de la liste de portes
   NoeudListePortes* nouveau;
   nouveau = new NoeudListePortes(p);
   nouveau->suivant = 0;
   nouveau->precedent = 0;

   // cas o� la liste est vide
   if (nbPorte == 0)
   {
      acces = nouveau;
      fin = nouveau;
      nbPorte++;
      return;
   }

   // sinon, on ajoute la nouvelle porte � la fin de la liste
   fin->suivant = nouveau;
   nouveau->precedent = fin;
   fin = nouveau;
   nbPorte++;
}

//Cette fonction doit retourner le nombre de portes pr�sentes dans la liste de portes.
int ListePortes::tailleListePortes() const
{
   return nbPorte;
}

//Cette fonction doit supprimer la porte dont l'indice dans la liste est sp�cifi�
//par porteASupprimer dans la liste. Par exemple, si porteASupprimer vaut 0, il faut
//supprimer la premi�re porte de la liste. Si l'indice de la porte � supprimer
//est invalide, c'est-�-dire s'il est n�gatif ou plus grand ou �gal au nombre
//de portes pr�sentes dans la liste, il faut lancer une exception invalid_argument.
void ListePortes::supprimePorte(int porteASupprimer)
{
   // Pr�condition : la position de la porte � supprimer doit �tre valide
   if (porteASupprimer < 0 || porteASupprimer >= nbPorte)
   {
      throw std::range_error("supprimePorte: Position de la porte invalide");
   }


   // on met � jour les pointeurs avant de supprimer
   NoeudListePortes* trouve;

   if (porteASupprimer == 0) //cas o� la position de la porte = 0
   {
      trouve = acces;
      acces = acces->suivant;
      if (nbPorte != 1)  //s'il y avait juste un noeud, la ligne suivante serait ill�gale
      {
         acces->precedent = 0;
      }
      trouve->suivant = 0;
   }
   else if (porteASupprimer == nbPorte-1) // cas o� on supprime le dernier noeud de la liste
   {
      trouve = fin;
      fin = fin->precedent;
      fin->suivant = 0;
      trouve->precedent = 0;
   }
   else
   {
      NoeudListePortes* courant = acces; // on se positionne au d�but de la liste

      // boucle pour positionner courant sur le noeud pr�c�dent celui � supprimer
      int compteur = 0;
      while (compteur < porteASupprimer)
      {
         courant = courant->suivant;
         compteur++;
      }

      trouve = courant->suivant;
      courant->suivant = trouve->suivant;
      trouve->suivant = 0;
      trouve->precedent = 0;
   }

   // lib�ration de la m�moire associ�e au noeud � supprimer
   delete trouve;
   nbPorte--;
}

//Retourne si la liste des portes est vide ?
bool ListePortes::estVideListePortes() const
{
   return nbPorte == 0;
}

// el�ment dans la liste � une position donn�e, la premi�re position est en position 1;
// Lance une exception invalid_argument si la position n'est pas correcte.
Porte ListePortes::elementAt(int pos) const
{
   // pr�condition : position doit �tre entre 1 et le nombre de portes
   if (pos < 1 || pos > nbPorte)
   {
      throw std::range_error("elementAt: Position de la porte invalide");
   }

   NoeudListePortes* courant = acces; // Position au d�but de la liste
   int compteur = 1;

   while (compteur < pos) // boucle pour positionner courant sur le bon noeud
   {
      courant = courant->suivant;
      compteur++;
   }

   return courant->porte;
}

void ListePortes::_copier(NoeudListePortes* sourceAcces)
{
   try
   {
      // on copie le premier noeud
      acces = new NoeudListePortes(sourceAcces->porte);
      acces->precedent = 0;

      // on copie le reste de la liste de portes
      fin = acces;
      for (NoeudListePortes* temp = sourceAcces->suivant; temp != 0; temp = temp->suivant)
      {
         fin->suivant = new NoeudListePortes(temp->porte);
         fin->suivant->precedent = fin;
         fin = fin->suivant;
         fin->suivant = 0;
      }

      fin->suivant = 0;

   }
   catch (std::exception&)
   {
      // Il y a une erreur d'allocation de m�moire
      // Il faut lib�rer la m�moire d�j� allou�e
      _detruire();

      // On relance alors l'exception pour indiquer qu'une erreur est survenue
      throw;
   }
}

void ListePortes::_detruire()
{
   NoeudListePortes* courant = acces;
   while (courant != 0)
   {
      acces = acces->suivant;
      delete courant;
      courant = acces;
   }
}

}
