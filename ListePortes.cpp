/**
 * \file ListePortes.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe ListePortes
 * \author Éric Guillemette, Mathieu L'Écuyer
 * \version 0.1
 * \date juin 2014
 */

#include "ListePortes.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les définitions du TP1.
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
 * \return L'objet courant contenant à présent les données de l'objet source.
 */
const ListePortes& ListePortes::operator =(const ListePortes& source)
{
   if (this != &source)
   {
      // On détruit la liste de portes originale
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
   // on vérifie que la porte n'est pas déjà présente
   NoeudListePortes* courant = acces;
   while (courant != 0)
   {
      if (courant->porte.getCouleur() == p.getCouleur()
            && courant->porte.getDestination() == p.getDestination())
      {
         throw std::logic_error("ajoutePorte: Porte déjà présente (doublon)");
      }

      courant = courant->suivant;
   }

   // on crée le nouveau noeud de la liste de portes
   NoeudListePortes* nouveau;
   nouveau = new NoeudListePortes(p);
   nouveau->suivant = 0;
   nouveau->precedent = 0;

   // cas où la liste est vide
   if (nbPorte == 0)
   {
      acces = nouveau;
      fin = nouveau;
      nbPorte++;
      return;
   }

   // sinon, on ajoute la nouvelle porte à la fin de la liste
   fin->suivant = nouveau;
   nouveau->precedent = fin;
   fin = nouveau;
   nbPorte++;
}

/**
 * \fn int ListePortes::tailleListePortes() const
 *
 * \return nbPorte : Un entier représentant le nombre de portes, donc la taille de la liste.
 */
int ListePortes::tailleListePortes() const
{
   return nbPorte;
}

/**
 * \fn void ListePortes::supprimePorte(int porteASupprimer)
 *
 * \param[in] porteASupprimer : Un entier représentant l'indice de la porte à supprimer.
 */
void ListePortes::supprimePorte(int porteASupprimer)
{
   // Précondition : la position de la porte à supprimer doit être valide
   if (porteASupprimer < 0 || porteASupprimer >= nbPorte)
   {
      throw std::invalid_argument("supprimePorte: Position de la porte invalide");
   }

   // on met à jour les pointeurs avant de supprimer
   NoeudListePortes* trouve;

   if (porteASupprimer == 0) // cas où la position de la porte = 0
   {
      trouve = acces;
      acces = acces->suivant;
      if (nbPorte != 1)  // s'il y avait juste un noeud, la ligne suivante serait illégale
      {
         acces->precedent = 0;
      }
      trouve->suivant = 0;
   }
   else if (porteASupprimer == nbPorte-1) // cas où on supprime le dernier noeud de la liste
   {
      trouve = fin;
      fin = fin->precedent;
      fin->suivant = 0;
      trouve->precedent = 0;
   }
   else
   {
      NoeudListePortes* courant = acces; // on se positionne au début de la liste

      // boucle pour positionner courant sur le noeud précédent celui à supprimer
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

   // libération de la mémoire associée au noeud à supprimer
   delete trouve;
   nbPorte--;
}

/**
 * \fn bool ListePortes::estVideListePortes() const
 *
 * \return Un booléen VRAI si la liste est vide, FAUX sinon.
 */
bool ListePortes::estVideListePortes() const
{
   return nbPorte == 0;
}

/**
 * \fn Porte ListePortes::elementAt(int pos) const
 *
 * \param[in] pos : La position (indice) de l'élément à récupérer dans la liste.
 *
 * \return L'objet Porte correspondant à la position donnée.
 */
Porte ListePortes::elementAt(int pos) const
{
   // précondition : position doit être entre 1 et le nombre de portes
   if (pos < 1 || pos > nbPorte)
   {
      throw std::invalid_argument("elementAt: Position de la porte invalide");
   }

   NoeudListePortes* courant = acces; // Position au début de la liste
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
 * \param[in] sourceAcces : Un pointeur sur le début de la liste source.
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
      // Il y a une erreur d'allocation de mémoire
      // Il faut libérer la mémoire déjà allouée
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
