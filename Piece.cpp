/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Piece
 * \author Éric Guillemette, Mathieu L'Écuyer
 * \version 0.1
 * \date juin 2014
 */

#include "Piece.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les définitions du TP1.
 */
namespace TP1
{

/**
 * \fn Piece::Piece()
 */
Piece::Piece() :
      portes(ListePortes()), parcourue(false)
{
}

/**
 * \overload Piece::Piece(const std::string & s)
 *
 * \param[in] s : Une chaîne de caractères représentant le nom de la pièce.
 */
Piece::Piece(const std::string & s) :
      portes(ListePortes()), parcourue(false), nom(s)
{
}

/**
 * \fn Piece::~Piece()
 */
Piece::~Piece()
{
   portes.~ListePortes(); // appel du destructeur de ListePortes pour libérer la mémoire.
}

/**
 * \fn Piece::Piece(const Piece& p)
 *
 * \param[in] p : Un objet Piece existant.
 */
Piece::Piece(const Piece& p)
{
   portes = p.portes; // surcharge de l'opérateur d'assignation de ListePortes
   parcourue = p.parcourue;
   nom = p.nom;
}

/**
 * \fn const Piece& Piece::operator =(const Piece& source)
 *
 * \param[in] source : Un objet Piece existant.
 *
 * \return L'objet courant contenant à présent les données de l'objet source.
 */
const Piece& Piece::operator =(const Piece& source)
{
   if (this != &source)
   {
      portes = source.portes; // surcharge de l'opérateur d'assignation de ListePortes
      parcourue = source.parcourue;
      nom = source.nom;
   }

   return (*this);
}

/**
 * \fn std::string Piece::getNom() const
 *
 * \return nom : Le nom de la pièce.
 */
std::string Piece::getNom() const
{
   return nom;
}

/**
 * \fn void Piece::setParcourue(bool p)
 *
 * \param[in] p : Un booléen de valeur true ou false.
 */
void Piece::setParcourue(bool p)
{
   parcourue = p;
}

/**
 * \fn bool Piece::getParcourue() const
 *
 * \return parcourue : Un booléen pour indiquer si la pièce a été parcourue ou non.
 */
bool Piece::getParcourue() const
{
   return parcourue;
}

/**
 * \fn const ListePortes & Piece::getPortes() const
 *
 * \return portes : Un objet ListePortes représentant la liste de portes de la pièce.
 */
const ListePortes & Piece::getPortes() const
{
   return portes;
}

/**
 * \fn void Piece::ajoutePorte(Porte& p)
 *
 * \param[in] p : Un objet Porte à ajouter à la liste de portes.
 */
void Piece::ajoutePorte(Porte& p)
{
   portes.ajoutePorte(p); // appel de la méthode ajoutePorte() de ListePortes
}

} // namespace TP1
