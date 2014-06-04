/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Porte
 * \author Éric Guillemette, Mathieu L'Écuyer
 * \version 0.1
 * \date juin 2014
 */

#include "Porte.h"

/**
 * \namespace TP1
 *
 * Espace de nommage regroupant les définitions du TP1.
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
 * \param[in] c : la couleur de la porte.
 * \param[in] d : la pièce de destination.
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
 * \param[in] source : un objet Porte existant.
 */
Porte::Porte(const Porte& source) :
      destination(source.destination), color(source.color)
{

}

/**
 * \fn const Porte& Porte::operator =(const Porte& source)
 *
 * \param[in] source : un objet Porte existant.
 *
 * \return L'objet courant contenant à présent les données de l'objet source.
 */
const Porte& Porte::operator =(const Porte& source)
{
   if (this != &source)
   {
      color = source.color;
      destination = source.destination;
   }

   return *this;
}

/**
 * \fn Couleur Porte::getCouleur() const
 *
 * \return color : la couleur d'une porte.
 */
Couleur Porte::getCouleur() const
{
   return color;
}

/**
 * \fn Piece* Porte::getDestination() const
 *
 * \return destination : la pièce de destination d'une porte.
 */
Piece* Porte::getDestination() const
{
   return destination;
}

} // namespace TP1
