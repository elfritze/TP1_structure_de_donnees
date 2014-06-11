/**
 * \file Chemin.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Chemin
 * \author Éric Guillemette, Mathieu L'Écuyer
 * \version 0.1
 * \date juin 2014
 */

#include "Chemin.h"
#include <iostream>

using namespace std;

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les définitions du TP1.
 */
namespace TP1
{

/**
 * \fn Chemin::Chemin()
 */
Chemin::Chemin() :
      debut(0), cpt(0)
{
}

/**
 * \fn Chemin::~Chemin()
 */
Chemin::~Chemin()
{
   _detruire();
}

/**
 * \fn Chemin::Chemin(const Chemin& source)
 *
 * \param[in] source : Un objet Chemin existant.
 */
Chemin::Chemin(const Chemin& source)
{
   debut = source.debut;
   cpt = source.cpt;
   if (debut != 0)
   {
      _copier(source.debut);
   }
}

/**
 * \fn const Chemin& Chemin::operator=(const Chemin& source)
 *
 * \param[in] source : Un objet Chemin existant.
 *
 * \return L'objet courant contenant à présent les données de l'objet source.
 */
const Chemin& Chemin::operator=(const Chemin& source)
{
   if (this != &source)
   {
      if (debut != 0)
      {
         _detruire();
      }

      // On copie à partir du début
      debut = source.debut;
      cpt = source.cpt;
      if (source.debut != 0) // si la liste chaînée source n'est pas vide
      {
         _copier(source.debut);
      }
   }

   return (*this);
}

/**
 * \fn void Chemin::ajoutePiece(const std::string &nomPiece, int distanceDuDebut)
 *
 * \param[in] nomPiece : Le nom de la pièce à ajouter à la file.
 * \param[in] distanceDuDebut : Le nombre de déplacement depuis le début du labyrinthe.
 */
void Chemin::ajoutePiece(const std::string &nomPiece, int distanceDuDebut)
{
   // On crée le nouveau noeud du chemin
   NoeudChemin * nouveau = new NoeudChemin(nomPiece, distanceDuDebut);
   nouveau->suivant = 0;

   // On parcourt la liste jusqu'à la fin
   NoeudChemin * courant = debut;
   NoeudChemin * pred = 0;
   while (courant != 0)
   {
      pred = courant;
      courant = courant->suivant;
   }

   // Si la liste est vide, on insère au début
   if (debut == 0)
   {
      debut = nouveau;
   }
   else
   {
      pred->suivant = nouveau; // Sinon on ajoute à la fin
   }

   cpt++;
}

/**
 * \fn void Chemin::retirePiece(int numPiece)
 *
 * \param[in] numPiece : L'indice de la pièce à supprimer dans la chaîne.
 */
void Chemin::retirePiece(int numPiece)
{
   // Vérification des préconditions
   if (numPiece >= 1 && numPiece <= tailleChemin())
   {
      int i = 1;
      NoeudChemin * courant = debut;
      NoeudChemin * precedent = 0;

      // On boucle pour atteindre le noeud de la pièce désirée
      while (i < numPiece)
      {
         precedent = courant;
         courant = precedent->suivant;
         i++;
      }

      // Si le noeud désiré est le premier, on réassigne le début au noeud suivant.
      if (debut == courant)
      {
         debut = courant->suivant;
      }
      else
      {
         // Sinon on associe le pointeur suivant du noeud précédant
         // au noeud suivant du noeud à supprimer
         precedent->suivant = courant->suivant;
      }

      // On supprime le noeud désiré
      courant->suivant = 0;
      delete courant;
      cpt--;
   }
   else
   {
      throw std::invalid_argument("retirePiece: L'indice est invalide");
   }
}

/**
 * \fn const std::string & Chemin::getNomPiece() const
 *
 * \return Le nom de la pièce au début du chemin.
 */
const std::string & Chemin::getNomPiece() const
{
   return debut->nomPiece;
}

/**
 * \fn int Chemin::getDistanceDuDebut() const
 *
 * \return La distance du début, soit de la pièce au début d'un chemin.
 */
int Chemin::getDistanceDuDebut() const
{
   return debut->distanceDuDebut;
}

/**
 * \fn int Chemin::tailleChemin() const
 *
 * \return Un entier représentant la taille du chemin.
 */
int Chemin::tailleChemin() const
{
   return cpt;
}

/**
 * \fn void Chemin::afficheChemin() const
 */
void Chemin::afficheChemin() const
{
   for (NoeudChemin* temp = debut; temp != 0; temp = temp->suivant)
   {
      cout << temp->nomPiece << " " << temp->distanceDuDebut;
   }
}

/**
 * \fn void Chemin::_copier(NoeudChemin * sn)
 *
 * \param[in] sn : Un pointeur sur le début du chemin.
 */
void Chemin::_copier(NoeudChemin * sn)
{
   try
   {
      // On copie le premier noeud
      debut = new NoeudChemin(sn->nomPiece, sn->distanceDuDebut);

      // On copie le reste de la liste
      NoeudChemin* nouveau = debut;
      for (NoeudChemin* temp = sn->suivant; temp != 0; temp = temp->suivant)
      {
         nouveau->suivant = new NoeudChemin(temp->nomPiece, temp->distanceDuDebut);
         nouveau = nouveau->suivant;
      }
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
 * \fn void Chemin::_detruire()
 */
void Chemin::_detruire()
{
   NoeudChemin * temp = debut;
   while(debut != 0)
   {
      debut = temp->suivant;
      delete temp;
      temp = debut;
   }
   cpt = 0;
}

} // namespace TP1
