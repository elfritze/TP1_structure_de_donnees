/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe Porte
 * \author �ric Guillemette, Mathieu L'�cuyer
 * \version 0.1
 * \date juin 2014
 */

#include "Porte.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les d�finitions du TP1.
 */
namespace TP1
{

/**
 * \fn Porte::Porte()
 */
Porte::Porte() :
      destination(0), color(Aucun)
{

}

/**
 * \fn Porte::Porte(Couleur c, Piece* d)
 *
 * \param[in] c : La couleur de la porte.
 * \param[in] d : La pi�ce de destination.
 */
Porte::Porte(Couleur c, Piece* d) :
      destination(d), color(c)
{

}

/**
 * \fn Porte::~Porte()
 */
Porte::~Porte()
{

}

/**
 * \fn Porte::Porte(const Porte& source)
 *
 * \param[in] source : Un objet Porte existant.
 */
Porte::Porte(const Porte& source)
{
   destination = source.destination;
   color = source.color;
}

/**
 * \fn const Porte& Porte::operator =(const Porte& source)
 *
 * \param[in] source : Un objet Porte existant.
 *
 * \return L'objet courant contenant � pr�sent les donn�es de l'objet source.
 */
const Porte& Porte::operator =(const Porte& source)
{
   if (this != &source)
   {
      destination = source.destination;
      color = source.color;
   }

   return (*this);
}

/**
 * \fn Couleur Porte::getCouleur() const
 *
 * \return color : La couleur d'une porte.
 */
Couleur Porte::getCouleur() const
{
   return color;
}

/**
 * \fn Piece* Porte::getDestination() const
 *
 * \return destination : La pi�ce de destination d'une porte.
 */
Piece* Porte::getDestination() const
{
   return destination;
}

} // namespace TP1
