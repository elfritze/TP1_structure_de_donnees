/**
 * \file ListePortes.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe ListePortes
 * \author �ric Guillemette, Mathieu L'�cuyer
 * \version 0.1
 * \date juin 2014
 */

#include "ListePortes.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les d�finitions du TP1.
 */
namespace TP1
{

/**
 * \fn ListePortes::ListePortes()
 */
ListePortes::ListePortes() :
      acces(0), fin(0), nbPorte(0)
{

}

/**
 * \fn ListePortes::~ListePortes()
 */
ListePortes::~ListePortes()
{
   _detruire();
}

/**
 * \fn ListePortes::ListePortes(const ListePortes& source)
 *
 * \param[in] source : Un objet ListePortes existant.
 */
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

/**
 * \fn const ListePortes& ListePortes::operator =(const ListePortes& source)
 *
 * \param[in] source : Un objet ListePortes existant.
 *
 * \return L'objet courant contenant � pr�sent les donn�es de l'objet source.
 */
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

   return (*this);
}

/**
 * \fn void ListePortes::ajoutePorte(Porte& p)
 *
 * \param[in] p : Un objet Porte.
 */
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

/**
 * \fn int ListePortes::tailleListePortes() const
 *
 * \return nbPorte : Un entier repr�sentant le nombre de portes, donc la taille de la liste.
 */
int ListePortes::tailleListePortes() const
{
   return nbPorte;
}

/**
 * \fn void ListePortes::supprimePorte(int porteASupprimer)
 *
 * \param[in] porteASupprimer : Un entier repr�sentant l'indice de la porte � supprimer.
 */
void ListePortes::supprimePorte(int porteASupprimer)
{
   // Pr�condition : la position de la porte � supprimer doit �tre valide
   if (porteASupprimer < 0 || porteASupprimer >= nbPorte)
   {
      throw std::invalid_argument("supprimePorte: Position de la porte invalide");
   }

   // on met � jour les pointeurs avant de supprimer
   NoeudListePortes* trouve;

   if (porteASupprimer == 0) // cas o� la position de la porte = 0
   {
      trouve = acces;
      acces = acces->suivant;
      if (nbPorte != 1)  // s'il y avait juste un noeud, la ligne suivante serait ill�gale
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

/**
 * \fn bool ListePortes::estVideListePortes() const
 *
 * \return Un bool�en VRAI si la liste est vide, FAUX sinon.
 */
bool ListePortes::estVideListePortes() const
{
   return nbPorte == 0;
}

/**
 * \fn Porte ListePortes::elementAt(int pos) const
 *
 * \param[in] pos : La position (indice) de l'�l�ment � r�cup�rer dans la liste.
 *
 * \return L'objet Porte correspondant � la position donn�e.
 */
Porte ListePortes::elementAt(int pos) const
{
   // pr�condition : position doit �tre entre 1 et le nombre de portes
   if (pos < 1 || pos > nbPorte)
   {
      throw std::invalid_argument("elementAt: Position de la porte invalide");
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

/**
 * \fn void ListePortes::_copier(NoeudListePortes* sourceAcces)
 *
 * \param[in] sourceAcces : Un pointeur sur le d�but de la liste source.
 */
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

/**
 * \fn void ListePortes::_detruire()
 */
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

} // namespace TP1
