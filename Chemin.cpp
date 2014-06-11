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
      debut(0)
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
   if (debut != 0)
      _detruire();

   //On copie le début
   debut = source.debut;
   if (source.debut != 0)
      _copier(source.debut); //On appelle la méthode copier pour copier le reste de la liste chainée à partir du début.

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
   NoeudChemin * nouveau = new NoeudChemin(nomPiece, distanceDuDebut);
   NoeudChemin * courant = debut;
   NoeudChemin * pred = 0;

   // On parcoure la liste jusqu'à la fin
   while (courant != 0)
   {
      pred = courant;
      courant = courant->suivant;
   }

   //Si la liste est vide on insere au début
   if (debut == 0)
      debut = nouveau;
   else
      pred->suivant = nouveau; // Sinon on ajoute à la fin
}

/**
 * \fn void Chemin::retirePiece(int numPiece)
 *
 * \param[in] numPiece : L'indice de la pièce à supprimer dans la chaîne.
 */
void Chemin::retirePiece(int numPiece)
{
   //Vérification
   if (numPiece >= 1 && numPiece <= tailleChemin())
   {
      int i = 1;
      NoeudChemin * courant = debut;
      NoeudChemin * precedent = courant;

      //On loop n fois pour atteindre la piece désirée
      while (i < numPiece)
      {
         precedent = courant;
         courant = courant->suivant;
         i++;
      }

      //Si le noeud désiré est le premier on réassigne le début au suivant du début.
      if (debut == courant)
         debut = courant->suivant;
      else
         precedent->suivant = courant->suivant;	// Sinon on associe le suivant du noeud précédant le noeud désiré au noeud suivant du noeud désiré

      //On se débarasse du noeud désiré
      courant->suivant = 0;
      delete courant;
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
   int i = 0;
   for (NoeudChemin* temp = debut; temp != 0; temp = temp->suivant)
   {
      i++;
   }

   return i;
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
 * \fn void Chemin::_copier(NoeudChemin* sn)
 *
 * \param[in] sn : Un pointeur sur le début du chemin.
 */
void Chemin::_copier(NoeudChemin* sn)
{
   try
   {

      // copier le premier noeud
      debut = new NoeudChemin(sn->nomPiece, sn->distanceDuDebut);

      NoeudChemin* nouveau = debut;
      for (NoeudChemin* temp = sn->suivant; temp != 0; temp = temp->suivant)
      {
         nouveau->suivant = new NoeudChemin(temp->nomPiece, temp->distanceDuDebut);
         nouveau = nouveau->suivant;
      }
   }
   catch (std::exception&)
   {
      _detruire();
      throw;
   }
}

/**
 * \fn void Chemin::_detruire()
 */
void Chemin::_detruire()
{
   NoeudChemin * courant = debut;
   NoeudChemin * temp = 0;
   while (courant != 0)
   {
      temp = courant->suivant;
      delete courant;
      courant = temp;
   }
   debut = 0;
   delete debut;
}

} // namespace TP1
