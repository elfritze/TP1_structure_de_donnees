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
 * \return L'objet courant contenant � pr�sent les donn�es de l'objet source.
 */
const Chemin& Chemin::operator=(const Chemin& source)
{
   if (this != &source)
   {
      if (debut != 0)
      {
         _detruire();
      }

      // On copie � partir du d�but
      debut = source.debut;
      cpt = source.cpt;
      if (source.debut != 0) // si la liste cha�n�e source n'est pas vide
      {
         _copier(source.debut);
      }
   }

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
   // On cr�e le nouveau noeud du chemin
   NoeudChemin * nouveau = new NoeudChemin(nomPiece, distanceDuDebut);
   nouveau->suivant = 0;

   // On parcourt la liste jusqu'� la fin
   NoeudChemin * courant = debut;
   NoeudChemin * pred = 0;
   while (courant != 0)
   {
      pred = courant;
      courant = courant->suivant;
   }

   // Si la liste est vide, on ins�re au d�but
   if (debut == 0)
   {
      debut = nouveau;
   }
   else
   {
      pred->suivant = nouveau; // Sinon on ajoute � la fin
   }

   cpt++;
}

/**
 * \fn void Chemin::retirePiece(int numPiece)
 *
 * \param[in] numPiece : L'indice de la pi�ce � supprimer dans la cha�ne.
 */
void Chemin::retirePiece(int numPiece)
{
   // V�rification des pr�conditions
   if (numPiece >= 1 && numPiece <= tailleChemin())
   {
      int i = 1;
      NoeudChemin * courant = debut;
      NoeudChemin * precedent = 0;

      // On boucle pour atteindre le noeud de la pi�ce d�sir�e
      while (i < numPiece)
      {
         precedent = courant;
         courant = precedent->suivant;
         i++;
      }

      // Si le noeud d�sir� est le premier, on r�assigne le d�but au noeud suivant.
      if (debut == courant)
      {
         debut = courant->suivant;
      }
      else
      {
         // Sinon on associe le pointeur suivant du noeud pr�c�dant
         // au noeud suivant du noeud � supprimer
         precedent->suivant = courant->suivant;
      }

      // On supprime le noeud d�sir�
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
 * \param[in] sn : Un pointeur sur le d�but du chemin.
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
      // Il y a une erreur d'allocation de m�moire
      // Il faut lib�rer la m�moire d�j� allou�e
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
