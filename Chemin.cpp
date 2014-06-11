/**
 * \file Chemin.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe Chemin
 * \author �ric Guillemette, Mathieu L'�cuyer
 * \version 0.1
 * \date juin 2014
 */

#include "Chemin.h"
#include <iostream>

using namespace std;

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les d�finitions du TP1.
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
 * \return L'objet courant contenant � pr�sent les donn�es de l'objet source.
 */
const Chemin& Chemin::operator=(const Chemin& source)
{
   if (debut != 0)
      _detruire();

   //On copie le d�but
   debut = source.debut;
   if (source.debut != 0)
      _copier(source.debut); //On appelle la m�thode copier pour copier le reste de la liste chain�e � partir du d�but.

   return (*this);
}

/**
 * \fn void Chemin::ajoutePiece(const std::string &nomPiece, int distanceDuDebut)
 *
 * \param[in] nomPiece : Le nom de la pi�ce � ajouter � la file.
 * \param[in] distanceDuDebut : Le nombre de d�placement depuis le d�but du labyrinthe.
 */
void Chemin::ajoutePiece(const std::string &nomPiece, int distanceDuDebut)
{
   NoeudChemin * nouveau = new NoeudChemin(nomPiece, distanceDuDebut);
   NoeudChemin * courant = debut;
   NoeudChemin * pred = 0;

   // On parcoure la liste jusqu'� la fin
   while (courant != 0)
   {
      pred = courant;
      courant = courant->suivant;
   }

   //Si la liste est vide on insere au d�but
   if (debut == 0)
      debut = nouveau;
   else
      pred->suivant = nouveau; // Sinon on ajoute � la fin
}

/**
 * \fn void Chemin::retirePiece(int numPiece)
 *
 * \param[in] numPiece : L'indice de la pi�ce � supprimer dans la cha�ne.
 */
void Chemin::retirePiece(int numPiece)
{
   //V�rification
   if (numPiece >= 1 && numPiece <= tailleChemin())
   {
      int i = 1;
      NoeudChemin * courant = debut;
      NoeudChemin * precedent = courant;

      //On loop n fois pour atteindre la piece d�sir�e
      while (i < numPiece)
      {
         precedent = courant;
         courant = courant->suivant;
         i++;
      }

      //Si le noeud d�sir� est le premier on r�assigne le d�but au suivant du d�but.
      if (debut == courant)
         debut = courant->suivant;
      else
         precedent->suivant = courant->suivant;	// Sinon on associe le suivant du noeud pr�c�dant le noeud d�sir� au noeud suivant du noeud d�sir�

      //On se d�barasse du noeud d�sir�
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
 * \return Le nom de la pi�ce au d�but du chemin.
 */
const std::string & Chemin::getNomPiece() const
{
   return debut->nomPiece;
}

/**
 * \fn int Chemin::getDistanceDuDebut() const
 *
 * \return La distance du d�but, soit de la pi�ce au d�but d'un chemin.
 */
int Chemin::getDistanceDuDebut() const
{
   return debut->distanceDuDebut;
}

/**
 * \fn int Chemin::tailleChemin() const
 *
 * \return Un entier repr�sentant la taille du chemin.
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
 * \param[in] sn : Un pointeur sur le d�but du chemin.
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
