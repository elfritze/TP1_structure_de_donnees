/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe Piece
 * \author �ric Guillemette, Mathieu L'�cuyer
 * \version 0.1
 * \date juin 2014
 */

#include "Piece.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les d�finitions du TP1.
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
 * \param[in] s : Une cha�ne de caract�res repr�sentant le nom de la pi�ce.
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
   portes.~ListePortes(); // appel du destructeur de ListePortes pour lib�rer la m�moire.
}

/**
 * \fn Piece::Piece(const Piece& p)
 *
 * \param[in] p : Un objet Piece existant.
 */
Piece::Piece(const Piece& p)
{
   portes = p.portes; // surcharge de l'op�rateur d'assignation de ListePortes
   parcourue = p.parcourue;
   nom = p.nom;
}

/**
 * \fn const Piece& Piece::operator =(const Piece& source)
 *
 * \param[in] source : Un objet Piece existant.
 *
 * \return L'objet courant contenant � pr�sent les donn�es de l'objet source.
 */
const Piece& Piece::operator =(const Piece& source)
{
   if (this != &source)
   {
      portes = source.portes; // surcharge de l'op�rateur d'assignation de ListePortes
      parcourue = source.parcourue;
      nom = source.nom;
   }

   return (*this);
}

/**
 * \fn std::string Piece::getNom() const
 *
 * \return nom : Le nom de la pi�ce.
 */
std::string Piece::getNom() const
{
   return nom;
}

/**
 * \fn void Piece::setParcourue(bool p)
 *
 * \param[in] p : Un bool�en de valeur true ou false.
 */
void Piece::setParcourue(bool p)
{
   parcourue = p;
}

/**
 * \fn bool Piece::getParcourue() const
 *
 * \return parcourue : Un bool�en pour indiquer si la pi�ce a �t� parcourue ou non.
 */
bool Piece::getParcourue() const
{
   return parcourue;
}

/**
 * \fn const ListePortes & Piece::getPortes() const
 *
 * \return portes : Un objet ListePortes repr�sentant la liste de portes de la pi�ce.
 */
const ListePortes & Piece::getPortes() const
{
   return portes;
}

/**
 * \fn void Piece::ajoutePorte(Porte& p)
 *
 * \param[in] p : Un objet Porte � ajouter � la liste de portes.
 */
void Piece::ajoutePorte(Porte& p)
{
   portes.ajoutePorte(p); // appel de la m�thode ajoutePorte() de ListePortes
}

} // namespace TP1
